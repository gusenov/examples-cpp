#ifndef LEVEL2_H
#define LEVEL2_H

#include "level2_impl.h"

struct level2 : public level2_impl<level2>
{
    using level2_impl<level2>::level2_impl;
};

#endif
