#include <iostream>
#include <ostream>
#include <string>
#include <typeinfo>
#include "../pchar.h"

using namespace std;

class A {
  public:
    A(void) : SomeInt(0) {}
    virtual ~A(void) {}

    // Невиртуальная функция:
    const wchar_t* Id(void) const { return L"A"; }

    // Виртуальная функция:
    virtual const wchar_t* VirtId(void) const { return L"A"; }
    // A::VirtId однажды объявляенная виртуальной такой и останется для всех
    // производных классов в которых есть метод с такой же сигнатурой.

    int GetSomeInt(void) const { return SomeInt; }

    // Здесь и далее много функций-членов задекларировано как const путём
    // включения ключевого слова const после списка параметров в декларации.
    // Эта нотация является частью концепции const-correctness.
    // Нотация const-member-function означает, что функция-член не изменяет
    // членов данных в классе и не нужно беспокоиться о побочных эффектах
    // в многопоточном сценарии. Компилятор со своей стороны закрепляет эту
    // нотацию поэтому можно быть уверенным, что функция помеченная как const
    // действительно таковой и является.

    int SomeInt;
};

class B1 : virtual public A {
  public:
    B1(void) : A(), m_fValue(10.0f) {
      // Т.к. SomeInt не является членом B, то мы не можем инициализировать его
      // в списке инициализации перед открывающей фигурной скобкой, где мы
      // инициализируем базовый класс A и член данных m_fValue:
      SomeInt = 10;
    }
    virtual ~B1(void) {}
    const wchar_t* Id(void) const { return L"B1"; }

    virtual const wchar_t* VirtId(void) const override { return L"B1"; }
    // Всегда нужно тщательно прописывать virtual и override.

    const wchar_t* Conflict(void) const { return L"B1::Conflict()"; }
  private:
    float m_fValue;
};

class B2 : virtual public A {
  public:
    B2(void) : A() {}
    virtual ~B2(void) {}
    const wchar_t* Id(void) const { return L"B2"; }
    virtual const wchar_t* VirtId(void) const override { return L"B2"; }
    const wchar_t* Conflict(void) const { return L"B2::Conflict()"; }
};

class B3 : public A {
  public:
  	B3(void) : A() {}
  	virtual ~B3(void) {}
  	const wchar_t* Id(void) const { return L"B3"; }
  	virtual const wchar_t* VirtId(void) const override { return L"B3"; }
  	const wchar_t* Conflict(void) const { return L"B3::Conflict()"; }
};

class VirtualClass : virtual public B1,	virtual public B2 {

// VirtualClass имеет виртуальное наследование от B1 (который имеет
// виртуальное наследование от A) и от B2 (который также имеет виртуальное
// наследование от A). Т.к. вся цепочка наследований которая исходит от
// VirtualClass восходит к виртуальному A, то есть только одна копия данных A;
// поэтому проблемы ромба не возникает. Функция DemonstrateVirtualInheritance
// демонстрирует это.

// Даже с виртуальным наследованием в VirtualClass есть одна неоднозначность.
// B1::Conflict и B2::Conflict имеют одно и то же имя и те же самый параметры
// поэтому невозможно разрешить какая именно из них нужна не используя
// base-class-specifier синтаксис.

  public:
  	VirtualClass(void) : B1(), B2(), m_id(L"VirtualClass") {}
  	virtual ~VirtualClass(void) {}
  	const wchar_t* Id(void) const { return m_id.c_str(); }
  	virtual const wchar_t* VirtId(void) const override { return m_id.c_str(); }
  private:
  	wstring m_id;
};

