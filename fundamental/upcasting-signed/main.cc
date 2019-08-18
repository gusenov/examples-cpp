#include "utils.h"

int main(int argc, const char * argv[]) {

    // std::cout << sizeof(char) << std::endl;           // 1
    // std::cout << sizeof(short) << std::endl;          // 2
    // std::cout << sizeof(int) << std::endl;            // 4
    // std::cout << sizeof(float) << std::endl;          // 4
    // std::cout << sizeof(long) << std::endl;           // 8
    // std::cout << sizeof(unsigned long) << std::endl;  // 8
    // std::cout << sizeof(double) << std::endl;         // 8
    // std::cout << sizeof(long double) << std::endl;    // 16

    char char30 = 30;
    // PrintAsBits(char30);  // 00011110

    long long30 = char30;
    // PrintAsBits(long30);
    // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00011110

    char char_30 = -30;
    // PrintAsBits(char_30);  // 11100010

    long long_30 = char_30;
    // PrintAsBits(long_30);
    // 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11100010
    // std::cout << long_30 << std::endl;  // -30

    char char128 = 127;
    // PrintAsBits(char128);  // 01111111

    char char_128 = -128;
    // PrintAsBits(char_128);  // 10000000

    short short512 = 0b0000001000000000;
    // std::cout << short512 << std::endl;  // 512
    // PrintAsBits(short512);  // 00000010 00000000

    long long512 = short512;
    // PrintAsBits(long512);
    // 00000000 00000000 00000000 00000000 00000000 00000000 00000010 00000000

    short short_32768 = 0b1000000000000000;
    // std::cout << short_32768 << std::endl;  // -32768

    long long_32768 = short_32768;
    // PrintAsBits(long_32768);
    // 11111111 11111111 11111111 11111111 11111111 11111111 10000000 00000000

    short short_1 = 0b1111111111111111;
    // std::cout << short_1 << std::endl;  // -1

    long long_1 = short_1;
    // PrintAsBits(long_1);
    // 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111

    short short_150 = -150;
    // PrintAsBits(short_150);  // 11111111 01101010

    short short_277 = -277;
    // PrintAsBits(short_277);  // 11111110 11101011

    return 0;
}
