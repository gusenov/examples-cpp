#include <cstdlib>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

std::mutex g_mut;
std::condition_variable g_cond;
bool g_ready = false;

void loop()
{
    std::unique_lock<std::mutex> lck(g_mut);
    g_cond.wait(lck, []() {
        return g_ready;  // условие, когда прекратить ожидать.
    });
    std::cout << "Hello, World!" << std::endl;
}

void test1()
{
    std::thread thd(&loop);
    thd.join();
    // Зависание...
}

void test2()
{
    g_ready = true;
    std::thread thd(&loop);
    thd.join();
    
    // Зависания не будет потому что сначала проверяется условие.
}

void test3()
{
    std::thread thd(&loop);
    
    // Без задержки g_ready = true; успеет выполниться еще того как начнет работать loop()
    std::this_thread::sleep_for(std::chrono::seconds(1));  // https://stackoverflow.com/a/10613664/12847278
    
    g_ready = true;
    g_cond.notify_one();  // Без этой строки будет зависание...
    
    thd.join();
}

int main(int argc, char* argv[])
{
    test2();
    
    system("read -n 1 -s -p \"Press any key to continue...\"; echo");  // https://discussions.apple.com/thread/2130719
    return EXIT_SUCCESS;
}