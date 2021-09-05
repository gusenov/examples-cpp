#pragma once

namespace test6
{

class Bar
{
public:
    Bar()
    {
        std::cout << "Bar()" << std::endl;
    }

    ~Bar()
    {}

    Bar(Bar const&)
    {
        std::cout << "Bar(Bar const&)" << std::endl;
    }

    Bar(Bar&&) noexcept
    {
        std::cout << "Bar(Bar&&)" << std::endl;
    }

    void operator()() const
    {
        std::cout << "void operator()()" << std::endl;
    }
};

void Foo(Bar const&)
{
    std::cout << "void Foo(std::function<void()> const&)" << std::endl;
}

void Foo(Bar&&)
{
    std::cout << "void Foo(std::function<void()>&&)" << std::endl;
}

void Run()
{
    Foo(Bar());
    // Bar()
    // void Foo(std::function<void()>&&)
}

}