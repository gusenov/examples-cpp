#include <codecvt>
#include <locale>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <regex>
#include "StrUtils.hpp"

void StrUtils::ToStdWString(std::string const &src, std::wstring &dst) {
    dst = ToStdWString(src);
}

std::wstring StrUtils::ToStdWString(std::string const &src) {
#ifdef __APPLE__
    using cvt_t = std::codecvt_utf8<wchar_t>;
#elif __GNUC__
#elif _MSC_VER
    using cvt_t = std::codecvt_utf8_utf16<wchar_t>;
#else
#error "Your compiler is not supported"
#endif
    return std::wstring_convert<cvt_t>().from_bytes(src);
}

void StrUtils::ToStdString(std::wstring const &src, std::string &dst) {
    dst = ToStdString(src);
}

std::string StrUtils::ToStdString(std::wstring const &src) {
#ifdef __APPLE__
    using cvt_t = std::codecvt_utf8<wchar_t>;
#elif __GNUC__
#elif _MSC_VER
    using cvt_t = std::codecvt_utf8_utf16<wchar_t>;
#else
#error "Your compiler is not supported"
#endif
    return std::wstring_convert<cvt_t>().to_bytes(src);
}
