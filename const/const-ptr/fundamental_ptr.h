#ifndef FUNDAMENTAL_PTR_H
#define FUNDAMENTAL_PTR_H

void fundamental_ptr() {
    int i = 0;


    // const int ci;
    // error: default initialization of an object of const type 'const int'

    const int ci = 1;
    // ci = 2;
    // error: cannot assign to variable 'ci' with const-qualified type 'const int'

    int const ic = 2;


    // Всего const, int и * можно расположить 6 способами:

    // 1) const int *  // const слева от * значит нельзя менять данные.

    const int* cip;
    cip = nullptr;  // сам указатель менять можно.
    // *cip = 3;  // данные менять нельзя:
    // error: read-only variable is not assignable

    // 2) int const *

    // Эквивалентно вышеприведенному примеру:
    int const* icp;
    icp = nullptr;
    // *icp = 4;
    // error: read-only variable is not assignable

    // 3) int * const  // const справа от * значит нельзя менять указатель.

    // int* const ipc;
    // error: default initialization of an object of const type 'int *const'

    int* const ipc = &i;
    // ipc = nullptr;  // нельзя менять указатель:
    // error: cannot assign to variable 'ipc' with const-qualified type 'int *const'

    *ipc = 5;  // данные менять можно.

    // Нерабочие варианты:

    // 4) const * int

    // const* int cpi;
    // error: expected unqualified-id

    // const* int cpi = nullptr;
    // error: expected unqualified-id

    // 5) * int const pic;
    // error: expected '(' for function-style cast or type construction

    // 6) * const int
    // error: expected expression

    // Вывод: слева от * всегда должен быть указан тип.



    // Всего int, * и два const можно расположить 12 способами:

    // Когда const слева и справа от *, то нельзя менять указатель и данные.

    // 1) const int * const

    // const int* const cipc;
    // error: default initialization of an object of const type 'const int *const'

    const int* const cipc = &i;

    // cipc = nullptr;
    // error: cannot assign to variable 'cipc' with const-qualified type 'const int *const'

    // *cipc = 6;
    // error: read-only variable is not assignable

    // 2) int const * const

    // int const* const icpc;
    // error: default initialization of an object of const type 'const int *const'

    int const* const icpc = &i;

    // icpc = nullptr;
    // error: cannot assign to variable 'icpc' with const-qualified type 'const int *const'

    // *icpc = 7;
    // error: read-only variable is not assignable

    // 3) const const int *
    // const const int* ccip;
    // warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]

    // 4) int const const *
    // int const const* iccp;
    // warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]

    // 5) const int const *
    // const int const* cicp;
    // warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]

    // 6) int * const const
    // int* const const ipcc;
    // warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]
    // error: default initialization of an object of const type 'int *const'

    // 7) const * const int
    // const* const int cpci;
    // error: expected unqualified-id

    // 8) const * int const
    // const* int const cpic;
    // error: expected unqualified-id

    // 9) const const * int
    // const const* int ccpi;
    // warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]
    // error: expected unqualified-id

    // 10) * const const int
    // * const const int pcci;
    // error: expected expression

    // 11) * int const const
    // * int const const picc;
    // error: expected '(' for function-style cast or type construction

    // 12) * const int const
    // * const int const *pcic;
    // error: expected expression

    // Вывод: при использовании двух const, один должен быть слева от *,
    // другой - справа.
    // Между любыми двумя const должен быть символ *.
}

#endif  // FUNDAMENTAL_PTR_H
