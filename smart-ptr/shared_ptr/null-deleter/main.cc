#include <iostream>
#include <memory>
#include <cstdlib>

class MyType {
public:
    MyType() {
        std::cout << "MyType()" << std::endl;
    }
    ~MyType() {
        std::cout << "~MyType()" << std::endl;
    }
};

void null_deleter(MyType *)
{}

void nasty_function(std::shared_ptr<MyType> ptr)
{}

void test1() {
    MyType *t = new MyType;
    nasty_function(std::shared_ptr<MyType>(t, [](MyType*){}));
}
// MyType()

void test2() {
    MyType *t = new MyType;
    nasty_function(std::shared_ptr<MyType>(t, &null_deleter));
}
// MyType()

int main(int argc, char* argv[]) {
    test2();
    return EXIT_SUCCESS;
}
