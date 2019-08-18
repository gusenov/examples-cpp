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
void FPrintAsBits(T val, FILE *f, LineEnd end = LineEnd::New) {
    static T one = 1;
    for (short i = sizeof(T) * 8 - 1; 0 <= i;) {
        fprintf(f, "%c", (val & (one << i)) ? '1' : '0');
        --i;
        if (0 == (i + 1) % 8)
            fprintf(f, " ");
    }
    switch (end) {
        case LineEnd::New:
            fprintf(f, "\r\n");
            break;
        case LineEnd::Space:
            fprintf(f, " ");
            break;
        default:
            break;
    }
}

#endif /* UTILS_H */
