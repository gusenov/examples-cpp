#include <iostream>
#include <bitset>

enum States {
    State1 = 0,
    State2 = 1,
    State3 = 2,
    State4 = 3,
    State5 = 4,
    State6 = 5,
    State7 = 6,
    State8 = 7
};

void test1(std::bitset<8> flags = std::bitset<8>()) {  // 76543210
    std::cout << flags.to_string() << std::endl;       // 00000000
    flags.set(State1);
    flags.set(State7);                            // 76543210
    std::cout << flags.to_string() << std::endl;  // 01000001
    if (flags.test(State1) && flags.test(State7)) {
        std::cout << "State1 and State7" << std::endl;  // State1 and State7
    }
}

int main(int argc, char* argv[]) {
    test1();
    return 0;
}
