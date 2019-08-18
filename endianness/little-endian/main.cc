#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "utils.h"

int const W = 32;

//---------------------------------------------------------------------------

void DetermineEndianness() {
    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
    printf("\n");
}

void show_mem_rep(char *start, int n) {
    for (int i = 0; i < n; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void SeeMemReprOfMultibyteDataTypes(int i) {
    show_mem_rep((char *)&i, sizeof(i));
}

//---------------------------------------------------------------------------

template<typename T>
void ShowMemReprWithAddr(T val) {
    std::cout << "Входное значение = " << val << std::endl;
    std::cout << "Его бинарное представление = ";
    PrintAsBits(val);
    std::cout << "Его HEX представление = 0x" << std::hex << val << std::endl;
    std::cout << std::endl;

    std::cout << std::setw(W) << "byte val as int16_t dec"
              << std::setw(W) << "byte val as int16_t hex"
              << std::setw(W) << "addr of byte as hex"
              << std::setw(W) << "addr of byte as dec"
              << std::endl;

    unsigned char *start = reinterpret_cast<unsigned char *>(&val);
    size_t sz = sizeof(val);
    for (size_t idx = 0; idx < sz; ++idx) {

        int16_t byteForOutput = start[idx];
        // Здесь используется int16_t, а не int8_t потому что int8_t такой же
        // как и signed char, а char не воспринимается потоком как число.

        void const *ptr = static_cast<void const *>(start + idx);
        uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
        std::cout << std::setw(W) << std::dec << byteForOutput
                  << std::setw(W) << std::hex << byteForOutput
                  << std::setw(W) << ptr
                  << std::setw(W) << std::dec << addr
                  << std::endl;
    }
}

//---------------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    DetermineEndianness();
    SeeMemReprOfMultibyteDataTypes(0x01234567);

    // Little endian
    // 67 45 23 01

    // Big endian
    // 01 23 45 67


    // PrintSeparator();
    // ShowMemReprWithAddr(0x1234567);

    // Порядок от младшего к старшему (англ. little-endian — малым концом):
    /*
    Входное значение = 19088743
    Его бинарное представление = 0b  0000 0001  0010 0011  0100 0101  0110 0111
    Его HEX представление      = 0x     0    1     2    3     4    5     6    7

             byte val as int16_t dec         byte val as int16_t hex             addr of byte as hex             addr of byte as dec
                                 103                              67                  0x7ffee88e9afc                 140732800080636
                                  69                              45                  0x7ffee88e9afd                 140732800080637
                                  35                              23                  0x7ffee88e9afe                 140732800080638
                                   1                               1                  0x7ffee88e9aff                 140732800080639
    */
    int n = 103 * pow(256, 0)
          +  69 * pow(256, 1)
          +  35 * pow(256, 2)
          +   1 * pow(256, 3);
    assert(19088743 == n && 0x1234567 == n);


    // PrintSeparator();
    // ShowMemReprWithAddr(5445);

    // Порядок от младшего к старшему (англ. little-endian — малым концом):
    /*
    Входное значение = 5445
    Его бинарное представление = 00000000 00000000 00010101 01000101
    Его HEX представление = 0x1545

             byte val as int16_t dec         byte val as int16_t hex             addr of byte as hex             addr of byte as dec
                                  69                              45                  0x7ffee88e9afc                 140732800080636
                                  21                              15                  0x7ffee88e9afd                 140732800080637
                                   0                               0                  0x7ffee88e9afe                 140732800080638
                                   0                               0                  0x7ffee88e9aff                 140732800080639
    */


    PrintSeparator();
    ShowMemReprWithAddr(1234567);

    // Порядок от младшего к старшему (англ. little-endian — малым концом):
    /*
    Входное значение = 1234567
    Его бинарное представление = 0b  0000 0000  0001 0010  1101 0110  1000 0111
    Его HEX представление =      0x     0    0     1    2     d    6     8    7

             byte val as int16_t dec         byte val as int16_t hex             addr of byte as hex             addr of byte as dec
                                 135                              87                  0x7ffee099cacc                 140732666596044
                                 214                              d6                  0x7ffee099cacd                 140732666596045
                                  18                              12                  0x7ffee099cace                 140732666596046
                                   0                               0                  0x7ffee099cacf                 140732666596047
    */

    return 0;
}
