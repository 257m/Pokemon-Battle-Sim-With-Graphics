#include "../include/execution.h"
#include "../include/ability.h"
#include "../include/definitions.h"
#include "../include/display.h"
#include "../include/drawing.h"
#include "../include/effects.h"
#include "../include/enumdefs.h"
#include "../include/general.h"
#include "../include/items.h"
#include "../include/moves.h"
#include "../include/offsets.h"
#include "../include/pokemon.h"
#include "../include/sdldef.h"
#include "../include/switching.h"

void Damage_Anim(bool eop, double hp, double initial_hp, int initial_damage)
{
	// Draw
	DestRect.x = 0;
	DestRect.y = 0;
	DestRect.w = width;
	DestRect.h = 144;
	SDL_RenderCopy(renderer, Battle_Background, NULL, &DestRect);

	DestRect.x = 128;
	DestRect.y = 96;
	DestRect.w = 128;
	DestRect.h = 42;
	SDL_RenderCopy(renderer, HpBar, NULL, &DestRect); // 74,25 | 121,26

	drawText(POKEMONDEX[Parties[0].Member[0]->Poke].Name, 154, 103, 255, 255,
			 255, REGULAR_FONT);

	DestRect.x = 201;
	DestRect.y = 120;
	DestRect.w = ceil(
		((double)Parties[0].Member[0]->CurrentHp / Parties[0].Member[0]->Hp) *
		48);
	DestRect.h = 2;
	if (((double)Parties[0].Member[0]->CurrentHp / Parties[0].Member[0]->Hp) >
		0.5) {
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}
	else if (((double)Parties[0].Member[0]->CurrentHp /
			  Parties[0].Member[0]->Hp) > 0.2) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	SDL_RenderFillRect(renderer, &DestRect);

	sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->CurrentHp);
	drawText(TempTextBuffer2, 218 - (strlen(TempTextBuffer2) * 5), 125, 255,
			 255, 255, SMALL_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->Hp);
	drawText(TempTextBuffer2, 225, 125, 255, 255, 255, SMALL_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->Level);
	drawText(TempTextBuffer2, 234, 104, 255, 255, 255, SECONDARY_FONT);

	DestRect.x = 0;
	DestRect.y = 20;
	DestRect.w = 128;
	DestRect.h = 42;
	SDL_RenderCopy(renderer, EnemyHpBar, NULL, &DestRect); // 50,25 | 97,26

	drawText(POKEMONDEX[Parties[1].Member[0]->Poke].Name, 2, 27, 255, 255, 255,
			 REGULAR_FONT);

	DestRect.x = 49;
	DestRect.y = 44;
	DestRect.w = ceil(
		((double)Parties[1].Member[0]->CurrentHp / Parties[1].Member[0]->Hp) *
		48);
	DestRect.h = 2;
	if (((double)Parties[1].Member[0]->CurrentHp / Parties[1].Member[0]->Hp) >
		0.5) {
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}
	else if (((double)Parties[1].Member[0]->CurrentHp /
			  Parties[1].Member[0]->Hp) > 0.2) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	SDL_RenderFillRect(renderer, &DestRect);

	sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->CurrentHp);
	drawText(TempTextBuffer2, 66 - (strlen(TempTextBuffer2) * 5), 49, 255, 255,
			 255, SMALL_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->Hp);
	drawText(TempTextBuffer2, 73, 49, 255, 255, 255, SMALL_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->Level);
	drawText(TempTextBuffer2, 84, 28, 255, 255, 255, SECONDARY_FONT);

	DestRect.x = 24;
	DestRect.y = 64;
	DestRect.w = 80;
	DestRect.h = 80;
	SDL_RenderCopy(renderer, Pokemon_Back_Sprites[Parties[0].Member[0]->Poke],
				   NULL, &DestRect);

	DestRect.x = 149;
	DestRect.y =
		16 + Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke];
	SDL_RenderCopy(renderer, Pokemon_Front_Sprites[Parties[1].Member[0]->Poke],
				   NULL, &DestRect);

	DestRect.x = 49 + (eop * 152);
	DestRect.y = 44 + (eop * 76);
	DestRect.w = ceil(((double)Parties[eop].Member[0]->CurrentHp /
					   Parties[eop].Member[0]->Hp) *
					  48);

	double vx = (double)(initial_damage + 50) / 5;
	SourceRect.x = 201 - (eop * 152);
	SourceRect.y = 120 - (eop * 76);
	DestRect.x = 201 - (eop * 152);
	DestRect.y = 120 - (eop * 76);
	SourceRect.w = 48;
	SourceRect.h = 2;
	DestRect.h = 2;
	thisdraw = SDL_GetTicks();
	bool Anim_running = 1;
	while (Anim_running) {
		lastdraw = thisdraw;
		thisdraw = SDL_GetTicks();
		timesincelastdraw = thisdraw - lastdraw;
		// printf("%d\t%d\t%d\n",hp,initial_hp,initial_damage);
		// Lower hp
		initial_hp -= vx * ((double)timesincelastdraw / 1000);
		// Check to see if anim is done
		if (initial_hp <= hp) {
			// Reset initial to hp just in case it is below
			initial_hp = hp;
			// End loop
			Anim_running = 0;
		}
		// Draw
		DestRect.w =
			ceil(((double)initial_hp / Parties[eop].Member[0]->Hp) * 48);
		SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
		SDL_RenderFillRect(renderer, &SourceRect);
		SDL_SetRenderDrawColor(renderer, 108, 108, 120, 255);
		SDL_RenderFillRect(
			renderer,
			&((const SDL_Rect){46 + (!eop * 152), 49 + (!eop * 76), 20, 8}));
		sprintf(TempTextBuffer2, "%.0f", initial_hp);
		drawText(TempTextBuffer2,
				 66 + (!eop * 152) - (strlen(TempTextBuffer2) * 5),
				 49 + (!eop * 76), 255, 255, 255, SMALL_FONT);
		if ((initial_hp / Parties[eop].Member[0]->Hp) > 0.5) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		}
		else if ((initial_hp / Parties[eop].Member[0]->Hp) > 0.2) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		}
		SDL_RenderFillRect(renderer, &DestRect);
		SDL_RenderPresent(renderer);
		lastframestart = framestart;
		framestart = SDL_GetTicks;
		if (framestart - lastframestart < framedelay) {
			SDL_Delay(framedelay - (framestart - lastframestart));
		}
	}
}

