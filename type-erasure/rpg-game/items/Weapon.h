#pragma once

struct Weapon 
{
    bool can_attack() const { return true; } // All weapons can do damage
};