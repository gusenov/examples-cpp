#include <iostream>
#include <cstdlib>




class C {
public:
    C() = default;
    virtual ~C() = default;
};

class V: public C {
public:
    V() = default;
    ~V() override = default;
};




class I {
public:
    I() = default;
    virtual ~I() = default;
};

class B: public I {
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
         public C
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
    
    
    assert(dynamic_cast<C*>(i) == nullptr);  // TRUE
    assert(dynamic_cast<C*>(b) == nullptr);  // TRUE
    assert(dynamic_cast<C*>(r) == nullptr);  // TRUE
    
    assert(dynamic_cast<C*>(a) != nullptr);  // TRUE
    assert(dynamic_cast<C*>(h) != nullptr);  // TRUE
    assert(dynamic_cast<C*>(w) != nullptr);  // TRUE
    
    
    assert(reinterpret_cast<C*>(i) != nullptr);  // TRUE
    assert(reinterpret_cast<C*>(b) != nullptr);  // TRUE
    assert(reinterpret_cast<C*>(r) != nullptr);  // TRUE


    return EXIT_SUCCESS;
}