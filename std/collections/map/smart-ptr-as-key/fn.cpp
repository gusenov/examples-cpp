//
// Created by Abbas Gussenov on 12.05.2023.
//

#include <iostream>
#include "fn.h"


void test2()
{
    std::cout << "Output # 2:" << std::endl;

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
// Output # 2:
// 2 -> 2
// 2 -> 22
// 1 -> 11
// 1 -> 1




void test3_2(std::unordered_map<Key_S, int> const& keyToValue)
{
    for (auto const& [k, v]: keyToValue)
    {
        std::cout << k->GetValue() << " -> " << v << std::endl;
    }
}

void test3_3(std::unordered_map<Key_S, int> const keyToValue)
{
    for (auto const& [k, v]: keyToValue)
    {
        std::cout << k->GetValue() << " -> " << v << std::endl;
    }
}




void test4()
{
    std::cout << "Output # 4:" << std::endl;

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
// Output # 4:
// # 1:
// 2 -> 22
// 1 -> 11
// 2 -> 2
// 1 -> 1
// # 2:
// 1 -> 11
// 2 -> 22

// Почему?