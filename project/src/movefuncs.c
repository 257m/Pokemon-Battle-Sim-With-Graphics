#include "../include/ability.h"
#include "../include/definitions.h"
#include "../include/display.h"
#include "../include/drawing.h"
#include "../include/effects.h"
#include "../include/execution.h"
#include "../include/general.h"
#include "../include/moves.h"
#include "../include/pokemon.h"
#include "../include/switching.h"
#include <stdint.h>

void Boost(unsigned char stat, char boostrate, struct MyPokemon* pokemon)
{
	pokemon->StatBoosts[stat] += boostrate;
	if (pokemon->StatBoosts[stat] > 6)
		pokemon->StatBoosts[stat] = 6;
	else if (pokemon->StatBoosts[stat] < -6)
		pokemon->StatBoosts[stat] = -6;
}

void Boostandprint(unsigned char stat, char boostrate,
				   struct MyPokemon* pokemon, bool eop)
{
	if (boostrate == 0)
		return;
	if (pokemon->StatBoosts[stat] >= 6 && boostrate > 0) {
		pokemon->StatBoosts[stat] = 6;
		sprintf(TempTextBuffer, "%s%s's %s can't go any higher", EOPTEXT[eop],
				POKEMONDEX[pokemon->Poke].Name, Stagenames[stat]);
		TextBoxUpdateFast(TempTextBuffer, 50, 1000);
	}
	else if (pokemon->StatBoosts[stat] <= -6 && boostrate < 0) {
		pokemon->StatBoosts[stat] = -6;
		sprintf(TempTextBuffer, "%s%s's %s can't go any lower", EOPTEXT[eop],
				POKEMONDEX[pokemon->Poke].Name, Stagenames[stat]);
		TextBoxUpdateFast(TempTextBuffer, 50, 1000);
	}
	else {
		if (boostrate > 0) {
			if (pokemon->StatBoosts[stat] + boostrate > 6)
				boostrate = pokemon->StatBoosts[stat] + boostrate - 6;
			pokemon->StatBoosts[stat] += boostrate;
			sprintf(TempTextBuffer, "%s%s's %s rose by %d stages", EOPTEXT[eop],
					POKEMONDEX[pokemon->Poke].Name, Stagenames[stat],
					boostrate);
			TextBoxUpdateFast(TempTextBuffer, 50, 1000);
		}
		else if (boostrate < 0) {
			if (pokemon->StatBoosts[stat] + boostrate < -6)
				boostrate = pokemon->StatBoosts[stat] + boostrate + 6;
			pokemon->StatBoosts[stat] += boostrate;
			sprintf(TempTextBuffer, "%s%s's %s fell by %d stages", EOPTEXT[eop],
					POKEMONDEX[pokemon->Poke].Name, Stagenames[stat],
					boostrate * -1);
			TextBoxUpdateFast(TempTextBuffer, 50, 1000);
		}
	}
}

void ResetBoosts(struct MyPokemon* pokemon)
{
	for (int i = 0; i < 8; i++)
		pokemon->StatBoosts[i] = 0;
}

char StatusImmunity(unsigned char status, bool eop)
{
	if (status == STATUS_BURN &&
		(POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == FIRE ||
		 POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == FIRE))
		return 0;
	else if ((status == STATUS_TOXIC || status == STATUS_POISON) &&
			 (POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == POISON ||
			  POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == POISON ||
			  POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == METAL ||
			  POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == METAL))
		return 0;
	else if (CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
					 nFLAG_POWDER_MOVE) &&
			 (POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == PLANT ||
			  POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == PLANT))
		return 0;
	else if ((status == STATUS_PARALYSIS) &&
			 (POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == ELECTRIC ||
			  POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == ELECTRIC ||
			  (Parties[eop].Turn->Move == Thunder_Wave &&
			   (POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == GROUND ||
				POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == GROUND))))
		return 0;
	else if ((status == STATUS_FREEZE) &&
			 (POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1 == ICE ||
			  POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2 == ICE))
		return 0;
	return 1;
}

void Nothingf(char et, bool eop, bool pos)
{
}

void Strugglef(char et, bool eop, bool pos)
{
	Parties[eop].Turn->PP = 1;
	if (et == 2)
		Parties[eop].Member[0]->CurrentHp -= Parties[0].Member[0]->Hp / 4;
}

