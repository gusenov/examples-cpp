//
// Created by Abbas Gussenov on 1/30/21.
//

#ifndef FORWARDDECLARE_SECOND_HPP
#define FORWARDDECLARE_SECOND_HPP


#include <memory>

class First;
class Third;

class Second {
public:
    ~Second();

    First Back();
    Third const& Forward();

private:
    std::unique_ptr<Third> m_third;
    // Везде где конструируется Second, нужно подключать Third.hpp иначе будет ошибка:
    // error: invalid application of 'sizeof' to an incomplete type 'Third'
};


#endif //FORWARDDECLARE_SECOND_HPP
