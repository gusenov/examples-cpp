#include <list>
#include <utility>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    
    std::list<std::string> lsStr1 { "Hello", "World" };
    std::list<std::string> lsStr2 { "Hello", "World" };
    std::list<std::string> lsStr3 { "World", "Hello" };
    
    assert(lsStr1 == lsStr2);  // TRUE
    assert(lsStr2 != lsStr3);  // TRUE
    
    std::pair<std::string, std::string> pairStr1 { "Hello", "World" };
    std::pair<std::string, std::string> pairStr2 { "Hello", "World" };
    std::pair<std::string, std::string> pairStr3 { "World", "Hello" };

    assert(pairStr1 == pairStr2);  // TRUE
    assert(pairStr2 != pairStr3);  // TRUE

    std::list<std::pair<std::string, std::string>> lsPairStr1 {
        { "Hello", "World" },
        { "World", "Hello" },
    };

    std::list<std::pair<std::string, std::string>> lsPairStr2 {
        { "Hello", "World" },
        { "World", "Hello" },
    };

    std::list<std::pair<std::string, std::string>> lsPairStr3 {
        { "World", "Hello" },
        { "Hello", "World" },
    };

    assert(lsPairStr1 == lsPairStr2);  // TRUE
    assert(lsPairStr2 != lsPairStr3);  // TRUE

    return EXIT_SUCCESS;
}