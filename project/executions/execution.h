#ifndef EXECUTION_H
#define EXECUTION_H

#define DMG_VELOCITY 0.01

void Damage_Anim(bool eop, double hp, double initial_hp, int initial_damage);
void UDBOG(int *hp, int *damage);
void UDBOG2(int *hp, double damage, bool eop, unsigned status);
void ExecuteMove(bool eop);

#endif