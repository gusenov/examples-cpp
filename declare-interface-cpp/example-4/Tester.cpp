#include "Tester.h"

#include <iostream>

Tester::Tester(std::string name) {
  std::cout << "Tester constructor" << std::endl;
  this->privatename = name;
}

Tester::~Tester() {
  std::cout << "Tester destructor" << std::endl;

  // Если убрать virtual ~IBase() {}; из интерфейса, то Tester::~Tester()
  // никогда не будет вызываться.
  
}

void Tester::Describe() {
  std::cout << "I'm Tester [" << this->privatename << "]" << std::endl;
}