void UDBOG(int* hp, int* damage)
{
	int initial_hp = *hp;
	int initial_damage = *damage;
	if (*hp - *damage < 0)
		*damage = *hp;
	*hp -= *damage;
	Damage_Anim((hp == &Parties[1].Member[0]->CurrentHp), (double)(*hp),
				(double)initial_hp, initial_damage);
}

void UDBOG2(int* hp, double damage, bool eop, unsigned status)
{
	if (*hp - damage < 0)
		damage = *hp;
	*hp -= damage;
	if (status == STATUS_BURN) {
		printf("%s took some damage from its burn!\n",
			   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
	}
	else if (status == STATUS_POISON) {
		printf("%s is hurt by poison!\n",
			   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
	}
	else if (status == STATUS_TOXIC) {
		printf("%s is hurt by poison! (it's badly poisoned)\n",
			   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
	}
	else if (status == ESM + EFFECT_CONFUSION) {
		printf("It hurt itself in its confusion\n");
	}
	printf("%s%s is at %d/%d\n", EOPTEXT[eop],
		   POKEMONDEX[Parties[eop].Member[0]->Poke].Name,
		   Parties[eop].Member[0]->CurrentHp, Parties[eop].Member[0]->Hp);
}

void ExecuteMove(bool eop)
{
	if (!Parties[eop].Dead) {
		if (!Parties[eop].Switching) {
			Parties[eop].Hit =
				(rand() <
				 RAND_MAX *
					 ((double)(MoveList[Parties[eop].Turn->Move].Accuracy *
							   statboostmult(
								   Parties[eop].Member[0]->StatBoosts[5] /
								   statboostmult(Parties[!eop]
													 .Member[0]
													 ->StatBoosts[6]))) /
					  100));
			if (MoveList[Parties[eop].Turn->Move].Accuracy > 100)
				Parties[eop].Hit = 1;
			Parties[eop].Crit =
				rand() % CRIT_CHANCE <
				power2(Parties[eop].Member[0]->StatBoosts[7] +
					   CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
							   nFLAG_HIGH_CRIT));
			if (Parties[eop].Member[0]->Non_Volatile_Status ==
				STATUS_PARALYSIS) {
				Parties[eop].Para = (rand() % 4 == 0);
				if (Parties[eop].Para)
					Parties[eop].CanMove = 0;
			}
			else if (Parties[eop].Member[0]->Non_Volatile_Status ==
						 STATUS_BURN &&
					 MoveList[Parties[eop].Turn->Move].Category == 1)
				Parties[eop].TemporaryMult /= 2;
			else if (Parties[eop].Member[0]->Non_Volatile_Status ==
					 STATUS_SLEEP) {
				if (Parties[eop].Member[0]->Counter == 0) {
					Parties[eop].CanMove = 0;
					Parties[eop].Sleep = 1;
				}
				else {
					if (Parties[eop].Member[0]->Counter > 3) {
						Parties[eop].Sleep = 0;
					}
					else if (map2(rand(), 3, RAND_MAX) < 1) {
						Parties[eop].Sleep = 0;
					}
					else {
						Parties[eop].CanMove = 0;
						Parties[eop].Sleep = 1;
					}
				}
				if (Parties[eop].Sleep)
					Parties[eop].Member[0]->Counter++;
				else {
					Parties[eop].Member[0]->Counter = 0;
					Parties[eop].Member[0]->Non_Volatile_Status = 0;
					printf("%s%s woke up\n", EOPTEXT[eop],
						   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
				}
			}
			else if (Parties[eop].Member[0]->Non_Volatile_Status ==
					 STATUS_FREEZE) {
				Parties[eop].Frozen = (map2(rand(), 5, RAND_MAX) != 0);
				if (Parties[eop].Frozen) {
					Parties[eop].CanMove = 0;
				}
				else {
					Parties[eop].Member[0]->Non_Volatile_Status = 0;
					sprintf(TempTextBuffer, "%s%s thawed out\n", EOPTEXT[eop],
							POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
					TextBoxUpdateFast(TempTextBuffer, 50, 1000);
				}
			}
			if (Parties[eop].Flinch)
				Parties[eop].CanMove = 0;
			ACTIVATE_EFFECTS(EET_PREMOVE, eop);
			MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >> 5](
				3, eop, 0);
			MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
						   REMOVE_FIRST_FIVE_BITS](3, eop, 1);
			display_move(eop);
			Parties[eop].Turn->PP--;
			if (Parties[eop].Member[0]->CurrentHp > 0 && Parties[eop].Hit &&
				Parties[eop].CanMove) {
				if (MoveList[Parties[eop].Turn->Move].Category == 0) {
					ABILITY_FUNC_LIST
					[AbilityList[Parties[eop].Member[0]->Ability].abilityfunc](
						2, eop);
					ABILITY_FUNC_LIST
					[AbilityList[Parties[!eop].Member[0]->Ability].abilityfunc](
						-4, !eop);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >>
								   5](1, eop, 0);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
								   REMOVE_FIRST_FIVE_BITS](1, eop, 1);
					ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item]
									   .itemfunc](1, eop);
					ITEM_FUNC_LIST[ItemList[Parties[!eop].Member[0]->Item]
									   .itemfunc](-1, !eop);
					move_result(eop);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >>
								   5](2, eop, 0);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
								   REMOVE_FIRST_FIVE_BITS](2, eop, 1);
					ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item]
									   .itemfunc](3, eop);
					ITEM_FUNC_LIST[ItemList[Parties[!eop].Member[0]->Item]
									   .itemfunc](-3, !eop);
				}
				else if (MoveList[Parties[eop].Turn->Move].Category == 1) {
					ABILITY_FUNC_LIST
					[AbilityList[Parties[eop].Member[0]->Ability].abilityfunc](
						2, eop);
					ABILITY_FUNC_LIST
					[AbilityList[Parties[!eop].Member[0]->Ability].abilityfunc](
						-4, !eop);
					Parties[eop].Damage = never0(
						((((2 * Parties[eop].Member[0]->Level / 5 + 2) *
						   (Parties[eop].Member[0]->Atk *
							(Parties[eop].Crit &&
									 (Parties[eop].Member[0]->StatBoosts[0] <
									  0) ?
								   1 :
								   statboostmult(
									 Parties[eop].Member[0]->StatBoosts[0]))) *
						   MoveList[Parties[eop].Turn->Move].BP /
						   (Parties[!eop].Member[0]->Def *
							(Parties[eop].Crit &&
									 (Parties[!eop].Member[0]->StatBoosts[1] >
									  0) ?
								   1 :
								   statboostmult(Parties[!eop]
												   .Member[0]
												   ->StatBoosts[1])))) /
						  50) +
						 2) *
						(Parties[eop].STAB *=
						 (Parties[eop].MoveTempType ==
									  POKEMONDEX[Parties[eop].Member[0]->Poke]
										  .Type1 ||
								  Parties[eop].MoveTempType ==
									  POKEMONDEX[Parties[eop].Member[0]->Poke]
										  .Type2 ?
								1.5 :
								1)) *
						(TypeChart[Parties[eop].MoveTempType]
								  [POKEMONDEX[Parties[!eop].Member[0]->Poke]
									   .Type1] *
						 TypeChart[Parties[eop].MoveTempType]
								  [POKEMONDEX[Parties[!eop].Member[0]->Poke]
									   .Type2]) *
						((rand() % 16) + 85) / 100 *
						Parties[eop].TemporaryMult *
						(Parties[eop].Crit ? 1.5 : 1));
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >>
								   5](1, eop, 0);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
								   REMOVE_FIRST_FIVE_BITS](1, eop, 0);
					ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item]
									   .itemfunc](1, eop);
					ITEM_FUNC_LIST[ItemList[Parties[!eop].Member[0]->Item]
									   .itemfunc](-1, !eop);
					if (!(CHK_BIT(Parties[!eop].EFFECT_FLAGS[0],
								  EFFECT_PROTECT) &&
						  CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
								  nFLAG_PROTECT_AFFECTED))) {
						UDBOG(&Parties[!eop].Member[0]->CurrentHp,
							  &Parties[eop].Damage);
					}
					else {
						Parties[eop].Damage = 0;
					}
					move_result(eop);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >>
								   5](2, eop, 0);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
								   REMOVE_FIRST_FIVE_BITS](2, eop, 1);
					ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item]
									   .itemfunc](3, eop);
					ITEM_FUNC_LIST[ItemList[Parties[!eop].Member[0]->Item]
									   .itemfunc](-3, !eop);
				}
				else if (MoveList[Parties[eop].Turn->Move].Category == 2) {
					ABILITY_FUNC_LIST
					[AbilityList[Parties[eop].Member[0]->Ability].abilityfunc](
						2, eop);
					ABILITY_FUNC_LIST
					[AbilityList[Parties[!eop].Member[0]->Ability].abilityfunc](
						-4, !eop);
					Parties[eop].Damage = never0(
						(((((2 * Parties[eop].Member[0]->Level / 5 + 2) *
							(Parties[eop].Member[0]->SpA *
							 (Parties[eop].Crit &&
									  (Parties[eop].Member[0]->StatBoosts[2] <
									   0) ?
									1 :
									statboostmult(
									  Parties[eop].Member[0]->StatBoosts[2]))) *
							MoveList[Parties[eop].Turn->Move].BP /
							(Parties[!eop].Member[0]->SpD *
							 (Parties[eop].Crit &&
									  (Parties[!eop].Member[0]->StatBoosts[3] >
									   0) ?
									1 :
									statboostmult(Parties[!eop]
													.Member[0]
													->StatBoosts[3])))) /
						   50) +
						  2) *
						 (Parties[eop].STAB *=
						  (Parties[eop].MoveTempType ==
									   POKEMONDEX[Parties[eop].Member[0]->Poke]
										   .Type1 ||
								   Parties[eop].MoveTempType ==
									   POKEMONDEX[Parties[eop].Member[0]->Poke]
										   .Type2 ?
								 1.5 :
								 1)) *
						 TypeChart[Parties[eop].MoveTempType]
								  [POKEMONDEX[Parties[!eop].Member[0]->Poke]
									   .Type1] *
						 TypeChart[Parties[eop].MoveTempType]
								  [POKEMONDEX[Parties[!eop].Member[0]->Poke]
									   .Type2] *
						 ((rand() % 16) + 85) / 100) *
						Parties[eop].TemporaryMult *
						(Parties[eop].Crit ? 1.5 : 1));
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >>
								   5](1, eop, 0);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
								   REMOVE_FIRST_FIVE_BITS](1, eop, 1);
					ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item]
									   .itemfunc](1, eop);
					ITEM_FUNC_LIST[ItemList[Parties[!eop].Member[0]->Item]
									   .itemfunc](-1, !eop);
					if (!(CHK_BIT(Parties[!eop].EFFECT_FLAGS[0],
								  EFFECT_PROTECT) &&
						  CHK_BIT(MoveList[Parties[eop].Turn->Move].FLAGS,
								  nFLAG_PROTECT_AFFECTED))) {
						UDBOG(&Parties[!eop].Member[0]->CurrentHp,
							  &Parties[eop].Damage);
					}
					else {
						Parties[eop].Damage = 0;
					}
					move_result(eop);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >>
								   5](2, eop, 0);
					MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
								   REMOVE_FIRST_FIVE_BITS](2, eop, 1);
					ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item]
									   .itemfunc](3, eop);
					ITEM_FUNC_LIST[ItemList[Parties[!eop].Member[0]->Item]
									   .itemfunc](-3, !eop);
				}
			}
		}
		else {
			if (Parties[eop].Member[0]->Non_Volatile_Status == 5)
				Parties[eop].Member[0]->Counter = 0;
			printf("%s, that's enough!\nCome back!\n",
				   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
			ResetBoosts(Parties[eop].Member[0]);
			CLEAR_EFFECTS(eop);
			CLEAR_EFFECT_COUNTERS(eop);
			Switch(eop, Parties[eop].SwitchSave);
			printf("Go! %s!\n", POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
		}
		printf("\n");
	}
}

