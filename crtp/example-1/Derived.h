#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h"
#include <iostream>

using namespace std;

struct Derived : public Base<Derived>
{
    void implementation() {
      std::cout << "Derived::implementation()" << std::endl;
    }

    static void static_sub_func() {
      std::cout << "Derived::static_sub_func()" << std::endl;
    }
};

#endif
