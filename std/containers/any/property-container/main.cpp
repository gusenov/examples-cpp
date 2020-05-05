#include <iostream>
#include <string>
#include <unordered_map>
#include <any>

enum UserKey : uint64_t {
    k1, k2, k3
};

class UserInfo {
    std::unordered_map<uint64_t, std::any> _propertyContainer;
public:
    UserInfo() = default;
    ~UserInfo() = default;

    template <class T>
    T Get(uint64_t key) {
        T value;
        if constexpr (std::is_pointer_v<T>)
            value = nullptr;
        if (auto it  = _propertyContainer.find(key);
                 it != _propertyContainer.end()) {
            value = std::any_cast<T>(it->second);
        };
        return value;
    }

    template <class T>
    void Set(uint64_t key, T value) {
        _propertyContainer[key] = value;
    }
};

int main(int argc, const char * argv[]) {
    UserInfo ui;

    ui.Set(k1, 100);
    std::cout << "k1 = " << ui.template Get<int>(k1) << std::endl;  // k1 = 100

    ui.Set(k2, true);
    std::cout << "k2 = " << ui.template Get<bool>(k2) << std::endl;  // k2 = 1

    ui.Set(k3, &ui);
    std::cout << "k3 = " << ui.template Get<UserInfo *>(k3) << std::endl;  // k3 = 0x7ffee42cdad8
    std::cout << "ui = " << &ui << std::endl;  // ui = 0x7ffee42cdad8
    
    return 0;
}
