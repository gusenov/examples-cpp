#ifndef C_H
#define C_H

#include "B.h"
#include <iostream>

struct C : B {
  ~C() override {
    std::cout << "~C()" << std::endl;
  }
};

#endif
