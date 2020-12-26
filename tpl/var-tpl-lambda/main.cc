#include <cstdlib>
#include <iostream>

class Exe {
public:
    Exe() = default;
    ~Exe() = default;
    
    void Exec(std::function<void()> const& fn) {
        fn();
    }
};

template<class T>
void Bar();

template<>
void Bar<int>()
{
    std::clog << "int" << std::endl;
}

template<>
void Bar<float>()
{
    std::clog << "float" << std::endl;
}

template<>
void Bar<bool>()
{
    std::clog << "bool" << std::endl;
}

template<class ...T>
void Foo(Exe& e)
{
    (
        e.Exec([]() {
            Bar<T>();
        })
        , ...
    );
}

int main(int argc, char const* argv[])
{
    Exe e;
    Foo<int, float, bool>(e);
    // int
    // float
    // bool

    return EXIT_SUCCESS;
}
