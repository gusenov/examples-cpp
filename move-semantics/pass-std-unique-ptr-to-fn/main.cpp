#include <iostream>
#include <memory>

class Object
{
public:
    Object()
    {
        std::cout << "Object()" << std::endl;
    }

    ~Object()
    {
        std::cout << "~Object()" << std::endl;
    }
};

void fn(std::unique_ptr<int> i)
{
}

void foo(std::unique_ptr<Object> o)
{
    std::cout << "foo begin" << std::endl;
    std::cout << "foo end;" << std::endl;
}

// std::unique_ptr<Object>&& - ссылка
void bar(std::unique_ptr<Object>&& o)
{
    std::cout << "bar begin" << std::endl;
    std::cout << "bar end;" << std::endl;
}

void test1()
{
    std::unique_ptr<int> i;
    // fn(i);
    // Call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'
    // copy constructor is implicitly deleted because 'unique_ptr<int>' has a user-declared move constructor passing argument to parameter 'i' here
}

void test2()
{
    std::cout << "test2 begin" << std::endl;
    auto o = std::make_unique<Object>();
    foo(std::move(o));
    std::cout << "test2 end;" << std::endl;
}
// test2 begin
// Object()
// foo begin
// foo end;
// ~Object()
// test2 end;

void test3()
{
    foo(std::make_unique<Object>());
}
// Object()
// foo begin
// foo end;
// ~Object()

void test4()
{
    auto o = std::make_unique<Object>();
    // bar(o);
    // No matching function for call to 'bar'
    // candidate function not viable: expects an rvalue for 1st argument
}

void test5()
{
    std::cout << "test5 begin" << std::endl;
    bar(std::make_unique<Object>());
    std::cout << "test5 end" << std::endl;
}
// test5 begin
// Object()
// bar begin
// bar end;
// ~Object()
// test5 end

void test6()
{
    std::cout << "test6 begin" << std::endl;
    auto o = std::make_unique<Object>();

    // std::move просто cast'ит объект к T&&, с объектом ничего не случается.
    // А внутри bar() с объектом тоже ничего не делаем, поэтому объект будет разрушен после исполнения test6().
    bar(std::move(o));

    std::cout << "test6 end" << std::endl;
}
// test6 begin
// Object()
// bar begin
// bar end;
// test6 end
// ~Object()

int main()
{
    test6();
    return 0;
}
