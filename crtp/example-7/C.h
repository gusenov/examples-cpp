#ifndef C_H
#define C_H

#include "B.h"

class C : public B<C> {

public:

  void foo() const {
    std::cout << "C::foo()\n";
  }

};

#endif
