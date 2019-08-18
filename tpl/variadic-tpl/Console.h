#ifndef CONSOLE_H
#define CONSOLE_H


#include <iostream>
#include <utility>

class Console {
protected:
    template <typename T>
    void log_argument(T t) {
        std::cout << t << " ";
    }
public:
    template <typename... Args>
    void log(Args&&... args) {
        int dummy[] = { 0, ((void) log_argument(std::forward<Args>(args)),0)... };
        std::cout << std::endl;
    }

    template <typename... Args>
    void warn(Args&&... args) {
        std::cout << "WARNING: ";
        int dummy[] = { 0, ((void) log_argument(std::forward<Args>(args)),0)... };
        std::cout << std::endl;
    }

    template <typename... Args>
    void error(Args&&... args) {
        std::cout << "ERROR: ";
        int dummy[] = { 0, ((void) log_argument(std::forward<Args>(args)),0)... };
        std::cout << std::endl;
    }
};

#endif // CONSOLE_H
