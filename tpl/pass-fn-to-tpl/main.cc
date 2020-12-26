#include <iostream>
#include <vector>
#include <cassert>

class A {
public:
    A(int data) : data_(data) {
    }
    ~A() = default;
    
    int GetData() const {
        return data_;
    }
    
private:
    int data_;
};

class B {
public:
    B(int data) : data_(data) {
    }
    
    ~B() = default;

    int GetData() const {
        return data_;
    }
    
private:
    int data_;
};

class Cont {
public:
    Cont() = default;
    ~Cont() = default;
    
    template<class T, bool (*cmp)(T const& lhs, T const& rhs)>
    bool HasUniqueData(T const& a) const {
        const auto& vec = GetVector<T>();
        for (auto const& v: vec) {
            if (&a == &v)
                continue;
            if (cmp(a, v))
                return false;
        }
        return true;
    }
    
    template<class T>
    const std::vector<T>& GetVector() const;
    
    template<>
    const std::vector<A>& GetVector() const {
        return a_;
    }
    
    template<>
    const std::vector<B>& GetVector() const {
        return b_;
    }

    template<class T>
    std::vector<T>& GetVector() {
        // Applying Scott Meyer's to-const-and-back-again pattern for avoiding
        // code duplication. Implement non-const version by forwarding to the
        // const version.
        return const_cast<std::vector<T>&>(std::as_const(*this).GetVector<T>());
    }

private:
    std::vector<A> a_;
    std::vector<B> b_;
};

template<class T, int (T::*DataGetter)() const>
bool HasUniqueData2(std::vector<T> const& vec, T const& el) {
    for (auto const& v: vec) {
        if (&el == &v)
            continue;
        if ( (el.*DataGetter)() == (v.*DataGetter)() )
            return false;
    }
    return true;
}

template<class T, typename DataGetter>
bool HasUniqueData3(std::vector<T> const& vec, T const& el, DataGetter dataGetter) {
    for (auto const& v: vec) {
        if (&el == &v)
            continue;
        if ( (el.*dataGetter)() == (v.*dataGetter)() )
            return false;
    }
    return true;
}

int main(int argc, char const* argv[]) {    
    Cont cont;
    auto& vecA = cont.GetVector<A>();
    vecA.emplace_back(10);
    vecA.emplace_back(20);
    vecA.emplace_back(30);
    
    auto& vecB = cont.GetVector<B>();
    vecB.emplace_back(40);
    vecB.emplace_back(50);
    vecB.emplace_back(50);
    vecB.emplace_back(60);
    
    constexpr auto cmp = [](const auto& lhs, const auto& rhs) -> bool {
        return lhs.GetData() == rhs.GetData();
    };
    bool result;
    
    for (auto& a: vecA) {
        result = cont.HasUniqueData<A, cmp>(a);
        assert(result);  // TRUE

        result = HasUniqueData2<A, &A::GetData>(vecA, a);
        assert(result);  // TRUE

        result = HasUniqueData3<A>(vecA, a, &A::GetData);
        assert(result);  // TRUE
    }
    
    result = cont.HasUniqueData<B, cmp>(vecB.at(0));
    assert(result); // TRUE
    result = cont.HasUniqueData<B, cmp>(vecB.at(1));
    assert(!result); // TRUE
    result = cont.HasUniqueData<B, cmp>(vecB.at(2));
    assert(!result); // TRUE
    result = cont.HasUniqueData<B, cmp>(vecB.at(3));
    assert(result); // TRUE
    
    return EXIT_SUCCESS;
}
