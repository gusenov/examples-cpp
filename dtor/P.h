#ifndef P_H
#define P_H

#include <iostream>
#include "N.h"

class P : public N {

  public:

    virtual ~P() {
      std::cout << "~P()" << std::endl;
    }
    
};

#endif
