#include <iostream>
#include <ostream>
#include "../pchar.h"

// Глобальная переменная:
int g_x = 10;
// Есть общепринятое соглашение по которому глобальные переменные должны иметь
// префикс g_.

// Обе следующие функции находятся в глобальном пространстве имён.

int AddTwoNumbers(int a, int b) {
  return a + b;
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  int y = 20;

  std::wcout << L"The result of AddTwoNumbers(g_x, y) where g_x = "  << g_x
  << L" and y = " << y << L" is " << AddTwoNumbers(g_x, y) << L"." << std::endl;
  // The result of AddTwoNumbers(g_x, y) where g_x = 10 and y = 20 is 30.

  if (true == 1) { std::wcout << L"true == 1!" << std::endl; }
  // true == 1!

  return 0;
}
