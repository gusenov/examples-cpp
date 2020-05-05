#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

void foo() {
    int a = 10;
    std::cout << "a=" << a << std::endl;
    // a=10

    int& b = a;
    std::cout << "b=" << b << std::endl;
    // b=10

    int &c = b;
    b = 20;
    std::cout << "c=" << c << std::endl;
    // c=20

    int &d = c;
    a = 30;
    std::cout << "d=" << d << std::endl;
    // d=30
}

struct Record {
    int i = 0;
};

int& bar(Record& rec) {
    return rec.i;
}

int main(int argc, char *argv[]) {
    int a = 1;
    int& b = a;

    Record rec;
    bar(rec) = b;

    std::cout << rec.i << std::endl;  // 1
    b = 2;
    std::cout << rec.i << std::endl;  // 1

    return 0;
}
