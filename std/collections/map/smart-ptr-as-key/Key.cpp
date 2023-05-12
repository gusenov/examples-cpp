//
// Created by Abbas Gussenov on 12.05.2023.
//

#include "Key.h"

Key::Key(int const aValue)
    : m_value(aValue)
{
}

int Key::GetValue() const
{
    return m_value;
}