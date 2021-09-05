#pragma once

namespace test4
{

class Bar
{
public:
    Bar()
    {
        std::cout << "Bar()" << std::endl;
    }

    void operator()() const
    {
        std::cout << "void operator()()" << std::endl;
    }
};

void Foo(std::function<void()> foo)
{
    std::cout << "void Foo(std::function<void()>)" << std::endl;
    foo();
}

void Run()
{

    std::function<void()> lm;
    {
        Bar b;
        // Bar()
        lm = [b]() {
            b();
        };
    }

    Foo(lm);
    // void Foo(std::function<void()>)
    // void operator()()
}

}
