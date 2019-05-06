#include "Derived.h"

// void func1(Base x) {}
// Это не скомпилируется потому что Base это не тип и не класс, а шаблон.
// error: variable or field ‘func’ declared void
//  Не может определить типа Base, считает что это unknown type.
// error: missing template arguments before ‘x’
// К томе же принимая экземпляр Base по значению происходит object slicing.
// Нужно передавать по ссылке или по указателю.

void func1(Base<Derived>& x) {
  x.implementation();
}

void func2(Derived x) {
  x.implementation();
}

template<class T>
void func3(T x) {
  x.implementation();
}

// Эта функция может быть вызвана с любым типом произведенным от Base.
// И она использует статический тип того, что ей передано в параметре
// чтобы решить какую функцию вызвать.
template <typename T>
void func4(Base<T>& x) {
  x.implementation();
}

int main(int argc, char* argv[]) {
  Derived d;

  std::cout << "№ 1\n";

  func1(d);
  // OUTPUT:
  // implementation()
  // Derived::implementation()

  std::cout << "№ 2\n";

  func2(d);
  // OUTPUT: Derived::implementation()

  std::cout << "№ 3\n";

  func3(d);
  // OUTPUT: Derived::implementation()

  std::cout << "№ 4\n";

  func4(d);
  // OUTPUT:
  // implementation()
  // Derived::implementation()

  std::cout << "№ 5\n";

  Derived::static_func();
  // OUTPUT:
  // Derived::static_sub_func()

  return 0;
}
