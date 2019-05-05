#ifndef I_H
#define I_H

#include <iostream>
#include "H.h"

class I : H {  // по умолчанию наследование приватное.

  public:

    ~I() {
      std::cout << "~I()" << std::endl;
    }

};

#endif
