void endturn(bool eop) {
    MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc >> 5](5,eop,0);
    MOVE_FUNC_LIST[MoveList[Parties[eop].Turn->Move].movefunc & REMOVE_FIRST_FIVE_BITS](5,eop,1);
    if (((unsigned char)MoveList[Parties[eop].Turn->Move].movefunc >> 5 != MF_PROTECT) && ((~MoveList[Parties[eop].Turn->Move].movefunc & REMOVE_FIRST_FIVE_BITS) != MF_PROTECT)) Parties[eop].EFFECT_COUNTERS[EFFECT_PROTECT] = 0; 
    if (Parties[eop].Member[0]->Non_Volatile_Status == STATUS_BURN) {
        UDBOG2(&Parties[eop].Member[0]->CurrentHp,never0(Parties[eop].Member[0]->Hp/16),eop,STATUS_BURN);
      } else if (Parties[eop].Member[0]->Non_Volatile_Status == STATUS_POISON) {
        UDBOG2(&Parties[eop].Member[0]->CurrentHp,never0(Parties[eop].Member[0]->Hp/8),eop,STATUS_POISON);
      } else if (Parties[eop].Member[0]->Non_Volatile_Status == STATUS_TOXIC) {
        if (Parties[eop].Member[0]->Counter < 16) Parties[eop].Member[0]->Counter++;
        UDBOG2(&Parties[eop].Member[0]->CurrentHp,never0(Parties[eop].Member[0]->Hp*((double)Parties[eop].Member[0]->Counter/16)),eop,STATUS_TOXIC);
      }
      if (Parties[eop].Member[0]->CurrentHp <= 0) {
        DisplayDie(eop);
        printf("\033[1F%s fainted!\n",str_decompress_and_format_free(POKEMONDEX[Parties[eop].Member[0]->Poke].Name));
        SwitchIn(eop);
        printf("\n");
      } else {
      ITEM_FUNC_LIST[ItemList[Parties[eop].Member[0]->Item].itemfunc](5,eop);
      }
}