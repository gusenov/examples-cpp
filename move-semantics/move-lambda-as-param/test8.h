#pragma once

namespace test8
{

void Foo(std::function<void()>)
{
    std::cout << "void Foo(std::function<void()> const&)" << std::endl;
}

void Foo(std::function<void()>&&)
{
    std::cout << "void Foo(std::function<void()>&&)" << std::endl;
}

void Run()
{
    auto lm = []() {
        // Do nothing
    };
    // Foo(lm);  // Call to 'Foo' is ambiguous
}

}
