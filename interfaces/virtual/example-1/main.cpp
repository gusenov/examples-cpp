#include "IVehicle.h"
#include "Car.h"

int main(int argc, char* argv[]) {

  IVehicle *v = new Car();
  v->StartEngine();  // OUTPUT: code to start the engine of the car...
  delete v;  // OUTPUT: ~Car()

  Car *c = new Car();
  c->StartEngine();  // OUTPUT: code to start the engine of the car...
  delete c;  // OUTPUT: ~Car()

  return 0;
}
