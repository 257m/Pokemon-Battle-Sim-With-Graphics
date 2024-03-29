#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "common.h"
#include "enumdefs.h"

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define CHK_BIT(BF, N) ((BF >> N) & 0x1)
#define tern(C, R1, R2) C ? R1 : R2

typedef void (*gpf)(char,bool);
typedef void (*ugpf)(unsigned char,bool);
typedef void (*mf)(char,bool,bool);

struct PokemonDex {
char Name [12]; // Stores the name of pokemon later
unsigned char Hp;
unsigned char Atk;
unsigned char Def;
unsigned char SpA;
unsigned char SpD;
unsigned char Spe;
// These are the BST values of pokemon stats
unsigned int Type1 : 5; // The first type of pokemon stores 0-32 if a pokemon has been declared with a type > 21 it will cause a segfault
unsigned int Type2 : 5; // Same as Type1 but for the secondary type
unsigned int extrabits : 6;
}__attribute__((__packed__)); // the gains from the pack are basiclly none-existent but I did it because I can

/*
This is how pokemon data is stored the entire dex will be stored in a array
*/


extern float TypeChart [TYPE_MAX][18];
//  This is the type chart I am soon going to make it so that it stores values from 0-3 instead but that is a task for another day

struct Move {
 char Name [16]; // Stores the names of the pokemon
 unsigned char BP; // The Basepower of the move its a value from 0-255. Note that some move may have a BP over 255 in some cases but that will be handled by a PP multiplier
 unsigned int Accuracy : 7; // The Accruacy of the move it is a vlaue fro 0-127 and if it is above 100 it is considesed by the game to be a move that never misses.
 unsigned int PP : 3; // it is a 4 bit unsigned int and simply multiplyed by 5 when trying to retrieve the actual value
 unsigned int Type : 5; // Pretty obvious it stores the Type of the pokemon and it will segfault if above 21 because there are only 22 types if you add the NULL type
 unsigned int Category : 2; // [0] Status [1] Physical [2] Special [4] haven't decided yet I could probably shave off a bit if I merged this with Priority. Actually nevermind 3x12 is 3 which is above 32 so at the very least 6 bits
 int Priority : 4; // Priority of the move from -8 to 8. Although it will at max be -6 to 6 but 12 is higher than 8 so I need 16. We could shave off a bit by merging this with Type because 21x12 is 252 which fits in a byte but that is not worth it and restricts my ability to add more types
 unsigned int movefunc : 10; // Two number values conresponding to a function stored in MOVE_FUNC_LIST. The first five bits are the index of movefunc1 the next five are the index for movefunc2
 unsigned char GNRL_PURPOSE [10]; // General info on the move it's meaning will be interpeted differently based on the movefunc. the first 5 bytes are reserved for movefunc1 the next 5 are for movefunc2
 unsigned char FLAGS; // Flags to stores things that do not vary based on movefunc. Such as if it is a Contact Move or Not
}__attribute__((__packed__));

/*
The structure for move storage is subject to change
*/

struct Nature {
  float Atk;
  float Def;
  float SpA;
  float SpD;
  float Spe;
  char NatureName [8];
};

/*
Structure for storing nature data the values will soon be compressed
*/

extern struct Nature NATURE_LIST [];

typedef struct {
unsigned char Move;
unsigned int PP : 6;
unsigned int PPmult : 2;
}__attribute__((__packed__)) MoveSlot;

typedef struct { 
char Name [16];
unsigned char itemfunc;
unsigned char GNRL_PURPOSE[2];
} Item;

typedef struct {
char Name [16];
unsigned char abilityfunc;
unsigned char GNRL_PURPOSE [2];
} Ability;

 struct MyPokemon {
 char StatBoosts [8]; // [0] Attack [1] Defense [2] Special Attack [3] Special Defense [4] Speed [5] Accuracy [6] Evasion [7] Crit
 MoveSlot Moves [4];
 int CurrentHp;
 unsigned int Hp;
 unsigned int Atk;
 unsigned int Def;
 unsigned int SpA;
 unsigned int SpD;
 unsigned int Spe;
 unsigned char Item;
 unsigned char Ability;
 unsigned char EVS [6];
 unsigned char Counter;
 unsigned int ItemUsable : 1;
 unsigned int Level : 7;
 unsigned int Non_Volatile_Status : 4;
 unsigned int Nature : 5;
 unsigned int IVHp : 5;
 unsigned int IVAtk : 5;
 unsigned int IVDef : 5;
 unsigned int IVSpA : 5;
 unsigned int IVSpD : 5;
 unsigned int IVSpe : 5;
 unsigned int Poke : 10;
};

struct Party {
 struct MyPokemon *Member [6];
 MoveSlot *Turn;
 int Damage;
 double STAB;
 double TemporaryMult;
 double SpeedTM;
 uint64_t EFFECT_FLAGS [2];
 char EFFECT_COUNTERS [128];
 unsigned char SwitchSave;
 unsigned int MoveTempType : 5;
 unsigned int Hit : 1;
 unsigned int CanMove : 1;
 unsigned int Dead : 1;
 unsigned int DoesNothing : 1;
 unsigned int Para : 1;
 unsigned int Sleep : 1;
 unsigned int Frozen : 1;
 unsigned int Flinch : 1;
 unsigned int Crit : 1;
 unsigned int Confused : 1;
 unsigned int Switching : 1;
 unsigned int AI_MODE : 1;
};

extern struct Party Parties [2];
extern bool StatCalc;
extern bool BattleMode;
extern bool Retrieve;
extern bool Execute;
extern bool Reset;
extern bool First;
extern bool Display;
extern char TextBuffer [32];
extern bool EndFirst;
extern unsigned int TurnCounter;
extern bool HideMove;
extern unsigned long int randseed;

#define CRIT_CHANCE 16
#define REMOVE_FIRST_FIVE_BITS 31
#define KEEP_LAST_FOUR_BITS 15

extern char TempTextBuffer [128];
extern char TempTextBuffer2 [16];
extern char TempTextBuffer3 [12];

#endif // DEFINITIONS_H //