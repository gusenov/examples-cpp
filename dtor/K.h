#ifndef K_H
#define K_H

#include <iostream>
#include "J.h"

class K : public J {

  public:

    ~K() {
      std::cout << "~K()" << std::endl;
    }

};

#endif
