#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP

template<typename T>
class MyClass {
public:
    MyClass();

    void SetValue(T t) {
        t_ = t;
    }

private:
    T t_;
};

#endif  // MY_CLASS_HPP
