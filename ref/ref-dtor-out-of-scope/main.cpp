#include <iostream>

using namespace std;

class C {
public:
    ~C() { cout << "~C()" << endl; }
    void Hello() { cout << "Hello" << endl; }
};

class A {
    int b;
    C c;

public:
    int& GetB() { return b; }
    void SetB(int val) { b = val; }

    C& GetC() { return c; }
};

int main() {
    A a;
    a.SetB(10);
    cout << "A::b = " << a.GetB() << endl;
    a.GetB() = 20;
    cout << "A::b = " << a.GetB() << endl;

    {
        // C c = a.GetC();
        // При выходе из области видимости для "c" вызовется деструктор.

        C& c = a.GetC();
        c.Hello();
        // При выходе из области для ссылки деструктор не вызывается.
    }

    return 0;
}
