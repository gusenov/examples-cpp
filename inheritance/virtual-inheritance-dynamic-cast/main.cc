#include <iostream>
#include <cstdlib>

class I {
public:
    I() = default;
    virtual ~I() = default;
};




class C: public virtual I {
public:
    C() = default;
    ~C() override = default;
};

class V: public virtual C {
public:
    V() = default;
    ~V() override = default;
};




class B: public virtual I {
public:
    B() = default;
    ~B() override = default;
};

class R: public B {
public:
    R() = default;
    ~R() override = default;
};

class A: public R,
         public virtual C
{
public:
    A() = default;
    ~A() override = default;
};

class H: public A {
public:
    H() = default;
    ~H() override = default;
};

class W: public H {
public:
    W() = default;
    ~W() override = default;
};

class S: public W,
         public V
{
public:
    S() = default;
    ~S() override = default;
};




int main() {
    S s;
    
    I* i = &s;
    B* b = &s;
    R* r = &s;
    A* a = &s;
    H* h = &s;
    W* w = &s;
    
    
    assert(dynamic_cast<C*>(i) != nullptr);  // TRUE
    assert(dynamic_cast<C*>(b) != nullptr);  // TRUE
    assert(dynamic_cast<C*>(r) != nullptr);  // TRUE
    
    assert(dynamic_cast<C*>(a) != nullptr);  // TRUE
    assert(dynamic_cast<C*>(h) != nullptr);  // TRUE
    assert(dynamic_cast<C*>(w) != nullptr);  // TRUE


    return EXIT_SUCCESS;
}