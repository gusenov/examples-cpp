#include <iostream>

using namespace std;

class A {
    int data;

public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }

    A(const A& a) { SetData(a.GetData()); cout << "A(A&)" << endl; }
    A& operator=(const A& other)  {
        cout << "A& operator=(const A&)" << endl;
        if (this == &other) return *this;
        SetData(other.GetData());
        return *this;
    }

    A(A&& other) noexcept  { cout << "A(A&&)" << endl; }
    A& operator=(A&& other) noexcept {
        cout << "A& operator=(const A&&) noexcept" << endl;
        if (this == &other) return *this;
        return *this;
    }

    void SetData(int val) { data = val; }
    int GetData() const { return data; }
};

class B {
public:
    A GetA() { return A(); }
    // Все что после return можно считать уже там.
    // Здесь не будет копирования результата.

    A GetA_() {
        A a;
        a.SetData(100500);
        cout << "|" << endl;
        return a;
    }
};

// The called function has access to the memory the return value will occupy,
// even though that memory is not "in scope" when the copy is being made,
// it's still available.
// (c) https://stackoverflow.com/a/665794

// Copy construtor was called only once on the returning object,
// when assigning the returned object to another outer scope object,
// assignment operator is called, not the copy constructor.
// (c) https://stackoverflow.com/questions/665781/copy-constructor-in-c-is-called-when-object-is-returned-from-a-function#comment20804168_665916

void test1() {
    B b;
    b.GetA();
    // A()
    // ~A()
    // Объект сразу уничтожается, т.к. ничему не назначен.

    cout << "end;" << endl;
    // end;
}

void test2() {
    B b;
    A a = b.GetA();
    // A()

    cout << "end;" << endl;
    // end;
    // ~A()
}

void test3() {
    B b;
    A a = b.GetA_();
    // A()
    // |
    cout << a.GetData() << endl;
    // 100500

    A a2;
    // A()
    a2 = a;
    // A& operator=(const A&)

    cout << "end;" << endl;
    // end;
    // ~A()
    // ~A()
}

int main() {
    cout << "test1:" << endl;
    test1();
    cout << endl;

    cout << "test2:" << endl;
    test2();
    cout << endl;

    cout << "test3:" << endl;
    test3();
    cout << endl;

    cout << "end." << endl;

    return 0;
}
