#ifndef ISHAPE_H_
#define ISHAPE_H_

#include <memory>

struct IShape {
    virtual ~IShape() = default;

    virtual std::weak_ptr<IShape> GetWeakPtr() = 0;
};

std::shared_ptr<IShape> NewRectangle();
IShape* NewRectangleR();

#endif  // ISHAPE_H_
