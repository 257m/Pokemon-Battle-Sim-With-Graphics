void NoAbilityf(char et,bool eop) {
}

void TypeBasedBoost(char et,bool eop) {
  if (et == 1) {
  if (AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[0] == Parties[eop].MoveTempType) {
  if (Parties[eop].Member[0]->CurrentHp <= (Parties[eop].Member[0]->Hp/AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1])) {
    Parties[eop].TemporaryMult *= 1.5;
  }
    }
    }
}

void StatDecreaseImmunity(char et,bool eop) {
}

void TypeChange(char et,bool eop) {
	#define TypeChangeSecondType ((AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[0] & 31) << 2) + (AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1] >> 6)
	if (et == 2) {
		if (Parties[eop].MoveTempType != AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[0] >> 3)
			return;
		if (CHK_BIT(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1],5)) {
				Parties[eop].TemporaryMult *= TypeChart[TypeChangeSecondType][POKEMONDEX[Parties[!eop].Member[0]->Poke].Type1] * TypeChart[TypeChangeSecondType][POKEMONDEX[Parties[!eop].Member[0]->Poke].Type2];
			if (POKEMONDEX[Parties[eop].Member[0]->Poke].Type1 == TypeChangeSecondType || POKEMONDEX[Parties[eop].Member[0]->Poke].Type2 == TypeChangeSecondType)
					Parties[eop].TemporaryMult *= 1.5;
    	}
		else {
			Parties[eop].MoveTempType = TypeChangeSecondType;
		}
		Parties[eop].TemporaryMult *= 1 + (((double)((((unsigned char)(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1] << 3)) >> 3)))/20);
  }
	#undef TypeChangeSecondType
}

void TypeImmunity(char et,bool eop) {
  int boost = 0;
  if (et == -4) {
    if ((Parties[!eop].MoveTempType == ((unsigned char)(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[0] >> 3))) && MoveList[Parties[!eop].Turn->Move].Category != 0 && CHK_BIT(MoveList[Parties[!eop].Turn->Move].FLAGS,nFLAG_TYPE_IMMUNITY_AFFECTED)) {
      
      Parties[!eop].TemporaryMult = 0;
      
      if (((unsigned char)(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[0] << 5)) >> 5 == 1) {
        if ((Parties[eop].Member[0]->CurrentHp + Parties[eop].Member[0]->Hp*(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1]/100)) <= Parties[eop].Member[0]->Hp) {
        boost = Parties[eop].Member[0]->Hp*AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1]/100;
        if (boost + Parties[eop].Member[0]->CurrentHp > Parties[eop].Member[0]->Hp) {
          boost = Parties[eop].Member[0]->Hp-Parties[eop].Member[0]->CurrentHp;
        }
        Parties[eop].Member[0]->CurrentHp += boost;
        printf("%s%s regained some hp!\n",EOPTEXT[eop],POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
          } else {
          Parties[eop].Member[0]->CurrentHp = Parties[eop].Member[0]->Hp;
          }
      } 
      
      else if (((unsigned char)(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[0] << 5)) >> 5 == 2) {
        boost = (unsigned char)(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1] << 4) >> 4;
        if (CHK_BIT(boost,3)) {
          boost *= -1;
        }
        Boostandprint((unsigned char)(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1] >> 5),boost,Parties[eop ^ CHK_BIT(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1],4)].Member[0],eop ^ CHK_BIT(AbilityList[Parties[eop].Member[0]->Ability].GNRL_PURPOSE[1],4));
      } 
      
    }
  }
}

gpf ABILITY_FUNC_LIST [] = {
&  NoAbilityf,
&  TypeBasedBoost,
&  StatDecreaseImmunity,
&  TypeChange,
&  TypeImmunity,
};