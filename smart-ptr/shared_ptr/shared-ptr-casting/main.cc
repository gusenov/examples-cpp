#include <memory>
#include <iostream>
#include <cstdlib>

struct I {
    virtual ~I() = default;

    virtual void SayHello() const = 0;
};

class T : public I {
public:
    T() = default;
    ~T() = default;

    void SayHello() const override {
        std::cout << "Hello!" << std::endl;
    }

private:
};

struct J {
    virtual ~J() = default;

    virtual void SayGoodBye() const = 0;
};

void test1() {
    std::shared_ptr<I> i;
    std::shared_ptr<T> t = std::make_shared<T>();
    i = t;
    i->SayHello();
    // Hello!
}

void test2() {
    std::shared_ptr<J> j;
    std::shared_ptr<T> t = std::make_shared<T>();
    // j = t;  // error: no viable overloaded '='

    j = std::dynamic_pointer_cast<J>(t);
    assert(!j);  // TRUE
}

void test3() {
    std::shared_ptr<I> i1;
    std::shared_ptr<T> t1 = std::make_shared<T>();
    std::shared_ptr<T> t2;
    i1 = t1;
    // t2 = i1;  // error: no viable overloaded '='

    t2 = std::dynamic_pointer_cast<T>(i1);
    assert(t2);  // TRUE
}

void test4() {
    std::shared_ptr<I const> i;
    std::shared_ptr<T const> t = std::make_shared<T>();
    i = t;
    assert(i);  // TRUE
}

void test5() {
    std::shared_ptr<I const> i;
    std::shared_ptr<T> t = std::make_shared<T>();
    i = t;
    assert(i);  // TRUE
}

template<typename W> void foo(std::shared_ptr<W const> const &ptr) {}
template<typename W> void bar(std::shared_ptr<W const> ptr) {}
void test6() {
    std::shared_ptr<T> t = std::make_shared<T>();
    std::shared_ptr<T const> tc = t;

    // foo(t);
    // error: no matching function for call to 'foo'
    // note: candidate template ignored: cannot deduce a type for 'W' that would make 'const W' equal 'T'

    // bar(t);
    // error: no matching function for call to 'bar'
    // note: candidate template ignored: cannot deduce a type for 'W' that would make 'const W' equal 'T'

    foo(tc);
    bar(tc);

    std::shared_ptr<I const> i;
    i = t;
    foo(i);
    bar(i);
}

void test7() {
    std::shared_ptr<T const> tc;
    std::shared_ptr<T> t = std::make_shared<T>();
    tc = t;
    assert(tc);  // TRUE
}

int main(int argc, char const * argv[]) {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    // test7();

    return EXIT_SUCCESS;
}
