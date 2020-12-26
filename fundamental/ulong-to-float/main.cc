#include <iostream>
#include <vector>
#include <cassert>
#include <climits>

int main(int argc, char const* argv[]) {
    
    // name: ULONG_MAX
    // expresses: Maximum value for an object of type unsigned long int
    // possible value: 4294967295 (2^32 - 1) or greater*
    // the actual value depends on the particular system and library implementation, 
    // but shall reflect the limits of these types in the target platform.
    // http://www.cplusplus.com/reference/climits/

    // std::cout << sizeof(ULONG_MAX) << std::endl;
    // 8
    
    // std::cout << "ULONG_MAX = " << ULONG_MAX << std::endl;
    // ULONG_MAX = 18446744073709551615
    
    float ulong_max_as_float = ULONG_MAX;
    // std::cout << std::fixed << ulong_max_as_float << std::endl;
    // 18446744073709551616.000000
    
    unsigned long ulong_max = ulong_max_as_float;
    // std::cout << ulong_max << std::endl;
    // 0
    
    // std::cout << sizeof(float) << std::endl;
    // 4
    
    // std::cout << sizeof(int) << std::endl;
    // 4

    // std::cout << sizeof(unsigned long) << std::endl;
    // 8
        
    return EXIT_SUCCESS;
}
