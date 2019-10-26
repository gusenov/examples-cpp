#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, const char **argv) {
    std::string a;
    char *c = new char[5];
    c[0] = 'A';
    c[1] = 'b';
    c[2] = 'b';
    c[3] = 'a';
    c[4] = 's';

    const char *cc = c;
    a = cc;

    delete[] c;

    std::cout << a << std::endl;  // Abbas

    return EXIT_SUCCESS;
}