void endturn(bool eop)
{
	MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >> 5](5, eop, 0);
	MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc &
				   REMOVE_FIRST_FIVE_BITS](5, eop, 1);
	ACTIVATE_EFFECTS(EET_POSTMOVE, eop);
	if (Parties[eop].Member[0]->Non_Volatile_Status == STATUS_BURN) {
		UDBOG2(&Parties[eop].Member[0]->CurrentHp,
			   never0(Parties[eop].Member[0]->Hp / 16), eop, STATUS_BURN);
	}
	else if (Parties[eop].Member[0]->Non_Volatile_Status == STATUS_POISON) {
		UDBOG2(&Parties[eop].Member[0]->CurrentHp,
			   never0(Parties[eop].Member[0]->Hp / 8), eop, STATUS_POISON);
	}
	else if (Parties[eop].Member[0]->Non_Volatile_Status == STATUS_TOXIC) {
		if (Parties[eop].Member[0]->Counter < 16)
			Parties[eop].Member[0]->Counter++;
		UDBOG2(&Parties[eop].Member[0]->CurrentHp,
			   never0(Parties[eop].Member[0]->Hp *
					  ((double)Parties[eop].Member[0]->Counter / 16)),
			   eop, STATUS_TOXIC);
	}
	if (Parties[eop].Member[0]->CurrentHp <= 0) {
		DisplayDie(eop);
		printf("\033[1F%s fainted!\n",
			   POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
		SwitchIn(eop);
		printf("\n");
	}
	else {
		ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item].itemfunc](5, eop);
	}
}