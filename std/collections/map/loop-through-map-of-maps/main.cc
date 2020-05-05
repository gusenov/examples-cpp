#include <cstdlib>
#include <random>
#include <limits>
#include <iostream>
#include <map>

struct ID {
    int no;
};

namespace std {

template <>
struct hash<ID> {
    std::size_t operator()(ID const& id) const {
        return id.no;
    }
};

template <>
struct less<ID> {
    bool operator() (ID const& lhs, ID const& rhs) const {
        return lhs.no < rhs.no;
    }
};
} // namespace std

using InnerMap = std::map<ID, ID>;

using OuterMap = std::map<std::wstring, InnerMap>;

int main() {

    OuterMap om;

    {
        ID id1 { .no = 0 };
        ID id2 { .no = 1 };
        om[L"bar"][id1] = id2;
    }

    for (auto const & [ str, im ] : om) {
        std::wcout << str << ":" << std::endl;
        for (auto const & [ id1, id2 ] : im) {
            std::wcout << "\t" << id1.no << ": " << id2.no << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
