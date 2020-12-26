#include <cstdlib>
#include <iostream>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

static inline A* MakeA() {
    std::cout << "MakeA()" << std::endl;
    return new A();
}

template<typename Ctor>
void foo(Ctor ctor) {
    auto obj = ctor();
    delete obj;
}

template<class T, T* (*Ctor)() = nullptr>
void bar() {
    T *obj = nullptr;
    if (Ctor != nullptr)
        obj = Ctor();
    else
        obj = new T();
    assert(obj);
    delete obj;
}

void test1() {
    foo(&MakeA);
    // A()
    // ~A()
}

void test2() {
    bar<A, MakeA>();
    // MakeA()
    // A()
    // ~A()
}

void test3() {
    auto FactoryFn = []() { return new A(); };
    bar<A, FactoryFn>();
    // A()
    // ~A()
}

void test4() {
    bar<A>();
    // A()
    // ~A()
}

int main(int argc, char const * argv[]) {
    test4();
    return EXIT_SUCCESS;
}
