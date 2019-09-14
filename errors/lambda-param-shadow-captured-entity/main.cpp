#include <iostream>

int main(int argc, const char * argv[]) {
    int i = 1000;

    auto foo = [i](int i) {
        std::cout << i << std::endl;  // 2000
        // lambda parameter перекрывает explicitly captured entity!
        // error: a lambda parameter cannot shadow an explicitly captured entity
    };

    foo(2000);

    return 0;
}
