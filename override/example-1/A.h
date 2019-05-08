#ifndef A_H
#define A_H

#include <iostream>

struct A {
  virtual ~A() {
    std::cout << "~A() from A" << std::endl;
  };

  void foo() {
    std::cout << "foo() from A" << std::endl;
  }

  virtual void bar() {
    std::cout << "bar() from A" << std::endl;
  }
};

#endif
