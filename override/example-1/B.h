#ifndef B_H
#define B_H

#include "A.h"
#include <iostream>

struct B : A {
  ~B() {
    std::cout << "~B() from B" << std::endl;
  }

  // Если здесь оставить override, то будет ошибка:
  // error: ‘void B::foo()’ marked ‘override’, but does not override
  void foo() /*override*/ {
    std::cout << "foo() from B" << std::endl;
  }

  // А здесь override работает потому что в предке A функция bar() объявлена
  // как виртуальная:
  void bar() override {
    std::cout << "bar() from B" << std::endl;
  }
};

#endif
