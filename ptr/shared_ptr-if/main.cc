#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() = default;
    ~MyClass() {
        std::cout << "~MyClass()" << std::endl;
    }
};

int main(int argc, char const * argv[]) {
    std::shared_ptr<MyClass> myvar;

    if ( ! myvar )
        std::cout << "shared_ptr is empty!" << std::endl;
    // shared_ptr is empty!

    myvar = std::make_shared<MyClass>();

    if ( myvar )
        std::cout << "shared_ptr is not empty!" << std::endl;
    // shared_ptr is not empty!

    myvar.reset();
    // ~MyClass()

    if ( ! myvar )
        std::cout << "shared_ptr is empty!" << std::endl;
    // shared_ptr is empty!

    std::cout << "end." << std::endl;
    // end.

    return 0;
}
