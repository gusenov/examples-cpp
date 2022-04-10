#ifndef C_H
#define C_H

#include "B.h"
#include <iostream>

struct C: B <C> {
  void foo() { // can be either present or absent
    std::cout << "foo() from C" << std::endl;
  }
};

#endif
