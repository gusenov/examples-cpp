#ifndef B_H
#define B_H

#include "A.h"
#include <type_traits>

template <typename T = void>
class B : public A<B<T>> {

  void foo(...) {
    std::cout << "B::foo()\n";
  }

  // std::is_base_of возвращает true, если T==B.
  // Здесь используется своя версия is_base_of, которая возвращает false_type
  // когда два аргумента шаблона одинаковые:
  void foo( Type2Type< std::enable_if< is_base_of<T,B>::value == true, B>::type> ) {
    static_cast<const T*>(this)->foo( Type2Type<T> );
  }

};

#endif
