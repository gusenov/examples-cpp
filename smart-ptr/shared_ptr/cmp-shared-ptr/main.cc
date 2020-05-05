#include <memory>
#include <iostream>

struct Rectangle {
    int width;
    int height;
    int x;
    int y;
};

int main(int argc, char const * argv[]) {
    auto rect1 = std::make_shared<Rectangle>();
    auto rect2 = rect1;
    assert(rect1 == rect2);  // TRUE

    auto rect3 = std::shared_ptr<Rectangle>(rect2.get(), [](auto){});
    assert(rect1 == rect3);  // TRUE
    assert(rect2 == rect3);  // TRUE

    auto rect4 = std::make_shared<Rectangle>();
    assert(rect1 != rect4);  // TRUE
    assert(rect2 != rect4);  // TRUE
    assert(rect3 != rect4);  // TRUE

    return 0;
}
