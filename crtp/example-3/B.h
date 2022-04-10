#ifndef B_H
#define B_H

#include "A.h"
#include <iostream>

template<class Derived>
struct B: A <Derived> {
  void foo() {
    std::cout << "do something" << std::endl;
  }
};

#endif
