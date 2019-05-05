#ifndef S_H
#define S_H

#include <iostream>

class S {

  virtual void foo(void) = 0;

  protected:

    ~S() {
      std::cout << "~S()" << std::endl;
    }

};

#endif
