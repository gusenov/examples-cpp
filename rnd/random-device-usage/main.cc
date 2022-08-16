#include <random>

struct Random
{
    Random()
        : device()
        , engine(device())
    {}

    std::random_device device;
    std::default_random_engine engine;
};

void test1()
{
    Random r[100000];
    // libc++abi: terminating with uncaught exception of type std::__1::system_error: random_device failed to open /dev/urandom: Too many open files
}

int main()
{
    test1();
    return EXIT_SUCCESS;
}