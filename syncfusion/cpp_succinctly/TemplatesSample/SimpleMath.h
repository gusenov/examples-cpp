#pragma once

template<class T>
class SimpleMath {
  public:
    SimpleMath(void) { }
    ~SimpleMath(void) { }
    T Add(T a, T b) { return a + b; }
    T Subtract(T a, T b) { return a - b; }
    T Multiply(T a, T b) { return a * b; }
    T Divide(T a, T b) { return a / b; }
};
