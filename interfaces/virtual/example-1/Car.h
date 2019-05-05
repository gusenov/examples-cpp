#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "IVehicle.h"

struct Car : IVehicle {
  virtual void StartEngine() override {
    std::cout << "code to start the engine of the car...\n";
  }

  // Необязательно определять этот деструктор:
  virtual ~Car() {
    std::cout << "~Car()\n";
  }
};

#endif
