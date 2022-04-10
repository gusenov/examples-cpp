#ifndef A_H
#define A_H

#include "Type2Type.h"

template <typename T> class A {
  void foo() const {
    static_cast<const T*>(this)->foo( Type2Type<T> );
  }
};

#endif
