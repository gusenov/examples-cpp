#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

int main(int argc, const char * argv[]) {
    std::unordered_map<std::string, int> dow;
    dow.insert({ "Sun.", 1 });
    dow.insert(std::make_pair("Mon.", 2));
    dow["Tue."] = 3;
    // Wed.
    // Thu.
    // Fri.
    // Sat.

    auto it = dow.find("Sun.");
    assert(1 == it->second);
    it->second = 7;
    assert(7 == it->second);

    it = dow.find("Sun.");
    assert(7 == it->second);

    it = dow.find("Mon.");
    --it->second;
    assert(1 == it->second);
    assert(1 == dow["Mon."]);

    assert(2 == --dow["Tue."]);

    assert(3 == dow.size());

    return 0;
}