void StatMod(char et, bool eop, bool pos)
{
	char temp;
	char mult;
	bool soo = eop;
	unsigned char rs = pos * 5;
	if (CHK_BIT(MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs + 4], 7)) {
		soo = !eop;
		if (Parties[!eop].Dead)
			return;
	}
	if (et == 2) {
		if (!(CHK_BIT(Parties[!eop].EFFECT_FLAGS[0], EFFECT_PROTECT) &&
			  CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
					  nFLAG_PROTECT_AFFECTED) &&
			  soo == !eop)) {
			if (((Parties[eop].TemporaryMult == 0) ||
				 TypeChart[Parties[eop].MoveTempType]
						  [POKEMONDEX[Parties[soo].Member[0]->Poke].Type1] *
						 TypeChart[Parties[eop].MoveTempType]
								  [POKEMONDEX[Parties[soo].Member[0]->Poke]
									   .Type2] <=
					 0) &&
				CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
						nFLAG_TYPE_IMMUNITY_AFFECTED) &&
				soo == !eop)
				return;
			if (rand() <
				RAND_MAX * (((double)(((unsigned char)(MoveList[Parties[eop]
																	.Turn->Move]
														   .GNRL_PURPOSE[rs + 4]
													   << 1)) >>
									  1)) /
							100)) {
				for (int i = 0; i < 8; i++) {
					temp = MoveList[Parties[eop].Turn->Move]
							   .GNRL_PURPOSE[rs + i / 2];
					mult = 1;
					if (i % 2 == 0) {
						if (CHK_BIT(MoveList[Parties[eop].Turn->Move]
										.GNRL_PURPOSE[rs + i / 2],
									7)) {
							CLR_BIT(temp, 7);
							mult = -1;
						}
						if (!((((temp >> 4) * mult) < 0) &&
							  (AbilityList[Parties[soo].Member[0]->Ability]
								   .abilityfunc ==
							   AF_IMMUNE_TO_STAT_DECREASE) &&
							  CHK_BIT(
								  AbilityList[Parties[soo].Member[0]->Ability]
									  .GNRL_PURPOSE[rs + 0],
								  i) &&
							  CHK_BIT(
								  AbilityList[Parties[soo].Member[0]->Ability]
									  .GNRL_PURPOSE[rs + 1],
								  soo))) {
							Boostandprint(i, (temp >> 4) * mult,
										  Parties[soo].Member[0], soo);
						}
					}
					else {
						if (CHK_BIT(MoveList[Parties[eop].Turn->Move]
										.GNRL_PURPOSE[rs + i / 2],
									3)) {
							CLR_BIT(temp, 3);
							mult = -1;
						}
						if (!((((temp - ((temp >> 4) << 4)) * mult) < 0) &&
							  (AbilityList[Parties[soo].Member[0]->Ability]
								   .abilityfunc ==
							   AF_IMMUNE_TO_STAT_DECREASE) &&
							  CHK_BIT(
								  AbilityList[Parties[soo].Member[0]->Ability]
									  .GNRL_PURPOSE[rs + 0],
								  i) &&
							  CHK_BIT(
								  AbilityList[Parties[soo].Member[0]->Ability]
									  .GNRL_PURPOSE[rs + 1],
								  soo))) {
							Boostandprint(i, (temp - ((temp >> 4) << 4)) * mult,
										  Parties[soo].Member[0], soo);
						}
					}
				}
			}
		}
	}
}

void StatusInfliction(char et, bool eop, bool pos)
{
	unsigned char rs = pos * 5;
	if (et == 2) {
		if (!Parties[!eop].Dead) {
			if (!(CHK_BIT(Parties[!eop].EFFECT_FLAGS[0], EFFECT_PROTECT) &&
				  CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
						  nFLAG_PROTECT_AFFECTED))) {
				if (((Parties[eop].TemporaryMult == 0) ||
					 (TypeChart[MoveList[Parties[eop].MoveTempType].Type]
							   [POKEMONDEX[Parties[!eop].Member[0]->Poke]
									.Type1] *
						  TypeChart[MoveList[Parties[eop].MoveTempType].Type]
								   [POKEMONDEX[Parties[!eop].Member[0]->Poke]
										.Type2] <=
					  0)) &&
					CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
							nFLAG_TYPE_IMMUNITY_AFFECTED))
					return;
				if (rand() < RAND_MAX *
								 ((double)MoveList[Parties[eop].Turn->Move]
									  .GNRL_PURPOSE[rs + 1]) /
								 100) {
					if ((StatusImmunity(MoveList[Parties[eop].Turn->Move]
											.GNRL_PURPOSE[rs + 0],
										eop) ||
						 !CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
								  nFLAG_TYPE_IMMUNITY_AFFECTED))) {
						if (MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs] <
								EFFECT_STATUS_MAX &&
							Parties[!eop].Member[0]->Non_Volatile_Status == 0) {
							Parties[!eop].Member[0]->Non_Volatile_Status =
								MoveList[Parties[eop].Turn->Move]
									.GNRL_PURPOSE[rs];
						}
						else {
							if (MoveList[Parties[eop].Turn->Move]
									.GNRL_PURPOSE[rs] == STATE_FLINCH)
								Parties[!eop].Flinch = 1;
							else
								EFFECT_FUNC_LIST
							[MoveList[Parties[eop].Turn->Move]
								 .GNRL_PURPOSE[rs] -
							 EFFECT_STATUS_MAX](EET_INFLICTION, eop);
						}
					}
				}
			}
		}
	}
}

