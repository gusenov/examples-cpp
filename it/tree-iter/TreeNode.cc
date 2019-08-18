#include "TreeNode.h"
#include "TreeNodeIterator.h"

TreeNode::TreeNode(int value) {
    value_ = value;
}

int TreeNode::GetValue() const {
    return value_;
}

void TreeNode::AddChildNode(TreeNode *node) {
    children_.push_back(node);
}

size_t TreeNode::GetChildrenCount() const {
    return children_.size();
}

TreeNode * TreeNode::GetChildAtIndex(size_t index) const {
    return children_.at(index);
}

TreeNodeIterator TreeNode::begin() {
    return TreeNodeIterator(this);
}

TreeNodeIterator TreeNode::end() {
    TreeNode *node = this;
    while (node->GetChildrenCount()) {
        node = node->GetChildAtIndex(node->GetChildrenCount() - 1);
    }
    return TreeNodeIterator(nullptr);
}
