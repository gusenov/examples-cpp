//---------------------------------------------------------------------------
// Константность.
//---------------------------------------------------------------------------

#include <iostream>
#include "fundamental_ptr.h"
#include "ptr2ptr.h"
#include "MyClass.h"

using namespace std;

int main(int argc, char** argv) {
    fundamental_ptr();
    ptr2ptr();

    MyClass mc;
    int* i = mc.GetIntPtr();
    *i = 100;  // допустимо.

    return 0;
}
