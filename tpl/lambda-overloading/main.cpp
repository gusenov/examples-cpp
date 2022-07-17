#include <iostream>

struct Cat
{
    void Ruffle() const
    {
        std::cout << "Purr!" << std::endl;
    }

    void Stroke() const
    {
        std::cout << "Pur!" << std::endl;
    }
};

template<bool IsConst>
using CatHandler = typename std::conditional_t
<
      IsConst
    , std::function<void(Cat const*)>
    , std::function<void(Cat*)>
>;

template<bool IsConst>
void ruffle(CatHandler<IsConst>&& aHandler)
{
    Cat cat;
    aHandler(&cat);
}

template<bool IsConst>
void stroke(CatHandler<IsConst>&& aHandler)
{
    Cat cat;
    aHandler(&cat);
}

struct Tiger
    : Cat
{
};

template<bool IsConst>
using TigerHandler = typename std::conditional_t
<
      IsConst
    , std::function<void(Tiger const*)>
    , std::function<void(Tiger*)>
>;

template<bool IsConst>
void ruffle(TigerHandler<IsConst>&& aHandler)
{
    Tiger tiger;
    aHandler(&tiger);
}

template<bool IsConst>
void stroke(TigerHandler<IsConst>&& aHandler)
{
    Tiger tiger;
    aHandler(&tiger);
}

void test1()
{
    ruffle<true>([](Tiger const* aTiger){ aTiger->Ruffle(); });
    // Purr!

    // ruffle<true>([&](Tiger* aTiger){ aTiger->Ruffle(); });
    // error: no matching function for call to 'ruffle'

    ruffle<false>([](Tiger* aTiger){ aTiger->Ruffle(); });
    // Purr!

    ruffle<false>([](Tiger const* aTiger){ aTiger->Ruffle(); });
    // Purr!
}

void test2()
{
    // ruffle<true>([](Cat const* aCat) { aCat->Ruffle(); });
    // error: call to 'ruffle' is ambiguous

    CatHandler<true> handler = [](Cat const* aCat) { aCat->Stroke(); };
    stroke<true>(std::move(handler));
    // Pur!

    stroke<true>(CatHandler<true>( [](Cat const* aCat) { aCat->Stroke(); } ));
    // Pur!

    stroke<true>(CatHandler<true> {
        [](Cat const* aCat) { aCat->Stroke(); }
    });
    // Pur!

    // handler(nullptr);
    // 'handler' used after it was moved
}

int main()
{
    test2();
    return 0;
}
