#include <iostream>
#include <unordered_map>
#include "Key.h"
#include "fn.h"




namespace std
{

// Определение для сырого указателя никак не будет использовано для умного.

template <>
struct hash<Key const*>
{
    std::size_t operator()(Key const* const aKey) const
    {
        return aKey->GetValue();
    }
};

template <>
struct equal_to<Key const*>
{
    bool operator()(Key const* const lhs, Key const* const rhs) const
    {
        return lhs->GetValue() == rhs->GetValue();
    }
};

}




namespace std
{

// Нужно определить до первого использования.
// Иначе ошибки:
// Explicit specialization of 'std::hash<std::shared_ptr<Key>>' after instantiation
// Explicit specialization of 'std::equal_to<std::shared_ptr<Key>>' after instantiation

template <>
struct hash<Key_S>
{
    std::size_t operator()(Key_S const& aKey) const
    {
        return aKey->GetValue();
    }
};

template <>
struct equal_to<Key_S>
{
    bool operator()(Key_S lhs, Key_S rhs) const
    {
        return lhs->GetValue() == rhs->GetValue();
    }
};

}




void test1()
{
    std::cout << "Output # 1:" << std::endl;

    auto k1 = std::make_shared<Key>(1);
    auto k2 = std::make_shared<Key>(2);

    auto kOne = std::make_shared<Key>(1);
    auto kTwo = std::make_shared<Key>(2);

    std::unordered_map<Key_S, int> keyToValue;

    keyToValue.insert({k1, 1});
    keyToValue.insert({k2, 2});

    keyToValue.insert_or_assign(kOne, 11);
    keyToValue.insert_or_assign(kTwo, 22);

    for (auto const& [k, v]: keyToValue)
    {
        std::cout << k->GetValue() << " -> " << v << std::endl;
    }
}
// Output # 1:
// 2 -> 22
// 1 -> 11




void test3()
{
    std::cout << "Output # 3:" << std::endl;

    auto k1 = std::make_shared<Key>(1);
    auto k2 = std::make_shared<Key>(2);

    auto kOne = std::make_shared<Key>(1);
    auto kTwo = std::make_shared<Key>(2);

    std::unordered_map<Key_S, int> keyToValue;

    keyToValue.insert({k1, 1});
    keyToValue.insert({k2, 2});

    keyToValue.insert_or_assign(kOne, 11);
    keyToValue.insert_or_assign(kTwo, 22);

    std::cout << "# 1:" << std::endl;
    test3_2(keyToValue);
    std::cout << "# 2:" << std::endl;
    test3_3(keyToValue);
}
// Output # 3:
// # 1:
// 2 -> 22
// 1 -> 11
// # 2:
// 1 -> 11
// 2 -> 22




int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
