#pragma once
#include <string>

// concept
//  1. An abstract and general idea; an abstraction.
//  2. (generic programming) A description of supported operations on a type, including their syntax and semantics.

struct ObjectConcept 
{   
    virtual ~ObjectConcept() = default;
    virtual bool has_attack_concept() const = 0;
    virtual std::string name() const = 0;
};
