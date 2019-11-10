#ifndef C_H
#define C_H

#include "B.h"
#include <iostream>

struct C : B {
  // possibly absent to not override B::foo().
  void foo() const final { std::cout << "do something else" << std::endl; }
  // Ключевое слово final предотвращает дальнейшее наследование классов
  // или в случае с методом запрещает его переопределение в производных классах.
};

#endif
