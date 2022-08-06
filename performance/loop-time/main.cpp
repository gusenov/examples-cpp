#include <iostream>
#include <chrono>  // for high_resolution_clock

template <typename Function>
void MeasureExecutionTimes(Function&& aPortionOfCode)
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    aPortionOfCode();

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << std::fixed << elapsed.count() << " s\n";
}

// MacBook Pro (15-inch, 2018)
// Процессор    2,2 GHz 6‑ядерный процессор Intel Core i7
// Память   16 ГБ 2400 MHz DDR4

void test1()
{
    MeasureExecutionTimes([](){});
}
// Elapsed time: 0.000000 s

// Ten thousand
void test2()
{
    MeasureExecutionTimes([]() {
        for (int i = 0; i < 10000; ++i) {}
    });
}
// Elapsed time: 0.000014 s
// Elapsed time: 0.000021 s

// Million
void test3()
{
    MeasureExecutionTimes([]() {
        for (int i = 0; i < 1000000; ++i) {}
    });
}
// Elapsed time: 0.001796 s
// Elapsed time: 0.001898 s

// Ten millions
void test4()
{
    MeasureExecutionTimes([]() {
        for (int i = 0; i < 10000000; ++i) {}
    });
}
// Elapsed time: 0.018046 s
// Elapsed time: 0.018795 s

// Hundred million
void test5()
{
    MeasureExecutionTimes([]() {
        for (int i = 0; i < 100000000; ++i) {}
    });
}
// Elapsed time: 0.140169 s
// Elapsed time: 0.188318 s

// Billion
void test6()
{
    MeasureExecutionTimes([]() {
        for (int i = 0; i < 1000000000; ++i) {}
    });
}
// Elapsed time: 1.428908 s
// Elapsed time: 1.472331 s

int main()
{
    test6();
    return 0;
}
