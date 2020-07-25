#ifndef REGISTRAR_H_
#define REGISTRAR_H_

#include <memory>
#include "Factory.h"

template<typename T>
struct Instantiator: public Factory {
    Instantiator() {
        Add(T::GetClazz(), &Instantiator::New, &Instantiator::MakeShared);
    }

    static ISomething * New() {
        return new T();
    }

    static std::shared_ptr<ISomething> MakeShared() {
        return std::make_shared<T>();
    }
};

#endif  // REGISTRAR_H_
