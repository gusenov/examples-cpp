#include <iostream>
#include <ostream>
#include "../pchar.h"

using namespace std;

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {

  // Создание замкнутого лямбда-выражения (lambda expression closure):
  auto lm1 = []() {
    wcout << L"No capture, parameterless lambda." << endl;
  };
  // Вызов лямбды:
  lm1();

  // Создание лямбда-замыкания (lambda closure) с параметрами:
  auto lm2 = [](int a, int b) {
    wcout << a << L" + " << b << " = " << (a + b) << endl;
  };
  lm2(3,4);

  // Создание лямбда-замыкания (lambda closure) с указанием типа возвращаемого
  // значения:
  auto lm3 = [](int a, int b) -> int {
    wcout << a << L" % " << b << " = ";
    return a % b;
  };

  wcout << lm3(7, 5) << endl;

  int a = 5;
  int b = 6;

  // Захват копированием всех переменных, которые сейчас есть в области
  // видимости. Обратите внимание, что нам не нужно захватывать замыкание;
  // здесь мы просто делаем вызов анонимной лямбды написав () после закрывающей
  // скобки:
  [=]() {
    wcout << a << L" + " << b << " = " << (a + b) << endl;

    // Недопустимо модификация потому захват был сделан по значению и не было
    // указано, что с этой лямбда нужно обращаться как с mutable:
    // a = 10;
  }();

  [=]() mutable -> void {
    wcout << a << L" + " << b << " = " << (a + b) << endl;

    // Пометив лямбду как mutable можно модифицировать a. Но т.к. захват был
    // произведен по значению, то модификации не будут переданы (propagate)
    // наружу:
    a = 10;
  }();

  wcout << L"The value of a is " << a << L"." << endl;

  [&]() {
    wcout << a << L" + " << b << " = " << (a + b) << endl;

    // При захвате по ссылке нужно делать метку mutable, потому что это ссылка
    // и изменения будут переданы (propagate) наружу:
    a = 10;
  }();

  wcout << L"The value of a is " << a << L"." << endl;

  // Явное указание того, что a захыватывается по значению, а b по ссылке:
  [a,&b]() {
    b = 12;
    wcout << a << L" + " << b << " = " << (a + b) << endl;
  }();

  // Явное указание того, что b захватывается по ссылке, а всё остальное по
  // значению:
  [=,&b]() {
    b = 15;
    wcout << a << L" + " << b << " = " << (a + b) << endl;
  }();

  // Явное указание того, что a захватается по значению, а всё остальное по
  // ссылке:
  [&,a]() {
    b = 18;
    wcout << a << L" + " << b << " = " << (a + b) << endl;
  }();

  return 0;
}
