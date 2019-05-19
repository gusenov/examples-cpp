// Этот пример содержит некоторые плохие практики написания кода для того чтобы
// проиллюстрировать инициализацию. В частности нарушен порядок инициализаторов
// в дефинициях конструкторов в некоторых местах. Всегда нужно убеждаться, что
// порядок инициализации базовых классов и параметров соответствует тому
// порядку в котором инициализация фактические будет осуществляться в режиме
// исполнения программы. Это поможет избежать багов и сделает код легче для
// отладки.

#include <iostream>
#include <ostream>
#include "../pchar.h"

using namespace std;

// Две вспомогательные функции для вывода сообщений, чтобы понимать порядок
// в котором случаются вещи:

int CallingMsg(const wchar_t* cls) {
	wcout << L"Calling " << cls << L" constructor." << endl;
	return 0;
}

int InitializingIntMsg(int value, const wchar_t* mvarName) {
	wcout << L"Initializing " << mvarName << L"." << endl;
	return value;
}

// Каждый далее идующий класс имеет int конструктор, но только Y и Z используют
// это int значение. A, B, C и D даже не указывают имя для int параметра в
// конструкторе:

class A {
  public:
    // Конструктор по умолчанию:
    A(void) : m_value(InitializingIntMsg(5, L"DEFAULT m_value")) {
      wcout << L"DEFAULT Constructing A. m_value is '" << m_value << L"'."
        << endl;
    }

    // Параметризованный конструктор:
    explicit A(int) : m_value(InitializingIntMsg(20, L"m_value")) {
      wcout << L"Constructing A. m_value is '" << m_value << L"'." << endl;
    }

    virtual ~A(void) { wcout << L"Destroying A." << endl; }

  private:
    int m_value;
};

// Остальные классы имеют только параметризованный конструктор:

class B : virtual public A {
  public:
    explicit B(int) : A(CallingMsg(L"A")),
                      // Переменные-члены класса B инициализируются в том
                      // порядке в котором они задекларированы в классе, даже
                      // если в конструкторе указан другой порядок их
                      // инициализации:
                      m_b(InitializingIntMsg(2, L"m_b")),
                      m_a(InitializingIntMsg(5, L"m_a")) {
      wcout << L"Constructing B. m_a is '" << m_a
        << L"' and m_b is '" << m_b << L"'." << endl;
    }

    virtual ~B(void) { wcout << L"Destroying B." << endl; }

  private:
    int m_a;
    int m_b;
};

class C {
  public:
    explicit C(int) : m_c(InitializingIntMsg(0, L"m_c")) {
      wcout << L"Constructing C. m_c is '" << m_c << L"'." << endl;
    }

    virtual ~C(void) { wcout << L"Destroying C." << endl; }

  private:
    int m_c;
};

class D {
  public:
    explicit D(int) : m_d(InitializingIntMsg(3, L"m_d")) {
      wcout << L"Constructing D. m_d is '" << m_d << L"'." << endl;
    }

    virtual ~D(void) { wcout << L"Destroying D." << endl; }

  private:
    int m_d;
};

// Сначала инциализируется A потому что B унаследован от A.
// Потом инициализируются B и C потому что у них виртуальное наследование.
// И наконец инициализируется D.
class Y : virtual public B, public D, virtual public C {
  public:
                            // 1. Инициализировать базовый класс C:
    explicit Y(int value) : C(CallingMsg(L"C")),
                            // 2. Инициализировать переменную-член класса Y:
                            m_someInt(InitializingIntMsg(value, L"m_someInt")),
                            // 3. Инициализировать базовый класс D:
                            D(CallingMsg(L"D")),
                            // 4. Инициализировать базовый класс B:
                            B(CallingMsg(L"B")) {

      // Фактически же порядок будет следующим:
      // 1. Инициализировать базовый класс A через конструктор по умолчанию.
      //    B унаследован от A, и B является единственным источником
      //    наследования от A, поэтому B имеет приоритет над другими, а A имеет
      //    приоритет над B.
      // 2. Инициализировать базовый класс B.
      //    Наследование от B идёт раньше других классов.
      // 3. Инициализировать базовый класс C.
      // 4. Инициализировать базовый класс D.
      //    D не ициализируется сразу сразу после B потому что D наследуется
      //    напрямую, а C наследуется виртуально. Виртуальное наследование идёт
      //    в первую очередь.
      // 5. Инициализировать переменную-член m_someInt класса Y.

      wcout << L"Constructing Y. m_someInt is '" << m_someInt << L"'." << endl;
    }

