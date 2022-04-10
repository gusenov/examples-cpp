#ifndef OVERRIDING_H
#define OVERRIDING_H

#include "Base.h"
#include <iostream>

struct Overriding: Base<Overriding>
{
    void f() { std::cout << "Special case" << std::endl; }

    // This method must exists to prevent endless recursion in Base::f
    void pure() { std::cout << "pure() from Overriding" << std::endl; }
};

#endif
