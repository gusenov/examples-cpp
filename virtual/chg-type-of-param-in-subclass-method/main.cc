#include <cstdlib>
#include <iostream>




struct J1 {
};

struct I1 {
    virtual ~I1() = default;
    
    virtual I1* Foo() = 0;
    virtual void Bar(J1*) = 0;
};




struct J2 : J1 {
};

struct I2 : I1 {
    ~I2() override = default;
    I2* Foo() override = 0;
};




struct J3 : J1 {
};

struct I3 : I1 {
    ~I3() override = default;
    I3* Foo() override = 0;
};




class C1 : I2 {
public:
    C1() = default;
    ~C1() = default;
    C1* Foo() override {
        return this;
    }
    
    // void Bar(J2*) override
    // {}
    // error: non-virtual member function marked 'override' hides virtual member function
    // note: hidden overloaded virtual function 'I1::Bar' declared here: type mismatch at 1st parameter ('J1 *' vs 'J2 *')
    
    void Bar(J2*)
    {}
        
    void Bar(J1*) override
    {}
};




int main(int argc, char const* argv[])
{
    C1 c;
    return EXIT_SUCCESS;
}