    virtual ~Y(void) { wcout << L"Destroying Y." << endl; }

    int GetSomeInt(void) { return m_someInt; }

  private:
    int	m_someInt;
};

class Z : public D, virtual public B, public C {
  public:
    explicit Z(int value) : D(CallingMsg(L"D")),
                            A(CallingMsg(L"A")),
                            C(CallingMsg(L"C")),
                            m_someInt(InitializingIntMsg(value, L"m_someInt")),
                            B(CallingMsg(L"B")) {
      wcout << L"Constructing Z. m_someInt is '" <<
      m_someInt << L"'." << endl;
    }

    virtual ~Z(void) { wcout << L"Destroying Z." << endl; }

    int GetSomeInt(void) { return m_someInt; }

  private:
    int	m_someInt;
};

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  {
    // Создание объекта типа Y в его собственной области видимости:
    Y someY(CallingMsg(L"Y"));
    // Calling Y constructor.

    // Из-за того что базовые классы инициализирутся прежде производных и A
    // вступает в дело через виртуальное наследование, A инициализируется
    // конструктором по умолчанию прежде чем даже будет достигнут вызов его
    // инициализации в B. Когда же мы доберемся до конструктора B, то A
    // уже будет проинициализирован и поэтому его инициализация в конструкторе
    // B будет просто проигнорирована.

    // Initializing DEFAULT m_value.
    // DEFAULT Constructing A. m_value is '5'.

    // Calling B constructor.
    // Initializing m_a.
    // Initializing m_b.
    // Constructing B. m_a is '5' and m_b is '2'.

    // Calling C constructor.
    // Initializing m_c.
    // Constructing C. m_c is '0'.

    // Calling D constructor.
    // Initializing m_d.
    // Constructing D. m_d is '3'.

    // Initializing m_someInt.
    // Constructing Y. m_someInt is '0'.
    wcout << L"Y::GetSomeInt returns '" << someY.GetSomeInt() << L"'." << endl;
    // Y::GetSomeInt returns '0'.
  }
  // Destroying Y.
  // Destroying D.
  // Destroying C.
  // Destroying B.
  // Destroying A.

  wcout << endl << "Break between Y and Z." << endl << endl;
  // Break between Y and Z.

  {
    // Создание объекта типа Z в его собственной области видимости:
    Z someZ(CallingMsg(L"Z"));
    // Calling Z constructor.

    // Calling A constructor.
    // Initializing m_value.
    // Constructing A. m_value is '20'.

    // Calling B constructor.
    // Initializing m_a.
    // Initializing m_b.
    // Constructing B. m_a is '5' and m_b is '2'.

    // Calling D constructor.
    // Initializing m_d.
    // Constructing D. m_d is '3'.

    // Calling C constructor.
    // Initializing m_c.
    // Constructing C. m_c is '0'.

    // Initializing m_someInt.
    // Constructing Z. m_someInt is '0'.
    wcout << L"Z::GetSomeInt returns '" << someZ.GetSomeInt() << L"'." << endl;
    // Z::GetSomeInt returns '0'.
  }
  // Destroying Z.
  // Destroying C.
  // Destroying D.
  // Destroying B.
  // Destroying A.

  return 0;
}
