#include <iostream>

int main(int argc, char* argv[]) {
  // std::cout << "a = " << a << std::endl;

  // ОШИБКА:
  // ./main.cpp: In function ‘int main(int, char**)’:
  // ./main.cpp:4:26: error: ‘a’ was not declared in this scope
  //    std::cout << "a = " << a << std::endl;
  
  return 0;
}
