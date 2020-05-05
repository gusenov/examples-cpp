#include <iostream>
#include <cstdlib>

struct A {
    virtual ~A() = default;
    virtual void whoami() const = 0;
};

class B : public A {
public:
    B() {
    }

    ~B() override {
    }

    void whoami() const override {
        std::cout << "B" << std::endl;
    }
};

class C {
public:
    C() {
    }

    ~C() {
    }

    void whoami() const {
        std::cout << "C" << std::endl;
    }
};

enum class Type {
    A = 0,
    B = 1,
    C = 2,
};

struct Pointer {
    Type t;
    union {
        A *a;
        B *b;
        C *c;
    } addr;
};

int main(int argc, char *argv[]) {

    B b;
    C c;

    Pointer ptr;

    ptr.t = Type::A;
    ptr.addr.a = &b;
    ptr.addr.a->whoami();  // B

    ptr.t = Type::B;
    ptr.addr.b = &b;
    ptr.addr.b->whoami();  // B

    ptr.t = Type::C;
    ptr.addr.c = &c;
    ptr.addr.c->whoami();  // C

    return EXIT_SUCCESS;
}
