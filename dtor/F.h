#ifndef F_H
#define F_H

#include <iostream>
#include "E.h"

class F : E {

  public:

    ~F() {
      std::cout << "~F()" << std::endl;

      // Здесь дальше пойдёт вызов ~E().
      // Т.к. доступ к ~E() protected, то это возможно.

    }

};

#endif
