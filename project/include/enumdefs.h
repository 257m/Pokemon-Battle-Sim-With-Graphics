#ifndef ENUM_DEF_H
#define ENUM_DEF_H

enum {
NOTYPE,
NORMAL,
FIRE,
WATER,
ELECTRIC,
PLANT,
MAGIC,
AIR,
GROUND,
POISON,
LIGHT,
DARK,
BUG,
GHOST,
ICE,
METAL,
ROCK,
MARTIAL,
TYPE_MAX,
};

enum {
NOPOKE,
BULBASAUR,
IVYSAUR,
VENUSAUR,
CHARMANDER,
CHARMELEON,
CHARIZARD,
SQUIRTLE,
WARTORTLE,
BLASTOISE,
PIDGEY,
PIDGEOTTO,
PIDGEOT,
CORDAGAR,
BULEJ,
BULICJEL,
BULICAYJAL,
DEMELLAGON,
LAPOUSION,
LALEMORTA,
SLOR,
SLINOR,
SORLIGHNOR,
POOCHYENA,
MIGHTYENA,
BOLTYENA,
ILLSONAR,
DRILLBUR,
EXCADRILL,
RADRILLITE,
FOTOR,
FOTELUB,
FOTELOBUL,
AXQUAL,
AXAQUAN,
AXAQUANEL,
GRALOTH,
MUSHORALOTH,
BILUMINASOTH,
ELEMIG,
STELIRENGO,
LEECHESTER,
GUINER,
GUINEREM,
GARASOLEM,
FAETERNAERT,
DAROASINAUGHT,
RHINORIUM,
SPIRAMP,
TREVANTULA,
SALAVA,
SOLIGHN,
SOLIGHNIRE,
POKEMON_MAX,
};

enum {
STATUS_NULL,
STATUS_BURN,
STATUS_POISON,
STATUS_TOXIC,
STATUS_PARALYSIS,
STATUS_SLEEP,
STATUS_FREEZE,
STATE_FLINCH,
STATUS_MAX,
};

#define EFFECT_STATUS_MAX STATUS_MAX-1
#define ESM EFFECT_STATUS_MAX

enum {
STAT_ATK,
STAT_DEF,
STAT_SPA,
STAT_SPD,
STAT_SPE,
STAT_ACC,
STAT_EVA,
STAT_CRIT,
};

enum {
Hp,
Atk,
Def,
SpA,
SpD,
Spe,
};

enum {
Hardy,
Lonely,
Brave,
Adamant,
Naughty,
Bold,
Docile,
Relaxed,
Impish,
Lax,
Timid,
Hasty,
Serious,
Jolly,
Naive,
Modest,
Mild,
Quiet,
Bashful,
Rash,
Calm,
Gentle,
Sassy,
Careful,
};

enum {
Nothing,
Struggle,
Scratch,
Water_Gun,
Vine_Whip,
Ember,
Quick_Attack,
Super_Attack,
Stone_Edge,
Gust,
Thunder_Shock,
Thunder_Wave,
Swords_Dance,
Spirit_Dance,
Will_O_Wisp,
Spore,
Toxic,
Freeze,
Bulk_Up,
Charm,
Leer,
Flash,
Kinesis,
Leaf_Tornado,
Mirror_Shot,
Mud_Bomb,
Mud_Slap,
Muddy_Water,
Night_Daze,
Octazooka,
Sand_Attack,
Smoke_Screen,
Aurora_Beam,
Puppy_Dog_Eyes,
Breaking_Swipe,
Protect,
Mercury_Shot,
Superpower,
Gale_Blade,
Roar,
Icicle_Crash,
Confuse_Ray,
Feather_Dance,
Growl,
Luminous_Glow,
Earthquake,
Giga_Drain,
Blinding_Flash,
Blindstrike,
Web_Blast,
Illusion_Field,
Double_Edge,
Flash_Stream,
Photon_Blast,
Photon_Slash,
Tremor,
Shock,
Tornado,
Sting,
Shadowbolt,
Spectral_Punch,
Frostbreath,
Tackle,
Arcane_Punch,
Log_Throw,
Acid_Spray,
Rock_Toss,
Hydrobolt,
Aerobolt,
Sand_Slap,
Karate_Chop,
Firebolt,
Iron_Hit,
Soothing_Light,
MOVE_MAX,
};