// Примечание: если здесь сделать наследование от A перед наследованием от B1 и
// B3, то Visual C++ выдаст ошибку компиляции. Если сделать наследование от A
// после наследования от B1 и B3 то будет предупреждение при компиляции.
// Если наследоваться от класса не напрямую и напрямую, то это невозможно иметь
// его версию при прямом наследовании.
class NonVirtualClass : public B1, public B3 {

// NonVirtualClass имеет невиртуальное наследование от B1 (который имеет
// виртуальное наследование от A) и от B3 (который имеет невиртуальное
// наследование от A). Это приводит к проблеме ромба, с двумя копиями членов
// данных класса A становящихся членами данных класса NonVirtualClass.
// Функция DemonstrateNonVirtualInheritance показывает проблемы вытекающие из
// этого и также показывает синтаксис использующийся для разрешения того какая
// копия A нужна для использования.

  public:
    NonVirtualClass(void) : B1(), B3(), m_id(L"NonVirtualClass") {}
    virtual ~NonVirtualClass(void) {}
    const wchar_t* Id(void) const { return m_id.c_str(); }
    virtual const wchar_t* VirtId(void) const override { return m_id.c_str(); }

    // При работе с множественным наследованием именование очень важно, если
    // нужно избежать неодозначности. Декларация using позволяет разрешить
    // неодозначность определенным образом.

    // Если мы решаем, что хотим использовать B1::Conflict, то используем
    // using-декларацию:
    // using B1::Conflict;
    // В этом случае вызов NonVirtualClass::Conflict означает вызов
    // B1::Conflict.

    // Мы также можем использовать using-декларацию чтобы разрезолвить
    // неоднозначность между членами данных:
    // using B3::SomeInt;
    // В этом случае  NonVirtualClass::SomeInt означает B3::SomeInt, так что
    // инструкция nvC.SomeInt в DemonstrateNonVirtualInheritance будет
    // валидной (даже если IntelliSense говорит иначе).

  private:
    wstring m_id;
};

void DemonstrateNonVirtualInheritance(void) {
  NonVirtualClass nvC = NonVirtualClass();

  // SomeInt неоднозначен т.к. есть две копии A, одна ненапрямую от B1, а
  // другая ненапрямую от B3:
  // nvC.SomeInt = 20;

  // Но можно получить эти две копии SomeInt указывая нужный базовый класс:
  nvC.B1::SomeInt = 20;
  nvC.B3::SomeInt = 20;
  // Обратите внимание, что если NonVirtualClass также напрямую унаследован
  // от A, тогда эти две вышеприведенные инструкции будут невозможны.

  // Невозможно создать ссылку на A из-за неоднозначности:
  // A& nvCA = nvC;

  // Хотя можно создать ссылки на B1 и B3:
  B1& nvCB1 = nvC;
  B3& nvCB3 = nvC;

  // Мы можем создать ссылки на некоторые частные версии A:
  A& nvCAfromB1 = nvCB1;
  A& nvCAfromB3 = nvCB3;

  // Демонстрация того, что есть две копии данных из A:
  wcout << L"B1::SomeInt = " << nvCB1.SomeInt << endl <<  // B1::SomeInt = 20
    L"B3::SomeInt = " << nvCB3.SomeInt << endl << endl;   // B3::SomeInt = 20

  ++nvCB1.SomeInt;
  nvCB3.SomeInt += 20;

  wcout << L"B1::SomeInt = " << nvCB1.SomeInt << endl <<  // B1::SomeInt = 21
    L"B3::SomeInt = " << nvCB3.SomeInt << endl << endl;   // B3::SomeInt = 40

  wcout << typeid(nvC).name() << endl <<     // 15NonVirtualClass
    nvC.Id() << endl <<                      // NonVirtualClass
    nvC.VirtId() << endl <<                  // NonVirtualClass

    // Функция-член Conflict также неоднозначна т.к. B1 и B3 имеют у себя
    // функцию-член с именем Conflict и такой же сигнатурой.

    // Неоднозначность между B1 и B3:
    // nvC.Conflict() << endl <<

    // Разрешение неоднозначности:
    nvC.B3::Conflict() << endl <<            // B3::Conflict()
    nvC.B1::Conflict() << endl <<            // B1::Conflict()

    // GetSomeInt тоже неоднозначна:
    // nvC.GetSomeInt() << endl <<

    // Когда мы создаем ссылку базового класса на NonVirtualClass и вызываем
    // Id, мы получаем версию Id из базового класса.
    // Когда мы вызываем VirtId, мы получаем версию VirtId из класса
    // NonVirtualClass.

    endl << typeid(nvCB3).name() << endl <<  // 15NonVirtualClass
    nvCB3.Id() << endl <<                    // B3
    nvCB3.VirtId() << endl <<                // NonVirtualClass
    nvCB3.Conflict() << endl <<              // B3::Conflict()

    endl << typeid(nvCB1).name() << endl <<  // 15NonVirtualClass
    nvCB1.Id() << endl <<                    // B1
    nvCB1.VirtId() << endl <<                // NonVirtualClass
    nvCB1.GetSomeInt() << endl <<            // 21
    nvCB1.Conflict() << endl << endl;        // B1::Conflict()
}

