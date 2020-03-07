#include <vector>
#include <algorithm>
#include <iostream>

void test0() {
    std::vector<float> vec { 1, 2, 3 };

    auto it = vec.begin();
    std::advance(it, 0);
    vec.insert(it, 1.5);

    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // # 0   1 2 3
    //   1.5 1 2 3

    // Вставка в позицию, где уже есть элемент, сдвигает этот элемент вправо.
}

void test1() {
    std::vector<float> vec { 1, 2, 3 };

    auto it = vec.begin();
    std::advance(it, 1);
    vec.insert(it, 1.5);

    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // # 0 1   2 3
    //   1 1.5 2 3

    // Вставка в позицию, где уже есть элемент, сдвигает этот элемент вправо.
}

void test2() {
    std::vector<float> vec { 1, 2, 3 };

    auto it = vec.begin();
    std::advance(it, 2);
    vec.insert(it, 2.5);

    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // # 0 1 2   3
    //   1 2 2.5 3

    // Вставка в позицию, где уже есть элемент, сдвигает этот элемент вправо.
}

void test3() {
    std::vector<float> vec { 1, 2, 3 };

    auto it = vec.begin();
    std::advance(it, 3);
    vec.insert(it, 3.5);

    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // # 0 1 2 3
    //   1 2 3 3.5

    // Вставка в позицию, соответствующую числу элементов (zero-based),
    // добавляет новый элемент в конец списка.
}

void test4() {
    std::vector<int> vec { 1, 2, 3 };

    auto it = vec.begin();
    std::advance(it, 4);
    vec.insert(it, 4);

    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // # 0 1 2 3          4
    //   1 2 3 -268433411 4

    // Элемент вставился в четвертую (zero-based) позицию.
}

int main() {

    test0();
    // test1();
    // test2();
    // test3();
    // test4();

    return 0;
}
