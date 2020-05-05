#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "IShape.h"

class Rectangle : public IShape,

                  public std::enable_shared_from_this<IShape>
                  // Наследование от std::enable_shared_from_this обязательно
                  // должно быть публичным!!!

{
public:
    Rectangle() = default;
    ~Rectangle() override = default;

    std::weak_ptr<IShape> GetWeakPtr() override;
};

#endif  // RECTANGLE_H_
