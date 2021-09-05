#pragma once

namespace test1
{

void Foo(std::function<void()>)
{}

void Foo(std::function<void()> const&)
{}

void Run()
{
//    Foo([]() {
//        // Do nothing
//    });
    // Call to 'Foo' is ambiguous
}

}
