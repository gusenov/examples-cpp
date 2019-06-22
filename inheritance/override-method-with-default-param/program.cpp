// Задача:
// Перекрыть метод SetValue(int) класса A
// методом SetValue(int, bool = false).

#include <iostream>

class A {
    int _value;
public:
    virtual void SetValue(int value) {
        _value = value;
    }

    void PrintValue() {
        std::cout << _value << std::endl;
    }
};

class B : public virtual A {
public:
    // virtual void SetValue(int value, bool isPrint = true) override {}
    // error: 'SetValue' marked 'override' but does not override any member functions

    // virtual void SetValue(int value) override {
    //     A::SetValue(value);
    // }
    // void SetValue(int value, bool isPrint = true) {
    //     A::SetValue(value);
    //     if (isPrint) PrintValue();
    // }
    // error: call to member function 'SetValue' is ambiguous

    // virtual void SetValue(int value, bool isPrint = true) {
    //     SetValue(value);
    //     if (isPrint) PrintValue();
    // }
    // Segmentation fault

    virtual void SetValue(int value, bool isPrint = true) {
        A::SetValue(value);
        if (isPrint) PrintValue();
    }
    // warning: 'B::SetValue' hides overloaded virtual function [-Woverloaded-virtual]

    // Неоднозначности не будет потому что C++ сначала будет искать подходящую
    // сигнатуру среди методов класса B. При условии, что вызов делается
    // по указателю на B. Если же вызов будет делаться по указателю на A, то
    // C++ просто не найдет этот метод и будет жаловаться на избыточные
    // аргументы:
    // A *b = new B();
    // b->SetValue(1000);
    // b->SetValue(2000, false);
    // error: too many arguments to function call, expected single argument 'value', have 2 arguments
};

int main(int argc, char **argv) {
    B *b = new B();
    b->SetValue(1000);
    b->SetValue(2000, false);
    b->PrintValue();
    delete b;
    return 0;
}
