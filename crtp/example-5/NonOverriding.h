#ifndef NONOVERRIDING_H
#define NONOVERRIDING_H

#include "Base.h"
#include <iostream>

struct NonOverriding: Base<NonOverriding>
{
    void pure() { std::cout << "pure() from NonOverriding" << std::endl; }
};

#endif
