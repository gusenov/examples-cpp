#include <iostream>
#include <utility>
#include <functional>
#include <string>

using void_fn_t = std::function<void()>;

template<class... Args>
void out(const Args&... args) {
    (std::cout << ... << args) << std::endl;
}

template<class... Args>
void print(const Args&... args) {

    std::function<void(const void_fn_t&)> wrapper = [] (const void_fn_t& fn) {
        std::cout << "begin" << std::endl;
        fn();
        std::cout << "end;" << std::endl;
    };

    auto bound1 = [args = std::make_tuple(std::forward<const Args&>(args) ...)] () {
        std::apply([](auto& ... args) {
            out(args...);
        }, args);
    };

    wrapper(bound1);

    auto bound2 = std::bind(&out<const Args&...>, std::forward<const Args&>(args)...);  // WTF?
}

int main() {
    print("Hello, ", "World!");
    // begin
    // Hello, World!
    // end;

    return 0;
}
