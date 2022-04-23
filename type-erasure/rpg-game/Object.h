#pragma once
#include <memory>
#include <typeinfo>

#pragma mark - 1

//*

#include <string>

struct ObjectConcept;

// Object is a simple "passthrough" object that becomes transparent
class Object 
{    
public:    
    template<typename T> 
    Object(T const&);

    std::string name() const;
    bool has_attack_concept() const;

private:
    std::shared_ptr<ObjectConcept> object_;
};

//*/

#pragma mark - 2

/*

#include "ObjectConcept.h"

// Object is a simple "passthrough" object that becomes transparent
class Object 
    : public ObjectConcept
{    
public:    
    template<typename T> 
    Object(T const&);

    std::string name() const override;
    bool has_attack_concept() const override;

private:
    std::shared_ptr<ObjectConcept> object_;
};

//*/