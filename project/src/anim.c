#include "../include/definitions.h"
#include "../include/drawing.h"
#include "../include/offsets.h"
#include "../include/pokemon.h"
#include "../include/queue.h"
#include "../include/sdldef.h"

// function was deprecated a long time ago don't know why I still have not
// deleted it
void UpdateBattle()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw
	lastdraw = thisdraw;
	thisdraw = SDL_GetTicks();
	timesincelastdraw = thisdraw - lastdraw;

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

	sprintf(
		(free_pointers[0] = malloc(4)), "%d", Parties[0].Member[0]->CurrentHp);
	drawText(free_pointers[0], 218 - (strlen(free_pointers[0]) * 5), 125, 255,
		255, 255, SMALL_FONT);
	free(free_pointers[0]);

	sprintf((free_pointers[0] = malloc(4)), "%d", Parties[0].Member[0]->Hp);
	drawText(free_pointers[0], 225, 125, 255, 255, 255, SMALL_FONT);
	free(free_pointers[0]);

	drawText(POKEMONDEX[Parties[0].Member[0]->Poke].Name, 154, 103, 255, 255,
		255, REGULAR_FONT);
	free(free_pointers[0]);

	sprintf((free_pointers[0] = malloc(4)), "%d", Parties[0].Member[0]->Level);
	drawText(free_pointers[0], 234, 104, 255, 255, 255, SECONDARY_FONT);
	free(free_pointers[0]);

	DestRect.x = 0;
	DestRect.y = 20;
	DestRect.w = 128;
	DestRect.h = 42;
	SDL_RenderCopy(renderer, EnemyHpBar, NULL, &DestRect); // 50,25 | 97,26

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

	sprintf(
		(free_pointers[0] = malloc(4)), "%d", Parties[1].Member[0]->CurrentHp);
	drawText(free_pointers[0], 66 - (strlen(free_pointers[0]) * 5), 49, 255,
		255, 255, SMALL_FONT);
	free(free_pointers[0]);

	sprintf((free_pointers[0] = malloc(4)), "%d", Parties[1].Member[0]->Hp);
	drawText(free_pointers[0], 73, 49, 255, 255, 255, SMALL_FONT);
	free(free_pointers[0]);

	drawText((free_pointers[0] = POKEMONDEX[Parties[1].Member[0]->Poke].Name),
		2, 27, 255, 255, 255, REGULAR_FONT);
	free(free_pointers[0]);

	sprintf((free_pointers[0] = malloc(4)), "%d", Parties[1].Member[0]->Level);
	drawText(free_pointers[0], 84, 28, 255, 255, 255, SECONDARY_FONT);
	free(free_pointers[0]);

	DestRect.x = 24;
	DestRect.y = 64;
	DestRect.w = 80;
	DestRect.h = 80;
	SDL_RenderCopy(renderer, Pokemon_Back_Sprites[Parties[0].Member[0]->Poke],
		NULL, &DestRect);

	DestRect.x = 149;
	DestRect.y =
		16 + Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke];
	DestRect.w = 80;
	DestRect.h = 80;
	SDL_RenderCopy(renderer, Pokemon_Front_Sprites[Parties[1].Member[0]->Poke],
		NULL, &DestRect);

	DestRect.x = 0;
	DestRect.y = 144;
	DestRect.w = width;
	DestRect.h = 48;
	SDL_RenderCopy(renderer, TextBox, NULL, &DestRect);

	// Show what was drawn
	SDL_RenderPresent(renderer);
}

