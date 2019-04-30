#include "Tester.h"

#include <iostream>

void descriptor(IBase * obj) {
    obj->Describe();
}

int main(int argc, char** argv) {

  std::cout << std::endl << "Tester Testing..." << std::endl;  // Tester Testing...
  Tester * obj1 = new Tester("Declared with Tester");          // Tester constructor
  descriptor(obj1);                                            // I'm Tester [Declared with Tester]
  delete obj1;                                                 // Tester destructor

  std::cout << std::endl << "IBase Testing..." << std::endl;   // IBase Testing...
  IBase * obj2 = new Tester("Declared with IBase");            // Tester constructor
  descriptor(obj2);                                            // I'm Tester [Declared with IBase]
  delete obj2;                                                 // Tester destructor

  // this is a bad usage of the object since it is created with "new" but there are no "delete"
  std::cout << std::endl << "Tester not defined..." << std::endl;  // Tester not defined...
  descriptor(new Tester("Not defined"));
  // Tester constructor
  // I'm Tester [Not defined]


  return 0;
}
