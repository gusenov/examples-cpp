#ifndef TPrimitiveStorage_h
#define TPrimitiveStorage_h

#include "IPrimitiveStorage.h"


class TPrimitiveStorage : public virtual IPrimitiveStorage {
public:
    TPrimitiveStorage() = default;
    ~TPrimitiveStorage() override = default;

    char& GetRefOfChar() override;
    signed char& GetRefOfSignedChar() override;
    char signed& GetRefOfCharSigned() override;
    unsigned char& GetRefOfUnsignedChar() override;

private:
    char char_;
    signed char signedChar_;
    char signed charSigned_;

    unsigned char unsignedChar_;
    char unsigned charUnsigned_;

    short short_;
    short int shortInt_;
    int short intShort_;

    int int_;

    long long_;

    long int longInt_;
    int long intLong_;

    float float_;

    double double_;

    double long doubleLong_;
    long double longDouble_;
};

#endif /* TPrimitiveStorage_h */
