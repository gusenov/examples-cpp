#include <iostream>
#include <ostream>
#include <typeinfo>
#include "../pchar.h"

using namespace std;

class A {
  public:
    A(void) : m_value(0) {}
    virtual ~A(void) {}
    virtual int GetValue(void) { return m_value; }
    virtual void SetValue(int value) { m_value = value; }
  private:
    int m_value;
};

class B : virtual public A {
  public:
    B(void) : A() {}
    virtual ~B(void) {}
    virtual int GetValue(void) override { return A::GetValue(); }
    virtual void SetValue(int value) { A::SetValue(-value); }
};

class C {
  public:
    C(void) {}
    ~C(void) {}
};

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  A a1;
  B b1;
  C c1;

  A* p_a1 = &a1;
  B* p_b1 = &b1;

  // Неявное приведение типа объекта B к указателю на A:
  A* p_ab1 = &b1;
  A& r_ab1 = b1;

  // static_cast не может привести тип через виртуальное наследование:
  // B& b1Ref = static_cast<B&>(*p_ab1);
  // А dynamic_cast может:
  B& b1Ref = dynamic_cast<B&>(*p_ab1);

  try {
    B& b2Ref = dynamic_cast<B&>(*p_a1);
  } catch (bad_cast) {
    // Нельзя привести тип к производному классу, если этот экземпляр
    // фактически не принадлежит к производному классу или какому-нибудь
    // классу производному от него.
    wcout << L"You can't cast to a derived class if it isn't "
          << L"actually an instance of that derived class or of some "
          << L"class derived from it." << endl;
  }
  // ВЫВОД:
  // You can't cast to a derived class
  // if it isn't actually an instance of that derived class
  // or of some class derived from it.

  A& a1Ref = static_cast<A&>(*p_b1);

  A* a1Ptr = dynamic_cast<A*>(p_b1);

  A* dcBPtrToAPtr = dynamic_cast<A*>(p_b1);

  // Why oh why does it let you do this?
  B* dcAPtrToBPtr = dynamic_cast<B*>(p_a1);

  C* p_aPtrToCPtr = nullptr;
  // Это приведение типа вернёт null, поэтому если нужно исключение, то бросать
  // его надо самостоятельно:
  try {
    p_aPtrToCPtr = dynamic_cast<C*>(p_a1);
    if (p_aPtrToCPtr == nullptr) { throw bad_cast(); }
  } catch (std::bad_cast) {
    wcout << L"Bad cast!" << endl;
  }
  // ВЫВОД:
  // Bad cast!

  // Приведёт к runtime-исключению:
  try {
    C& r_aPtrToCPtr= dynamic_cast<C&>(a1Ref);
  } catch (std::bad_cast) {
    wcout << L"Bad cast!" << endl;
  }
  // ВЫВОД:
  // Bad cast!

  // Const cast для добавления const (это ОК):
  auto p_a2 = const_cast<const A*>(p_a1);
  // Недопустимо из-за константности:
  // p_a2->SetValue(20);

  // Const cast для удаления const (плохая идея):
  auto p_a3 = const_cast<A*>(p_a2);
  // Допустимо сейчас, т.к. мы удалили const:
  p_a3->SetValue(20);

  // Приведение типа в стиле C. Не следует так делать:
  A* cCast = (A*)p_b1;

  return 0;
}
