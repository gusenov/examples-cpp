//
// Created by Abbas Gussenov on 12.05.2023.
//

#pragma once
#include <memory>

class Key;
using Key_U = std::unique_ptr<Key>;
using Key_S = std::shared_ptr<Key>;
using Key_W = std::weak_ptr<Key>;
