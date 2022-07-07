//
// Created by Abbas Gussenov on 2/23/22.
//

#include "A.h"
#include <iostream>

// void Foo() { std::cout << "Foo() in A.cc" << std::endl; }
// duplicate symbol 'Foo()' in:
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/A.cc.o
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/B.cc.o
// ld: 1 duplicate symbol for architecture x86_64

// Объявление, чтобы можно было вызывать:
namespace {
    namespace {
        namespace {
            void Quuux();
        }
    }
}

void Bat()
{
    // Bar();
    // Undefined symbols for architecture x86_64:
    //   "Bar()", referenced from:
    //       Bat() in A.cc.o
    //       Baz() in B.cc.o
    // ld: symbol(s) not found for architecture x86_64

    // Qux();  // Use of undeclared identifier 'Qux'
    Quuux();
}

namespace
{  // An unnamed namespace hide names inside it from different translation units.

void Bar() { std::cout << "Bar() in A.cc" << std::endl; }

void Qux() { std::cout << "Qux() in B.cc" << std::endl; }
namespace
{
    void Quux() { std::cout << "Quux() in A.cc" << std::endl; }
    namespace
    {
        void Quuux() { std::cout << "Quuux() in A.cc" << std::endl; }
    }
}

}

void Temp()
{
    // Bar();  // Call to 'Bar' is ambiguous

    Quuux();
}

void Sub()
{
    // qwe::Asd();
    // Undefined symbols for architecture x86_64:
    //   "qwe::Asd()", referenced from:
    //       Sub() in A.cc.o
    // ld: symbol(s) not found for architecture x86_64
    //
    // Объявлено как qwe::Asd(), а определено как qwe::(anonymous namespace)::Asd(),
    // поэтому не находит.

    qwe::Zxc();
    // Объявление qwe::(anonymous namespace)::Zxc() и определение совпадают поэтому ОК.
}

namespace qwe
{

// void DoTheStuff() { std::cout << "DoTheStuff() in A.cc" << std::endl; }
// duplicate symbol 'qwe::DoTheStuff()' in:
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/A.cc.o
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/B.cc.o
// ld: 1 duplicate symbol for architecture x86_64

namespace
{  // An unnamed namespace hide names inside it from different translation units.

void Asd() { std::cout << "Asd() in A.cc" << std::endl; }
void Zxc() { std::cout << "Zxc() in A.cc" << std::endl; }
void Aaa() { std::cout << "Aaa() in A.cc" << std::endl; }

}

}
