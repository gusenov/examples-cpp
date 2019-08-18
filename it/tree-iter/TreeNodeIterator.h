#ifndef TreeNodeIterator_h
#define TreeNodeIterator_h

#include <iostream>
#include <stack>
#include "TreeNode.h"


class TreeNodeIterator {
    std::stack<TreeNode *> stack_;

public:
    // Обязательными являются первые два параметра:

    // Тип итератора:
    typedef std::input_iterator_tag iterator_category;
    // Тип выбирается из следующих типов:
    //   input_iterator_tag
    //     Должен поддерживать префиксную форму инкремента, оператор !=,
    //     оператор * и оператор ->. Понадобится конструктор и конструктор
    //     копирования.
    //   output_iterator_tag
    //   forward_iterator_tag
    //   bidirectional_iterator_tag
    //   random_access_iterator_tag

    // Тип значения которое хранится и возвращается операторами * и ->:
    typedef TreeNode value_type;

    // Тип который может описывать растояние между итераторами:
    typedef std::ptrdiff_t difference_type;

    // Тип указателя на значение:
    typedef TreeNode *pointer;

    // Тип ссылки на значения:
    typedef TreeNode &reference;


    explicit TreeNodeIterator(TreeNode *value = nullptr) {
        if (value)
            stack_.push(value);
    }

    // TreeNode * operator*() const {
    //     return !stack_.empty() ? stack_.top() : nullptr;
    // }

    typename TreeNodeIterator::reference operator*() const {
        TreeNode *node = nullptr;
        if (!stack_.empty()) {
            node = stack_.top();
        }
        return *node;
    }

    TreeNode * operator->() const {
        return !stack_.empty() ? stack_.top() : nullptr;
    }


    //  Хорошая практика добавлять поддержку != и == вместе:

    bool operator==(TreeNodeIterator const &other) const {
        if (stack_.empty() || other.stack_.empty())
            return stack_.empty() && other.stack_.empty();

        return stack_.top() == other.stack_.top();
    }

    bool operator!=(TreeNodeIterator const &other) const {
        return !(*this == other);
    }


    TreeNodeIterator & operator++() {
        if (!stack_.empty()) {
            TreeNode *node = stack_.top();
            stack_.pop();
            for (int i = node->GetChildrenCount() - 1; i >= 0; --i)
                stack_.push(node->GetChildAtIndex(i));
        }
        return *this;
    }

};

#endif /* TreeNodeIterator_h */
