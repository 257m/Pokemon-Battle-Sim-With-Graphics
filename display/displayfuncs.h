void TextBoxUpdate(char *text, unsigned int character_delay, unsigned int pause)
{
	bool Updating = 1;
	// unsigned int last_frame,this_frame;
	while (Updating) {
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

		sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->CurrentHp);
		drawText(TempTextBuffer2, 218 - (strlen(TempTextBuffer2) * 5), 125, 255,
			255, 255, SMALL_FONT);

		sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->Hp);
		drawText(TempTextBuffer2, 225, 125, 255, 255, 255, SMALL_FONT);

		drawText(POKEMONDEX[Parties[0].Member[0]->Poke].Name,
		154, 103, 255, 255, 255, REGULAR_FONT);

		sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->Level);
		drawText(TempTextBuffer2, 234, 104, 255, 255, 255, SECONDARY_FONT);

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

		sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->CurrentHp);
		drawText(TempTextBuffer2, 66 - (strlen(TempTextBuffer2) * 5), 49, 255,
			255, 255, SMALL_FONT);

		sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->Hp);
		drawText(TempTextBuffer2, 73, 49, 255, 255, 255, SMALL_FONT);

		drawText(POKEMONDEX[Parties[1].Member[0]->Poke].Name,2, 27, 255, 255, 255, REGULAR_FONT);

		sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->Level);
		drawText(TempTextBuffer2, 84, 28, 255, 255, 255, SECONDARY_FONT);

		DestRect.w = 80;
		DestRect.h = 80;

		if (Parties[0].Member[0]->CurrentHp > 0) {
			DestRect.x = 24;
			DestRect.y = 64;
			SDL_RenderCopy(renderer,
				Pokemon_Back_Sprites[Parties[0].Member[0]->Poke], NULL,
				&DestRect);
		}
		if (Parties[1].Member[0]->CurrentHp > 0) {
			DestRect.x = 149;
			DestRect.y =
				16 + Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke];
			SDL_RenderCopy(renderer,
				Pokemon_Front_Sprites[Parties[1].Member[0]->Poke], NULL,
				&DestRect);
		}

		DestRect.x = 0;
		DestRect.y = 144;
		DestRect.w = 256;
		DestRect.h = 48;
		SDL_RenderCopy(renderer, TextBox, NULL, &DestRect);

		if (!drawScrollingText(
				text, 12, 152, 0, 0, 0, REGULAR_FONT, character_delay)) {
			SDL_RenderPresent(renderer);
			SDL_Delay(pause);
			return;
		}

		// Show what was drawn
		SDL_RenderPresent(renderer);
		// last_frame = this_frame;
		// this_frame = SDL_GetTicks();
		// printf("Latency: %d\n",this_frame-last_frame);
	}
}

void TextBoxUpdateFast(
	char *text, unsigned int character_delay, unsigned int pause)
{
	// unsigned int last_frame,this_frame;
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

	drawText(POKEMONDEX[Parties[0].Member[0]->Poke].Name, 154, 103, 255, 255, 255, REGULAR_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[0].Member[0]->Level);
	drawText(TempTextBuffer2, 234, 104, 255, 255, 255, SECONDARY_FONT);

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

	sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->CurrentHp);
	drawText(TempTextBuffer2, 66 - (strlen(TempTextBuffer2) * 5), 49, 255, 255,
		255, SMALL_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->Hp);
	drawText(TempTextBuffer2, 73, 49, 255, 255, 255, SMALL_FONT);

	drawText(POKEMONDEX[Parties[1].Member[0]->Poke].Name, 2, 27, 255, 255, 255, REGULAR_FONT);

	sprintf(TempTextBuffer2, "%d", Parties[1].Member[0]->Level);
	drawText(TempTextBuffer2, 84, 28, 255, 255, 255, SECONDARY_FONT);

	DestRect.w = 80;
	DestRect.h = 80;

	if (Parties[0].Member[0]->CurrentHp > 0) {
		DestRect.x = 24;
		DestRect.y = 64;
		SDL_RenderCopy(renderer,
			Pokemon_Back_Sprites[Parties[0].Member[0]->Poke], NULL, &DestRect);
	}

	if (Parties[1].Member[0]->CurrentHp > 0) {
		DestRect.x = 149;
		DestRect.y =
			16 + Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke];
		SDL_RenderCopy(renderer,
			Pokemon_Front_Sprites[Parties[1].Member[0]->Poke], NULL, &DestRect);
	}

	DestRect.x = 0;
	DestRect.y = 144;
	DestRect.w = 256;
	DestRect.h = 48;
	SDL_RenderCopy(renderer, TextBox, NULL, &DestRect);

	int i;
	char character;
	int x = 12;
	int y = 154;
	SDL_Rect *glyph, dest;

	SDL_SetTextureColorMod(fontTextures[REGULAR_FONT], 0, 0, 0);

	i = 0;

	character = text[i++];

	unsigned int textlength = strlen(text) + 1;
	unsigned int start_time = SDL_GetTicks();
	dest.x = x;
	dest.y = y;
	while (i < textlength) {
		glyph = &glyphs[REGULAR_FONT][character];

		dest.w = glyph->w;
		dest.h = glyph->h;

		if ((i * character_delay) > (SDL_GetTicks() - start_time))
			SDL_Delay((i * character_delay) - (SDL_GetTicks() - start_time));
		SDL_RenderCopy(renderer, fontTextures[REGULAR_FONT], glyph, &dest);

		SDL_RenderPresent(renderer);
		// last_frame = this_frame;
		// this_frame = SDL_GetTicks();
		// printf("Latency: %d\n",this_frame-last_frame);

		dest.x += glyph->w;
		if (dest.x > 236) {
			dest.y += 20;
			dest.x = x;
		}

		character = text[i++];
	}
	SDL_Delay(pause);
}

