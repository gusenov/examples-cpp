#include <iostream>
#include <cstdlib>

int main() {
  // Компилируется:
  std::cout << "Hello, World" << std::endl;
  
  // Компилируется:
  std :: cout << "Hello, World" << std :: endl;
  
  // Компилируется:
  std 
  :: 
  cout << "Hello, World" << 
  std 
  :: 
  endl;
  
  // НЕ КОМПИЛИРУЕТСЯ:
  //std : : cout << "Hello, World" << std :: endl;
  
// НЕ КОМПИЛИРУЕТСЯ:
/*
std :
: cout << "Hello, World" << std :: endl;
*/

  return EXIT_SUCCESS;
}

