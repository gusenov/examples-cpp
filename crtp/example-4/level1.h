#ifndef LEVEL1_H
#define LEVEL1_H

#include "level1_impl.h"

struct level1 : public level1_impl<level1>
{
    using level1_impl<level1>::level1_impl;
};

#endif
