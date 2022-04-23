#include <vector>
#include <iostream>

#include "items/Weapon.h"
#include "items/Armor.h"
#include "items/Helmet.h"
#include "items/Scroll.h"
#include "items/FireScroll.h"
#include "items/Potion.h"
#include "items/PoisonPotion.h"

#include "Object.h"

#define SWORD
#define CHAIN_MAIL
#define HEALING
#define SLEEP

int main() 
{
    typedef std::vector< Object >    Backpack;
    typedef Backpack::const_iterator BackpackIter;

    Backpack backpack;

    // able to store objects of disparate types in my backpack
    backpack.push_back( Object( Weapon      ( SWORD      ) ) );
    backpack.push_back( Object( Armor       ( CHAIN_MAIL ) ) );
    backpack.push_back( Object( Potion      ( HEALING    ) ) );
    backpack.push_back( Object( Scroll      ( SLEEP      ) ) );
    backpack.push_back( Object( FireScroll  (            ) ) );
    backpack.push_back( Object( PoisonPotion(            ) ) );


    // look at all items that are capable of doing damage to an opponent in battle

    std::cout << "Items I can attack with:" << std::endl;
    
    for( BackpackIter item = backpack.begin(); item != backpack.end(); ++item )
        if( item->has_attack_concept() )
           std::cout << item->name() << std::endl;
}