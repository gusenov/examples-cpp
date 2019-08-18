#include <iostream>
#include <cstdlib>

#include "TreeNode.h"
#include "TreeNodeIterator.h"


void test1() {
    std::vector<TreeNode> v = { };
    auto iter = v.begin();
    std::cout << (*iter).GetValue() << std::endl;
    ++iter;
    while(iter != v.end()) {
        std::cout << iter->GetValue() << std::endl;
        ++iter;
    }
    exit(0);
}

int main(int argc, const char * argv[]) {
    // test1();

    TreeNode root(0);

    TreeNode n1(1);
    TreeNode n11(11);
    TreeNode n12(12);
    n1.AddChildNode(&n11);
    n1.AddChildNode(&n12);

    TreeNode n2(2);
    TreeNode n21(21);
    TreeNode n22(22);
    n2.AddChildNode(&n21);
    n2.AddChildNode(&n22);

    TreeNode n3(3);
    TreeNode n31(31);
    TreeNode n32(32);
    n3.AddChildNode(&n31);
    n3.AddChildNode(&n32);

    root.AddChildNode(&n1);
    root.AddChildNode(&n2);
    root.AddChildNode(&n3);

    auto iter = root.begin();
    std::cout << (*iter).GetValue() << std::endl;
    ++iter;

    while(iter != root.end()) {
        std::cout << iter->GetValue() << std::endl;
        ++iter;
    }

    return EXIT_SUCCESS;
}
