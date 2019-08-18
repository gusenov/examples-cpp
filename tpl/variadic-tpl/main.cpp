#include <iostream>
#include <list>
#include <cstdlib>

#include "Console.h"

//---------------------------------------------------------------------------

template<class... Args>
void print(Args... args) {
    (std::cout << ... << args) << "\n";
}

//---------------------------------------------------------------------------

template <typename T>
void func(T t) {
    std::cout << t << std::endl ;
}

template<typename T, typename... Args>
void func(T t, Args... args) {  // recursive variadic function.
    std::cout << t <<std::endl;
    func(args...) ;
}

//---------------------------------------------------------------------------

void Output() {
    std::cout<<std::endl;
}

template<typename First, typename ... Strings>
void Output(First arg, const Strings&... rest) {
    std::cout<<arg<<" ";
    Output(rest...);
}

//---------------------------------------------------------------------------

template <class T>
void func2(std::initializer_list<T> list) {
    for (auto elem : list) {
        std::cout << elem << std::endl ;
    }
}

//---------------------------------------------------------------------------

void foo(const std::list<std::string> & myArguments) {
}

//---------------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    std::cout << "---------------------------------------------------------------------------" << std::endl;

    print(1, ':', " Hello", ',', " ", "World!");
    // 1: Hello, World!

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    std::string str1("Hello");
    func(1, 2.5, 'a', str1);
    // 1
    // 2.5
    // a
    // Hello

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    Output("I", "am", "a", "sentence");  // I am a sentence
    Output("Let's", "try", 1, "or", 2, "digits");  // Let's try 1 or 2 digits

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    Console console;

    console.log("bunch", "of", "arguments");
    // bunch of arguments

    console.warn("or some numbers:", 1, 2, 3);
    // WARNING: or some numbers: 1 2 3

    console.error("just an", "example");
    // ERROR: just an example

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    func2({ 10, 20, 30, 40 }) ;
    // 10
    // 20
    // 30
    // 40

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    std::string str2("world");
    func2({ str1, str2 }) ;
    // Hello
    // world

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    foo({ "arg1", "arg2" });

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    return EXIT_SUCCESS;
}

//---------------------------------------------------------------------------
