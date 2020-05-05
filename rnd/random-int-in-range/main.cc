#include <cstdlib>
#include <random>
#include <limits>
#include <iostream>

void test1() {
    int first = 10, last = 40;

    std::cout << "first = " << first << std::endl;
    std::cout << "last = " << last << std::endl;

    std::uniform_int_distribution<int> distribution(first, last);

    // random_device does not need to be seeded because it requests random data
    // from your operating system (which will source from various locations,
    // like RDRAND for example).
    std::random_device rd;

    std::default_random_engine generator(rd());

    for (int i = 0; i < 16; ++i) {
        std::cout << distribution(generator) << "\n";
    }
}

int main() {
    test1();
    return EXIT_SUCCESS;
}
