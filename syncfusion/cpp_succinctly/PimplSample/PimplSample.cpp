#include <iostream>
#include <ostream>

#include "Sandwich.h"
#include "../pchar.h"

using namespace std;

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  Sandwich s;
  s.AddIngredient(L"Turkey");
  s.AddIngredient(L"Cheddar");
  s.AddIngredient(L"Lettuce");
  s.AddIngredient(L"Tomato");
  s.AddIngredient(L"Mayo");
  s.RemoveIngredient(L"Cheddar");
  s.SetBreadType(L"a Roll");

  wcout << s.GetSandwich() << endl;
  // A Turkey, Lettuce, Tomato, Mayo on a Roll.

  return 0;
}