enum {
MF_Nothing,
MF_Struggle,
MF_STATMOD,
MF_OTHERSTATUS,
MF_PROTECT,
MF_ROAR,
MF_DRAININGMOVE,
MF_EDGECASE,
MF_HEAL,
MF_MAX,
};

enum {
STATUS,
PHYSICAL,
SPECIAL,
};

enum {
NoItem,
Leftovers,
Focus_Sash,
Liechi_Berry,
Ganlon_Berry,
Petaya_Berry,
Apicot_Berry,
Salac_Berry,
Lansat_Berry,
ITEM_MAX,
};

enum {
TF_NONE,
TF_LEFTOVERS,
TF_FOCUS_SASH,
TF_BERRIES,
TF_MAX,
};

enum {
NoAbility,
Overgrow,
Blaze,
Torrent,
Swarm,
Clear_Body,
Big_Pecks,
Hyper_Cutter,
Aerilate,
Pixilate,
Frozen_Wing,
Galvanize,
Levitate,
Water_Absorb,
Motor_Drive,
Sap_Sipper,
ABILITY_MAX,
};

enum {
AF_NOABILITY,
AF_TYPE_BASED_BOOST,
AF_IMMUNE_TO_STAT_DECREASE,
AF_TYPECHANGE,
AF_TYPEIMMUNITY,
};

enum {
EFFECT_PROTECT,
EFFECT_CONFUSION,
EFFECT_MAX,
};

// Effect execution times
enum {
	EET_INFLICTION,
	EET_PREMOVE,
	EET_POSTMOVE
};

#define FLAG_MAKES_CONTACT 1
#define FLAG_PROTECT_AFFECTED 2
#define FLAG_TYPE_IMMUNITY_AFFECTED 4
#define FLAG_POWDER_MOVE 8
#define FLAG_HIGH_CRIT 16

enum {
nFLAG_MAKES_CONTACT,
nFLAG_PROTECT_AFFECTED,
nFLAG_TYPE_IMMUNITY_AFFECTED,
nFLAG_POWDER_MOVE,
nFLAG_HIGH_CRIT,
};

