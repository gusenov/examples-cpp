#include <iostream>
#include <ostream>
#include <string>
#include "../pchar.h"

struct Color
{
  float ARGB[4];

  void A(float value) { ARGB[0] = value; }
  float A(void) const { return ARGB[0];  }

  void R(float value) { ARGB[1] = value; }
  float R(void) const { return ARGB[1];  }

  void G(float value) { ARGB[2] = value; }
  float G(void) const { return ARGB[2];  }

  void B(float value) { ARGB[3] = value; }
  float B(void) const { return ARGB[3];  }
};

// Это stand-alone функция служит бинарным оператором,
// когда слева от оператора << стоит wostream,
// а справа экземпляр Color.
std::wostream& operator<<(std::wostream& stream, const Color& c)
{
  stream << L"ARGB:{ "
         << c.A() << L"f, "
         << c.R() << L"f, "
         << c.G() << L"f, "
         << c.B() << L"f }";
  return stream;
}

int _pmain(int /*argc*/, _pchar* /*argv*/[])
{
  std::wcout << L"Please input an integer and then press Enter: ";
  int a;

  std::wcin >> a;
  // Если ввести некорректное значение для integer, то std::wcin
  // сразу же закончит своё выполнение не вернув никаких данных
  // и продолжит такое поведеление в дальнейшем пока не будет разрешена ошибка.

  std::wcout << L"You entered '" << a << L"'." << std::endl;

  std::wcout << std::endl <<
    L"Please enter a noun (one word, no spaces) " <<
    L"and then press Enter: ";

  std::wstring noun;

  // wcin разбивает ввод по пробелам, поэтому если ввести пробел или
  // tab, то первое слово запишется в переменную noun, а второе будет ждать
  // во входном буфере.
  std::wcin >> noun;

  std::wcerr << L"The " << noun << L" is on fire! Oh no!" << std::endl;

  Color c = { { 100.0f/255.0f, 149.0f/255.0f, 237.0f/255.0f, 1.0f } };

  // Здесь используется кастомный оператор перегруженный выше.
  std::wcout << std::endl << L"Cornflower Blue is " << c << L"." << std::endl;

  return 0;
}
