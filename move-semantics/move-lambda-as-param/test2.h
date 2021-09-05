#pragma once

namespace test2
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
    Foo([]() {
        // Do nothing
    });
    // void Foo(std::function<void()>&&)
}

}
