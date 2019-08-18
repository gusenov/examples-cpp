#include <cstdlib>
#include "MostDerived.h"

int main(int argc, const char * argv[]) {
    MostDerived m;
    m.SaySomething("test");
    // test

    // m.SaySomething();
    // error: too few arguments to function call, single argument 'message' was not specified

    Derived &d = m;
    d.SaySomething();
    // Hello, World!

    Base &b = d;
    b.SaySomething();
    // Hello, World!

    ITalker &t = b;
    t.SaySomething();
    // Hello, World!

    return EXIT_SUCCESS;
}
