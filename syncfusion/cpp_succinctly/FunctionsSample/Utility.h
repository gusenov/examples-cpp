#pragma once

namespace Utility {
  // Декларация и дефиниция двух перегруженных inline-функций:
  inline bool IsEven(int value)       { return (value % 2) == 0; }
  inline bool IsEven(long long value) { return (value % 2) == 0; }

  // Любые функции дефинированные в заголовочном файле должны быть
  // задекларированы как inline; иначе будут ошибки линкера связанные с
  // множеством дефиниций.

  // Декларация двух перегруженных функций:
  void PrintIsEvenResult(int value);
  void PrintIsEvenResult(long long value);

  void PrintBool(bool value);
}
