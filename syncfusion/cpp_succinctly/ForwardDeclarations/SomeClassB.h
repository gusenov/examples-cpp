#pragma once

// #include "SomeClassA.h"  // class
// #include "Flavor.h"      // scoped enum (enum class)
// #include "Toppings.h"    // un-scoped enum

// Forward-декларации вместо include-инструкций:

class SomeClassA;     // class
// Компилятор подготовит тип для линковки.

// Таким образом мы сейчас сократили количество строк кода (на тысячи и тысячи)
// которые должны компилироваться в любоом файле исходного кода, который
// подключает SomeClassB.h, но не подключает SomeClassA.h или Windows.h.
// Если файл SomeClassB.h подключается в несколько десятков файлов, то
// сокращение будет на десятки или сотни тысяч строк кода!

enum class Flavor;    // scoped enum (enum class)
// Компилятор зарезервирует пространство для int.
// По умолчанию для enum class нижележащий тип это int.

enum Toppings : int;  // un-scoped enum
// Компилятор зарезервирует пространство для int.

// Если дефиниции этих типов в  SomeClassA.h, Flavor.h и Toppings.h не
// соответствуют forward-декларациям, тогда будут ошибки компиляции.
// Если нужно чтобы экземпляр SomeClassA был переменной-членом SomeClassB, или
// нужно передать один из аргументов напрямую, а не через ссылку или указатель,
// то тогда нужно подключать SomeClassA. Компилятор должен зарезервировать
// пространство для SomeClassA и ему нужна полная дефиниция SomeClassA что
// определить размер SomeClassA в памяти.

// Чтобы скомпилировать эту дефиницию класса компилятору нужно знать только
// тип SomeClassA и нижележащие под Flavor и Toppings типы:
class SomeClassB {
  public:
    SomeClassB(void);
    ~SomeClassB(void);

    // Указатель на SomeClassA в GetValueFromSomeClassA:
    int GetValueFromSomeClassA(const SomeClassA* value);

    // Ссылки на SomeClassA в CompareTwoSomeClassAs:
    bool CompareTwoSomeClassAs(const SomeClassA& first, const SomeClassA& second);

    // Различные использования Flavor и Toppings:
    void ChooseFlavor(Flavor flavor);
    void AddTopping(Toppings topping);
    void RemoveTopping(Toppings topping);

  private:
    Toppings m_toppings;
    Flavor m_flavor;
    // Другие члены данных и функции-члены...
};
