#include <memory>
#include <exception>
#include <iostream>
#include <tuple>

struct IShape;
using IShape_S = std::shared_ptr<IShape>;
using IShape_W = std::weak_ptr<IShape>;

struct IShape {
    virtual ~IShape() = default;
    virtual IShape_S shared() = 0;
    virtual IShape_W weak() = 0;
};

class Circle : public std::enable_shared_from_this<Circle>,
               public IShape
{
public:
    ~Circle() override = default;
    IShape_S shared() override {
        return shared_from_this();
    }
    IShape_W weak() override {
        return weak_from_this();
    }
};

enum class ShapeType {
    Circle
};

class ShapeFactory
{
public:
    static IShape* MakeShape(ShapeType shapeType) {
        switch (shapeType) {
        case ShapeType::Circle:
            return new Circle;
        default:
            return nullptr;
        }
        assert(false);
    }
};

int main(int argc, char const* argv[]) {
    {
        auto circle = IShape_S(ShapeFactory::MakeShape(ShapeType::Circle));  // !
        assert(circle->weak().expired());  // TRUE
        try {
            assert(circle->shared());
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;  // bad_weak_ptr
        }
    }

    {
        IShape_S circle = std::make_shared<Circle>();
        assert(!circle->weak().expired());  // TRUE
        assert(circle->shared());  // TRUE
    }
    
    std::pair my_pair1(123, "abc");
    auto my_pair2 = std::make_pair(123, "a");
        
    return 0;
}

// При создании shared_ptr через конструктор ему можно передать указатель на интерфейс.
// make_shared явно требует инстанцируемый класс.
