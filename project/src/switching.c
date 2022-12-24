#include "../include/common.h"
#include "../include/definitions.h"
#include "../include/display.h"
#include "../include/effects.h"
#include "../include/moves.h"
#include "../include/win.h"

void Switch(bool party, unsigned char member)
{
	struct MyPokemon *PointerSave;
	PointerSave = Parties[party].Member[0];
	Parties[party].Member[0] = Parties[party].Member[member];
	Parties[party].Member[member] = PointerSave;
}

void RandSwitch(bool eop)
{
	unsigned char aimove;
	aimove = 1 +
		(rand() %
			((Parties[eop].Member[1]->CurrentHp > 0) +
				(Parties[eop].Member[2]->CurrentHp > 0) +
				(Parties[eop].Member[3]->CurrentHp > 0) +
				(Parties[eop].Member[4]->CurrentHp > 0) +
				(Parties[eop].Member[5]->CurrentHp > 0)));
	while (1) {
		if (Parties[eop].Member[aimove]->CurrentHp > 0)
			break;
		aimove++;
	}
	Switch(eop, aimove);
}

void SwitchIn(const bool eop)
{
	if (!CheckIfAllDead(eop))
		return;
	if (!Parties[eop].AI_MODE) {
		PartyViewer(2, eop);
	}
	else {
		ResetBoosts(Parties[eop].Member[0]);
		CLEAR_EFFECTS(eop);
		CLEAR_EFFECT_COUNTERS(eop);
		RandSwitch(eop);
	}
}