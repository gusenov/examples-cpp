//
// Created by Abbas Gussenov on 1/30/21.
//

#ifndef FORWARDDECLARE_THIRD_HPP
#define FORWARDDECLARE_THIRD_HPP


#include <memory>

class Fourth;

class Third {
public:
    std::shared_ptr<Fourth> Forward();

private:
    std::shared_ptr<Fourth> m_fourth;
};


#endif //FORWARDDECLARE_THIRD_HPP
