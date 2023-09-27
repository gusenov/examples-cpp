#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<std::pair<int, std::string>> q;

    q.push(std::make_pair(1990, "Abbas"));
    std::cout << q.front().first << "\t" << q.front().second << std::endl;
    q.pop();

    q.emplace(1990, "Abbas");
    std::cout << q.front().first << "\t" << q.front().second << std::endl;
    q.pop();

    return 0;
}
