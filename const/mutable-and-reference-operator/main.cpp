#include <iostream>
#include "type_name.h"

class Class
{
public:
    Class()
        : m_int(0)
        , m_float(0)
    {}

    auto GetInt() const
    {
        auto result = &m_int;
        using T = decltype(result);
        std::cout << type_name<T>() << std::endl;  // const int *
        return result;
    }

    auto GetFloat() const
    {
        auto result = &m_float;
        using T = decltype(result);
        std::cout << type_name<T>() << std::endl;  // float *
        return result;
    }

private:
    int m_int;
    mutable float m_float;
};

int main()
{
    Class c;
    auto i = c.GetInt();
    auto f = c.GetFloat();
    return 0;
}
