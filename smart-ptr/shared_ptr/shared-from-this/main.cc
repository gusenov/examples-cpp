#include <memory>
#include <iostream>
#include <cstdlib>

class Clazz: public std::enable_shared_from_this<Clazz> {
// Без public будет ошибка:
// libc++abi.dylib: terminating with uncaught exception of type std::__1::bad_weak_ptr: bad_weak_ptr

public:
    Clazz() {
        std::cout << "Clazz()" << std::endl;
    }

    ~Clazz() {
        std::cout << "~Clazz()" << std::endl;
    }

    std::shared_ptr<Clazz> shared() {
        return shared_from_this();
    }
};

void test1() {
    std::shared_ptr<Clazz> a;

    {
        std::shared_ptr<Clazz> b = std::make_shared<Clazz>();
        a = b->shared();
    }

    std::cout << "end;" << std::endl;
}
/*
Clazz()
end;
~Clazz()
end.
 */

void test2()
{
    std::shared_ptr<Clazz> a;

    {
        std::shared_ptr<Clazz> b = std::make_unique<Clazz>();
        a = b->shared();
    }

    std::cout << "end;" << std::endl;
}
/*
Clazz()
end;
~Clazz()
end.
*/

int main(int argc, char const * argv[])
{
    test2();

    std::cout << "end." << std::endl;
    return EXIT_SUCCESS;
}
