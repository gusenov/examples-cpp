static int const TU = 0;




#include "print_number.h"
#include "eq_number.h"




void test_print_number() {
    int i = 1;
    float f = 2.0f;
    double d = 3.;

    print_number(i);
    // TU = 1
    // 1

    print_number(f);
    // TU = 1
    // 2

    print_number(d);
    // TU = 1
    // 3
}




// Explicit instantiation declaration:

extern
template
void eq_number(double const&, double const&);

// Без этой декларации,
// если компилятор первым скомпилирует main.cpp, а потом eq_number.cpp,
// то в следующих выводах № 2 и 3, TU будет равняться 0.
// Если же компилятор первым скомпилирует eq_number.cpp, а потом main.cpp,
// то в следующих выводах № 2 и 3, TU будет равняться 2.

// С этой декларацией,
// eq_number для double будет использоваться из eq_number.cpp.


void test_eq_number() {
    int ia = 20, ib = 30;
    eq_number(ia, ib);
    // № 1
    // TU = 0
    // 20 != 30

    float fa = 10.0f, fb = 10.f;
    eq_number(fa, fb);
    // № 2
    // TU = 0
    // 10 == 10

    double da = 90., db = 90.;
    eq_number(da, db);
    // № 3
    // TU = 2
    // 90 == 90
}




int main() {
    //test_print_number();
    test_eq_number();
    return 0;
}
