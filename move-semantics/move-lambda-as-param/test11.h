#pragma once

namespace test11
{

void Foo(std::function<void()>&&)
{
    std::cout << "void Foo(std::function<void()>&&)" << std::endl;
}

void Run()
{
    std::function<void()> lm = []() {
        // Do nothing
    };

//    Foo(lm);
    // No matching function for call to 'Foo'
}

}
