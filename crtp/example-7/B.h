#ifndef B_H
#define B_H

#include "A.h"
#include <type_traits>
#include <iostream>

template <typename T = void>
// По умолчанию T = void.
// Это разрешает объектам типа B<> быть самыми последними производными
// в иерархии и разрешает это:
// B<> b;
// b.foo();

class B : public A<B<T>> { // no inherinace if this is the topmost class

public:

  // Публичные конструкторы и деструкторы.

  // boilerplate code :-(
  void foo() const {
    foo_impl(std::is_same<T, void>{});
  }
  // B<T>::foo() ведет себя как non pure virtual метод в том смысле, что
  // если B<T> является самым последним производным классом (или точнее T = void)
  // то b.foo(); вызовет реализацию foo() по умолчанию, которая выведет B::foo().
  // Если T не void, то вызов перенаправится к производному классу.
  // Это совершается через tag dispatching.

private:

  void foo_impl(std::true_type) const {
    std::cout << "B::foo()\n";
  }

  // boilerplate code :-(
  void foo_impl(std::false_type) const {
    // Следующий тест нужен чтобы избежать бесконечного рекурсивного вызова.
    // Если производный класс T не переимплементирует foo(), тогда вызов
    // static_cast<const T*>(this)->foo(); разрезолвится в B::foo(), который
    // снова вызовет B::foo_impl(std::false_type). Более того этот тест может
    // быть разрезолвен на этапе компиляции и код будет либо if (true) либо
    // if (false), а оптимизатор может удалить оба теста (GCC с -O3).
    if (&B::foo == &T::foo)
      foo_impl(std::true_type{});
    else
      static_cast<const T*>(this)->foo();
  }

};

#endif
