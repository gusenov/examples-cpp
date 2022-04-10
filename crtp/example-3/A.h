#ifndef A_H
#define A_H

template<class Derived>
struct A {
  void foo() {
    static_cast<Derived*>(this)->foo();
    // Вызов из A идёт в самый последний производный класс и компилятор
    // идёт вверх по иерархии по не найдёт самый глубокий foo.
  }
};

#endif
