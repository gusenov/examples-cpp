#include <iostream>
#include <unordered_map>

using namespace std;

class A {
public:
    A() { std::cout << "Constructor " << this << std::endl; }
    A(const A& other) { std::cout << "Copy Constructor " << this << std::endl; }
    ~A() { std::cout << "Destructor " << this <<std::endl; }
};

void test1() {
    unordered_map<string, A*> umap;

    A *a = new A();

    umap.insert(std::pair<std::string, A*>("hello", a));
    // umap.clear();
    // Что с clear(), что без - delete для указателей не делается.

    std::cout << "Ending" << std::endl;
    // При выходе из области видимости и разрушении umap delete для указателей
    // также не вызывается.
}
// Constructor 0x7f8dd0c00620
// Ending

void test2() {
    unordered_map<string, A> umap;
    A a;
    umap.insert(std::pair<std::string, A>("hello", a));
    std::cout << "Ending" << std::endl;
}
// Constructor 0x7ffee20b6b00
// Copy Constructor 0x7ffee20b6ae8
// Copy Constructor 0x7fddd44029c8
// Destructor 0x7ffee20b6ae8
// Ending
// Destructor 0x7ffee20b6b00
// Destructor 0x7fddd44029c8

void test3() {
    unordered_map<string, A> umap;
    A a;
    umap.insert(std::pair<std::string, A>("hello", a));
    umap.clear();
    std::cout << "Ending" << std::endl;
}
// Constructor 0x7ffee3ff6b00
// Copy Constructor 0x7ffee3ff6ae8
// Copy Constructor 0x7fae18c029c8
// Destructor 0x7ffee3ff6ae8
// Destructor 0x7fae18c029c8
// Ending
// Destructor 0x7ffee3ff6b00

int main() {
    // test1();
    // test2();
    // test3();
}
