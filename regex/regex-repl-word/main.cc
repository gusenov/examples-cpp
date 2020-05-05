#include <string>
#include <regex>
#include <cstdlib>

int main(int argc, char const * argv[])
{
    std::string subject("bar-a+sin(pi)+1* bar /23-cos(bar)+i-i_1/j2-_j2*j23+100*bar");
    std::regex re(R"(\bbar\b)");

    assert(!std::regex_match(subject, re));  // TRUE
    assert(std::regex_match(subject, std::regex(R"(.*\bbar\b.*)")));  // TRUE

    auto result = std::regex_replace(subject, re, "abc");
    assert(result == "abc-a+sin(pi)+1* abc /23-cos(abc)+i-i_1/j2-_j2*j23+100*abc");  // TRUE

    return EXIT_SUCCESS;
}
