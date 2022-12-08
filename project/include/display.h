#ifndef DISPLAY_H
#define DISPLAY_H

void TextBoxUpdate(char *text, unsigned int character_delay, unsigned int pause);
void TextBoxUpdateFast(char *text, unsigned int character_delay, unsigned int pause);
void move_result(bool eop);
void PokemonViewer(bool InBattle,bool eop,unsigned char PartyMember);
int PartyViewer(char InBattle,bool eop);
void BagViewer(bool InBattle,bool eop);
void displaymember(unsigned int PartyMember,bool eop);
void displayparty(bool eop);

#endif // DISPLAY_H //