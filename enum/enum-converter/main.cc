#include <iostream>
#include <cstdlib>

#include "DifferentTypesValuesMapper.h"
#include "Color.h"

template<>
DifferentTypesValuesMapper<std::wstring, Color>::DifferentTypesValuesMapper() {
    Add(std::wstring(L"red"), Color::kRed);
    Add(std::wstring(L"green"), Color::kGreen);
    Add(std::wstring(L"blue"), Color::kBlue);
}

int main(int argc, char *argv[]) {
    
    DifferentTypesValuesMapper<std::wstring, Color> m;

    assert(m.Map<std::wstring>(Color::kRed) == L"red" );
    assert(m.Map<Color>(std::wstring(L"red")) == Color::kRed);

    assert(m.Map<std::wstring>(Color::kGreen) == L"green" );
    assert(m.Map<Color>(std::wstring(L"green")) == Color::kGreen);

    assert(m.Map<std::wstring>(Color::kBlue) == L"blue" );
    assert(m.Map<Color>(std::wstring(L"blue")) == Color::kBlue);
    
    
    assert(WString2Color::GetInstance().From(L"red") == Color::kRed);
    assert(WString2Color::GetInstance().To(Color::kRed) == L"red");

    return EXIT_SUCCESS;
}
