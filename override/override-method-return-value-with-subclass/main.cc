#include <iostream>
#include <cassert>

struct IImmutable {
    virtual ~IImmutable() = default;
    virtual int GetValue() const = 0;
};

struct IMutable : IImmutable {
    virtual ~IMutable() override = default;
    virtual void SetValue(int value) = 0;
};

class Object: public IMutable {
public:
    Object() = default;
    virtual ~Object() override = default;

    int GetValue() const override {
        return _value;
    }

    void SetValue(int value) override {
        _value = value;
    }

private:
    int _value;
};

struct Interface {
    virtual ~Interface() = default;

    virtual IImmutable& Foo() = 0;
};

class Concrete : public Interface {
public:
    Concrete() = default;
    virtual ~Concrete() = default;
    IMutable& Foo() override {
        return o;
    }
private:
    Object o;
};

int main(int argc, char const * argv[]) {
    Concrete c;
    c.Foo().SetValue(1);
    std::cout << c.Foo().GetValue() << std::endl;  // 1

    Interface& i = c;
    // i.Foo().SetValue(2);  // error: no member named 'SetValue' in 'IImmutable'
    std::cout << i.Foo().GetValue() << std::endl;  // 1

    return 0;
}
