#include <string>
#include <iostream>

class Duck
{
public:
    virtual void Feed(int aFoodType) { std::cout << "Feed(int)" << std::endl; }
    virtual void Feed(int aFoodType) const { std::cout << "Feed(int)" << std::endl; }
};

class Mole
{
public:
    virtual void Feed(std::string aFoodType) { std::cout << "Feed(std::string)" << std::endl; }
    virtual void Feed(std::string aFoodType) const { std::cout << "Feed(std::string)" << std::endl; }
};

class Duckmole
    : public Duck
    , public Mole
{
public:

    // FIX # 1:
//    void Feed(int aFoodType) override { return Duck::Feed(aFoodType); }
//    void Feed(int aFoodType) const override { return Duck::Feed(aFoodType); }

//    void Feed(std::string aFoodType) override { return Mole::Feed(aFoodType); }
//    void Feed(std::string aFoodType) const override { return Mole::Feed(aFoodType); }

    // FIX # 2:
    using Duck::Feed;
    using Mole::Feed;
};

int main()
{
    Duckmole duckmole;

    duckmole.Feed(0);
    // Member 'Feed' found in multiple base classes of different types
    // member found by ambiguous name lookup
    // member found by ambiguous name lookup

    duckmole.Feed("Plant");
    // Member 'Feed' found in multiple base classes of different types
    // member found by ambiguous name lookup
    // member found by ambiguous name lookup

    return 0;
}