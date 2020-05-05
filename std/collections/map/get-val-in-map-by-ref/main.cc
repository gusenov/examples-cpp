#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

void print(std::unordered_map<std::wstring, int>& ump, wchar_t const* key) {
    auto it = ump.find(key);
    assert(it != ump.end());
    std::wstring k = it->first;
    int v = it->second;
    std::wcout << v << std::endl;
}

int& getref(std::unordered_map<std::wstring, int>& ump, wchar_t const* key) {
    auto it = ump.find(key);
    assert(it != ump.end());
    return it->second;
}

void test1() {
    std::unordered_map<std::wstring, int> ump;

    wchar_t const* key = L"myKey";
    ump.insert({ key, 1 });

    {
        auto it = ump.find(key);
        assert(it != ump.end());
        int& val = it->second;
        std::wcout << val << std::endl;  // 1
        val = 2;
    }

    print(ump, key);  // 2

    {
        int &val = getref(ump, key);
        val = 3;
    }

    print(ump, key);  // 3

    for (int i = 4; i <= 10; ++i) {
        int &val = getref(ump, key);
        val = i;
        print(ump, key);
    }
    // 4
    // 5
    // 6
    // 7
    // 8
    // 9
    // 10
}

int main() {

    test1();

    return 0;
}
