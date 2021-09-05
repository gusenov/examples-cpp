#include <iostream>
#include <string>

class Node
{
public:
    Node(std::string const& name)
        : m_name(name)
    {}

    ~Node() = default;

    std::string const& GetName() {
        return m_name;
    }

    Node* GetNext() {
        return m_next;
    }

    void SetNext(Node* nextNode) {
        auto lm = [this, nextNode]() {
            m_next = nextNode;
        };
        lm();
    }

private:
    Node* m_next = nullptr;
    std::string m_name;
};

int main() {
    Node n1("Node # 1");
    Node n2("Node # 2");

    n1.SetNext(&n2);
    assert(n1.GetNext());  // true
    std::cout << n1.GetNext()->GetName() << std::endl;  // Node # 2

    return 0;
}
