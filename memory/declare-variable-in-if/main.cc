#include <iostream>

class A
{
public:
    explicit A(bool const is)
        : is_(is)
    {
        std::clog << "A(" << is << ")" << std::endl;
    }

    ~A()
    {
        std::clog << "~A()" << std::endl;
    }

    bool Is() const
    {
        return is_;
    }

private:
    bool is_ = true;
};

class B
{
public:
    B()
    {
        std::clog << "B()" << std::endl;
    }

    ~B()
    {
        std::clog << "~B()" << std::endl;
    }

    A const& GetA()
    {
        return a_;
    }

private:
    A a_{true};
};

class C
{
public:
    C()
    {
        std::clog << "C()" << std::endl;
    }

    ~C()
    {
        std::clog << "~C()" << std::endl;
    }

    B GetB()
    {
        return b_;
    }

private:
    B b_;
};

int main()
{
    std::clog << "C c;" << std::endl;
    C c;

    std::clog << std::endl;
    std::clog << "if" << std::endl;
    if (auto& t = c.GetB().GetA(); t.Is())
    {
        std::clog << "begin" << std::endl;
        std::clog << t.Is() << std::endl;
        std::clog << "end;" << std::endl;
    }

    std::clog << std::endl << "end." << std::endl;
    return 0;
}

/*

C c;
A(1)
B()
C()

if
~B()
~A()
begin
1
end;

end.
~C()
~B()
~A()

*/