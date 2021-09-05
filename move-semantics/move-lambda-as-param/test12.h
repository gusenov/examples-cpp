#pragma once

namespace test12
{

// https://stackoverflow.com/a/28483411/12847278
// rvalue reference можно инициализировать только через rvalue expression.
// Поэтому можно передать временный std::function<void()>, но нельзя передать
// переменную без явного moving'а.
// Это значит, что функция может предполагать, что аргумент больше не нужен и можно move'ить из него.
void Foo(std::function<void()>&& foo)
{
    // static_assert(::is_lvalue(foo));
    // function parameter 'foo' with unknown value cannot be used in a constant expression declared here

    assert(is_lvalue_1(foo));  // TRUE
    assert(tag_dispatch(is_lvalue_2(foo)));  // TRUE

    // https://stackoverflow.com/a/28483352/12847278
    // Все что имеет имя это L-value.
    // Поэтому foo это L-value.
    // Тип foo это "rvalue reference на std::function<void()>".
    // Но foo это L-value этого типа.
    // Чтобы обращаться с foo как с rvalue, нужно применить к нему std::move().

    std::function<void()> lm;


    // https://en.cppreference.com/w/cpp/utility/functional/function/operator%3D

//    lm = foo;

    // function& operator=( const function& other );
    // Assigns a copy of target of other, as if by executing function(other).swap(*this);

    // template<class _Rp, class ..._ArgTypes>
    // function<_Rp(_ArgTypes...)>&
    // function<_Rp(_ArgTypes...)>::operator=(const function& __f)
    // {
    //     function(__f).swap(*this);
    //     return *this;
    // }


    lm = std::move(foo);

    // function& operator=( function&& other );
    // Moves the target of other to *this. other is in a valid state with an unspecified value.

    // template<class _Rp, class ..._ArgTypes>
    // function<_Rp(_ArgTypes...)>&
    // function<_Rp(_ArgTypes...)>::operator=(function&& __f) _NOEXCEPT
    // {
    //     __f_ = std::move(__f.__f_);
    //     return *this;
    // }


    lm();
}

void Run()
{
    std::function<void()> lm = []() {
        std::cout << "Hello" << std::endl;
    };

//    Foo(lm);  // No matching function for call to 'Foo'

    Foo(std::move(lm));
    // Hello

    lm();  // Clang-Tidy: 'lm' used after it was moved
    // Hello
}

}
