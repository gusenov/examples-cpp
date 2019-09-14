#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun ( int x = 0)
    {
        cout << "Base::fun(), x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun ( int x = 10 ) // NOTE THIS CHANGE
    {
        cout << "Derived::fun(), x = " << x << endl;
    }
};


int main()
{
    Derived d1;
    Base *bp = &d1;
    bp->fun();
    // Derived::fun(), x = 0
    return 0;
}
