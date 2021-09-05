#pragma once

namespace test3
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
    auto lm = []() {
        // Do nothing
    };

    // No viable overloaded '='
//    lm = []() {
//        // Do nothing
//    };

    Foo(lm);
    // void Foo(std::function<void()>&&)
}

}
