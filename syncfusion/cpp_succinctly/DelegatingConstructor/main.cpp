#include <iostream>
#include <ostream>

using namespace std;

class SomeClass {
  public:
    SomeClass(void) : SomeClass(10) {
      // Эти инструкции выполнятся после исполнения инструкций в конструкторе
      // SomeClass(int):
      wcout << "Running SomeClass::SomeClass(void)." << endl;
    }
    SomeClass(int value) : m_value(value) {
      // Эти инструкции выполнятся после инициализации m_value сверху:
      wcout << "Running SomeClass::SomeClass(int)." << endl;
    }
    int GetValue(void) { return m_value; }
  private:
    int m_value;
};

int main(int argc, char* argv[]) {
  SomeClass someC;
  // Running SomeClass::SomeClass(int).
  // Running SomeClass::SomeClass(void).
  wcout << L"SomeClass::GetValue() = " << someC.GetValue() << endl;
  // SomeClass::GetValue() = 10
  return 0;
}
