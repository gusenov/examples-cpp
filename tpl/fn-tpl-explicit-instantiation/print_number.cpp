static int const TU = 1;




#include "print_number.h"
#include <iostream>




template<typename T>
void print_number(T const& number) {
    std::cout << "TU = " << TU << std::endl;
    std::cout << number << std::endl << std::endl;
}




// Explicit instantiation definitions:

template
void print_number(int const&);

template
void print_number(float const&);

template
void print_number(double const&);
