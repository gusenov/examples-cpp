#include <memory>
#include <iostream>
#include <string>
#include <array>
#include <charconv>
#include <sstream>
#include <iomanip>

void test1() {
    std::string s1 = "0.9147";
    float f1 = std::stod(s1);
    assert(f1 == 0.9147f);  // SUCCESS

    std::stringstream stream;
    stream << std::fixed << std::setprecision(4) << f1;
    std::string s2 = stream.str();
    assert(s1 == s2);

    float f2 = std::stod(s2);
    assert(f2 == f1);  // SUCCESS

    stream.str("");
    stream.clear();

    stream << std::fixed << std::setprecision(4) << f2;
    std::string s3 = stream.str();
    assert(s2 == s3);
}

void test2() {
    float f1 = 780.0;
    std::stringstream stream;
    stream << std::setprecision(2) << f1;
    std::string s1 = stream.str();
    assert(s1 == "780.000");
}

int main(int argc, char const * argv[]) {
    //test1();
    test2();
    return 0;
}
