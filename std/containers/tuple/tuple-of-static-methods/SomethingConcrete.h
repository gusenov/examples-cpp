#ifndef SOMETHING_CONCRETE_H_
#define SOMETHING_CONCRETE_H_

#include <string>
#include "ISomething.h"
#include "Registrar.h"

class SomethingConcrete : public ISomething {
public:
    SomethingConcrete() = default;
    ~SomethingConcrete() override = default;
    static std::string GetClazz();
private:
    static const Instantiator<SomethingConcrete> registration_;
};

#endif  // SOMETHING_CONCRETE_H_
