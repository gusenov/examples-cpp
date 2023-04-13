#include <iostream>
#include "StringUtils.h"

int main() {

    StringUtils stringUtils;

    auto const stdWStr =
//        stringUtils.ToString<std::wstring>("Hello, World!")  // Undefined symbols for architecture
        stringUtils.ToString<std::wstring>(std::string("Hello, World!"))
//        stringUtils.ToString<std::wstring>({"Hello, World!"})  // No matching member function for call to 'ToString'
    ;
    std::wcout << stdWStr;

    std::cout << std::endl;

    auto const stdStr =
//        stringUtils.ToString<std::string>(L"Hello, World!")  // Undefined symbols for architecture
        stringUtils.ToString<std::string>(std::wstring(L"Hello, World!"))
//        stringUtils.ToString<std::string>({L"Hello, World!"})  // No matching member function for call to 'ToString'
    ;
    std::cout << stdStr;

    return 0;
}
