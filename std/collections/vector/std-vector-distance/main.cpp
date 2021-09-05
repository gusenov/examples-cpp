#include <cassert>
#include <vector>

void test1() {

    std::vector<int> vec {
//    № 1   2  3  4  5  6  7  8  9  10  11
        0,  1, 2, 3, 4, 5, 6, 7, 8, 9   //
//      beg                             end
    };

    std::vector<int>::iterator beg = vec.begin();
    std::vector<int>::iterator end = vec.end();
    assert(beg == beg);
    assert(end == end);
    assert(beg != end);
    assert(beg < end);
    assert(end > beg);

    // NOTE:
    // For a random access iterator type, distance(a,b) is defined to be b-a.

    // [0]
    //  b
    //  |
    assert(std::distance(beg, beg) == 0);
    assert(beg - beg == 0);
    assert(std::distance(end, end) == 0);
    assert(end - end == 0);

    // 0 _ [1]
    // b _  |
    assert(std::distance(beg, beg + 1) == 1);
    assert(beg + 1 - beg == 1);
    assert(std::distance(beg + 1, beg) == -1);
    assert(beg - (beg + 1) == -1);

    // 0 _ 1 _ [2]
    // b _   _  |
    assert(std::distance(beg, beg + 2) == 2);
    assert(beg + 2 - beg == 2);
    assert(std::distance(beg + 2, beg) == -2);
    assert(beg - (beg + 2) == -2);

    // ... ... ...|
    assert(beg + 9 != end);
    assert(std::distance(beg, beg + 9) == 9);
    assert(beg + 9 - beg == 9);

    // ..... .....|
    assert(beg + 10 == end);
    assert(std::distance(beg, beg + 10) == 10);
    assert(beg + 10 - beg == 10);
    assert(std::distance(beg + 10, beg) == -10);
    assert(beg - (beg + 10) == -10);

    assert(std::distance(beg, beg + 100500) == 100500);
    assert(beg + 100500 - beg == 100500);
    assert(std::distance(beg + 100500, beg) == -100500);
    assert(beg - beg + 100500 == 100500);

    // ..... .....|
    assert(std::distance(beg, end) == vec.size() );  // 10
    assert(end - beg == vec.size());
    assert(std::distance(end, beg) == -vec.size() );  // -10
    assert(beg - end == -vec.size());

    assert(std::distance(end - 1, end) == 1);
    assert(end - (end - 1) == 1);
    assert(std::distance(end, end - 1) == -1);
    assert(end - 1 - end == -1);

    // 0 1 2 3 4 5 6 7 8 9
    //     |         |
    //      1 2 3 4 5
    assert(std::distance(beg + 2, beg + 7) == 5);
    assert(beg + 7 - (beg + 2) == 5);
    // +2: b + +
    // +7: b + + + + + + +

    assert((beg + 2) < (beg + 7));

    // 0 1 2 3 4 5 6 7 8 9
    //           |     |
    //            1 2 3
    assert(std::distance(beg + 5, beg + 8) == 3);
    assert(beg + 8 - (beg + 5) == 3);
    // +5: b + + + + +
    // +8: b + + + + + + + +

    assert((beg + 8) > (beg + 5));
}

void test2() {
    std::vector<int> vec;

    std::vector<int>::iterator beg = vec.begin();
    std::vector<int>::iterator end = vec.end();

    assert(beg == end);
    assert(std::distance(beg, end) == 0);
}

int main() {

    test1();
    test2();

    return EXIT_SUCCESS;
}
