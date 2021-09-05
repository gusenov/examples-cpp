#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

std::mutex g_display_mutex;
 
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();
 
    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();
 
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

void bar()
{
    throw "exceptions can be anything";
}

void test1()
{
    {
        std::cout << "before async" << std::endl;
        std::future<void> fut = std::async(foo);
        std::cout << "after async" << std::endl;
    }
    std::cout << "end;" << std::endl;
}
// before async
// after async
// thread 0x70000468e000 sleeping...
// ожидание
// end;
// end.

void test2()
{
    std::cout << "before async" << std::endl;
    std::async(foo);  // Блокирует пока foo полностью не выполнится!
    // Это потому что деструкция временного future возвращаемого async()
    // блокирует, пока foo() не завершит выполнение
    // (деструкция внутреннего shared state присоединяется (joins) к потоку в котором foo() работает).
    std::cout << "after async" << std::endl;
}
// before async
// thread 0x700000d99000 sleeping...
// ожидание
// after async
// end.

void test3()
{
    auto fut = std::async(bar);
    
    assert(fut.valid());
    
    // Для ожидания готовности результата, без его фактическог получения
    // используются функции: wait(), wait_until(time_point), wait_for(duration).
    // Первая ждет неопределенно, последние две не больше указанного таймаута
    // с использованием типов определенных в <chrono>.
    while (fut.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
    {
        std::cout << ".";
    }
    
    assert(fut.valid());
    
    std::cout << std::endl;
}
// .......................................................................................................................
// end.

void test4()
{
    auto fut = std::async(bar);
    try
    {
        // Все return-объекты имеют синхронную функцию get(), которая блокирует,
        // пока ассоциированное shared-состояние не будет готово, а затем либо
        // возвращают предоставленное значение (может быть void) или 
        // перебрасывают предоставленное исключение в вызывающий поток.
        fut.get();
    }
    catch(char const* e)
    {
        std::cout << e << std::endl;
    }
}
// exceptions can be anything
// end.

int main(int argc, char const* argv[])
{
    test4();
    
    std::cout << "end." << std::endl;
    return EXIT_SUCCESS;
}
