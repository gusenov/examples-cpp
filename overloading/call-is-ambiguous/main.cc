#include <cstdlib>
#include <iostream>
#include <memory>

struct I1 {
    virtual ~I1() = default;
};

struct I2 : I1 {
    ~I2() override = default;
};

class A : public I1 {
public:
    A() = default;
    ~A() override = default;
};

class B : public I2 {
public:
    B() = default;
    ~B() override = default;
};

class Z {
public:
    Z() = default;
    ~Z() = default;
    
    void Foo(I1* i1) {
        std::cout << "void Foo(I1* i1)" << std::endl;;
    }
    
    void Foo(I2* i2) {
        std::cout << "void Foo(I2* i2)" << std::endl;
    }

    void Foo(std::shared_ptr<I1> i1) {
        std::cout << "void Foo(std::shared_ptr<I1> i1)" << std::endl;
    }
    
    void Foo(std::shared_ptr<I2> i2) {
        std::cout << "void Foo(std::shared_ptr<I2> i2)" << std::endl;
    }
};

int main(int argc, char const* argv[]) {
    Z z;
    std::shared_ptr<I1> i1 = std::make_shared<A>();
    std::shared_ptr<I2> i2 = std::make_shared<B>();
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    z.Foo(i1.get());  // void Foo(I1* i1)
    z.Foo(i2.get());  // void Foo(I2* i2)
    
    z.Foo(i1);        // void Foo(std::shared_ptr<I1> i1)
    z.Foo(i2);        // void Foo(std::shared_ptr<I2> i2)
    
    z.Foo(a);         // void Foo(std::shared_ptr<I1> i1)
    // z.Foo(b);      // error: call to member function 'Foo' is ambiguous

    return EXIT_SUCCESS;
}