void ProtectingMove(char et, bool eop, bool pos)
{
	unsigned char rs = pos * 5;
	if (et == 1) {
		if (rand() <
			(RAND_MAX / pow(2, Parties[eop].EFFECT_COUNTERS[EFFECT_PROTECT])) +
				1) {
			if (First == !eop) {
				SET_BIT(Parties[eop].EFFECT_FLAGS[0], EFFECT_PROTECT);
				Parties[!eop].DoesNothing = 1;
				Parties[eop].EFFECT_COUNTERS[EFFECT_PROTECT]++;
			}
			else {
				Parties[eop].EFFECT_COUNTERS[EFFECT_PROTECT] = 0;
				TextBoxUpdateFast("But it failed!", 50, 1000);
			}
		}
		else {
			Parties[eop].EFFECT_COUNTERS[EFFECT_PROTECT] = 0;
			TextBoxUpdateFast("But it failed!", 50, 1000);
		}
	}
	else if (et == 5) {
		CLR_BIT(Parties[eop].EFFECT_FLAGS[0], EFFECT_PROTECT);
	}
}

void RoarFunc(char et, bool eop, bool pos)
{
	unsigned char randswitch;
	char rs = pos * 5;
	if (et == 2) {
		if (Parties[!eop].Dead)
			return;
		if (!(CHK_BIT(Parties[!eop].EFFECT_FLAGS[0], EFFECT_PROTECT) &&
			  CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
					  nFLAG_PROTECT_AFFECTED)) &&
			((Parties[!eop].Member[1]->CurrentHp > 0) +
			 (Parties[!eop].Member[2]->CurrentHp > 0) +
			 (Parties[!eop].Member[3]->CurrentHp > 0) +
			 (Parties[!eop].Member[4]->CurrentHp > 0) +
			 (Parties[!eop].Member[5]->CurrentHp > 0))) {
			randswitch =
				1 + (rand() % ((Parties[!eop].Member[1]->CurrentHp > 0) +
							   (Parties[!eop].Member[2]->CurrentHp > 0) +
							   (Parties[!eop].Member[3]->CurrentHp > 0) +
							   (Parties[!eop].Member[4]->CurrentHp > 0) +
							   (Parties[!eop].Member[5]->CurrentHp > 0)));
			while (1) {
				if (Parties[!eop].Member[randswitch]->CurrentHp > 0)
					break;
				randswitch++;
			}
			ResetBoosts(Parties[!eop].Member[0]);
			CLEAR_EFFECTS(!eop);
			CLEAR_EFFECT_COUNTERS(!eop);
			Switch(!eop, randswitch);
			sprintf(TempTextBuffer, "%s was dragged out!\n",
					POKEMONDEX[Parties[!eop].Member[0]->Poke].Name);
			TextBoxUpdateFast(TempTextBuffer, 50, 1000);
			Parties[!eop].Dead = 1;
		}
	}
}

