#include <iostream>
#include <string>

int main(int argc, char const * argv[]) {
    std::string str = "hello";
    char const *const kString = "hello";

    assert(str == kString);
    assert(kString == str);
    assert(str == "hello");
    assert(str != "world");
    assert("hello" == str);
    assert("world" != str);

    return 0;
}
