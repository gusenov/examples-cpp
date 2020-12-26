#include <cstdlib>
#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;
    
    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(std::size_t size)
{
    std::clog << "Allocating " << size << " bytes\n";
    
    s_AllocationMetrics.TotalAllocated += size;
    
    return malloc(size);
}

void operator delete(void* memory, std::size_t size) noexcept
{
    std::clog << "Freeing " << size << " bytes\n";

    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}

void operator delete(void* memory)
{
    free(memory);
}

class Object {
public:
    Object() {
        std::clog << "Object()" << std::endl;
    }

    ~Object() {
        std::clog << "~Object()" << std::endl;
    }

    int x, y, z;
};

static void PrintMemoryUsage() {
    std::clog << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main(int argc, char const* argv[]) {
    PrintMemoryUsage();
    // Memory Usage: 0 bytes

    // std::string string = "abcdefghijklmnopqrstuv";  // 22 символа
    // new не вызывается.

    std::string string = "abcdefghijklmnopqrstuvw"; // 23 символа
    // new вызывается:
    // Allocating 32 bytes

    PrintMemoryUsage();
    // Memory Usage: 32 bytes
    
    Object* obj = new Object;
    // Allocating 12 bytes
    // Object()

    PrintMemoryUsage();
    // Memory Usage: 44 bytes

    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        // Allocating 12 bytes
        // Object()
        PrintMemoryUsage();
        // Memory Usage: 56 bytes
    }
    // ~Object()

    PrintMemoryUsage();
    // Memory Usage: 56 bytes
    
    return EXIT_SUCCESS;
}
