#ifndef EQ_NUMBER_H
#define EQ_NUMBER_H

#include <iostream>

template <typename T>
void eq_number(T const& a, T const& b) {
    std::cout << "TU = " << TU << std::endl;
    std::cout << a << (a == b ? " == " : " != ") << b << std::endl << std::endl;
}

#endif
