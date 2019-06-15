#include <iostream>
#include <ostream>
#include <vector>
#include "SimpleMath.h"
#include "PeekLastItem.h"
#include "../pchar.h"

using namespace std;

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  SimpleMath<float> smf;

  wcout << "1.1F + 2.02F = " << smf.Add(1.1F, 2.02F) << "F." << endl;
  // 1.1F + 2.02F = 3.12F.

  vector<const wchar_t*> strs;
  strs.push_back(L"Hello");
  strs.push_back(L"World");

  wcout << L"Last word was '"
        << PeekLastItem<std::vector<const wchar_t*>,const wchar_t*>(strs)
        << L"'." << endl;
  // Last word was 'World'.

  return 0;
}
