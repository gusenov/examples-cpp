#include <cstdlib>
#include <iostream>

class Value {
public:
    Value() {
        std::cout << "Value()" << std::endl;
    }
    
    ~Value() {
        std::cout << "~Value()" << std::endl;
    }
};

Value foo1() {
    return Value();
}

void test1() {
    auto const& v = foo1();
    std::cout << "end;" << std::endl;
}
// Value()
// end;
// ~Value()

int main(int argc, char const * argv[]) {
    test1();
    return EXIT_SUCCESS;
}
