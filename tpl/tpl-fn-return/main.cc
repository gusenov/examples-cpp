#include <iostream>

template<typename T>
T foo() {
    return 2 + 2;
}

int main() {
    std::cout << foo<int>() << std::endl;
    std::cout << foo<float>() << std::endl;
    return 0;
}
