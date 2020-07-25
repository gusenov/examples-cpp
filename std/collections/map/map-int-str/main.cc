#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

template<typename TKey, typename TVal>
class Map {
public:
    Map() = default;
    ~Map() = default;
    
    std::size_t GetEntryCount() const {
        return m_.size();
    }
    
    void AddEntry(TKey key, TVal val) {
        m_[key] = val;
    }
    
    TVal GetValue(std::size_t entryIdx) {
        auto iter = m_.begin();
        std::advance(iter, entryIdx);
        return iter->second;
    }
    
    void RemoveEntryByIndex(std::size_t entryIdx) {
        auto iter = m_.begin();
        std::advance(iter, entryIdx);
        m_.erase(iter);
    }
    
    std::size_t RemoveEntryByKey(TKey key) {
        auto n = m_.erase(key);
        return n;
    }

    TVal* GetMax() {
        auto itMax = std::max_element(m_.begin(), m_.end());
        return itMax != m_.end() ? &itMax->second : nullptr;
    }
    
    void Clear() {
        m_.clear();
    }
    
private:
    std::map<TKey, TVal> m_;
};

int main(int argc, char* argv[]) {
    Map<std::size_t, std::string> m;
    
    m.AddEntry(14, "N");
    assert(m.GetEntryCount() == 1);
    assert(m.GetValue(0) == "N");

    m.AddEntry(8, "H");
    assert(m.GetEntryCount() == 2);
    assert(m.GetValue(0) == "H");
    assert(m.GetValue(1) == "N");
    
    m.RemoveEntryByIndex(1);
    assert(m.GetEntryCount() == 1);
    assert(m.GetValue(0) == "H");
    
    m.AddEntry(17, "Q");
    assert(m.GetEntryCount() == 2);
    assert(m.GetValue(0) == "H");
    assert(m.GetValue(1) == "Q");
    
    m.RemoveEntryByKey(8);
    assert(m.GetEntryCount() == 1);
    assert(m.GetValue(0) == "Q");
    
    m.AddEntry(24, "X");
    m.AddEntry(19, "S");
    assert(m.GetEntryCount() == 3);
    assert(m.GetValue(0) == "Q");
    assert(m.GetValue(1) == "S");
    assert(m.GetValue(2) == "X");
    
    m.AddEntry(1, "Z");
    assert(m.GetEntryCount() == 4);
    assert(m.GetValue(0) == "Z");
    assert(m.GetValue(1) == "Q");
    assert(m.GetValue(2) == "S");
    assert(m.GetValue(3) == "X");

    auto max = m.GetMax();
    assert(max);
    assert(*max == "X");
    
    m.Clear();

    return EXIT_SUCCESS;
}
