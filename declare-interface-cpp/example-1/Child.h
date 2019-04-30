#include "IDemo.h"
#include "Parent.h"

#include <iostream>

class Child : public Parent, public IDemo
{
  public:

    // Здесь virtual писать не обязательно т.к. в базовом классе декларация
    // уже сделана, но это хорошая практика соблюдать консистентность.
    virtual void OverrideMe()
    {
      std::cout << "Do stuff." << std::endl;
    }

    // В C++11 можно указать ключевое слово override чтобы можно было на этапе
    // компиляции проверять типы аргументов и возвращаемых значений:
    // virtual void OverrideMe() override;

};
