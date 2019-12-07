#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> us;

    us.insert(3);
    us.insert(4);
    us.insert(5);
    us.insert(0);

    auto it = us.begin();
    std::advance(it, 1);

    std::cout << *it << std::endl;
    // 5

    std::advance(it, 2);
    std::cout << *it << std::endl;
    // 3

    std::advance(it, 1);
    if (it == us.end())
        std::cout << "end" << std::endl;
        // end

    return 0;
}
