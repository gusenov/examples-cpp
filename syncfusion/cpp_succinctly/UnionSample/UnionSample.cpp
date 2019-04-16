#include <iostream>
#include <ostream>
#include "../pchar.h"

enum class SomeValueDataType { Int = 0, Float = 1, Double = 2 };

struct SomeData {
  SomeValueDataType Type;
  union { int iData; float fData; double dData; } Value;

  SomeData(void) { SomeData(0); }

  SomeData(int i) {
    Type = SomeValueDataType::Int;
    Value.iData = i;
  }

  SomeData(float f) {
    Type = SomeValueDataType::Float;
    Value.fData = f;
  }

  SomeData(double d) {
    Type = SomeValueDataType::Double;
    Value.dData = d;
  }
};

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  SomeData data = SomeData(2.3F);
  std::wcout << L"Size of SomeData::Value is "
             << sizeof(data.Value) << L" bytes." << std::endl;
  // Size of SomeData::Value is 8 bytes.

  switch (data.Type) {
  case SomeValueDataType::Int:
  std::wcout << L"Int data is " << data.Value.iData << L"." << std::endl;
  break;

  case SomeValueDataType::Float:
  std::wcout << L"Float data is " << data.Value.fData << L"F." << std::endl;
  // Float data is 2.3F.
  break;

  case SomeValueDataType::Double:
  std::wcout << L"Double data is " << data.Value.dData << L"." << std::endl;
  break;

  default:
  std::wcout << L"Data type is unknown." << std::endl;
  break;
  }
  return 0;
}
