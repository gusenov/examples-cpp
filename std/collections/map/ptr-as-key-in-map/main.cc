#include <iostream>
#include <unordered_map>
#include <cassert>
#include <string>

class MyClass {
public:
    MyClass() = default;
    ~MyClass() = default;
};

int main(int argc, char const* argv[]) {
    auto a = new MyClass();
    auto b = new MyClass();
    
    std::unordered_map<MyClass*, std::string> m;
    m[a] = "a";
    m[b] = "b";
    
    std::cout << m[a] << std::endl;  // a
    std::cout << m[b] << std::endl;  // b
    
    return EXIT_SUCCESS;
}
