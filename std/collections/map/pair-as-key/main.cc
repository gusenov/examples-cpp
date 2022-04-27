#include <memory>
#include <cstdlib>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cassert>

int g_id = 0;

class ID
{
public:
    ID()
        : m_id(g_id++)
    {}

    explicit ID(int aId)
        : m_id(aId)
    {}

    int AsInt() const { return m_id; }
    
    bool operator==(ID const& aOther) const { return AsInt() == aOther.AsInt(); }
    bool operator!=(ID const& aOther) const { return !(*this == aOther); }

private:
    int m_id;
};

namespace std 
{

template <>
struct hash<ID>
{
    std::size_t operator()(ID const& aId) const
    {
        return aId.AsInt();
    }
};

template <>
struct less<ID>
{
    bool operator()(ID const& lhs, ID const& rhs) const
    {
        return lhs.AsInt() < rhs.AsInt();
    }
};

}

template<typename TValue>
class MapWrapper
{
public:

    typedef std::pair<ID, ID> Key;
    
    int Count(Key const& aKey);
    TValue& At(Key const& aKey);
    TValue const& At(Key const& aKey) const;
    void InsertOrAssign(Key const& aKey, TValue aValue);
    
private:
    
    Key Sorted(Key const& aKey)
    {
        auto key = aKey;
        if (!std::less<ID>{}(key.first, key.second))
            std::swap(key.first, key.second);
        return key;
    }
    
    struct Compare 
    {
        bool operator()(Key const& lhs, Key const& rhs) const 
        {
            static std::less<ID> less;
            if (lhs.first != rhs.first) {
                return less(lhs.first, rhs.first);
            } else {
                return less(lhs.second, rhs.second);
            }
        }
    };
    std::map<Key, TValue, Compare> m_map;
    
    struct pair_hash 
    {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const 
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };
    // std::unordered_map<Key, TValue, pair_hash> m_map;
};

template<typename TValue>
int MapWrapper<TValue>::Count(Key const& aKey)
{
    return m_map.count(Sorted(aKey));
}

template<typename TValue>
TValue& MapWrapper<TValue>::At(Key const& aKey)
{
    return m_map.at(Sorted(aKey));
}

template<typename TValue>
TValue const& MapWrapper<TValue>::At(Key const& aKey) const
{
    return m_map.at(Sorted(aKey));
}

template<typename TValue>
void MapWrapper<TValue>::InsertOrAssign(Key const& aKey, TValue aValue)
{
    m_map.insert_or_assign(Sorted(aKey), aValue);
}

void test1()
{
    std::map<ID, std::string> m;
    ID key;
    std::cout << key.AsInt() << std::endl;  // 0
    m[key] = "zero";
}

void test2()
{
    MapWrapper<bool> m;
    m.InsertOrAssign({ID(10), ID(20)}, true);
    
    assert(1 == m.Count({ID(10), ID(20)}));
    assert(true == m.At({ID(10), ID(20)}));
    
    assert(1 == m.Count({ID(20), ID(10)}));
    assert(true == m.At({ID(20), ID(10)}));
    
    m.InsertOrAssign({ID(20), ID(10)}, false);
    
    assert(1 == m.Count({ID(10), ID(20)}));
    assert(false == m.At({ID(10), ID(20)}));
    
    assert(1 == m.Count({ID(20), ID(10)}));
    assert(false == m.At({ID(20), ID(10)}));
}

int main(int argc, char* argv[])
{
    test2();
    
    return EXIT_SUCCESS;
}
