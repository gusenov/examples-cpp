#include <iostream>

struct IStringable
{
    virtual std::string ToString() const = 0;
};

template<class T>
class Welcome
    : public T
{
public:
    std::string ToString() const override
    {
        return m_str;
    }

private:
    std::string m_str = "Hello, World!";
};

int main()
{
    Welcome<IStringable> w;
    IStringable& s = w;
    std::cout << s.ToString() << std::endl;
    return 0;
}
