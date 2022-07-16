#include <iostream>

class Bar;

template<bool IsConst>
using Handler = typename

    std::conditional_t
    <
          IsConst
        , std::function<void(Bar const*)>
        , std::function<void(Bar*)      >
    >;

class Bar
{
public:

    void Handle() const
    {
        m_handlerConst(this);
    }

    void HandleIfPresent() const
    {
        if (m_handlerConst)
            m_handlerConst(this);
    }

    void Handle()
    {
        m_handler(this);
    }

    void HandleIfPresent()
    {
        if (m_handler)
            m_handler(this);
    }

    void SetHandler(Handler<true>&& aHandler)
    {
        m_handlerConst = std::move(aHandler);
    }

    void SetHandler(Handler<false>&& aHandler)
    {
        m_handler = std::move(aHandler);
    }

private:
    Handler<true> m_handlerConst;
    Handler<false> m_handler;
};

void test1()
{
    Bar const b;

    b.HandleIfPresent();  // OK

    b.Handle();  // BAD
    // libc++abi: terminating with uncaught exception of type std::__1::bad_function_call: std::exception
}

void test2()
{
    Bar b;

    b.HandleIfPresent();  // OK

    b.SetHandler([](Bar*) {
        std::cout << "Hello, World!" << std::endl;
    });
    b.Handle();
}

int main()
{
    test2();
    return 0;
}
