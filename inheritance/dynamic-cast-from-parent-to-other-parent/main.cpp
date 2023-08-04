#include <iostream>
#include <cassert>

struct A
{
    virtual ~A() = default;
};

struct B
    : A
{
};

template<class T>
struct C
{
    virtual ~C() = default;
};

struct D
{};

struct E
{};

struct F
    : B
    , C<D>
    , C<E>
{
};

struct G
{
    virtual ~G() = default;
};

class H
    : public F
    , private G
{};

void test1()
{
    H h;
    F* f = &h;
    G* g = dynamic_cast<G*>(f);
    assert(!g);  // TRUE
    // Если у class H поменять private G на public G, то преобразование пройдет успешно.
}

int main()
{
    test1();
    return 0;
}
