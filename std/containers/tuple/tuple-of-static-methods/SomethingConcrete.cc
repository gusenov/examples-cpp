#include "SomethingConcrete.h"
#include <typeinfo>

Instantiator<SomethingConcrete> const SomethingConcrete::registration_;

std::string SomethingConcrete::GetClazz() {
    // return typeid(SomethingConcrete).name();  // 17SomethingConcrete

    return "SomethingConcrete";
}
