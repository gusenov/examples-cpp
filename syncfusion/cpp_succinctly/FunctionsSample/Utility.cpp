#include "Utility.h"
#include <iostream>
#include <ostream>

using namespace std;
using namespace Utility;

// Дефиниции stand-alone функций в пространствах имён:

void Utility::PrintIsEvenResult(int value) {
  wcout << L"The number " << value << L" is "
        << (IsEven(value) ? L"" : L"not ") << L"even." << endl;
}

void Utility::PrintIsEvenResult(long long value) {
  wcout << L"The number " << value << L" is "
        << (IsEven(value) ? L"" : L"not ") << L"even." << endl;
}

void Utility::PrintBool(bool value) {
  wcout << L"The value is" << (value ? L"true." : L"false.") << endl;
}

// Если использовать вложенные пространства имён, то нужно включать всю цепочку:
// void RootSpace::SubSpace::SubSubSpace::FunctionName(int param) {
// ...
// };
