#include "Utility.h"
#include "../pchar.h"

using namespace Utility;

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  int i1 = 3;
  int i2 = 4;

  long long ll1 = 6;
  long long ll2 = 7;

  bool b1 = IsEven(i1);

  PrintBool(b1);           // The value isfalse.

  PrintIsEvenResult(i1);   // The number 3 is not even.
  PrintIsEvenResult(i2);   // The number 4 is even.
  PrintIsEvenResult(ll1);  // The number 6 is even.
  PrintIsEvenResult(ll2);  // The number 7 is not even.

  return 0;
}
