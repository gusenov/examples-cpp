#include <iostream>
#include "A.h"
#include "B.h"

int main()
{
    // Bar();
    //
    // Undefined symbols for architecture x86_64:
    //   "Bar()", referenced from:
    //       _main in main.cc.o
    // ld: symbol(s) not found for architecture x86_64
    //
    // Не может найти Bar() потому что хотя в A.h и B.h есть объявление,
    // определение содержится в безымянном неймспейсе в A.cpp и B.cpp.

    // qwe::Asd();
    //
    // Undefined symbols for architecture x86_64:
    //   "qwe::Asd()", referenced from:
    //       _main in main.cc.o
    // ld: symbol(s) not found for architecture x86_64
    //
    // Не может найти qwe::Asd() потому что хотя в A.h и B.h есть объявление,
    // определение содержится в безымянном неймспейсе в A.cpp и B.cpp.
    // Объявлено как qwe::Asd(), а определено как qwe::(anonymous namespace)::Asd().

    // qwe::Zxc();
    //
    // Undefined symbols for architecture x86_64:
    //   "qwe::(anonymous namespace)::Zxc()", referenced from:
    //       _main in main.cc.o
    // ld: symbol(s) not found for architecture x86_64
    //
    // Ожидается, что определение qwe::Zxc() будет в этом модуле,
    // потому что объявлено как qwe::(anonymous namespace)::Zxc().

    Sub();  // Zxc() in A.cc
    // Sub() вызывает Zxc().

    Bat();  // Quuux() in A.cc
    // Bat() вызывает Quuux().

    qwe::Aaa();  // Aaa() in main.cc
    // В A.h есть объявление qwe::(anonymous namespace)::Aaa().
    // А определение дается позже в этом модуле.
    // Хотя в A.cpp есть определение, здесь будет искаться определение именно в этом модуле,
    // потому функция объявлена с internal linkage.

    return 0;
}

namespace qwe
{

namespace
{
void Aaa() { std::cout << "Aaa() in main.cc" << std::endl; }
}

}