#include "effects.h"

void PROTECTF(char et,bool eop) {
	if (et == EET_POSTMOVE) {
		if (((unsigned char)MoveList[Parties[eop].Turn->Move].movefunc >> 5 != MF_PROTECT) && ((~MoveList[Parties[eop].Turn->Move].movefunc & REMOVE_FIRST_FIVE_BITS) != MF_PROTECT)) 
		Parties[eop].EFFECT_COUNTERS[EFFECT_PROTECT] = 0; 
	}
}

void CONFUSIONF(char et,bool eop) {
	if (et == EET_INFLICTION) {
		SET_BIT(Parties[!eop].EFFECT_FLAGS[0],EFFECT_CONFUSION);
        if (Parties[!eop].EFFECT_COUNTERS[EFFECT_CONFUSION] == 0) 
			Parties[!eop].EFFECT_COUNTERS[EFFECT_CONFUSION] = (rand() % 4) + 2;
	}
	else if (et == EET_PREMOVE) {
		if (Parties[eop].CanMove) {
				printf("%s%s is confused!\n", EOPTEXT[eop],
					   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
				if (Parties[eop].EFFECT_COUNTERS[EFFECT_CONFUSION] > 0) {
					if (rand() % 2) {
						Parties[eop].CanMove = 0;
						Parties[eop].Confused = 1;
						UDBOG2(
							&Parties[eop].Member[0]->CurrentHp,
							(((((2 * Parties[eop].Member[0]->Level / 5 + 2) *
								(Parties[eop].Member[0]->Atk *
								 statboostmult(
									 Parties[eop].Member[0]->StatBoosts[0])) *
								40 /
								(Parties[eop].Member[0]->Def *
								 statboostmult(
									 Parties[eop].Member[0]->StatBoosts[1]))) /
							   50) +
							  2) *
							 ((rand() % 16) + 85) / 100),
							eop, ESM + EFFECT_CONFUSION);
					}
					Parties[eop].EFFECT_COUNTERS[EFFECT_CONFUSION]--;
				}
				else {
					CLR_BIT(Parties[eop].EFFECT_FLAGS[0], EFFECT_CONFUSION);
					printf("%s%s snapped out of its confusion!\n", EOPTEXT[eop],
						POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
				}
		}
	}
}

gpf EFFECT_FUNC_LIST [] = {&PROTECTF,&CONFUSIONF};

void ACTIVATE_EFFECTS(char et,bool eop) {
	for (int i = 0;i < (sizeof(EFFECT_FUNC_LIST)/sizeof(EFFECT_FUNC_LIST[0]));i++) {
		if (CHK_BIT(Parties[eop].EFFECT_FLAGS[0],i))
			EFFECT_FUNC_LIST[i](et,eop);
  }
}

void CLEAR_EFFECTS(bool eop) {
  Parties[eop].EFFECT_FLAGS[0] = 0;
  Parties[eop].EFFECT_FLAGS[1] = 0;
}

void CLEAR_EFFECT_COUNTERS(bool eop) {
  for (int i = 0;i < 128;i++) {
    Parties[eop].EFFECT_COUNTERS[i] = 0;
  }
}