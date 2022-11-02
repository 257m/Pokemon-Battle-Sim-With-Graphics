gpf EFFECT_FUNC_LIST [] = {&PROTECTF,&LEECH_SEEDF,&PERISH_SONGF,&CONFUSIONF};

void ACTIVATE_EFFECTS(char et,bool eop) {
  for (int i = 0;i < (sizeof(EFFECT_FUNC_LIST)/sizeof(EFFECT_FUNC_LIST[0]));i++) {
  if (CHK_BIT(Parties[0].EFFECT_FLAGS[0],i)) EFFECT_FUNC_LIST[i](et,eop);
  }
}

void CLEAR_EFFECTS(bool eop) {
  for (int j = 0;j < 2;j++) {
  for (int i = 0;i < 64;i++) {
    CLR_BIT(Parties[0].EFFECT_FLAGS[j],i);
  }
    }
}

void CLEAR_EFFECT_COUNTERS(bool eop) {
  for (int i = 0;i < 128;i++) {
    Parties[0].EFFECT_COUNTERS[i] = 0;
  }
}