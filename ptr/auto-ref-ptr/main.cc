#include <iostream>

int main() {
    int a = 30;
    int *b = &a;
    auto &c = b;

    std::cout << "a = " << a << std::endl;
    // a = 30

    std::cout << "b = " << *b << std::endl;
    // b = 30

    std::cout << "c = " << *c << std::endl;
    // c = 30

    *c = 10;

    std::cout << "a = " << a << std::endl;
    // a = 10

    std::cout << "b = " << *b << std::endl;
    // b = 10

    std::cout << "c = " << *c << std::endl;
    // c = 10

    return 0;
}
