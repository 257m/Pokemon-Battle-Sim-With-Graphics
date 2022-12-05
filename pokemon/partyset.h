struct MyPokemon* pokemon_create() {
  struct MyPokemon* pokemon = malloc(sizeof(struct MyPokemon));
  return pokemon;
}

struct MyPokemon* pokemon_clear(struct MyPokemon* pokemon) {
 for (int i = 0;i < 4;i++) {
 pokemon->Moves[i].Move = 0;
 pokemon->Moves[i].PP = 0;
 pokemon->Moves[i].PPmult = 0;
   }
 for (int i = 0;i < 8;i++) {
   pokemon->StatBoosts[i] = 0;
 }
 pokemon->CurrentHp = 0;
 pokemon->Hp = 0;
 pokemon->Atk = 0;
 pokemon->Def = 0;
 pokemon->SpA = 0;
 pokemon->SpD = 0;
 pokemon->Spe = 0;
 pokemon->Item = 0;
 pokemon->Ability = 0;
 pokemon->EVS[Hp] = 0;
 pokemon->EVS[Atk] = 0;
 pokemon->EVS[Def] = 0;
 pokemon->EVS[SpA] = 0;
 pokemon->EVS[SpD] = 0;
 pokemon->EVS[Spe] = 0;
 pokemon->Counter = 0;
 pokemon->ItemUsable = 0;
 pokemon->Level = 0;
 pokemon->Non_Volatile_Status = 0;
 pokemon->Nature = 0;
 pokemon->IVHp = 0;
 pokemon->IVAtk = 0;
 pokemon->IVDef = 0;
 pokemon->IVSpA = 0;
 pokemon->IVSpD = 0;
 pokemon->IVSpe = 0;
 pokemon->Poke = 0;
 return pokemon;
}

struct MyPokemon* pokemon_randomize(struct MyPokemon* pokemon) {
 for (int i = 0;i < 4;i++) {
   pokemon->Moves[i].Move = (rand() % (MOVE_MAX-2))+2;
   pokemon->Moves[i].PP = 0;
   pokemon->Moves[i].PPmult = rand() % 4;
   }
 pokemon->Item = rand() % ITEM_MAX;
 pokemon->Ability = rand() % ABILITY_MAX;
 pokemon->Level = (rand() % 100) + 1;
 pokemon->Nature = rand() % 25;
 pokemon->IVHp = rand() % 32;
 pokemon->IVAtk = rand() % 32;
 pokemon->IVDef = rand() % 32;
 pokemon->IVSpA = rand() % 32;
 pokemon->IVSpD = rand() % 32;
 pokemon->IVSpe = rand() % 32;
 pokemon->Poke = (rand() % (POKEMON_MAX-1))+1;
 char tempstat;
 char tempstat2;
 for (int i = 0;i < 127;i++) {
   tempstat = rand() % 6;
   if (pokemon->EVS[tempstat] >= 252) {
     tempstat2 = tempstat;
     tempstat = rand() % 5;
     if (tempstat >= tempstat2) tempstat++;
     }
   pokemon->EVS[tempstat] += 4;
 }
 return pokemon;
}

#define pokemon_delete(pokepointer) free(pokepointer); pokepointer = NULL;

struct MyPokemon Pokemon1 = {
.Poke = ILLSONAR,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Freeze,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon Pokemon2 = {
.Poke = PIDGEOTTO,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon Pokemon3 = {
.Poke = PIDGEOT,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon Pokemon4 = {
.Poke = SQUIRTLE,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon Pokemon5 = {
.Poke = WARTORTLE,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon Pokemon6 = {
.Poke = BLASTOISE,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon EnemyPokemon1 = {
.Poke = DAROASINAUGHT,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Double_Edge,0,3},{Photon_Blast,0,3},{Freeze,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon EnemyPokemon2 = {
.Poke = BULEJ,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon EnemyPokemon3 = {
.Poke = BULICJEL,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon EnemyPokemon4 = {
.Poke = ILLSONAR,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon EnemyPokemon5 = {
.Poke = ILLSONAR,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct MyPokemon EnemyPokemon6 = {
.Poke = ILLSONAR,
.Level = 100,
.CurrentHp = 20,
.Item = Focus_Sash,
.Ability = Levitate,
.Nature = Jolly,
.IVHp = 0,
.IVAtk = 0,
.IVDef = 31,
.IVSpA = 31,
.IVSpD = 31,
.IVSpe = 31,
.Moves = {{Illusion_Field,0,3},{Blinding_Flash,0,3},{Luminous_Glow,0,3},{Blindstrike,0,3}},
.EVS[Hp] = 0,
.EVS[Atk] = 0,
.EVS[Def] = 0,
.EVS[SpA] = 252,
.EVS[SpD] = 252,
.EVS[Spe] = 4
};

struct Party Parties [2] = {
{
  &Pokemon1,
  &Pokemon2,
  &Pokemon3,
  &Pokemon4,
  &Pokemon5,
  &Pokemon6,
},
{
  &EnemyPokemon1,
  &EnemyPokemon2,
  &EnemyPokemon3,
  &EnemyPokemon4,
  &EnemyPokemon5,
  &EnemyPokemon6,
}
};