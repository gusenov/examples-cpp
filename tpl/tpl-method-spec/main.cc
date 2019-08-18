#include <cstdio>
#include <cstdlib>
#include "TPrimitiveStorage.h"

int main(int argc, const char* argv[]) {
    IPrimitiveStorage* primitiveStorage = new TPrimitiveStorage();

    char* charPointer = primitiveStorage->GetPointerOf<char>();
    *charPointer = 'A';
    printf("char = '%c'\n", primitiveStorage->GetRefOfChar());

    unsigned char* unsignedCharPointer = primitiveStorage->GetPointerOf<unsigned char>();
    *unsignedCharPointer = 'B';
    printf("unsigned char = '%c'\n", primitiveStorage->GetRefOfUnsignedChar());

    delete primitiveStorage;
    return EXIT_SUCCESS;
}
