#ifndef LEVEL2_IMPL_H
#define LEVEL2_IMPL_H

#include "level1_impl.h"

template<typename derived_t>
struct level2_impl : public level1_impl<derived_t>
{
    auto only_for_level2_and_derived() const
    {
        return derived().bar;
    };
};

#endif
