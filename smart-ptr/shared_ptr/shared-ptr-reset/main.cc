#include <memory>
#include <iostream>
#include <cstdlib>

struct A {
    virtual ~A() = default;

    virtual void whoami() const = 0;
};

class B : public A {
public:
    B() = default;
    ~B() override {
        std::cout << "~B()" << std::endl;
    }

    void whoami() const override {
        std::cout << "B" << std::endl;
    }

private:
};


void test1() {  // BAD!
    std::shared_ptr<A> a = std::make_shared<B>();
    auto ptr = a.get();
    a.reset(ptr);
    std::cout << "end;" << std::endl;
}
// ~B()
// end;
// ~B()
// a.out(52021,0x118a985c0) malloc: *** error for object 0x7faf67c00658: pointer being freed was not allocated
// a.out(52021,0x118a985c0) malloc: *** set a breakpoint in malloc_error_break to debug
// ./run.sh: line 7: 52021 Abort trap: 6           "$EXE_FILE"


void test2() {  // BAD!
    std::shared_ptr<A> a = std::make_shared<B>();
    auto ptr = a.get();
    a = std::shared_ptr<A>(ptr);
    std::cout << "end;" << std::endl;
}
// ~B()
// end;
// ~B()
// a.out(52031,0x11488c5c0) malloc: *** error for object 0x7fb9bd500018: pointer being freed was not allocated
// a.out(52031,0x11488c5c0) malloc: *** set a breakpoint in malloc_error_break to debug
// ./run.sh: line 7: 52031 Abort trap: 6           "$EXE_FILE"


void test3() {
    std::shared_ptr<A> a = std::make_shared<B>();
    auto b = std::dynamic_pointer_cast<B>(a);
    a = b;
    std::cout << "end;" << std::endl;
}
// end;
// ~B()


int main(int argc, char const * argv[]) {
    // test1();
    // test2();
    test3();

    return EXIT_SUCCESS;
}
