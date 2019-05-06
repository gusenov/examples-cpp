#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h"
#include <iostream>

struct Derived : Base
{
  int downsize(int x)
  {
    while (x > 42) x /= 2;
    return x;
  }

  void epilogue()
  { std::cout << "We're done!\n"; }
};

#endif
