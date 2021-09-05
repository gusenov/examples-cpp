#pragma once

namespace test7
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

void Foo(Bar&&)
{
    std::cout << "void Foo(std::function<void()>&&)" << std::endl;
}

void Run()
{
    Bar b;
    Foo(std::move(b));  // без std::move будет No matching function for call to 'Foo'
    // Bar()
    // void Foo(std::function<void()>&&)
}

}
