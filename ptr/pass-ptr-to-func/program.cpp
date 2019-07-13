#include <cassert>

class MyClass {
  int m_Data;
public:
  MyClass(int initVal) : m_Data(initVal) {}
  void SetData(int data) { m_Data = data; }
  int GetData() { return m_Data; }
};

// Передача по указателю:
void MyFunctionPtr(MyClass* arg) {
  arg->SetData(arg->GetData() * arg->GetData());
}

// Передача указателя по ссылке:
void MyFunctionPtrRef(MyClass*& arg) {
  arg->SetData(arg->GetData() * arg->GetData());
}

// Передача по ссылке:
void MyFunctionRef(MyClass& arg) {
  arg.SetData(arg.GetData() * arg.GetData());
}

int main(int argc, char* argv[]) {
  MyClass* my = new MyClass(2);

  MyFunctionPtr(my);
  assert(my->GetData() == 4);

  MyFunctionPtrRef(my);
  assert(my->GetData() == 16);

  MyFunctionRef(*my);
  assert(my->GetData() == 256);

  delete my;
  return 0;
}