void display_move(bool eop)
{
	if (Parties[eop].CanMove) {
		sprintf(TempTextBuffer, "%s%s used %s!", EOPTEXT[eop],POKEMONDEX[Parties[eop].Member[0]->Poke].Name,MoveList[Parties[eop].Turn->Move].Name);
		TextBoxUpdateFast(TempTextBuffer, 50, 1000);
		if (!Parties[eop].Hit)
			TextBoxUpdateFast("But it missed!", 50, 1000);
	}
	else if (!Parties[eop].Confused) {
		sprintf(TempTextBuffer, "%s%s couldn't move",EOPTEXT[eop],POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
		TextBoxUpdateFast(TempTextBuffer, 50, 1000);
		if (Parties[eop].Flinch)
			TextBoxUpdateFast("It flinched!", 50, 1000);
		else if (Parties[eop].Para)
			TextBoxUpdateFast("It was paralyzed!", 50, 1000);
		else if (Parties[eop].Sleep)
			TextBoxUpdateFast("It is asleep", 50, 1000);
		else if (Parties[eop].Frozen)
			TextBoxUpdateFast("It is frozen!", 50, 1000);
	}
}

void move_result(bool eop)
{
	if (Parties[eop].Hit && Parties[eop].CanMove) {
		if (MoveList[Parties[eop].Turn->Move].Category != 0) {
			if (Parties[eop].Damage > 0) {
				printf("It did %d damage!\n", Parties[eop].Damage);
				if (TypeChart[Parties[eop].MoveTempType]
							 [POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1] *
						TypeChart[Parties[eop].MoveTempType]
								 [POKEMONDEX[Parties[!eop].Member[0]->Poke]
										 .Type2] >=
					2) {
					TextBoxUpdateFast("It's super effective!", 50, 1000);
				}
				else if (TypeChart[Parties[eop].MoveTempType]
								  [POKEMONDEX[Parties[!eop].Member[0]->Poke]
										  .Type1] *
						TypeChart[Parties[eop].MoveTempType]
								 [POKEMONDEX[Parties[!eop].Member[0]->Poke]
										 .Type2] <=
					0.5) {
					if (TypeChart[Parties[eop].MoveTempType]
								 [POKEMONDEX[Parties[!eop].Member[0]->Poke]
										 .Type1] *
							TypeChart[Parties[eop].MoveTempType]
									 [POKEMONDEX[Parties[!eop].Member[0]->Poke]
											 .Type2] <=
						0) {
						sprintf(TempTextBuffer, "It dosen't affect %s",POKEMONDEX[Parties[!eop].Member[0]->Poke].Name);
						TextBoxUpdateFast(TempTextBuffer, 50, 1000);
					}
					else
						TextBoxUpdateFast(
							"It's not very effective...", 50, 1000);
				}
				if (Parties[eop].Crit && Parties[eop].Damage > 0)
					TextBoxUpdateFast("It was a critical hit!", 50, 1000);
			}
			else {
				if (CHK_BIT(Parties[!eop].EFFECT_FLAGS[0], EFFECT_PROTECT)) {
					sprintf(TempTextBuffer, "%s%s protected itself!",
						EOPTEXT[!eop],POKEMONDEX[Parties[!eop].Member[0]->Poke].Name);
					TextBoxUpdateFast(TempTextBuffer, 50, 1000);
				}
				else {
					sprintf(TempTextBuffer, "It had no effect on %s%s...",
						EOPTEXT[!eop + 2],
						POKEMONDEX[Parties[!eop].Member[0]->Poke].Name);
					TextBoxUpdateFast(TempTextBuffer, 50, 1000);
				}
			}
			printf("%s%s is at %d/%d hp\n", EOPTEXT[!eop],
					POKEMONDEX[Parties[!eop].Member[0]->Poke].Name,
				Parties[!eop].Member[0]->CurrentHp,
				Parties[!eop].Member[0]->Hp);
		}
	}

	if (Parties[!eop].Member[0]->CurrentHp <= 0) {
		DisplayDie(!eop);
		sprintf(TempTextBuffer, "%s%s fainted!", EOPTEXT[!eop],POKEMONDEX[Parties[!eop].Member[0]->Poke].Name);
		TextBoxUpdateFast(TempTextBuffer, 50, 1000);
		SwitchIn(!eop);
		Parties[!eop].Dead = 1;
	}
}