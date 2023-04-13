//
// Created by Abbas Gussenov on 13.04.2023.
//

#include "StringUtils.h"

/*
template<class TOutputString, class TInputString>
TOutputString StringUtils::ToString(TInputString const&)
{
    if constexpr (std::is_same_v<TOutputString, std::wstring>)
        return L"std::wstring - base - cpp";
    else if constexpr (std::is_same_v<TOutputString, std::string>)
        return "std::string - base - cpp";
    return {};
}
*/

template<>
std::wstring StringUtils::ToString<std::wstring, std::string>(std::string const& aInputString)
{
    return L"std::wstring - spec - cpp";
}

/*
template
std::wstring StringUtils::ToString<std::wstring, std::string>(std::string const&);
*/
// Explicit instantiation of 'ToString<std::wstring, std::string>' that occurs after an explicit specialization has no effect

/*
template
std::wstring StringUtils::ToString(std::string const&);
*/
// Explicit instantiation of 'ToString<std::wstring, std::string>' that occurs after an explicit specialization has no effect

template<>
std::string StringUtils::ToString<std::string, std::wstring>(std::wstring const& aInputString)
{
    return "std::string - spec - cpp";
}

/*
template
std::string StringUtils::ToString<std::string, std::wstring>(std::wstring const&);
*/
// Explicit instantiation of 'ToString<std::string, std::wstring>' that occurs after an explicit specialization has no effect

/*
template
std::string StringUtils::ToString(std::wstring const&);
*/
// Explicit instantiation of 'ToString<std::string, std::wstring>' that occurs after an explicit specialization has no effect

StringUtils::StringUtils()
{
}