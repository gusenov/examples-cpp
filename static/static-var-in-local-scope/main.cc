#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>

void PrintLines(std::vector<std::wstring> const& lines, int leftMargin)
{
    auto const cnt = leftMargin;
    
    for (auto const& line: lines)
    {
        static auto const totalLeftMargin = 2 * leftMargin;
        
        assert(4 == totalLeftMargin);
        for (int i = 0; i < totalLeftMargin; ++i)
            std::wcout << "-";
        
        std::wcout << line << std::endl;
    }
    
}

int main(int argc, char const* argv[])
{
    PrintLines(std::vector<std::wstring> {
        L"First",
        L"Second",
    }, 2);
    // ----First
    // ----Second

    PrintLines(std::vector<std::wstring> {
        L"First",
        L"Second",
    }, 4);
    // ----First
    // ----Second

    return EXIT_SUCCESS;
}
