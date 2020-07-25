#ifndef Color_h
#define Color_h

#include "Mapper.h"
#include <string>

enum Color {
    kRed,
    kGreen,
    kBlue,    
};

using WString2Color = Mapper<std::wstring, Color>;
template<>
inline WString2Color::Mapper() {
    Add(L"red", Color::kRed);
    Add(L"green", Color::kGreen);
    Add(L"blue", Color::kBlue);
}

#endif