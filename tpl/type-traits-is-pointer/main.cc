#include <cstdlib>
#include <iostream>
#include <type_traits>

class Class
{
public:
    Class() = default;
    ~Class() = default;
};

int main(int argc, char const* argv[])
{
    Class* ptr = nullptr;
    static_assert(std::is_pointer_v<decltype(ptr)>);  // TRUE
    
    auto& ref = ptr;
    // static_assert(std::is_pointer_v<decltype(ref)>);  // FALSE
    // error: static_assert failed due to requirement 'std::is_pointer_v<Class *&>'
    static_assert(!std::is_pointer_v<decltype(ref)>);  // TRUE
    static_assert(std::is_pointer_v<std::remove_reference<decltype(ref)>::type>);  // TRUE

    return EXIT_SUCCESS;
}
