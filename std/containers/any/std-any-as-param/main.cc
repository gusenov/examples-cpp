#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <any>


void test1(std::any arg) {
    std::cout << std::any_cast<int>(arg) << std::endl;
}

int main(int argc, char const * argv[]) {
    test1(100);
    // 100

    return EXIT_SUCCESS;
}
