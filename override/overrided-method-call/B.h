#ifndef B_H
#define B_H

#include "A.h"
#include <iostream>

struct B : A {
  void foo() const override { std::cout << "do something" << std::endl; }
};

#endif
