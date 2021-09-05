//
// Created by Abbas Gussenov on 1/30/21.
//

#include "First.hpp"
#include "Second.hpp"
#include "Third.hpp"

Second::~Second() = default;

First Second::Back() {
    return First();
}

Third const& Second::Forward() {
    return *m_third;
}