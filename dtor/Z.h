#ifndef Z_H
#define Z_H

#include "X.h"
#include <iostream>

class Z : public X {
  public:
    ~Z() {
      std::cout << "~Z()" << std::endl;
    }
};

#endif
