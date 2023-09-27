#include <iostream>

struct Interface
{
    virtual void Foo(int param = -1) = 0;
    // Clang-Tidy: Default arguments on virtual or override methods are prohibited
};

class Abstract
    : public Interface
{
public:
    void Foo(int param) override
    {
        std::cout << "Abstract = " << param << std::endl;
    }
};

class Base
    : public Abstract
{
public:
    void Foo(int param = 1) override
    {
        std::cout << "Base = " << param << std::endl;
    }
};

class Impl
    : public Base
{
public:
    void Foo(int param) override
    {
        std::cout << "Impl = " << param << std::endl;
    }
};

class Concrete
    : public Impl
{
public:
    void Foo(int param = 3) override
    {
        std::cout << "Concrete = " << param << std::endl;
    }
};

void test1()
{
    std::cout << "Concrete" << std::endl;
    Concrete concrete;
    concrete.Foo();

    std::cout << std::endl;

    std::cout << "Impl" << std::endl;
    Impl& impl = concrete;
    impl.Foo(2);

    std::cout << std::endl;

    std::cout << "Base" << std::endl;
    Base& base = impl;
    base.Foo();

    std::cout << std::endl;

    std::cout << "Abstract" << std::endl;
    Abstract& abstract = base;
    abstract.Foo(0);

    std::cout << std::endl;

    std::cout << "Interface" << std::endl;
    Interface& interface = abstract;
    interface.Foo();
}
/*
Concrete
Concrete = 3

Impl
Concrete = 2

Base
Concrete = 1

Abstract
Concrete = 0

Interface
Concrete = -1
*/

int main()
{
    test1();
    return 0;
}
