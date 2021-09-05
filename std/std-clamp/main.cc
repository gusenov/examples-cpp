#include <algorithm>
#include <iostream>

int main(int argc, char* argv[])
{
    int lo = 10;
    int hi = 30;
    
    std::cout << std::clamp(9, lo, hi) << std::endl;  // 10
    std::cout << std::clamp(10, lo, hi) << std::endl;  // 10
    std::cout << std::clamp(30, lo, hi) << std::endl;  // 30
    std::cout << std::clamp(31, lo, hi) << std::endl;  // 30

    return EXIT_SUCCESS;
}
