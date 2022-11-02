void PokemonViewer(bool InBattle,bool eop,unsigned char PartyMember) {
}

int PartyViewer(char InBattle,bool eop) {
	bool Viewing = 1;
	unsigned char OptionSelect = 0;
	bool SelectionOpen = 0;
	unsigned SelectionAction = 0;
	while (Viewing) {
		while(SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_j || event.key.keysym.sym == SDLK_f) {
					if (!SelectionOpen) {
					if (OptionSelect == 6) { 
						if (InBattle != 2) {
							Viewing = 0;
							}
						}
						else {
							SelectionOpen = 1;
							}
						} else {
						if (SelectionAction == 0) {
							if (OptionSelect != 0 && Parties[eop].Member[OptionSelect]->CurrentHp) {
							if (InBattle == 1) {
							Parties[eop].SwitchSave = OptionSelect;
							Parties[eop].Switching = 1;
							return 1;
								} else {
								ResetBoosts(Parties[eop].Member[0]);
            		CLEAR_EFFECTS(eop);
            		CLEAR_EFFECT_COUNTERS(eop);
								Switch(eop,OptionSelect);
								return 1;
								}
								}
						}
						}
				} else if (event.key.keysym.sym == SDLK_k || event.key.keysym.sym == SDLK_g) {
					if (!SelectionOpen) {
						if (InBattle != 2)
							Viewing = 0;
						}
					else {
						SelectionOpen = 0;
						SelectionAction = 0;
						}
				} else if (event.key.keysym.sym == SDLK_n || event.key.keysym.sym == SDLK_v) {

				} else if (event.key.keysym.sym == SDLK_m || event.key.keysym.sym == SDLK_b) {
								
				} else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
        	if (!SelectionOpen) {
					if (OptionSelect != 6)
						if (Parties[eop].Member[OptionSelect+1] != NULL)
							OptionSelect++;
						else OptionSelect = 6;
						}
					else {
					OptionSelect = 5;
					while (Parties[eop].Member[OptionSelect] == NULL) {
						OptionSelect--;
					}
						}
						} else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
					if (!SelectionOpen) {
					if (OptionSelect != 6) {
						if (OptionSelect % 2)
							OptionSelect--;
						}
					else {
					OptionSelect = 5;
					while (Parties[eop].Member[OptionSelect] == NULL) {
						OptionSelect--;
					}
						}
						}
        } else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
          if (!SelectionOpen) {
					if (OptionSelect != 6) {
						if (OptionSelect > 1) OptionSelect -= 2;
					}
					else {
						OptionSelect = 5;
						while (Parties[eop].Member[OptionSelect] == NULL)
							OptionSelect--;
					}
						} else {
						if (SelectionAction > 0) SelectionAction--;
						}
        } else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
         	if (!SelectionOpen) {
					if (OptionSelect != 6)
						if (OptionSelect < 4 && Parties[eop].Member[OptionSelect+2] != NULL)
							OptionSelect += 2;
						else OptionSelect = 6;
					else {
					OptionSelect = 5;
					while (Parties[eop].Member[OptionSelect] == NULL)
						OptionSelect--;
						}
        }  else {
					if (SelectionAction < 1) SelectionAction++;
					}
					}
				} 
			}
		
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

		DestRect.x = 57;
		DestRect.y = 25;
		DestRect.h = 5;
		SourceRect.x = 3;
		SourceRect.y = 2;
		SourceRect.w = 124;
		SourceRect.h = 46;
		for (int j = 0;j < 2;j++) {
	  for (int i = 0;i < 3;i++) {
			if (Parties[eop].Member[(i*2)+j] != NULL) {
			SDL_RenderCopy(renderer,PartyTile,NULL,&SourceRect);
			drawText(str_decompress_format_prealloc(POKEMONDEX[Parties[eop].Member[(i*2)+j]->Poke].Name,TempTextBuffer),SourceRect.x+40,SourceRect.y+6,255,255,255,REGULAR_FONT);
			sprintf(TempTextBuffer,"Lvl %d",Parties[eop].Member[(i*2)+j]->Level);
			drawText(TempTextBuffer,SourceRect.x+4,SourceRect.y+34,255,255,255,SMALL_FONT);
			sprintf(TempTextBuffer,"/%d",Parties[eop].Member[(i*2)+j]->Hp);
			drawText(TempTextBuffer,SourceRect.x+78,SourceRect.y+34,255,255,255,SMALL_FONT);
			sprintf(TempTextBuffer,"%d",Parties[eop].Member[(i*2)+j]->CurrentHp);
			drawText(TempTextBuffer,SourceRect.x+78-(strlen(TempTextBuffer)*5),SourceRect.y+34,255,255,255,SMALL_FONT);
			if (((double)Parties[eop].Member[(i*2)+j]->CurrentHp/Parties[eop].Member[(i*2)+j]->Hp) > 0.5) {
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
          } else if (((double)Parties[eop].Member[(i*2)+j]->CurrentHp/Parties[eop].Member[(i*2)+j]->Hp) > 0.2) {
          SDL_SetRenderDrawColor(renderer,255,255,0,255);
          } else {
          SDL_SetRenderDrawColor(renderer,255,0,0,255);
          }
			DestRect.w = ceil(((double)Parties[eop].Member[(i*2)+j]->CurrentHp/Parties[eop].Member[(i*2)+j]->Hp)*62);
			SDL_RenderFillRect(renderer,&DestRect);
				}
			DestRect.y += 48;
			SourceRect.y += 48;
		}
			DestRect.x = 183;
			DestRect.y = 25;
			SourceRect.x = 129;
			SourceRect.y = 2;
		}

		if (OptionSelect != 6) {
		DestRect.x = ((OptionSelect % 2)*126)+3;
		DestRect.y = ((OptionSelect / 2)*48)+2;
		DestRect.w = 124;
		DestRect.h = 46;
		SDL_SetRenderDrawColor(renderer,255,0,0,255);
		SDL_RenderDrawRect(renderer,&DestRect);
		}
		else {
		DestRect.x = 170;
		DestRect.y = 170;
		DestRect.w = 62;
		DestRect.h = 23;
		SDL_SetRenderDrawColor(renderer,255,0,0,255);
		SDL_RenderDrawRect(renderer,&DestRect);
		}

		if (SelectionOpen) {
			DestRect.x = 184;
			DestRect.y = 144;
			DestRect.w = 72;
			DestRect.h = 48;
			drawSelectionBox(&DestRect);
			drawText("Shift",204,153,0,0,0,REGULAR_FONT);
			drawText("Summary",204,171,0,0,0,REGULAR_FONT);
			DestRect.x = 196;
			DestRect.y = 153+(SelectionAction*18);
			DestRect.w = 8;
			DestRect.h = 9;
			SDL_RenderCopy(renderer,Indicator,NULL,&DestRect);
		}

		// Show what was drawn
    SDL_RenderPresent(renderer);
	}
	return 0;
}

