#ifndef IKNOWNNUMBER_H
#define IKNOWNNUMBER_H

#include "IGenerate.h"

class KnownNumber : virtual public IGenerate {

  virtual int Generate(void) override {
    return 10;
  }

  public:

    // Необязательно определять этот деструктор:
    ~KnownNumber() {
      std::cout << "~KnownNumber()\n";
    }

};

#endif