enum {
STAT1_0_STAT2_0,
STAT1_0_STAT2_1,
STAT1_0_STAT2_2,
STAT1_0_STAT2_3,
STAT1_0_STAT2_4,
STAT1_0_STAT2_5,
STAT1_0_STAT2_6,
STAT1_0_STAT2_7,
STAT1_0_STAT2_n0,
STAT1_0_STAT2_n1,
STAT1_0_STAT2_n2,
STAT1_0_STAT2_n3,
STAT1_0_STAT2_n4,
STAT1_0_STAT2_n5,
STAT1_0_STAT2_n6,
STAT1_0_STAT2_n7,
STAT1_1_STAT2_0,
STAT1_1_STAT2_1,
STAT1_1_STAT2_2,
STAT1_1_STAT2_3,
STAT1_1_STAT2_4,
STAT1_1_STAT2_5,
STAT1_1_STAT2_6,
STAT1_1_STAT2_7,
STAT1_1_STAT2_n0,
STAT1_1_STAT2_n1,
STAT1_1_STAT2_n2,
STAT1_1_STAT2_n3,
STAT1_1_STAT2_n4,
STAT1_1_STAT2_n5,
STAT1_1_STAT2_n6,
STAT1_1_STAT2_n7,
STAT1_2_STAT2_0,
STAT1_2_STAT2_1,
STAT1_2_STAT2_2,
STAT1_2_STAT2_3,
STAT1_2_STAT2_4,
STAT1_2_STAT2_5,
STAT1_2_STAT2_6,
STAT1_2_STAT2_7,
STAT1_2_STAT2_n0,
STAT1_2_STAT2_n1,
STAT1_2_STAT2_n2,
STAT1_2_STAT2_n3,
STAT1_2_STAT2_n4,
STAT1_2_STAT2_n5,
STAT1_2_STAT2_n6,
STAT1_2_STAT2_n7,
STAT1_3_STAT2_0,
STAT1_3_STAT2_1,
STAT1_3_STAT2_2,
STAT1_3_STAT2_3,
STAT1_3_STAT2_4,
STAT1_3_STAT2_5,
STAT1_3_STAT2_6,
STAT1_3_STAT2_7,
STAT1_3_STAT2_n0,
STAT1_3_STAT2_n1,
STAT1_3_STAT2_n2,
STAT1_3_STAT2_n3,
STAT1_3_STAT2_n4,
STAT1_3_STAT2_n5,
STAT1_3_STAT2_n6,
STAT1_3_STAT2_n7,
STAT1_4_STAT2_0,
STAT1_4_STAT2_1,
STAT1_4_STAT2_2,
STAT1_4_STAT2_3,
STAT1_4_STAT2_4,
STAT1_4_STAT2_5,
STAT1_4_STAT2_6,
STAT1_4_STAT2_7,
STAT1_4_STAT2_n0,
STAT1_4_STAT2_n1,
STAT1_4_STAT2_n2,
STAT1_4_STAT2_n3,
STAT1_4_STAT2_n4,
STAT1_4_STAT2_n5,
STAT1_4_STAT2_n6,
STAT1_4_STAT2_n7,
STAT1_5_STAT2_0,
STAT1_5_STAT2_1,
STAT1_5_STAT2_2,
STAT1_5_STAT2_3,
STAT1_5_STAT2_4,
STAT1_5_STAT2_5,
STAT1_5_STAT2_6,
STAT1_5_STAT2_7,
STAT1_5_STAT2_n0,
STAT1_5_STAT2_n1,
STAT1_5_STAT2_n2,
STAT1_5_STAT2_n3,
STAT1_5_STAT2_n4,
STAT1_5_STAT2_n5,
STAT1_5_STAT2_n6,
STAT1_5_STAT2_n7,
STAT1_6_STAT2_0,
STAT1_6_STAT2_1,
STAT1_6_STAT2_2,
STAT1_6_STAT2_3,
STAT1_6_STAT2_4,
STAT1_6_STAT2_5,
STAT1_6_STAT2_6,
STAT1_6_STAT2_7,
STAT1_6_STAT2_n0,
STAT1_6_STAT2_n1,
STAT1_6_STAT2_n2,
STAT1_6_STAT2_n3,
STAT1_6_STAT2_n4,
STAT1_6_STAT2_n5,
STAT1_6_STAT2_n6,
STAT1_6_STAT2_n7,
STAT1_7_STAT2_0,
STAT1_7_STAT2_1,
STAT1_7_STAT2_2,
STAT1_7_STAT2_3,
STAT1_7_STAT2_4,
STAT1_7_STAT2_5,
STAT1_7_STAT2_6,
STAT1_7_STAT2_7,
STAT1_7_STAT2_n0,
STAT1_7_STAT2_n1,
STAT1_7_STAT2_n2,
STAT1_7_STAT2_n3,
STAT1_7_STAT2_n4,
STAT1_7_STAT2_n5,
STAT1_7_STAT2_n6,
STAT1_7_STAT2_n7,
STAT1_n0_STAT2_0,
STAT1_n0_STAT2_1,
STAT1_n0_STAT2_2,
STAT1_n0_STAT2_3,
STAT1_n0_STAT2_4,
STAT1_n0_STAT2_5,
STAT1_n0_STAT2_6,
STAT1_n0_STAT2_7,
STAT1_n0_STAT2_n0,
STAT1_n0_STAT2_n1,
STAT1_n0_STAT2_n2,
STAT1_n0_STAT2_n3,
STAT1_n0_STAT2_n4,
STAT1_n0_STAT2_n5,
STAT1_n0_STAT2_n6,
STAT1_n0_STAT2_n7,
STAT1_n1_STAT2_0,
STAT1_n1_STAT2_1,
STAT1_n1_STAT2_2,
STAT1_n1_STAT2_3,
STAT1_n1_STAT2_4,
STAT1_n1_STAT2_5,
STAT1_n1_STAT2_6,
STAT1_n1_STAT2_7,
STAT1_n1_STAT2_n0,
STAT1_n1_STAT2_n1,
STAT1_n1_STAT2_n2,
STAT1_n1_STAT2_n3,
STAT1_n1_STAT2_n4,
STAT1_n1_STAT2_n5,
STAT1_n1_STAT2_n6,
STAT1_n1_STAT2_n7,
STAT1_n2_STAT2_0,
STAT1_n2_STAT2_1,
STAT1_n2_STAT2_2,
STAT1_n2_STAT2_3,
STAT1_n2_STAT2_4,
STAT1_n2_STAT2_5,
STAT1_n2_STAT2_6,
STAT1_n2_STAT2_7,
STAT1_n2_STAT2_n0,
STAT1_n2_STAT2_n1,
STAT1_n2_STAT2_n2,
STAT1_n2_STAT2_n3,
STAT1_n2_STAT2_n4,
STAT1_n2_STAT2_n5,
STAT1_n2_STAT2_n6,
STAT1_n2_STAT2_n7,
STAT1_n3_STAT2_0,
STAT1_n3_STAT2_1,
STAT1_n3_STAT2_2,
STAT1_n3_STAT2_3,
STAT1_n3_STAT2_4,
STAT1_n3_STAT2_5,
STAT1_n3_STAT2_6,
STAT1_n3_STAT2_7,
STAT1_n3_STAT2_n0,
STAT1_n3_STAT2_n1,
STAT1_n3_STAT2_n2,
STAT1_n3_STAT2_n3,
STAT1_n3_STAT2_n4,
STAT1_n3_STAT2_n5,
STAT1_n3_STAT2_n6,
STAT1_n3_STAT2_n7,
STAT1_n4_STAT2_0,
STAT1_n4_STAT2_1,
STAT1_n4_STAT2_2,
STAT1_n4_STAT2_3,
STAT1_n4_STAT2_4,
STAT1_n4_STAT2_5,
STAT1_n4_STAT2_6,
STAT1_n4_STAT2_7,
STAT1_n4_STAT2_n0,
STAT1_n4_STAT2_n1,
STAT1_n4_STAT2_n2,
STAT1_n4_STAT2_n3,
STAT1_n4_STAT2_n4,
STAT1_n4_STAT2_n5,
STAT1_n4_STAT2_n6,
STAT1_n4_STAT2_n7,
STAT1_n5_STAT2_0,
STAT1_n5_STAT2_1,
STAT1_n5_STAT2_2,
STAT1_n5_STAT2_3,
STAT1_n5_STAT2_4,
STAT1_n5_STAT2_5,
STAT1_n5_STAT2_6,
STAT1_n5_STAT2_7,
STAT1_n5_STAT2_n0,
STAT1_n5_STAT2_n1,
STAT1_n5_STAT2_n2,
STAT1_n5_STAT2_n3,
STAT1_n5_STAT2_n4,
STAT1_n5_STAT2_n5,
STAT1_n5_STAT2_n6,
STAT1_n5_STAT2_n7,
STAT1_n6_STAT2_0,
STAT1_n6_STAT2_1,
STAT1_n6_STAT2_2,
STAT1_n6_STAT2_3,
STAT1_n6_STAT2_4,
STAT1_n6_STAT2_5,
STAT1_n6_STAT2_6,
STAT1_n6_STAT2_7,
STAT1_n6_STAT2_n0,
STAT1_n6_STAT2_n1,
STAT1_n6_STAT2_n2,
STAT1_n6_STAT2_n3,
STAT1_n6_STAT2_n4,
STAT1_n6_STAT2_n5,
STAT1_n6_STAT2_n6,
STAT1_n6_STAT2_n7,
STAT1_n7_STAT2_0,
STAT1_n7_STAT2_1,
STAT1_n7_STAT2_2,
STAT1_n7_STAT2_3,
STAT1_n7_STAT2_4,
STAT1_n7_STAT2_5,
STAT1_n7_STAT2_6,
STAT1_n7_STAT2_7,
STAT1_n7_STAT2_n0,
STAT1_n7_STAT2_n1,
STAT1_n7_STAT2_n2,
STAT1_n7_STAT2_n3,
STAT1_n7_STAT2_n4,
STAT1_n7_STAT2_n5,
STAT1_n7_STAT2_n6,
STAT1_n7_STAT2_n7,
};

#endif // ENUM_DEF_H //