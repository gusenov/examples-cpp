#include <iostream>

int main(int argc, char* argv[]) 
{
    std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;
    std::cout << std::endl;

    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << "sizeof(signed char) = " << sizeof(signed char) << std::endl;
    std::cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << std::endl;
    std::cout << std::endl;


    std::cout << "sizeof(char16_t) = " << sizeof(char16_t) << std::endl;
    std::cout << "sizeof(char32_t) = " << sizeof(char32_t) << std::endl;
    std::cout << std::endl;

    std::cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << std::endl;
    // 'wchar_t' cannot be signed or unsigned!
    std::cout << std::endl;

    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
    std::cout << "sizeof(short int) = " << sizeof(short int) << std::endl;
    std::cout << "sizeof(signed short) = " << sizeof(signed short) << std::endl;
    std::cout << "sizeof(signed short int) = " << sizeof(signed short int) << std::endl;
    std::cout << "sizeof(unsigned short) = " << sizeof(unsigned short) << std::endl;
    std::cout << "sizeof(unsigned short int) = " << sizeof(unsigned short int) << std::endl;
    std::cout << std::endl;
    
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(signed int) = " << sizeof(signed int) << std::endl;
    std::cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << std::endl;
    std::cout << std::endl;
    
    std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
    std::cout << "sizeof(long int) = " << sizeof(long int) << std::endl;
    std::cout << "sizeof(signed long) = " << sizeof(signed long) << std::endl;
    std::cout << "sizeof(signed long int) = " << sizeof(signed long int) << std::endl;
    std::cout << "sizeof(unsigned long) = " << sizeof(unsigned long) << std::endl;
    std::cout << "sizeof(unsigned long int) = " << sizeof(unsigned long int) << std::endl;
    std::cout << std::endl;
    
    std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
    std::cout << "sizeof(long long int) = " << sizeof(long long int) << std::endl;
    std::cout << "sizeof(signed long long) = " << sizeof(signed long long) << std::endl;
    std::cout << "sizeof(signed long long int) = " << sizeof(signed long long int) << std::endl;
    std::cout << "sizeof(unsigned long long) = " << sizeof(unsigned long long) << std::endl;
    std::cout << "sizeof(unsigned long long int) = " << sizeof(unsigned long long int) << std::endl;
    std::cout << std::endl;

    std::cout << "sizeof(int8_t) = " << sizeof(int8_t) << std::endl;
    std::cout << "sizeof(uint8_t) = " << sizeof(uint8_t) << std::endl;
    std::cout << "sizeof(int16_t) = " << sizeof(int16_t) << std::endl;
    std::cout << "sizeof(uint16_t) = " << sizeof(uint16_t) << std::endl;
    std::cout << "sizeof(int32_t) = " << sizeof(int32_t) << std::endl;
    std::cout << "sizeof(uint32_t) = " << sizeof(uint32_t) << std::endl;
    std::cout << "sizeof(int64_t) = " << sizeof(int64_t) << std::endl;
    std::cout << "sizeof(uint64_t) = " << sizeof(uint64_t) << std::endl;
    std::cout << std::endl;


    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
    std::cout << "sizeof(long double) = " << sizeof(long double) << std::endl;
    std::cout << std::endl;

    return 0;
}

/*
MacBook Pro (15-inch, 2018)
2,2 GHz 6‑ядерный процессор Intel Core i7
16 ГБ 2400 MHz DDR4

sizeof(bool) = 1

sizeof(char) = 1
sizeof(signed char) = 1
sizeof(unsigned char) = 1

sizeof(char16_t) = 2
sizeof(char32_t) = 4

sizeof(wchar_t) = 4

sizeof(short) = 2
sizeof(short int) = 2
sizeof(signed short) = 2
sizeof(signed short int) = 2
sizeof(unsigned short) = 2
sizeof(unsigned short int) = 2

sizeof(int) = 4
sizeof(signed int) = 4
sizeof(unsigned int) = 4

sizeof(long) = 8
sizeof(long int) = 8
sizeof(signed long) = 8
sizeof(signed long int) = 8
sizeof(unsigned long) = 8
sizeof(unsigned long int) = 8

sizeof(long long) = 8
sizeof(long long int) = 8
sizeof(signed long long) = 8
sizeof(signed long long int) = 8
sizeof(unsigned long long) = 8
sizeof(unsigned long long int) = 8

sizeof(int8_t) = 1
sizeof(uint8_t) = 1
sizeof(int16_t) = 2
sizeof(uint16_t) = 2
sizeof(int32_t) = 4
sizeof(uint32_t) = 4
sizeof(int64_t) = 8
sizeof(uint64_t) = 8

sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 16
*/
