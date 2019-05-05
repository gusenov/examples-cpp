#ifndef G_H
#define G_H

#include <iostream>
#include "A.h"

class G: A {

  // НЕ СКОМПИЛИРУЕТСЯ:

  /*

  public:

    ~G() {  // error: ‘A::~A()’ is private within this context
      std::cout << "~G()" << std::endl;
    }

  */

};

#endif
