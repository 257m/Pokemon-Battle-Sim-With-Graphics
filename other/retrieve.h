void RetrieveAIMove(bool eop) {
	unsigned char aimove;
	bool WillSwitch = 0;
	while (1) {
	if (rand() % 10 || ((Parties[eop].Member[1]->CurrentHp > 0) +(Parties[eop].Member[2]->CurrentHp > 0) + (Parties[eop].Member[3]->CurrentHp > 0) + (Parties[eop].Member[4]->CurrentHp > 0) + (Parties[eop].Member[5]->CurrentHp > 0)) == 0) {
      aimove = rand() % 4;
        } else {
        aimove = 1 + (rand() % ((Parties[eop].Member[1]->CurrentHp > 0) +(Parties[eop].Member[2]->CurrentHp > 0) + (Parties[eop].Member[3]->CurrentHp > 0) + (Parties[eop].Member[4]->CurrentHp > 0) + (Parties[eop].Member[5]->CurrentHp > 0)));
            while(1) {
            if (Parties[eop].Member[aimove]->CurrentHp > 0) break;
            aimove++;
            }
					WillSwitch = 1;
        }
	if (!WillSwitch) {
		Parties[eop].Turn = &Parties[eop].Member[0]->Moves[aimove];
		if (Parties[eop].Member[0]->Moves[aimove].Move == Nothing) continue;
		if (Parties[eop].Member[0]->Moves[0].PP && Parties[eop].Member[0]->Moves[1].PP <= 0 && Parties[eop].Member[0]->Moves[2].PP <= 0 && Parties[eop].Member[0]->Moves[3].PP <= 0) {
			Parties[eop].Turn = &Struggle_Slot;
			break;
			}
		if (Parties[eop].Member[0]->Moves[aimove].PP <= 0) continue;
		break;
		} else {
		if (Parties[eop].Member[aimove] == NULL || Parties[eop].Member[aimove]->CurrentHp <= 0) continue;
		Parties[eop].SwitchSave = aimove;
    Parties[eop].Switching = 1;
		break;
	}
		}
}


enum {
ACTION_SELECTION,
MOVE_SELECTION,
};

