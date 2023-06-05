#include <iostream>

class Test1
{
public:
    Test1()
        : m_data(30)
    {
    }

    int GetData() const
    {
        return m_data;
    }

private:
    int m_data = 10;
};
// Test # 1
// 30

void test1()
{
    std::cout << "Test # 1" << std::endl;

    Test1 t1;
    std::cout << t1.GetData() << std::endl;
}

int main()
{
    test1();
    return 0;
}
