#ifndef FACTORY_H_
#define FACTORY_H_

#include <string>

struct ISomething;
using ctor_raw_t = ISomething* (*)();
using ctor_shared_t = std::shared_ptr<ISomething> (*)();

class Factory {
public:
    Factory() {
    }

    void Add(std::string clazz, ctor_raw_t ctorRaw, ctor_shared_t ctorSmart);

    static ISomething* New_R(std::string clazz);
    static std::shared_ptr<ISomething> New_S(std::string clazz);
};

#endif  // FACTORY_H_
