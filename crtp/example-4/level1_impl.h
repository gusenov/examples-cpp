#ifndef LEVEL1_IMPL_H
#define LEVEL1_IMPL_H

#include "level0_impl.h"
#include <iostream>

template<typename derived_t>
struct level1_impl : level0_impl<derived_t>
{
    auto only_for_level1_and_derived() const
    {
        return derived().foo;
    };
    auto do_something() const { std::cout<<"hi"<<std::endl; }
};

#endif
