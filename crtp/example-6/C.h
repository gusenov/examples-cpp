#ifndef C_H
#define C_H

#include "B.h"

class C : public B<C> {
  void foo(...) {
    std::cout << "C::foo()\n";
  }
};

#endif
