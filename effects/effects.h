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