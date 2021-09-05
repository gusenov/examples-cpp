//
// Created by Abbas Gussenov on 1/30/21.
//

#include "Third.hpp"

std::shared_ptr<Fourth> Third::Forward() {
    return m_fourth;
}
