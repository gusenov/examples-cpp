#ifndef T_H
#define T_H

#include <iostream>
#include "S.h"

class T : public S {

  public:

    virtual void foo(void) {
      std::cout << "foo()" << std::endl;
      return;
    }

    ~T() {
      std::cout << "~T()" << std::endl;
    }

};

#endif
