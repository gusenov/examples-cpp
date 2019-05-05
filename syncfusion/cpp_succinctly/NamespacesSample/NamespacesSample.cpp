#include <iostream>
#include <ostream>
#include <string>
#include "../pchar.h"

// В C# директива using автоматически привносит в область видимости любые типы
// из этого пространства имен, которые есть в любых referenced assemblies.
// В C++ директива using привносит в область видимости типы из подключаемых
// заголовочных файлов, а не все типы из библиотек слинкованных с вашей
// программой или библиотекой.

using namespace std;

// Никогда не стоит включать директиву using в заголовочный файл.
// В таком случае вы не только импортируете типы и пространства имён из
// этого пространства имён в заголовочный файл, но вы также импортируете
// их в каждый исходный или заголовочный файл, который подключает этот
// заголовочный файл. Это приводит к проблемам загрязнения пространства имён.
// Директиву using namespace лучше использовать только в исходных файлах.

namespace Places {
  namespace Cities {
    struct City {
      City(const wchar_t* name) {
        Name = wstring(name);
      }
      wstring Name;
    };
  }
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  // Ключевое слово auto является эквивалентом ключевого слова var в C#:
  auto nyc = Places::Cities::City(L"New York City");

  wcout << L"City name is " << nyc.Name.c_str() << L"." << endl;
  return 0;
}