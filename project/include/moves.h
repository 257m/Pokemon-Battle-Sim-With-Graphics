#ifndef MOVES_H
#define MOVES_H

#include "enumdefs.h"
#include "definitions.h"

#define SELF 0
#define OTHER 128

extern const struct Move MoveList [MOVE_MAX];
void Boost(unsigned char stat,char boostrate,struct MyPokemon* pokemon);
void Boostandprint(unsigned char stat,char boostrate,struct MyPokemon* pokemon,bool eop);
void ResetBoosts(struct MyPokemon* pokemon);
char StatusImmunity(unsigned char status,bool eop);
extern mf MOVE_FUNC_LIST [MF_MAX];

extern MoveSlot Empty_slot;
extern MoveSlot Struggle_Slot;

#endif // MOVES_H //