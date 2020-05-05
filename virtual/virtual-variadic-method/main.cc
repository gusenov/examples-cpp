#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <string>

struct IMovable {
    virtual ~IMovable() = default;
    virtual void Move(int speed, ...) = 0;
};

class Car: public IMovable {
public:
    Car() = default;
    ~Car() override = default;

    void Move(int speed, ...) override {
        std::cout << "Driving..." << std::endl;
        std::cout << "speed = " << speed << std::endl;

        va_list ap;
        va_start(ap, speed);
        char* const dest = va_arg(ap, char* const);
        std::cout << "destination = " << dest << std::endl;
        va_end(ap);
    }
};

class Helicopter : public IMovable {
public:
    Helicopter() = default;
    ~Helicopter() override = default;

    void Move(int speed, ...) override {
        std::cout << "Passing..." << std::endl;
        std::cout << "speed = " << speed << std::endl;

        va_list ap;
        va_start(ap, speed);
        int height = va_arg(ap, int);
        std::cout << "height = " << height << std::endl;
        va_end(ap);
    }
};

int main() {

    IMovable *car = new Car();
    car->Move(82, "A");
    delete car;

    std::cout << std::endl;

    IMovable *helicopter = new Helicopter();
    helicopter->Move(300, 4500);
    delete helicopter;

    return EXIT_SUCCESS;
}
