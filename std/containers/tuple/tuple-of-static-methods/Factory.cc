#include <iostream>
#include <unordered_map>
#include "Factory.h"

using ctor_t = std::tuple<ctor_raw_t, ctor_shared_t>;

// static std::unordered_map<std::string, ctor_t> ctors = {};
// Почему-то не сохраняет вставленные значения!

static std::unordered_map<std::string, ctor_t>& GetCtors() {
    static auto ctors = new std::unordered_map<std::string, ctor_t>();
    return *ctors;
}

static int foo = 246;

void Factory::Add(std::string clazz, ctor_raw_t ctorRaw, ctor_shared_t ctorSmart) {
    std::cout << "Factory::Add(" << clazz << ")" << std::endl;
    auto& ctors = GetCtors();
    ctors.insert(std::make_pair(clazz, std::make_tuple(ctorRaw, ctorSmart)));
    assert(ctors.find(clazz) != ctors.end());
    assert(ctors.size() == 1);
    foo = 763;
}

ISomething* Factory::New_R(std::string clazz) {
    assert(foo == 763);
    auto& ctors = GetCtors();
    assert(ctors.size() == 1);
    if (auto it = ctors.find(clazz); it != ctors.end()) {
        auto tuple = (*it).second;
        return std::get<0>(tuple)();
    }
    return nullptr;
}

std::shared_ptr<ISomething> Factory::New_S(std::string clazz) {
    std::cout << "New_S(" << clazz << ")" << std::endl;

    assert(foo == 763);
    auto& ctors = GetCtors();
    assert(ctors.size() == 1);
    assert(ctors.count(clazz) == 1);

    std::cout << "Keys:";
    for (auto &[key, value]: ctors) {
        std::cout << " '" << key << "'";
    }
    std::cout << std::endl;

    if (auto it = ctors.find(clazz); it != ctors.end()) {
        auto tuple = (*it).second;
        return std::get<1>(tuple)();
    }

    return nullptr;
}