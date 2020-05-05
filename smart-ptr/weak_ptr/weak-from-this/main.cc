#include <iostream>
#include <cstdlib>

#include "IShape.h"
#include "Rectangle.h"

void test1() {
    auto rect = std::make_shared<Rectangle>();
    auto w = rect->GetWeakPtr();
    assert(!w.expired());  // TRUE
}

void test2() {
    auto rect_s = std::make_shared<Rectangle>();
    auto rect_r = rect_s.get();
    auto w = rect_r->GetWeakPtr();
    assert(!w.expired());  // TRUE
}

void test3() {
    auto rect = NewRectangle();
    auto w = rect->GetWeakPtr();
    assert(!w.expired());  // TRUE
}

void test4() {
    auto rect = new Rectangle();
    auto w = rect->GetWeakPtr();
    // bad_weak_ptr
    assert(w.expired());  // TRUE
    delete rect;
}

void test5() {
    auto rect = new Rectangle();
    auto rect_s = std::shared_ptr<IShape>(rect);
    auto w = rect->GetWeakPtr();
    assert(!w.expired());  // TRUE
}

void test6() {
    auto rect = new Rectangle();
    std::shared_ptr<IShape> rect_s;
    rect_s.reset(rect);
    auto w = rect->GetWeakPtr();
    assert(!w.expired());  // TRUE
}

void test7() {
    auto rect = NewRectangleR();
    std::shared_ptr<IShape> rect_s;
    rect_s.reset(rect);
    auto w = rect->GetWeakPtr();
    // bad_weak_ptr
    assert(w.expired());  // TRUE
}

void test8() {
    auto rect = NewRectangleR();
    std::shared_ptr<IShape> rect_s(rect);
    auto w = rect->GetWeakPtr();
    // bad_weak_ptr
    assert(w.expired());  // TRUE
}

void test9() {
    IShape *rect = new Rectangle();
    std::shared_ptr<IShape> rect_s;
    rect_s.reset(rect);
    auto w = rect->GetWeakPtr();
    // bad_weak_ptr
    assert(w.expired());  // TRUE
}

int main(int argc, char const * argv[]) {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
    test9();

    return EXIT_SUCCESS;
}
