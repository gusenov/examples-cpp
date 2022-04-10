#ifndef LEVEL0_H
#define LEVEL0_H

#include "level0_impl.h"

struct level0 : public level0_impl<level0>
{
    using level0_impl<level0>::level0_impl;
};

#endif
