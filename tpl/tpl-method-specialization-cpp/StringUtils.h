//
// Created by Abbas Gussenov on 13.04.2023.
//

#ifndef TPL_METHOD_SPECIALIZATION_CPP_STRINGUTILS_H
#define TPL_METHOD_SPECIALIZATION_CPP_STRINGUTILS_H

#include <string>

struct StringUtils
{
    StringUtils();

    template<class TOutputString, class TInputString>
	static TOutputString ToString(TInputString const&);

    /*
    template<> std::wstring ToString(std:: string const&);
    template<> std:: string ToString(std::wstring const&);
    */

    /*
    template<> std::wstring ToString(std:: string const&)
    {
        return L"std::string - spec - h";
    }

    template<> std:: string ToString(std::wstring const&)
    {
        return "std::string - spec - h";
    }
    */

};

/*
template<> std::wstring StringUtils::ToString(std:: string const&);
template<> std:: string StringUtils::ToString(std::wstring const&);
*/

#endif //TPL_METHOD_SPECIALIZATION_CPP_STRINGUTILS_H
