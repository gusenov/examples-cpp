#include <iostream>

class MyClass {
public:
    MyClass() {
    }

    void Foo() {
        std::cout << "void Foo()" << std::endl;
    }

    void Foo() const {
        std::cout << "void Foo() const" << std::endl;
    }
};

int main(int argc, char const * argv[]) {
    MyClass my;

    my.Foo();
    // void Foo()

    MyClass const &c_my = my;
    c_my.Foo();
    // void Foo() const

    return 0;
}
