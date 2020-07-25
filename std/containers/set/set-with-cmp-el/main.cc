#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

class El {
public:
    El(int val) : val_(val) {
    }
    ~El() = default;
    int GetVal() const {
        return val_;
    }
    void SetVal(int val) {
        val_ = val;
    }
private:
    int val_;
};

struct ElCmp {
  bool operator()(El const *const lhs, El const *const rhs) const  {
      return lhs->GetVal() < rhs->GetVal();
  }
};

int main(int argc, char* argv[]) {
    std::set<El*, ElCmp> s;
    
    auto a = new El(10);
    s.insert(a);
    
    auto b = new El(5);
    s.insert(b);
    
    auto c = new El(15);
    s.insert(c);
    
    for (auto el : s)
        std::cout << el->GetVal() << " ";
    std::cout << std::endl;
    // 5 10 15
    
    c->SetVal(1);
    for (auto el : s)
        std::cout << el->GetVal() << " ";
    std::cout << std::endl;
    // 5 10 1

    return EXIT_SUCCESS;
}
