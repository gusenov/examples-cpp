//
// Created by Abbas Gussenov on 12.05.2023.
//

#pragma once
#include "KeyFwd.h"


class Key {
public:
    explicit Key(int);

    int GetValue() const;

private:
    int m_value;
};


