#include <iostream>
#include <memory>


struct IFlying
{
    virtual ~IFlying() = default;

protected:

    virtual void Fly() = 0;
};


struct ISwimming
{
    virtual ~ISwimming() = default;

private:

    virtual void Swim() = 0;

    virtual void Float()
    {
        std::cout << "ISwimming::Float" << std::endl;
    }

    virtual void Sail()
    {
        std::cout << "ISwimming::Sail" << std::endl;
    }
};


struct IWalking
{
    virtual ~IWalking() = default;
};


struct ISounding
{
    virtual ~ISounding() = default;

    virtual void Sound() = 0;

    void Resound()
    {
        Sound();
    }
};


class Duck
    : public IFlying
    , public ISwimming
    , public IWalking
    , private ISounding
{
public:

#pragma mark - IFlying

    // Fly был изначально определен как protected, переопределяем как public.
    void Fly() override
    {
        std::cout << "Duck::Fly" << std::endl;
    }

#pragma mark - ISwimming

    // Swim был изначально определен как private, переопределяем как public.
    void Swim() override
    {
        std::cout << "Duck::Swim" << std::endl;
    }

    // Float был изначально определен как private, переопределяем как public.
    void Float() override
    {
        // Исходную реализацию вызвать нельзя!
        // ISwimming::Float();
        // 'Float' is a private member of 'ISwimming'

        std::cout << "Duck::Float" << std::endl;
    }

#pragma mark - IWalking

#pragma mark - ISounding

    // Sound изначально определен как public, ISounding унаследован как private.
    void Sound() override
    {
        std::cout << "Duck::Sound" << std::endl;
    }

protected:

    void Quack()
    {
        Resound();
    }
};


void test1()
{
    std::unique_ptr<IFlying> duck(new Duck());
    // duck->Fly();
    // 'Fly' is a protected member of 'IFlying'
}


void test2()
{
    Duck duck;
    duck.Fly();
    // Duck::Fly
}


void test3()
{
    std::unique_ptr<ISwimming> duck(new Duck());
    // duck->Swim();
    // 'Swim' is a private member of 'ISwimming'
}


void test4()
{
    Duck duck;

    duck.Swim();
    // Duck::Swim

    duck.Float();
    // Duck::Float

    // duck.Sail();
    // 'Sail' is a private member of 'ISwimming'

    duck.Sound();
    // Duck::Sound

    // В ISounding метод Resound публичный.
    // Но ISounding унаследован в Duck приватно.
    // duck.Resound();
    // 'Resound' is a private member of 'ISounding'
}


void test5()
{
    // std::unique_ptr<ISounding> duck(new Duck());
    // Cannot cast 'Duck' to its private base class 'ISounding'

    // Нельзя на Duck смотреть как на ISounding потому что он унаследован как private.
}


int main()
{
    test4();
    return 0;
}
