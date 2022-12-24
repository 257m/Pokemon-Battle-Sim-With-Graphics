#ifndef ABILITY_H
#define ABILITY_H

#include "enumdefs.h"
#include "definitions.h"

extern const Ability AbilityList [ABILITY_MAX];
void NoAbilityf(char et,bool eop);
void TypeBasedBoost(char et,bool eop);
void StatDecreaseImmunity(char et,bool eop);
void TypeChange(char et,bool eop);
void TypeImmunity(char et,bool eop);
extern gpf ABILITY_FUNC_LIST [];

#endif // ABILITY_H //