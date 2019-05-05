#ifndef A_H
#define A_H

#include <iostream>

class A {

  // По умолчанию всё приватное.

  ~A() {  // note: declared private here
    std::cout << "~A()" << std::endl;
  }

};

#endif
