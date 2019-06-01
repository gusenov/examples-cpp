#include <iostream>
#include <ostream>
#include <memory>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <algorithm>
#include <cstdlib>
#include "InvalidArgumentException.h"
#include "../pchar.h"

using namespace CppForCsExceptions;
using namespace std;

class ThrowClass {
  public:
    ThrowClass(void) : m_shouldThrow(false) {
      wcout << L"Constructing ThrowClass." << endl;
    }

    explicit ThrowClass(bool shouldThrow) : m_shouldThrow(shouldThrow) {
      wcout << L"Constructing ThrowClass. shouldThrow = "
            << (shouldThrow ? L"true." : L"false.") << endl;
      if (shouldThrow) {
        throw InvalidArgumentException<const char*>(
          "ThrowClass",
          "ThrowClass(bool shouldThrow)",
          "shouldThrow",
          "true"
        );
      }
    }

    ~ThrowClass(void) { wcout << L"Destroying ThrowClass." << endl; }

    const wchar_t* GetShouldThrow(void) const {
      return (m_shouldThrow ? L"True" : L"False");
    }

  private:
    bool m_shouldThrow;
};

class RegularClass {
  public:
    RegularClass(void) { wcout << L"Constructing RegularClass." << endl; }
    ~RegularClass(void) { wcout << L"Destroying RegularClass." << endl; }
};

class ContainStuffClass {
  public:
    ContainStuffClass(void) : m_regularClass(new RegularClass()),
                              m_throwClass(new ThrowClass()) {
      wcout << L"Constructing ContainStuffClass." << endl;
    }

    ContainStuffClass(const ContainStuffClass& other) :
      m_regularClass(new RegularClass(*other.m_regularClass)),
      m_throwClass(other.m_throwClass) {
        wcout << L"Copy constructing ContainStuffClass." << endl;
    }

    ~ContainStuffClass(void) {
      wcout << L"Destroying ContainStuffClass." << endl;
    }

    const wchar_t* GetString(void) const { return L"I'm a ContainStuffClass."; }

  private:
    unique_ptr<RegularClass> m_regularClass;
    shared_ptr<ThrowClass> m_throwClass;
};

void TerminateHandler(void) {
  wcout << L"Terminating due to unhandled exception." << endl;

  // Если вызвать abort (из <cstdlib>), то программа завершится аномально.
  // Если ничего не вызывать для того чтобы выйти из этого метода, то программа
  // также завершится аномально.
  abort();

  // Можно вызвать exit(0) (также из <cstdlib>), тогда программа выйдет так
  // как будто ничего плохого не произошло. Это плохая практика потому что
  // кое-что плохое произошло. Но тем не менее это возможно, бросить
  // необрабатываемое исключение и всё же выйти таким образом, чтобы это
  // не интерпретировалось как сбой. Если программа внезапно завершается, без
  // сбоя, то возможно в ней есть что-то подобное.
  // exit(0);
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {

  // Установка кастомного обработчика для std::terminate. Этот обработчик
  // сработает, если запустить программу из командной строки. Отладчик
  // Visual Studio перехватит необработанное исключение и предоставит средства
  // для отладки.
  set_terminate(&TerminateHandler);

  try {
    ContainStuffClass cSC;
    // ВЫВОД:
    // Constructing RegularClass.
    // Constructing ThrowClass.
    // Constructing ContainStuffClass.

    wcout << cSC.GetString() << endl;
    // ВЫВОД:
    // I'm a ContainStuffClass.

    ThrowClass tC(false);
    // ВЫВОД:
    // Constructing ThrowClass. shouldThrow = false.
    wcout << L"tC should throw? " << tC.GetShouldThrow() << endl;
    // ВЫВОД:
    // tC should throw? False

    tC = ThrowClass(true);
    // ВЫВОД:
    // Constructing ThrowClass. shouldThrow = true.

    // Destroying ThrowClass.
    // Destroying ContainStuffClass.
    // Destroying ThrowClass.
    // Destroying RegularClass.

    wcout << L"tC should throw? " << tC.GetShouldThrow() << endl;
  }

  // Одним из недостатков использования шаблонов для исключений является то,
  // что нужнен catch-обработчик для каждой возможной специализации. Если
  // только нет базового класса от которого они все унаследованы. И он в
  // данном случае есть. Чтобы избежать отлова других std::invalid_argument
  // исключений, мы создали абстрактный класс InvalidArgumentExceptionBase
  // который единственно служит как базовый класс для всех специализаций
  // InvalidArgumentException<T>. Теперь мы можем отлавливать их все
  // (если нужно) без необходимости писать catch-обработчик для каждого по
  // отдельности. Однако при необходимости можно написать обработчик для
  // каждой отдельной специализации.
  catch (InvalidArgumentExceptionBase& e) {
    wcout << L"Caught '" << typeid(e).name() << L"'." << endl
          << L"Message: " << e.what() << endl;
    // ВЫВОД:
    // Caught 'N18CppForCsExceptions24InvalidArgumentExceptionIPKcEE'.
    // Message: ThrowClass::ThrowClass(bool shouldThrow) -
    // parameter 'shouldThrow' had invalid value 'true'.
  }

  // Отлов исключений унаследованных от std::exception, для которых у нас нет
  // специализированного обработчика. Так как непонятно, что это, то нужно
  // поймать это, занести в журнал и перебросить.
  catch (std::exception& e) {
    wcout << L"Caught '" << typeid(e).name() << L"'." << endl
          << L"Message: " << e.what() << endl;

    // Простая инструкция trow означает переброс.
    throw;
  }
  // Этот catch отлавливает всё, независимо от типа. Также как и с отловом
  // System.Exception в C#, этот отлов нужен только для того чтобы перебросить
  // исключение.
  catch (...) {
    wcout << L"Caught unknown exception type." << endl;
    throw;
  }

  // Эта строка приветет к запуску кастомного обработчика терминации:
  wcout << L"tC should throw? " << ThrowClass(true).GetShouldThrow() << endl;
  // ВЫВОД:
  // tC should throw? Constructing ThrowClass. shouldThrow = true.
  // Terminating due to unhandled exception.
  // Аварийный останов (стек памяти сброшен на диск)

  return 0;
}
