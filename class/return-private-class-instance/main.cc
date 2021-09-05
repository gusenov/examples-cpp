#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>

class External
{
    class Internal
    {
    public:
        Internal() = default;
        ~Internal() = default;
        
        void WhoAmI() const
        {
            std::cout << "Internal" << std::endl;
        }
    };
    
public:
    External() = default;
    ~External() = default;
    
    Internal GetInstance() const {
        return m_instance;
    }
    
private:
    Internal m_instance;
};

int main(int argc, char const* argv[])
{
    External xtal;
    auto inst = xtal.GetInstance();
    
    inst.WhoAmI();
    // Internal

    return EXIT_SUCCESS;
}
