#ifndef Derived_h
#define Derived_h

#include "Base.h"


class Derived : public Base {
public:
    ~Derived() override = default;
    void SaySomething() override;
};

#endif /* Derived_h */
