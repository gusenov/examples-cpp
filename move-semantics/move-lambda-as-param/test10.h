#pragma once

namespace test10
{

void Foo(std::function<void()> const&)
{
    std::cout << "void Foo(std::function<void()> const&)" << std::endl;
}

void Foo(std::function<void()>&&)
{
    std::cout << "void Foo(std::function<void()>&&)" << std::endl;
}

void Run()
{
    std::function<void()> lm = []() {
        // Do nothing
    };
    Foo(lm);
    // void Foo(std::function<void()> const&)
}

}
