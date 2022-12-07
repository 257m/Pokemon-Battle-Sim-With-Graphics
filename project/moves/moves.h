#ifndef MOVES_H
#define MOVES_H

#define SELF 0
#define OTHER 128

extern const struct Move MoveList [];
void Boost(unsigned char stat,char boostrate,struct MyPokemon* pokemon);
void Boostandprint(unsigned char stat,char boostrate,struct MyPokemon* pokemon,bool eop);
void ResetBoosts(struct MyPokemon* pokemon);
char StatusImmunity(unsigned char status,bool eop);
extern mf MOVE_FUNC_LIST [];

#endif // MOVES_H //