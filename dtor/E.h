#ifndef E_H
#define E_H

#include <iostream>

class E {

  protected:

    ~E() {  // note: declared protected here
      std::cout << "~E()" << std::endl;
    }

};

#endif
