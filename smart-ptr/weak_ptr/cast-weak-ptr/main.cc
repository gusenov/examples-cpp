#include <iostream>
#include <cstdlib>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

class B : public A {
public:
    B() : A() {
        std::cout << "B()" << std::endl;
    }
    
    ~B() {
        std::cout << "~B()" << std::endl;
    }
};

using A_W = std::weak_ptr<A>;
using B_W = std::weak_ptr<B>;

int main(int argc, char *argv[]) {
    B_W b_w;
    assert(b_w.expired());  // TRUE
    
    auto b_s = b_w.lock();
    auto a_s = std::dynamic_pointer_cast<A>(b_s);
    assert(!a_s);  // TRUE
    
    b_s = std::make_shared<B>();
    // A()
    // B()
    b_w = b_s;
    assert(!b_w.expired());  // TRUE
    a_s = std::dynamic_pointer_cast<A>(b_s);
    assert(a_s);  // TRUE
    
    std::cout << "end." << std::endl;
    return EXIT_SUCCESS;
}
// end.
// ~B()
// ~A()
