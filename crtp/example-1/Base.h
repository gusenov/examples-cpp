#ifndef BASE_H
#define BASE_H

#include <iostream>

template <class T>
struct Base {
  void implementation() {
    std::cout << "implementation()" << std::endl;

    static_cast<T*>(this)->implementation();
  }

  static void static_func() {
    T::static_sub_func();
  }
};

#endif
