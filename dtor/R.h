#ifndef R_H
#define R_H

#include <iostream>
#include "Q.h"

class R : public Q {

  public:

    ~R() {
      std::cout << "~R()" << std::endl;
    }

};

#endif