void BagViewer(bool InBattle,bool eop) {
}


void displaymember(unsigned int PartyMember,bool eop) {
    printf("\e[1;37mP%d:\e[0m\n",PartyMember+1);
    printf("Pokemon: %s\n",str_decompress_and_format_free(POKEMONDEX[Parties[eop].Member[PartyMember]->Poke].Name));
    printf("Level: %d\n",Parties[eop].Member[PartyMember]->Level);
    printf("Health: %d/%d\n",Parties[eop].Member[PartyMember]->CurrentHp,Parties[eop].Member[PartyMember]->Hp);
    printf("Attack: %d\n",Parties[eop].Member[PartyMember]->Atk);
    printf("Defense: %d\n",Parties[eop].Member[PartyMember]->Def);
    printf("Special Attack: %d\n",Parties[eop].Member[PartyMember]->SpA);
    printf("Special Defense: %d\n",Parties[eop].Member[PartyMember]->SpD);
    printf("Speed: %d\n",Parties[eop].Member[PartyMember]->Spe);
    printf("Nature: %s\n",NATURE_LIST[Parties[eop].Member[PartyMember]->Nature].NatureName);
    printf("Move 1: %s %d/%.0f\n",str_decompress_and_format_free(MoveList[Parties[eop].Member[PartyMember]->Moves[0].Move].Name),Parties[eop].Member[PartyMember]->Moves[0].PP,(MoveList[Parties[eop].Member[PartyMember]->Moves[0].Move].PP+1) * 5 * ppboostmult(Parties[eop].Member[PartyMember]->Moves[0].PPmult));
    printf("Move 2: %s %d/%.0f\n",str_decompress_and_format_free(MoveList[Parties[eop].Member[PartyMember]->Moves[1].Move].Name),Parties[eop].Member[PartyMember]->Moves[1].PP,(MoveList[Parties[eop].Member[PartyMember]->Moves[1].Move].PP+1) * 5 * ppboostmult(Parties[eop].Member[PartyMember]->Moves[1].PPmult));
    printf("Move 3: %s %d/%.0f\n",str_decompress_and_format_free(MoveList[Parties[eop].Member[PartyMember]->Moves[2].Move].Name),Parties[eop].Member[PartyMember]->Moves[2].PP,(MoveList[Parties[eop].Member[PartyMember]->Moves[2].Move].PP+1) * 5 * ppboostmult(Parties[eop].Member[PartyMember]->Moves[2].PPmult));
    printf("Move 4: %s %d/%.0f\n",str_decompress_and_format_free(MoveList[Parties[eop].Member[PartyMember]->Moves[3].Move].Name),Parties[eop].Member[PartyMember]->Moves[3].PP,(MoveList[Parties[eop].Member[PartyMember]->Moves[3].Move].PP+1) * 5 * ppboostmult(Parties[eop].Member[PartyMember]->Moves[3].PPmult));
    printf("Item: %s (%s)\n",ItemList[Parties[eop].Member[PartyMember]->Item].Name,Itemtext[Parties[eop].Member[PartyMember]->ItemUsable]);
    printf("Ability: %s\n",AbilityList[Parties[eop].Member[PartyMember]->Ability].Name);
    printf("Status: %s\n",Statusnames[Parties[eop].Member[PartyMember]->Non_Volatile_Status]);
    printf("IVs: %d %d %d %d %d %d\n",Parties[eop].Member[PartyMember]->IVHp,Parties[eop].Member[PartyMember]->IVAtk,Parties[eop].Member[PartyMember]->IVDef,Parties[eop].Member[PartyMember]->IVSpA,Parties[eop].Member[PartyMember]->IVSpD,Parties[eop].Member[PartyMember]->IVSpe);
   printf("EVs: %d %d %d %d %d %d\n",Parties[eop].Member[PartyMember]->EVS[Hp],Parties[eop].Member[PartyMember]->EVS[Atk],Parties[eop].Member[PartyMember]->EVS[Def],Parties[eop].Member[PartyMember]->EVS[SpA],Parties[eop].Member[PartyMember]->EVS[SpD],Parties[eop].Member[PartyMember]->EVS[Spe]);
  printf("\e[?25l");
  system ("/bin/stty raw");
  system ("/bin/stty -echo");
  getchar();
  system ("/bin/stty echo");
  system ("/bin/stty cooked");
  printf("\e[?25h");
  printf("\033[2K\r");
  for (int i = 0;i < 20;i++) {
      printf("\033[1A");
      printf("\033[2K");
        }
}

void displayparty(bool eop) {
  for (int i = 0;i < 6;i++) {   
printf("\e[1;37mP%d:\e[0m %s\r\t\t\t\t\033[1CLvl:%d\t\033[1CHp:%d/%d\n",i+1,str_decompress_and_format_free(POKEMONDEX[Parties[eop].Member[i]->Poke].Name),Parties[eop].Member[i]->Level,Parties[eop].Member[i]->CurrentHp,Parties[eop].Member[i]->Hp);
    }
      printf("\nPartyMember: ");
      fgets(TextBuffer,31,stdin);
      TextBuffer[strcspn(TextBuffer, "\n")] = 0;
      for (int i = 0;i < 8;i++) {
      printf("\033[1A");
      printf("\033[2K");
        }
      if (TextBuffer[1] > 48 && TextBuffer[1] < 55) {
        displaymember(TextBuffer[1]-49,eop);
        printf("\n");
        }
}