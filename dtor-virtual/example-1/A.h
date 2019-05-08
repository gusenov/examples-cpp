#ifndef A_H
#define A_H

#include <iostream>

struct A {
  virtual ~A() {
    std::cout << "~A()" << std::endl;
  };
};

#endif
