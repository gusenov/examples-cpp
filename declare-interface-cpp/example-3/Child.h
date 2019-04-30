#include "IDemo.h"

#include <iostream>

class Child : public IDemo
{
  public:

    // Ключевое слово virtual не обязательно, но это хорошая идея
    // оставить его чтобы сделать код яснее, он служит индикатором того, что
    // этот метод может использоваться полиморфно и есть в базовом классе.
    // ПРИМЕЧАНИЕ: За исключением override в C++11.

    virtual void OverrideMe()
    {
      std::cout << "do stuff" << std::endl;
    }
};
