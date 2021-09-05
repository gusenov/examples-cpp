#include <iostream>
#include <string>
#include <cstdlib>




static_assert(std::is_move_constructible<std::function<void()>>::value);  // TRUE
// If the class doesn't contain C(C&&) = delete;
// then it's impossible to detect whether it contains C(C&&) { ... } or not:
// std::is_move_constructible<C>::value will be true in either case,
// and there is no other way to detect it.
// The presence of C(C&&) = delete; can be detected:
// std::is_move_constructible<C>::value is false if C(C&&) = delete; is present.
// https://stackoverflow.com/a/42427286/12847278




// https://stackoverflow.com/a/36296823/12847278
template <typename T>
constexpr bool is_lvalue_1(T&&) {
  return std::is_lvalue_reference<T>{};
}

// https://stackoverflow.com/a/36312021/12847278
template<class T>
constexpr std::is_lvalue_reference<T&&>
is_lvalue_2(T&&){return {};}
bool tag_dispatch( std::true_type ) {
    return true;
}
bool tag_dispatch( std::false_type ) {
    return false;
}




#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "test4.h"
#include "test5.h"
#include "test6.h"
#include "test7.h"
#include "test8.h"
#include "test9.h"
#include "test10.h"
#include "test11.h"
#include "test12.h"




int main()
{
//    test1::Run();
//    test2::Run();
//    test3::Run();
//    test4::Run();
//    test5::Run();
//    test6::Run();
//    test7::Run();
//    test8::Run();
//    test9::Run();
//    test10::Run();
//    test11::Run();
    test12::Run();

    return EXIT_SUCCESS;
}
