#include <memory>
#include <cstdlib>
#include <iostream>
#include <vector>

void print(std::vector<int> const& v)
{
    for (auto const i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

void test1()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin());
    print(v);
    //   0 1 2 3 4 
    // x 1 2 3 4 5
}

void test2()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.end());
    // Segmentation fault: 11
}

void test3()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin() + 5);
    print(v);
    // 0 1 2 3 4 x
}

void test4()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin() + 6);
    // Segmentation fault: 11
}

void test5()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin() + 7);
    // Segmentation fault: 11
}

void test6()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin(), v.begin());
    print(v);
    // 0 1 2 3 4 5
}

void test7()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin(), v.end());
    print(v);
    // 
}

void test8()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin(), v.begin() + 6);
    print(v);
    // 
}

void test9()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin(), v.begin() + 7);
    print(v);
    // Segmentation fault: 11
}

void test10()
{
    std::vector<int> v {0, 1, 2, 3, 4, 5};
    v.erase(v.begin(), v.begin() + 5);
    print(v);
    // 5
}

int main(int argc, char* argv[])
{
    test10();
    
    return EXIT_SUCCESS;
}
