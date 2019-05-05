#ifndef Q_H
#define Q_H

#include <iostream>

class Q {

  protected:

    ~Q() {  // note: declared protected here
      std::cout << "~Q()" << std::endl;
    }

};

#endif