void RetrieveUserMove(bool eop) {
	unsigned char MoveSelected = 0;
	unsigned char OptionSelect = 0;
	bool Menu = ACTION_SELECTION;
	bool Retrieving = 1;
	bool Done = 0;
	SDL_FlushEvent(SDL_KEYDOWN);
	while(!Done) {
	while(Retrieving) {
		bool UpAndDown = (SDL_GetTicks()/250) % 2;
		while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN) {
							if (event.key.keysym.sym == SDLK_j || event.key.keysym.sym == SDLK_f) {
								if (!Menu) {
									if (OptionSelect == 0) Menu = !Menu;
									else if (OptionSelect == 1) BagViewer(1,eop);
 									else if (OptionSelect == 2) {
										if (PartyViewer(1,eop)) return;
										}
								} else {
									MoveSelected = OptionSelect;
									Retrieving = 0;
								}
							} else if (event.key.keysym.sym == SDLK_k || event.key.keysym.sym == SDLK_g) {
								Menu = ACTION_SELECTION;
							} else if (event.key.keysym.sym == SDLK_n || event.key.keysym.sym == SDLK_v) {
								
							} else if (event.key.keysym.sym == SDLK_m || event.key.keysym.sym == SDLK_b) {
								
							} else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
                if (OptionSelect % 2 == 0) OptionSelect++;
              } else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
                if (OptionSelect % 2) OptionSelect--;
              } else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
                if (OptionSelect > 1) OptionSelect -= 2;
              } else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
                if (OptionSelect < 2) OptionSelect += 2;
              }
							}
        }
        // Draw
        DestRect.x = 0;
        DestRect.y = 0;
        DestRect.w = width;
        DestRect.h = 144;
        SDL_RenderCopy(renderer,Battle_Background,NULL,&DestRect);

        DestRect.x = 128;
        DestRect.y = 96+!UpAndDown;
        DestRect.w = 128;
        DestRect.h = 42;
        SDL_RenderCopy(renderer,HpBar,NULL,&DestRect); // 74,25 | 121,26

        DestRect.x = 201;
        DestRect.y = 120+!UpAndDown;
        DestRect.w = ceil(((double)Parties[0].Member[0]->CurrentHp/Parties[0].Member[0]->Hp)*48);
        DestRect.h = 2;
        if (((double)Parties[0].Member[0]->CurrentHp/Parties[0].Member[0]->Hp) > 0.5) {
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
          } else if (((double)Parties[0].Member[0]->CurrentHp/Parties[0].Member[0]->Hp) > 0.2) {
          SDL_SetRenderDrawColor(renderer,255,255,0,255);
          } else {
          SDL_SetRenderDrawColor(renderer,255,0,0,255);
          }
        SDL_RenderFillRect(renderer,&DestRect);

				sprintf(TempTextBuffer,"%d",Parties[0].Member[0]->CurrentHp);
				drawText(TempTextBuffer,218-(strlen(TempTextBuffer)*5),125+!UpAndDown,255,255,255,SMALL_FONT);

				sprintf(TempTextBuffer,"%d",Parties[0].Member[0]->Hp);
				drawText(TempTextBuffer,225,125+!UpAndDown,255,255,255,SMALL_FONT);

				drawText(str_decompress_format_prealloc(POKEMONDEX[Parties[0].Member[0]->Poke].Name,TempTextBuffer),154,103+!UpAndDown,255,255,255,REGULAR_FONT);

				sprintf(TempTextBuffer,"%d",Parties[0].Member[0]->Level);
				drawText(TempTextBuffer,234,104+!UpAndDown,255,255,255,SECONDARY_FONT);

        DestRect.x = 0;
        DestRect.y = 20;
        DestRect.w = 128;
        DestRect.h = 42;
        SDL_RenderCopy(renderer,EnemyHpBar,NULL,&DestRect); // 50,25 | 97,26

        DestRect.x = 49;
        DestRect.y = 44;
        DestRect.w = ceil(((double)Parties[1].Member[0]->CurrentHp/Parties[1].Member[0]->Hp)*48);
        DestRect.h = 2;
        if (((double)Parties[1].Member[0]->CurrentHp/Parties[1].Member[0]->Hp) > 0.5) {
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
          } else if (((double)Parties[1].Member[0]->CurrentHp/Parties[1].Member[0]->Hp) > 0.2) {
          SDL_SetRenderDrawColor(renderer,255,255,0,255);
          } else {
          SDL_SetRenderDrawColor(renderer,255,0,0,255);
          }
        SDL_RenderFillRect(renderer,&DestRect);

				sprintf(TempTextBuffer,"%d",Parties[1].Member[0]->CurrentHp);
				drawText(TempTextBuffer,66-(strlen(TempTextBuffer)*5),49,255,255,255,SMALL_FONT);

				sprintf(TempTextBuffer,"%d",Parties[1].Member[0]->Hp);
				drawText(TempTextBuffer,73,49,255,255,255,SMALL_FONT);

				drawText(str_decompress_format_prealloc(POKEMONDEX[Parties[1].Member[0]->Poke].Name,TempTextBuffer),2,27,255,255,255,REGULAR_FONT);

				sprintf(TempTextBuffer,"%d",Parties[1].Member[0]->Level);
				drawText(TempTextBuffer,84,28,255,255,255,SECONDARY_FONT);
    
        DestRect.x = 24;
        DestRect.y = 64+UpAndDown;
        DestRect.w = 80;
        DestRect.h = 80;
        SDL_RenderCopy(renderer,Pokemon_Back_Sprites[Parties[0].Member[0]->Poke],NULL,&DestRect);

        DestRect.x = 149;
        DestRect.y = 16+Pokemon_Front_Sprite_Offsets_y[Parties[1].Member[0]->Poke];
        SDL_RenderCopy(renderer,Pokemon_Front_Sprites[Parties[1].Member[0]->Poke],NULL,&DestRect);

        DestRect.x = 0;
        DestRect.y = 144;
        DestRect.w = 256;
        DestRect.h = 48;
        SDL_RenderCopy(renderer,TextBox,NULL,&DestRect);

				if (!Menu) {
				DestRect.x = 138;
				DestRect.y = 146;
				DestRect.w = 116;
		    DestRect.h = 44;
		    drawSelectionBox(&DestRect);
				
				drawText("FIGHT",152,154,0,0,0,REGULAR_FONT);
				drawText("BAG",206,154,0,0,0,REGULAR_FONT);
				drawText("POKEMON",152,172,0,0,0,REGULAR_FONT);
		    drawText("RUN",206,172,0,0,0,REGULAR_FONT);

				DestRect.x = 144+((OptionSelect % 2)*54);
				DestRect.y = 154+((OptionSelect > 1)*18);
				DestRect.w = 8;
		    DestRect.h = 9;
		    SDL_RenderCopy(renderer,Indicator,NULL,&DestRect);
				} else {
				DestRect.x = 186;
				DestRect.y = 146;
				DestRect.w = 68;
				DestRect.h = 44;
				drawSelectionBox(&DestRect);

				DestRect.x = 2;
				DestRect.y = 146;
				DestRect.w = 182;
				DestRect.h = 44;
				drawSelectionBox(&DestRect);

				drawText(str_decompress_format_prealloc(MoveList[Parties[eop].Member[0]->Moves[0].Move].Name,TempTextBuffer),16,155,0,0,0,SMALL_FONT);
				drawText(str_decompress_format_prealloc(MoveList[Parties[eop].Member[0]->Moves[1].Move].Name,TempTextBuffer),105,155,0,0,0,SMALL_FONT);
				drawText(str_decompress_format_prealloc(MoveList[Parties[eop].Member[0]->Moves[2].Move].Name,TempTextBuffer),16,173,0,0,0,SMALL_FONT);
				drawText(str_decompress_format_prealloc(MoveList[Parties[eop].Member[0]->Moves[3].Move].Name,TempTextBuffer),105,173,0,0,0,SMALL_FONT);
				
				sprintf(TempTextBuffer,"PP: %d/%0.f",Parties[eop].Member[0]->Moves[OptionSelect].PP,(MoveList[Parties[eop].Member[0]->Moves[OptionSelect].Move].PP+1) * 5 * ppboostmult(Parties[eop].Member[0]->Moves[OptionSelect].PPmult));
				drawText(TempTextBuffer,192,154,0,0,0,REGULAR_FONT);

				sprintf(TempTextBuffer,"Type: %s",TypeNames[MoveList[Parties[eop].Member[0]->Moves[OptionSelect].Move].Type]);
				drawText(TempTextBuffer,192,172,0,0,0,SMALL_FONT);
					

				DestRect.x = 8+((OptionSelect % 2)*89);
				DestRect.y = 155+((OptionSelect > 1)*18);
				DestRect.w = 8;
		    DestRect.h = 9;
		    SDL_RenderCopy(renderer,Indicator,NULL,&DestRect);
				}
		
        // Show what was drawn
        SDL_RenderPresent(renderer);
	}
    if (MoveSelected < 4) {
      Parties[eop].Turn = &Parties[eop].Member[0]->Moves[MoveSelected];
      if(Parties[eop].Member[0]->Moves[MoveSelected].Move == Nothing) {
				
  } else if (Parties[eop].Member[0]->Moves[MoveSelected].PP <= 0) {
    if (Parties[eop].Member[0]->Moves[0].PP && Parties[eop].Member[0]->Moves[1].PP <= 0 && Parties[eop].Member[0]->Moves[2].PP <= 0 && Parties[eop].Member[0]->Moves[3].PP <= 0) {
      Parties[eop].Turn = &Struggle_Slot;
			}
  } else {
		Done = 1;
	}
    }
      }
	}