#ifndef TreeNode_h
#define TreeNode_h

#include <vector>


class TreeNodeIterator;
class TreeNode {
    std::vector<TreeNode *> children_;
    int value_ = -1;
public:
    explicit TreeNode(int value);
    ~TreeNode() = default;
    int GetValue() const;
    void AddChildNode(TreeNode *node);
    size_t GetChildrenCount() const;
    TreeNode * GetChildAtIndex(size_t index) const;
    TreeNodeIterator begin();
    TreeNodeIterator end();
};

#endif /* TreeNode_h */
