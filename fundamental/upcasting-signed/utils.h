#ifndef UTILS_H
#define  UTILS_H

#include <iostream>
#include <cstdio>


void Separator() {
    std::cout << "//---------------------------------------------------------------------------" << std::endl;
}

enum class LineEnd {
    Empty,
    New,
    Space
};

template<typename T>
void PrintAsBits(T val, LineEnd end = LineEnd::New) {
    static T one = 1;
    for (short i = sizeof(T) * 8 - 1; 0 <= i;) {
        printf("%c", (val & (one << i)) ? '1' : '0');
        --i;
        if (0 == (i + 1) % 8)
            printf(" ");
    }
    switch (end) {
        case LineEnd::New:
            printf("\r\n");
            break;
        case LineEnd::Space:
            printf(" ");
            break;
        default:
            break;
    }
}

#endif /* UTILS_H */
