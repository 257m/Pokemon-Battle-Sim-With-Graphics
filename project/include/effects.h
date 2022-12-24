#ifndef EFFECT_H
#define EFFECT_H

#include "common.h"
#include "definitions.h"

void PROTECTF(char et,bool eop);
void CONFUSIONF(char et,bool eop);
extern gpf EFFECT_FUNC_LIST [];
void ACTIVATE_EFFECTS(char et,bool eop);
void CLEAR_EFFECTS(bool eop);
void CLEAR_EFFECT_COUNTERS(bool eop);

#endif // EFFECT_H //