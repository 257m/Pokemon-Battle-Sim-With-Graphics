struct Nature NATURE_LIST [] = {
{1,1,1,1,1,"Hardy"},
{1.1,0.9,1,1,1,"Lonely"},
{1.1,1,1,1,0.9,"Brave"},
{1.1,1,0.9,1,1,"Adamant"},
{1.1,1,1,0.9,1,"Naughty"},
{0.9,1.1,1,1,1,"Bold"},
{1,1,1,1,1,"Docile"},
{1,1.1,1,1,0.9,"Relaxed"},
{1,1.1,0.9,1,1,"Impish"},
{1,1.1,1,0.9,1,"Lax"},
{0.9,1,1,1,1.1,"Timid"},
{1,0.9,1,1,1.1,"Hasty"},
{1,1,1,1,1,"Serious"},
{1,1,0.9,1,1.1,"Jolly"},
{1,1,1,0.9,1.1,"Naive"},
{0.9,1,1.1,1,1,"Modest"},
{1,0.9,1.1,1,1,"Mild"},
{1,1,1.1,1,0.9,"Quiet"},
{1,1,1,1,1,"Bashful"},
{1,1,1.1,0.9,1,"Rash"},
{0.9,1,1,1.1,1,"Calm"},
{1,0.9,1,1.1,1,"Gentle"},
{1,1,1,1.1,0.9,"Sassy"},
{1,1,0.9,1.1,1,"Careful"},
{1,1,1,1.1,1,"Quirky"}
};

extern struct Party Parties [2];
extern bool StatCalc = 1;
extern bool BattleMode = 0;
extern bool Retrieve = 0;
bool Execute = 0;
bool Reset = 0;
bool First = 0;
bool Display = 0;
char TextBuffer [32];
bool EndFirst;
unsigned int TurnCounter = 0;
bool HideMove = 0;
unsigned long int randseed;