void DemonstrateVirtualInheritance(void) {
	VirtualClass vC = VirtualClass();

	// Это работает т.к. VirtualClass имеет виртуальное наследование от B1,
  // который в свою очередь имеет виртуальное наследование от A, и VirtualClass
  // имеет виртуальное наследование от A, что означает, что все наследования от
  // A виртуальные и поэтому есть только одна копия A:
	vC.SomeInt = 20;

  // Мы можем создать ссылки напрямую на A, а также на B1 и B2:
	A& vCA = vC;
	B1& vCB1 = vC;
	B2& vCB2 = vC;

  // Есть только одна копия данных A:
	wcout << L"B1::SomeInt = " << vCB1.SomeInt << endl <<    // B1::SomeInt = 20
    L"B3::SomeInt = " << vCB2.SomeInt << endl << endl;     // B3::SomeInt = 20

	++vCB1.SomeInt;
	vCB2.SomeInt += 20;

	wcout << L"B1::SomeInt = " << vCB1.SomeInt << endl <<    // B1::SomeInt = 41
    L"B3::SomeInt = " << vCB2.SomeInt << endl << endl;     // B3::SomeInt = 41

	wcout << typeid(vC).name() << endl <<  // 12VirtualClass
    vC.Id() << endl <<                   // VirtualClass
    vC.VirtId() << endl <<               // VirtualClass
    vC.B2::Id() << endl <<               // B2
    vC.B2::VirtId() << endl <<           // B2
    vC.B1::Id() << endl <<               // B1
    vC.B1::VirtId() << endl <<           // B1
    vC.A::Id() << endl <<                // A
    vC.A::VirtId() << endl <<            // A

    // Функция-член Conflict всё ещё неодозначна B1 и B2 имеют функцию-член
    // с именем Conflict с одной и той же сигнатурой.
    // Здесь есть неоднозначность между B1 и B2:
    // vC.Conflict() << endl <<
    // Но мы можем разрешить эту неоднозначность:
    vC.B2::Conflict() << endl <<         // B2::Conflict()
    vC.B1::Conflict() << endl <<         // B1::Conflict()

    // Здесь нет неоднозначности из-за виртуального наследования:
    vC.GetSomeInt() << endl << endl <<   // 41

    typeid(vCB2).name() << endl <<       // 12VirtualClass
    vCB2.Id() << endl <<                 // B2
    vCB2.VirtId() << endl <<             // VirtualClass
    vCB2.Conflict() << endl << endl <<   // B2::Conflict()

    typeid(vCB1).name() << endl <<       // 12VirtualClass
    vCB1.Id() << endl <<                 // B1
    vCB1.VirtId() << endl <<             // VirtualClass
    vCB1.GetSomeInt() << endl <<         // 41
    vCB1.Conflict() << endl << endl <<   // B1::Conflict()

    typeid(vCA).name() << endl <<        // 12VirtualClass
    vCA.Id() << endl <<                  // A
    vCA.VirtId() << endl <<              // VirtualClass
    vCA.GetSomeInt() << endl << endl;    // 41
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
	DemonstrateNonVirtualInheritance();
	DemonstrateVirtualInheritance();
	return 0;
}
