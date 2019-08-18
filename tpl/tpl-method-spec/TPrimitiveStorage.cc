#include "TPrimitiveStorage.h"




char& TPrimitiveStorage::GetRefOfChar() {
    return char_;
}

template<>
char* IPrimitiveStorage::GetPointerOf<char>() {
   return &GetRefOfChar();
}




signed char& TPrimitiveStorage::GetRefOfSignedChar() {
    return signedChar_;
}

template<>
signed char* IPrimitiveStorage::GetPointerOf<signed char>() {
   return &GetRefOfSignedChar();
}




char signed& TPrimitiveStorage::GetRefOfCharSigned() {
    return charSigned_;
}

// template<>
// char signed* IPrimitiveStorage::GetPointerOf<char signed>() {
//    return &GetRefOfCharSigned();
// }




unsigned char& TPrimitiveStorage::GetRefOfUnsignedChar() {
    return unsignedChar_;
}

template<>
unsigned char* IPrimitiveStorage::GetPointerOf<unsigned char>() {
   return &GetRefOfUnsignedChar();
}
