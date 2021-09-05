#include <iostream>

#include "First.hpp"
#include "Second.hpp"
#include "Third.hpp"

int main() {
    First first;
    Second second = first.Forward();
    first = second.Back();
    Third third = second.Forward();

    return 0;
}
