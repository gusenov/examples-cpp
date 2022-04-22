#include <memory>
#include <cstdlib>
#include <iostream>

class B
{
public:
    B() = default;
    
    B(B const&) = default;
    
    void Foo()
    {
        std::cout << "void Foo()" << std::endl;
    }
    
    void Foo() const
    {
        std::cout << "void Foo() const" << std::endl;
    }
};

struct Base
{
    virtual ~Base() = default;
    
    virtual Base* Clone() const = 0;
    virtual std::shared_ptr<B> CloneB() const = 0;
};

class A
    : public Base
{
public:
    A()
        : b_(std::make_shared<B>())
    {}

    std::shared_ptr<B> GetB()
    {
        return b_;
    }

    std::shared_ptr<B const> GetB() const
    {
        return b_;
    }
    
    // Base const* Clone() const override { return new A(*this); }
    // error: return type of virtual function 'Clone' is not covariant with the return type of the function it overrides (class type 'const Base *' is more qualified than class type 'Base *'
    
    A* Clone() const override { return new A(*this); }
    
    // std::shared_ptr<B const> CloneB() const override { return nullptr; }
    // error: virtual function 'CloneB' has a different return type ('shared_ptr<const B>') than the function it overrides (which has return type 'shared_ptr<B>')
    
    std::shared_ptr<B> CloneB() const override { return std::make_shared<B>(*b_); }

private:
    std::shared_ptr<B> b_;
};

void bar(std::shared_ptr<B const> const b)
{
    b->Foo();
}

int main(int argc, char* argv[])
{

    {
        A a;
        auto b = a.GetB();
        bar(b);
        // void Foo() const
    }

    {
        A const a;
        auto b = a.GetB();
        b->Foo();
        // void Foo() const
    }
    
    return EXIT_SUCCESS;
}