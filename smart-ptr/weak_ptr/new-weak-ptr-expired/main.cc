#include <memory>
#include <iostream>
#include <cstdlib>

std::weak_ptr<int> gw;

void f() {
    if (!gw.expired()) {
        std::cout << "gw is valid\n";
    } else {
        std::cout << "gw is expired\n";
    }
}

int main(int argc, char const * argv[]) {

    assert(gw.expired());  // TRUE

    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        assert(!gw.expired());  // TRUE

        f();
    }

    assert(gw.expired());  // TRUE

    f();

    return EXIT_SUCCESS;
}
