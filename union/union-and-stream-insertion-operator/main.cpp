#include <iostream>
#include <string>
#include <sstream>
#include "Vector3.h"

int main()
{

    std::string hello("Hello, World!");
    std::stringstream strstream;
    for (auto it = hello.begin(); it != hello.end(); ++it)
        strstream << *it;
    strstream << std::endl;
    std::cout << strstream.str();

    Vector3 v;
    std::cout << v << std::endl;

    float f = 2249.f;
    std::cout << f << std::endl;

    return 0;
}
