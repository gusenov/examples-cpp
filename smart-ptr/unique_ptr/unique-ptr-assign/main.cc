#include <iostream>
#include <memory>
#include <cstdlib>

static int cnt = 0;

class Class
{
public:
    Class() : m_cnt(++cnt)
    {
        std::clog << m_cnt << " Class()" << std::endl;
    }
    
    ~Class()
    {
        std::clog << m_cnt << " ~Class()" << std::endl;
    }
    
    int m_cnt;
};

int main(int argc, char const* argv[])
{
    std::unique_ptr ptr = std::make_unique<Class>();
    std::clog << "--" << std::endl;
    ptr = std::make_unique<Class>();
    std::clog << "--" << std::endl;
    ptr = std::make_unique<Class>();
    std::clog << "--" << std::endl;
    return EXIT_SUCCESS;
}

/*
1 Class()
--
2 Class()
1 ~Class()
--
3 Class()
2 ~Class()
--
3 ~Class()
*/