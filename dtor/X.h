#ifndef X_H
#define X_H

#include <iostream>

class X {
  public:
    // virtual ~X() = 0 {};  // error: pure-specifier on function-definition
    // virtual ~X() {} = 0;  // error: expected unqualified-id before ‘=’ token
    virtual ~X() = 0;
};

#endif
