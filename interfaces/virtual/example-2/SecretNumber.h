#ifndef ISECRETNUMBER_H
#define ISECRETNUMBER_H

#include "IGenerate.h"

class SecretNumber : virtual public IGenerate {

  virtual int Generate(void) override {
    return rand() % 100;  // in the range 0 to 99
  }

  public:

    // Необязательно определять этот деструктор:
    ~SecretNumber() {
      std::cout << "~SecretNumber()\n";
    }

};

#endif
