#include <iostream>
#include <map>

void test1()
{
    std::map<int, std::string> m;

    m.insert({1, "one"});
    m.insert({2, "two"});
    m.insert({3, "three"});
    m.insert({4, "four"});

    assert(m.size() == 4);

    // auto it = m.end();

    // --it; --it;  // вариант 1

    // std::advance(it, -2);  // вариант 2

    auto it = std::prev(m.end(), 2);  // вариант 3

    std::cout << it->first << " " << it->second << std::endl;
    // 3 three

    m.erase(m.begin(), it);
    assert(2 == m.size());
}

int main()
{
    test1();

    return 0;
}
