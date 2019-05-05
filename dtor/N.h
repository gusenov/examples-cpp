#ifndef N_H
#define N_H

#include <iostream>

class N {

  public:

    virtual ~N() {
      std::cout << "~N()" << std::endl;
    };

};

#endif
