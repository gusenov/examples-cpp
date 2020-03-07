#include <iostream>

template<typename T>
T foo() {
    T result;
    return result;
}

template<>
int foo<int>() {
    int result = 1;
    return result;
}

template<>
float foo<float>() {
    float result = 4;
    return result;
}

int main() {
    std::cout << foo<int>() << std::endl;  // 1
    std::cout << foo<float>() << std::endl;  // 4
    return 0;
}
