#ifndef EXECUTION_H
#define EXECUTION_H

#include "common.h"

#define DMG_VELOCITY 0.01

void HealthBar_Anim(bool eop, double hp, double initial_hp, int initial_damage);
void UDBOG(int *hp, int *damage);
void UDBOG2(int *hp, double damage, bool eop, unsigned status);
void ExecuteMove(bool eop);
void endturn(bool eop);

#endif // EXECUTION_H //