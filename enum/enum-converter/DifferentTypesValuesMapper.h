#ifndef DifferentTypesValuesMapper_h
#define DifferentTypesValuesMapper_h

#include <tuple>
#include <vector>
#include <type_traits>

template <typename ...Types>
class DifferentTypesValuesMapper {
    using Tuple = std::tuple<std::vector<Types>...>;
    
    template<int tupleElIdx>
    using type_of_tuple_element = typename std::tuple_element<tupleElIdx, Tuple>::type;
    
    template<typename TVec>
    using type_of_vector_element = typename TVec::value_type;

    template<int tupleElIdx>
    using type_of_tuple_vector_element = type_of_vector_element<type_of_tuple_element<tupleElIdx>>;

    template<int tupleElIdx, typename TVecEl>
    constexpr static bool is_type_of_tuple_vector_element_same_as = std::is_same<type_of_tuple_vector_element<tupleElIdx>, TVecEl>::value;
    
    template <int tupleElIdx, class TVecEl, bool>
    struct Getter {
        static std::vector<TVecEl> & Get(Tuple &tuple) {
            return Getter<tupleElIdx + 1, TVecEl, is_type_of_tuple_vector_element_same_as<tupleElIdx + 1, TVecEl>>::Get(tuple);
        }
    };

    template <int tupleElIdx, class TVecEl>
    struct Getter<tupleElIdx, TVecEl, true> {
       static std::vector<TVecEl> & Get(Tuple &tuple) {
           return std::get<tupleElIdx>(tuple);
       }
    };

    template <typename TVecEl>
    std::vector<TVecEl> & access() {
        return Getter<0, TVecEl, is_type_of_tuple_vector_element_same_as<0, TVecEl>>::Get(m_diffTypesValues);
    }

public:
    DifferentTypesValuesMapper();
    
    template<typename ...Args>
    void Add(Args const & ...ts) {
        (access<Args>().push_back(ts), ...);
    }
    
    template <typename TToType, typename TFromType>
    TToType const & Map(TFromType const &fromValue) {
        auto const &fromValues = access<TFromType>();
        auto const fromValuePos = distance(fromValues.begin(), find(fromValues.begin(), fromValues.end(), fromValue));
        return access<TToType>().at(fromValuePos);
    }

private:
    Tuple m_diffTypesValues;
};


#endif