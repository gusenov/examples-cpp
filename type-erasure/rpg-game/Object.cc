#include "Object.h"

#include "items/Weapon.h"
#include "items/Armor.h"
#include "items/Potion.h"
#include "items/Scroll.h"
#include "items/FireScroll.h"
#include "items/PoisonPotion.h"

#include "ObjectConcept.h"

/**
 * just done the inheritance thing. How is this better?
 * It is better not because it affords you more functionality than the inheritance approach,
 * but because it does not tighly couple Weapons and Armors etc through a common base class.
 * It gives me the power of retaining type as templates do.
 */
template<typename T> 
struct ObjectModel 
    : ObjectConcept 
{
    ObjectModel(T const& t) 
        : object(t) 
    {}
    
    ~ObjectModel() override = default;
    
    bool has_attack_concept() const override 
    { 
        return object.can_attack(); 
    }
    
    std::string name() const override 
    { 
        return typeid(object).name(); 
    }
    
private:
    T object;
};

#pragma mark - Object


template<typename T> 
Object::Object(T const& obj ) 
    : object_(new ObjectModel<T>(obj)) 
{}

template Object::Object(Weapon const&);
template Object::Object(Armor const&);
template Object::Object(Potion const&);
template Object::Object(Scroll const&);
template Object::Object(FireScroll const&);
template Object::Object(PoisonPotion const&);


std::string Object::name() const 
{ 
    return object_->name(); 
}

bool Object::has_attack_concept() const 
{ 
    return object_->has_attack_concept(); 
}
