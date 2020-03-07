#include <iostream>
#include <unordered_set>
#include <unordered_map>

void test1() {
    std::unordered_map<unsigned short int, std::unordered_set<std::string>> m;
    unsigned short int k = 18;
    if (m.find(k) == m.end()) {
        auto &s = m[k];
        s.insert("A");
    }
    for (auto str : m[18]) {
        std::cout << str << std::endl;
    }
    // A
}

void test2() {
    std::unordered_map<unsigned short int, std::unordered_set<std::string>> m;
    unsigned short int k = 5;
    assert(m.find(k) == m.end());  // TRUE
    for (auto str : m[k]) {
        std::cout << str << std::endl;
    }
    assert(m.find(k) != m.end());  // TRUE
}

int main(int argc, char const * argv[]) {
    //test1();
    test2();
    return 0;
}
