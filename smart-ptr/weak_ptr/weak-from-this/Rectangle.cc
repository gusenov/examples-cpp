#include <iostream>
#include "Rectangle.h"

std::weak_ptr<IShape> Rectangle::GetWeakPtr() {

    try {
        auto s = shared_from_this();
        assert(s);
    } catch(std::bad_weak_ptr& e) {
        // Если наследование от std::enable_shared_from_this не будет
        // публичным, то здесь будет исключение!

        std::cout << e.what() << std::endl;
    }

    std::weak_ptr<IShape> result = weak_from_this();
    return result;
}


std::shared_ptr<IShape> NewRectangle() {
    return std::shared_ptr<IShape>(new Rectangle());
}

IShape* NewRectangleR() {
    return new Rectangle();
}