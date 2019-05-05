#ifndef B_H
#define B_H

#include "A.h"

class B: A {

  // note: ‘B::B()’ is implicitly deleted because the default definition would
  // be ill-formed:

};

#endif
