#pragma once

namespace test9
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
    // Call to 'Foo' is ambiguous
//    Foo([]() {
//        // Do nothing
//    });
}

}