void DisplayDie(bool eop)
{
	Entity TempEntity = {0, 0, 0, 4};
	while (TempEntity.y < 80) {

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Draw
		lastdraw = thisdraw;
		thisdraw = SDL_GetTicks();
		timesincelastdraw = thisdraw - lastdraw;

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

		DestRect.x = 201;
		DestRect.y = 120;
		DestRect.w = ceil(((double)Parties[0].Member[0]->CurrentHp /
							  Parties[0].Member[0]->Hp) *
			48);
		DestRect.h = 2;
		if (((double)Parties[0].Member[0]->CurrentHp /
				Parties[0].Member[0]->Hp) > 0.5) {
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

		sprintf((free_pointers[0] = malloc(4)), "%d",
			Parties[0].Member[0]->CurrentHp);
		drawText(free_pointers[0], 218 - (strlen(free_pointers[0]) * 5), 125,
			255, 255, 255, SMALL_FONT);
		free(free_pointers[0]);

		sprintf((free_pointers[0] = malloc(4)), "%d", Parties[0].Member[0]->Hp);
		drawText(free_pointers[0], 225, 125, 255, 255, 255, SMALL_FONT);
		free(free_pointers[0]);

		drawText(POKEMONDEX[Parties[0].Member[0]->Poke].Name, 154, 103, 255,
			255, 255, REGULAR_FONT);

		sprintf(
			(free_pointers[0] = malloc(4)), "%d", Parties[0].Member[0]->Level);
		drawText(free_pointers[0], 234, 104, 255, 255, 255, SECONDARY_FONT);
		free(free_pointers[0]);

		DestRect.x = 0;
		DestRect.y = 20;
		DestRect.w = 128;
		DestRect.h = 42;
		SDL_RenderCopy(renderer, EnemyHpBar, NULL, &DestRect); // 50,25 | 97,26

		DestRect.x = 49;
		DestRect.y = 44;
		DestRect.w = ceil(((double)Parties[1].Member[0]->CurrentHp /
							  Parties[1].Member[0]->Hp) *
			48);
		DestRect.h = 2;
		if (((double)Parties[1].Member[0]->CurrentHp /
				Parties[1].Member[0]->Hp) > 0.5) {
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

		sprintf((free_pointers[0] = malloc(4)), "%d",
			Parties[1].Member[0]->CurrentHp);
		drawText(free_pointers[0], 66 - (strlen(free_pointers[0]) * 5), 49, 255,
			255, 255, SMALL_FONT);
		free(free_pointers[0]);

		sprintf((free_pointers[0] = malloc(4)), "%d", Parties[1].Member[0]->Hp);
		drawText(free_pointers[0], 73, 49, 255, 255, 255, SMALL_FONT);
		free(free_pointers[0]);

		drawText(POKEMONDEX[Parties[1].Member[0]->Poke].Name, 2, 27, 255, 255,
			255, REGULAR_FONT);

		sprintf(
			(free_pointers[0] = malloc(4)), "%d", Parties[1].Member[0]->Level);
		drawText(free_pointers[0], 84, 28, 255, 255, 255, SECONDARY_FONT);
		free(free_pointers[0]);

		if (eop) {
			DestRect.x = 24;
			DestRect.y = 64;
			DestRect.w = 80;
			DestRect.h = 80;
			SDL_RenderCopy(renderer,
				Pokemon_Back_Sprites[Parties[0].Member[0]->Poke], NULL,
				&DestRect);

			TempEntity.y += TempEntity.vy;

			DestRect.x = 149;
			DestRect.y = 16 +
				Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke] +
				TempEntity.y;
			DestRect.w = 80;
			DestRect.h = 80 - TempEntity.y;
			SourceRect.x = 0;
			SourceRect.y = 0;
			SourceRect.w = 80;
			SourceRect.h = 80 - TempEntity.y;
			SDL_RenderCopy(renderer,
				Pokemon_Front_Sprites[Parties[1].Member[0]->Poke], &SourceRect,
				&DestRect);
		}
		else {
			TempEntity.y += TempEntity.vy;

			DestRect.x = 24;
			DestRect.y = 64 + TempEntity.y;
			DestRect.w = 80;
			DestRect.h = 80 - TempEntity.y;
			SourceRect.x = 0;
			SourceRect.y = 0;
			SourceRect.w = 80;
			SourceRect.h = 80 - TempEntity.y;
			SDL_RenderCopy(renderer,
				Pokemon_Back_Sprites[Parties[0].Member[0]->Poke], &SourceRect,
				&DestRect);

			DestRect.x = 149;
			DestRect.y =
				16 + Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke];
			DestRect.w = 80;
			DestRect.h = 80;
			SDL_RenderCopy(renderer,
				Pokemon_Front_Sprites[Parties[1].Member[0]->Poke], NULL,
				&DestRect);
		}

		DestRect.x = 0;
		DestRect.y = 144;
		DestRect.w = width;
		DestRect.h = 48;
		SDL_RenderCopy(renderer, TextBox, NULL, &DestRect);

		// Show what was drawn
		SDL_RenderPresent(renderer);
	}
}