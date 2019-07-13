#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "sizeof(signed char) = " << sizeof(signed char) << std::endl;
    std::cout << "sizeof(short int) = " << sizeof(short int) << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(long int) = " << sizeof(long int) << std::endl;
    std::cout << "sizeof(long long int) = " << sizeof(long long int) << std::endl;
    std::cout << std::endl;

    std::cout << "sizeof(int8_t) = " << sizeof(int8_t) << std::endl;
    std::cout << "sizeof(int16_t) = " << sizeof(int16_t) << std::endl;
    std::cout << "sizeof(int32_t) = " << sizeof(int32_t) << std::endl;
    std::cout << "sizeof(int64_t) = " << sizeof(int64_t) << std::endl;
    std::cout << "sizeof(uint8_t) = " << sizeof(uint8_t) << std::endl;
    std::cout << "sizeof(uint16_t) = " << sizeof(uint16_t) << std::endl;
    std::cout << "sizeof(uint32_t) = " << sizeof(uint32_t) << std::endl;
    std::cout << "sizeof(uint64_t) = " << sizeof(uint64_t) << std::endl;
    std::cout << std::endl;

    return 0;
}

/*
sizeof(signed char) = 1
sizeof(short int) = 2
sizeof(int) = 4
sizeof(long int) = 8
sizeof(long long int) = 8

sizeof(int8_t) = 1
sizeof(int16_t) = 2
sizeof(int32_t) = 4
sizeof(int64_t) = 8
sizeof(uint8_t) = 1
sizeof(uint16_t) = 2
sizeof(uint32_t) = 4
sizeof(uint64_t) = 8
*/
