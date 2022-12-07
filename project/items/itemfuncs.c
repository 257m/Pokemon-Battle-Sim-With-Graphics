#include "defintions.h"

void NoItemf(char et,bool eop) {
}

void Leftoversf(char et,bool eop) {  
    int Recovery;
    if (et == 5) {
    if (Parties[eop].Member[0]->ItemUsable) {
    	if (Parties[eop].Member[0]->CurrentHp < Parties[eop].Member[0]->Hp) {
        	Recovery = Parties[eop].Member[0]->Hp/16;
        	if (Recovery + Parties[eop].Member[0]->CurrentHp > Parties[eop].Member[0]->Hp) Recovery = Parties[eop].Member[0]->Hp - Parties[eop].Member[0]->CurrentHp;
        	Parties[eop].Member[0]->CurrentHp += Recovery;
        	sprintf(TempTextBuffer,"%s restored a little HP using its Leftovers\n",POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
			TextBoxUpdateFast(TempTextBuffer,50,1000);
        }
      }
      }
}

void Focus_Sashf(char et,bool eop) {
    if (et == -1) {
    if (Parties[eop].Member[0]->ItemUsable) {
    if (Parties[eop].Member[0]->CurrentHp == Parties[eop].Member[0]->Hp && Parties[!eop].Damage >= Parties[eop].Member[0]->Hp && !(CHK_BIT(Parties[eop].EFFECT_FLAGS[0],EFFECT_PROTECT) && CHK_BIT(MoveList[Parties[!eop].Turn->Move].FLAGS,nFLAG_PROTECT_AFFECTED))) {
      Parties[!eop].Damage = Parties[eop].Member[0]->CurrentHp-1;
      	sprintf(TempTextBuffer,"%s hung on with its Focus Sash!\n",POKEMONDEX[Parties[eop].Member[0]->Poke].Name);
		TextBoxUpdateFast(TempTextBuffer,50,1000);
		Parties[eop].Member[0]->ItemUsable = 0;
      }
    }
      }
  
}

void Berries(char et,bool eop) {
  if (et == 3 || et == -3) {
    if (Parties[eop].Member[0]->ItemUsable) {
    if (Parties[eop].Member[0]->CurrentHp <= Parties[eop].Member[0]->Hp/(ItemList[Parties[eop].Member[0]->Item].GNRL_PURPOSE[1] & KEEP_LAST_FOUR_BITS)) {
      printf("%s%s's %s actiated!\n",EOPTEXT[eop],POKEMONDEX[Parties[eop].Member[0]->Poke].Name,ItemList[Parties[eop].Member[0]->Item].Name);
      Parties[eop].Member[0]->ItemUsable = 0;
      Boostandprint(ItemList[Parties[eop].Member[0]->Item].GNRL_PURPOSE[0] >> 4,ItemList[Parties[eop].Member[0]->Item].GNRL_PURPOSE[0] & KEEP_LAST_FOUR_BITS,Parties[eop].Member[0],eop);
      }
  }
}
  }

gpf ITEM_FUNC_LIST [] = {
&  NoItemf,
&  Leftoversf,
&  Focus_Sashf,
&  Berries,
};