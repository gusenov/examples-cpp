#ifndef B_H
#define B_H

#include "A.h"
#include <iostream>

struct B : A {
  ~B() = default;
};

#endif
