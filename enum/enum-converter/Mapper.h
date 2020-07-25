#ifndef Mapper_h
#define Mapper_h

#include <stdexcept>

// Сопоставитель (mapper).

#include <unordered_map>

template<typename TFrom, typename TTo>
class Mapper {
public:
    static Mapper & GetInstance() {
        static Mapper instance;
        return instance;
    }
    
    TTo const & From(TFrom const &from) { 
        if (auto it = m_map.find(from); it != m_map.end())
            return it->second;
        throw std::invalid_argument("Mapper::From(TFrom const &from) - parameter 'from' had invalid value.");
    }

    TFrom const & To(TTo const &to)
    {
        auto it = std::find_if(std::begin(m_map), std::end(m_map), [&to](const auto &mapping) {
            return mapping.second == to;
        });
        if (it != m_map.end())
            return it->first;
        throw std::invalid_argument("Mapper::To(TTo const &to) - parameter 'to' had invalid value.");
    }

private:
    Mapper();
    Mapper(Mapper const &) = delete;
    Mapper & operator=(Mapper const &) = delete;
    Mapper(Mapper &&) = delete;
    Mapper & operator=(Mapper &&) = delete;
    ~Mapper() = default;
    
    void Add(TFrom const &from, TTo const &to) {
        m_map[from] = to;
    }
    
    std::unordered_map<TFrom, TTo> m_map;
};

#endif /* Mapper_h */