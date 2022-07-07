//
// Created by Abbas Gussenov on 2/23/22.
//

#include "B.h"
#include <iostream>

// void Foo() { std::cout << "Foo() in B.cc" << std::endl; }
// duplicate symbol 'Foo()' in:
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/A.cc.o
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/B.cc.o
// ld: 1 duplicate symbol for architecture x86_64

void Baz()
{
    // Bar();
    // Undefined symbols for architecture x86_64:
    //   "Bar()", referenced from:
    //       Bat() in A.cc.o
    //       Baz() in B.cc.o
    // ld: symbol(s) not found for architecture x86_64
}

namespace
{  // An unnamed namespace hide names inside it from different translation units.

void Bar() { std::cout << "Bar() in B.cc" << std::endl; }

void Qux() { std::cout << "Qux() in B.cc" << std::endl; }
namespace
{
    void Quux() { std::cout << "Quux() in B.cc" << std::endl; }
    namespace
    {
        void Quuux() { std::cout << "Quuux() in B.cc" << std::endl; }
    }
}

}

void Test()
{
    // Bar();  // Call to 'Bar' is ambiguous

    Quuux();
}

namespace qwe
{

// void DoTheStuff() { std::cout << "DoTheStuff() in B.cc" << std::endl; }
// duplicate symbol 'qwe::DoTheStuff()' in:
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/A.cc.o
//     CMakeFiles/UnnamedNamespaceWithinNamedNamespace.dir/B.cc.o
// ld: 1 duplicate symbol for architecture x86_64

namespace
{  // An unnamed namespace hide names inside it from different translation units.

void Asd() { std::cout << "Asd() in B.cc" << std::endl; }
void Zxc() { std::cout << "Zxc() in B.cc" << std::endl; }

}

}
