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


void test1() {
    std::weak_ptr<A> w;
    assert(w.expired());  // TRUE
    assert(!w.lock());  // TRUE
    {
        std::shared_ptr<A> s = std::make_shared<B>();
        w = s;
        assert(!w.expired());  // TRUE
        assert(w.lock());  // TRUE
    }
    assert(w.expired());  // TRUE
    assert(!w.lock());  // TRUE
}


void test2() {
    std::weak_ptr<A> w;
    assert(w.expired());  // TRUE
    auto s = w.lock();
    assert(!s);  // TRUE
    s = std::make_shared<B>();
    assert(s);  // TRUE
    assert(w.expired());  // TRUE
}


int main(int argc, char const * argv[]) {
    // test1();
    test2();

    return EXIT_SUCCESS;
}
