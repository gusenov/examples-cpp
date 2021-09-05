#pragma once

#include <string>

struct StrUtils {

	static void ToStdWString(std::string const &src, std::wstring &dst);
	static std::wstring ToStdWString(std::string const &src);
	static void ToStdString(std::wstring const &src, std::string &dst);
	static std::string ToStdString(std::wstring const &src);

    StrUtils() = delete;
    StrUtils(StrUtils const &) = delete;
    StrUtils & operator=(StrUtils const &) = delete;
    StrUtils(StrUtils &&) = delete;
    StrUtils & operator=(StrUtils &&) = delete;
    ~StrUtils() = default;

};
