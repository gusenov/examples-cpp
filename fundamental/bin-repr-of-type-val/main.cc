#include <type_traits>
#include <cmath>
#include "cstring"
#include "utils.h"

#define MAKE_FILE_NAME(t) "output/"#t".txt"

template<typename T>
void OutBinReprOfTypeVal(char const *const filename) {
    FILE *f = fopen(filename, "w");

    unsigned char bitsCnt = sizeof(T) * 8;
    int min = 0, max = 0;

    if constexpr (std::is_unsigned_v<T>) {
        min = 0;
        max = pow(2, bitsCnt) - 1;
    } else if constexpr (std::is_signed_v<T>) {
        min = -pow(2, bitsCnt) / 2;
        max = pow(2, bitsCnt) / 2 - 1;
    }

    static char buffer[100];
    sprintf(buffer, "%d", min);
    size_t minLen = strlen(buffer);
    sprintf(buffer, "%d", max);
    size_t maxLen = strlen(buffer);
    size_t len = minLen > maxLen ? minLen : maxLen;
    sprintf(buffer, "%% %zu d\t", len);

    T i = min;
    while (true) {
        fprintf(f, buffer, i);
        FPrintAsBits(i, f);
        if (i == max)
            break;
        ++i;
    }

    fclose(f);
}

int main(int argc, const char * argv[]) {
    OutBinReprOfTypeVal<char>(MAKE_FILE_NAME(char));
    OutBinReprOfTypeVal<unsigned char>(MAKE_FILE_NAME(unsigned char));

    OutBinReprOfTypeVal<short>(MAKE_FILE_NAME(short));
    OutBinReprOfTypeVal<unsigned short>(MAKE_FILE_NAME(unsigned short));

    return 0;
}
