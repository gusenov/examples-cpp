#include <memory>
#include <iostream>
#include <ostream>
#include "../pchar.h"

using namespace std;

struct TwoInts {
  TwoInts(void) : A(), B() {}
  TwoInts(int a, int b) : A(a), B(b) {}
  int A;
  int B;
};

wostream& operator<<(wostream& stream, TwoInts* v) {
  stream << v->A << L" " << v->B;
  return stream;
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  // Неправильный способ: приводит к двойному освобождению:
  /*
  try {
    TwoInts* p_i = new TwoInts(10, 20);

    auto sp1 = shared_ptr<TwoInts>(p_i);
    auto sp2 = shared_ptr<TwoInts>(p_i);
    p_i = nullptr;

    wcout << L"sp1 count is " << sp1.use_count() << L"." << endl
          << L"sp2 count is " << sp2.use_count() << L"." << endl;
  } catch(exception& e) {
    wcout << L"There was an exception." << endl;
    wcout << e.what() << endl << endl;
  } catch(...) {
    wcout << L"There was an exception due to a double free "
          << L"because we tried freeing p_i twice!" << endl;
  }
  */

  // Правильный способ создавать shared_ptr-ы:
  {
    auto sp1 = shared_ptr<TwoInts>(new TwoInts(10, 20));
    auto sp2 = shared_ptr<TwoInts>(sp1);

    wcout << L"sp1 count is " << sp1.use_count() << L"." << endl
          << L"sp2 count is " << sp2.use_count() << L"." << endl;
    // sp1 count is 2.
    // sp2 count is 2.

    wcout << L"sp1 value is " << sp1 << L"." << endl
          << L"sp2 value is " << sp2 << L"." << endl;
    // sp1 value is 10 20.
    // sp2 value is 10 20.
  }

  // Еще один правильный способ. Функция std::make_shared берет тип в качестве
  // своего шаблонного аргумента и аргумент(ы) для параметров конструктора
  // и автоматически конструирует объект. Это более эффективно по памяти потому
  // что при создании объекта счетчик ссылок может быть сохранен в то же время,
  // что и объект на который указывает shared_ptr.
  {
    auto sp1 = make_shared<TwoInts>(10, 20);
    auto sp2 = shared_ptr<TwoInts>(sp1);

    wcout << L"sp1 count is " << sp1.use_count() << L"." << endl
          << L"sp2 count is " << sp2.use_count() << L"." << endl;
    // sp1 count is 2.
    // sp2 count is 2.

    wcout << L"sp1 value is " << sp1 << L"." << endl
          << L"sp2 value is " << sp2 << L"." << endl;
    // sp1 value is 10 20.
    // sp2 value is 10 20.
  }

  return 0;
}
