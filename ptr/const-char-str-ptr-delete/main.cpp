#include <cstdio>

const char* new_cstr() {
    char* const result = new char[6];
    result[0] = 'H';
    result[1] = 'E';
    result[2] = 'L';
    result[3] = 'L';
    result[4] = 'O';
    result[5] = '\0';
    return result;
}

int main(int argc, char* argv[]) {
    const char* const hello = new_cstr();
    printf("%s\n", hello);  // HELLO
    delete[] hello;  // допустимо.
    return 0;
}
