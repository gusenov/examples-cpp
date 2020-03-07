#include <iostream>

template<typename T>
struct Altitude {
    T height;
};

struct IFlyable {
    virtual void fly() = 0;

    // template<typename T>
    // virtual void gainAltitude(T height) {
    //     // gain height
    // }
    // error: 'virtual' cannot be specified on member function templates

    virtual void gainAltitude(Altitude<int> height) = 0;
};

class Airplane : public IFlyable {
public:
    void fly() override {
        std::cout << "Fly like an airplane" << std::endl;
    }

    void gainAltitude(Altitude<int> altitude) override {
        if (altitude.height > 100000)
            return;
        _height = altitude.height;
    }

private:
    int _height = 0;
};

class Bird : public IFlyable {
public:
    void fly() override {
        std::cout << "Fly like a bird" << std::endl;
    }

    void gainAltitude(Altitude<int> altitude) override {
        if (altitude.height > 100)
            return;
        _height = altitude.height;
    }

private:
    int _height = 0;
};

int main() {
    Airplane airplane;
    airplane.fly();
    airplane.gainAltitude( { 10000 } );

    Bird bird;
    bird.fly();
    bird.gainAltitude( { 10 } );

    return 0;
}
