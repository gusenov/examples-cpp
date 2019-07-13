#ifndef PTR2PTR_H
#define  PTR2PTR_H

#include <iostream>

#define int_ptr   int*                  /*|       int*       |*/
#define cint_ptr  const int_ptr         /*| const int*       |*/
#define int_cptr  int_ptr const         /*|       int* const |*/
#define cint_cptr const int_ptr const   /*| const int* const |*/

// НЕПРАВИЛЬНО:
#define cint_ptr__ptr     cint_ptr*                    /*|       cint_ptr*       =       const int**       |*/
#define c__cint_ptr__ptr  const cint_ptr__ptr          /*| const cint_ptr*       = const const int**       |*/
#define cint_ptr__cptr    cint_ptr__ptr const          /*|       cint_ptr* const =       const int** const |*/
#define c__cint_ptr__cptr const cint_ptr__ptr const    /*| const cint_ptr* const = const const int** const |*/

using namespace std;

void ptr2ptr(void) {
    // ПРАВИЛЬНО:

    int a = 711733;
    int aa = 437956;

    // Указатель с константностью по данным
    // на int:
    const int* b;
    b = nullptr;
    // *b = 2;  // error: read-only variable is not assignable
    b = &a;
    cout << "b = " << *b << endl;  // b = 711733

    // Указатель
    // на <указатель на int с константностью по данным>:
    const int** c;
    c = &b;
    *c = &aa;
    cout << "b = " << *b << endl;  // b = 437956
    // **c = 3;  // error: read-only variable is not assignable

    // Указатель с константностью по данным
    // на <указатель на int с константностью по данным>:
    const int* const* d = &b;
    d = c;
    // *d = nullptr;  // error: read-only variable is not assignable

    // Указатель с константностью по данным и по адресу
    // на <указатель на int с константностью по данным>:
    const int* const* const e = d;
    // *e = nullptr;  // error: read-only variable is not assignable
    // e = nullptr;
    // error: cannot assign to variable 'e' with const-qualified type 'const int *const *const'
}

#endif
