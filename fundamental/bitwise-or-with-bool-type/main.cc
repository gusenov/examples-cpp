#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    
    bool result = false;
    
    result |= false;
    assert(!result);  // TRUE
    
    result |= true;
    assert(result);  // TRUE
    
    result |= false;
    assert(result);  // TRUE
    
    return EXIT_SUCCESS;
}
