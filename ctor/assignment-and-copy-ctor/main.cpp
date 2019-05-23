#include <iostream>

using namespace std;

typedef struct TestStruct /* tag_name */ {
    int id;

    ~TestStruct() {
        cout << "Деструктор ~TestStruct()" << endl;
    }

    TestStruct() : id(42) {
        cout << "TestStruct()" << endl;
    }

    TestStruct(const TestStruct& other) {
        cout << "Конструктор копирования" << endl;
    }

    // TestStruct(TestStruct&& other) {
    //     cout << "Конструктор перемещения" << endl;
    // }
    // copy assignment operator is implicitly deleted

} TestStruct /* struct_alias */;

class A {
    TestStruct _t;
public:
    ~A() {
        cout << "Деструктор ~A()" << endl;
    }

    TestStruct GetTestStruct() {
        cout << "TestStruct GetTestStruct()" << endl;
        return _t;
    }

    void SetTestStruct(TestStruct t) {
        cout << "void SetTestStruct(TestStruct t)" << endl;
        
        _t = t;

        // Присваивание не вызывает деструктор! Оно делает ровно то, что
        // говорит - вызывает оператор присваивания. Сгенерированный
        // компилятором оператор присваивания делает очевидное: присваивает все
        // члены старого объекта новому (используя операторы присваивания этих
        // объектов). Ничего больше. Это одна из причина появления правила 3-х.

    }
};

int main(int argc, char* argv[]) {
    A a;
    // ВЫВОД:
    // TestStruct()

    cout << "--" << endl;

    a.GetTestStruct();
    // ВЫВОД:
    // TestStruct GetTestStruct()
    // Конструктор копирования
    // Деструктор ~TestStruct()

    cout << "--" << endl;

    TestStruct t = a.GetTestStruct();
    // ВЫВОД:
    // TestStruct GetTestStruct()
    // Конструктор копирования

    cout << "--" << endl;

    a.SetTestStruct(t);
    // ВЫВОД:
    // Конструктор копирования
    // void SetTestStruct(TestStruct t)
    // Деструктор ~TestStruct()

    // Деструктор ~TestStruct() вызывается для скопированного аргумента t;

    cout << "--" << endl;

    // ВЫВОД:
    // Деструктор ~TestStruct()

    // Деструктор ~TestStruct() вызывается для локальной переменной t.

    // ВЫВОД:
    // Деструктор ~A()
    // Деструктор ~TestStruct()

    // Деструктор ~TestStruct() вызывается для переменной _t класса A.

    return 0;
}