void Hp_Draining_Move(char et, bool eop, bool pos)
{
	int Recovery;
	unsigned char rs = pos * 5;
	if (et == 2) {
		Recovery = Parties[eop].Damage *
				   MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs] / 100;
		if (CHK_BIT(MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs + 1],
					7)) {
			Recovery *= -1;
			if (Recovery + Parties[eop].Member[0]->CurrentHp < 0)
				Recovery = -Parties[eop].Member[0]->CurrentHp;
		}
		else {
			if (Recovery + Parties[eop].Member[0]->CurrentHp >
				Parties[eop].Member[0]->Hp)
				Recovery = Parties[eop].Member[0]->Hp -
						   Parties[eop].Member[0]->CurrentHp;
		}
		Parties[eop].Member[0]->CurrentHp += Recovery;
		if (Recovery > 0) {
			printf("%s%s regained %d hp!\n", EOPTEXT[eop],
				   POKEMONDEX[Parties[eop].Member[0]->Poke].Name, Recovery);
			printf("%s%s is at %d/%d hp\n", EOPTEXT[eop],
				   POKEMONDEX[Parties[eop].Member[0]->Poke].Name,
				   Parties[eop].Member[0]->CurrentHp,
				   Parties[eop].Member[0]->Hp);
		}
		else if (Recovery < 0) {
			printf("%s%s took %d damage as recoil!\n", EOPTEXT[eop],
				   POKEMONDEX[Parties[eop].Member[0]->Poke].Name,
				   Recovery * -1);
			printf("%s%s is at %d/%d hp\n", EOPTEXT[eop],
				   POKEMONDEX[Parties[eop].Member[0]->Poke].Name,
				   Parties[eop].Member[0]->CurrentHp,
				   Parties[eop].Member[0]->Hp);
			if (Parties[eop].Member[0]->CurrentHp <= 0) {
				DisplayDie(eop);
				sprintf(TempTextBuffer, "%s%s fainted!\n", EOPTEXT[eop],
						POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
				TextBoxUpdateFast(TempTextBuffer, 50, 1000);
				SwitchIn(eop);
				Parties[eop].Dead = 1;
			}
		}
		else if (Parties[eop].Member[0]->CurrentHp ==
				 Parties[eop].Member[0]->Hp)
			printf("%s%s is already at full health!\n", EOPTEXT[eop],
				   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
	}
}

void EdgeCase(char et, bool eop, bool pos)
{
	unsigned char rs = pos * 5;
	if (Parties[eop].Turn->Move == Illusion_Field)
		if (et == 2)
			for (int i = 0; i < 8; i++)
				if (rand() <
					RAND_MAX * ((double)MoveList[Parties[eop].Turn->Move]
									.GNRL_PURPOSE[rs] /
								100))
					Boostandprint(i, -12, Parties[!eop].Member[0], !eop);
}

void HealingMove(char et, bool eop, bool pos)
{
	unsigned char rs = pos * 5;
if (et == 1) {
	bool new_eop = MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs] >=
					HEAL_OTHER_STATIC;
	if (new_eop)
		new_eop = !eop;
	else
		new_eop = eop;
	int hp_save = Parties[new_eop].Member[0]->CurrentHp;
	int damage_save = 0;
	switch (MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs] -
			(new_eop != eop) * HEAL_OTHER_STATIC) {
		case HEAL_SELF_STATIC:
			damage_save = *(
				(int16_t*)(MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE +
						   rs + 1));
			break;
		case HEAL_SELF_MAX:
			damage_save =
				(int)(Parties[new_eop].Member[0]->Hp *
				((double)(*((int16_t*)(MoveList[Parties[eop].Turn->Move]
										   .GNRL_PURPOSE +
									   rs + 1))) /
				 10000));
			break;
		case HEAL_SELF_CURRENT:
			damage_save =
				(int)(Parties[new_eop].Member[0]->CurrentHp *
				((double)(*((int16_t*)(MoveList[Parties[eop].Turn->Move]
										   .GNRL_PURPOSE +
									   rs + 1))) /
				 10000));
			break;
		case HEAL_SELF_LOST:
			damage_save =
				(int)((Parties[new_eop].Member[0]->Hp -
				 Parties[new_eop].Member[0]->CurrentHp) *
				((double)((int16_t)MoveList[Parties[eop].Turn->Move]
										   .GNRL_PURPOSE[rs + 1] << 8 | MoveList[Parties[eop].Turn->Move].GNRL_PURPOSE[rs + 2])) /
				 10000);
			break;
		default:
			break;
	}
	int damage_actual = damage_save;
	if (hp_save + damage_actual > Parties[new_eop].Member[0]->Hp)
		damage_actual = Parties[new_eop].Member[0]->Hp - hp_save;
	else if (hp_save + damage_actual < 0)
		damage_actual = -hp_save;
	Parties[new_eop].Member[0]->CurrentHp += damage_actual;
	HealthBar_Anim(eop, Parties[new_eop].Member[0]->CurrentHp, hp_save,
				   -damage_save);
	}
}

mf MOVE_FUNC_LIST[MF_MAX] = {&Nothingf,			&Strugglef,		 &StatMod,
							 &StatusInfliction, &ProtectingMove, &RoarFunc,
							 &Hp_Draining_Move, &EdgeCase,		 &HealingMove};