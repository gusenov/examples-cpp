#include "MyClass.h"

int MyClass::GetInt() const {
    return *pi_;
}

void MyClass::SetInt(int i) {
    *pi_ = i;
}

int* MyClass::GetIntPtr() const {
    return pi_;
}

void MyClass::SetIntPtr(int* pi) {
    pi_ = pi;
}
