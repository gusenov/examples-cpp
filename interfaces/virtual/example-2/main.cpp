#include <iostream>
#include "IGenerate.h"
#include "KnownNumber.h"
#include "SecretNumber.h"

int main(int argc, char* argv[]) {

  IGenerate *num;

  num = new KnownNumber();
  std::cout << num->Generate() << std::endl;  // OUTPUT: 10
  delete num;  // OUTPUT: ~KnownNumber()

  num = new SecretNumber();
  std::cout << num->Generate() << std::endl;  // OUTPUT: 83
  delete num;  // OUTPUT: ~SecretNumber()

  return 0;
}
