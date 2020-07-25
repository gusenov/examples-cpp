#include <cstdlib>
#include "Factory.h"
#include "ISomething.h"

void test1() {
    auto something_s = Factory::New_S("SomethingConcrete");
    assert(something_s);
}

void test2() {
    auto something_r = Factory::New_R("SomethingConcrete");
    assert(something_r);
    delete something_r;
}

int main(int argc, char const * argv[]) {
    test1();
    test2();
    return EXIT_SUCCESS;
}
