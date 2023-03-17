#include <iostream>

// https://stackoverflow.com/a/20170989/12847278
template <class T>
constexpr
std::string_view
type_name()
{
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

class Clazz
{
public:
    void Foo() const
    {
        using T1 = decltype(this);
        std::cout << typeid(T1).name() << std::endl;  // PK5Clazz
        std::cout << type_name<T1>() << std::endl;  // const Clazz *

        using T2 = std::remove_const<T1>::type;
        std::cout << type_name<T2>() << std::endl;  // const Clazz *

        using T3 = std::remove_cv<T1>::type;
        std::cout << type_name<T3>() << std::endl;  // const Clazz *

        using T4 = std::remove_pointer<T1>::type;
        std::cout << type_name<T4>() << std::endl;  // const Clazz

        using T5 = std::remove_const<T4>::type;
        std::cout << type_name<T5>() << std::endl;  // Clazz

        using T6 = std::remove_cv<T4>::type;
        std::cout << type_name<T6>() << std::endl;  // Clazz

        using T7 = std::decay<T1>::type;
        std::cout << type_name<T7>() << std::endl;  // const Clazz *
    }
};

int main()
{
    Clazz c;
    c.Foo();
    return 0;
}
