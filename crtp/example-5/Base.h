#ifndef BASE_H
#define BASE_H

#include <iostream>

template<typename Derived>
struct Base
{
    void f() { std::cout << "Basic case" << std::endl; }

    // "Pure virtual" method
    void pure() { static_cast<Derived*>(this)->pure(); }

    // Метод чтобы избежать приведения типов при каждом вызове:
    Derived& derived() { return *static_cast<Derived*>(this); }
    const Derived& derived() const { return *static_cast<const Derived*>(this); }

};

#endif
