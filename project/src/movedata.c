#include "../include/definitions.h"
#include "../include/enumdefs.h"
#include "../include/moves.h"

const struct Move MoveList[MOVE_MAX] = {
	// [0] Nothing
	{"Nothing", 0, 0, 0, NOTYPE, STATUS, 0, MF_Nothing << 5, {0, 0, 0, 0, 0},
		0},
	// [1] Struggle
	{"Struggle", 50, 101, 0, NOTYPE, 1, 0, MF_Struggle << 5, {0, 0, 0, 0, 0},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED},
	// [2] Scratch
	{"Scratch", 40, 100, 4, NORMAL, PHYSICAL, 0, MF_Nothing << 5,
		{0, 0, 0, 0, 0},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [3] Water Gun
	{"Water Gun", 40, 100, 4, WATER, SPECIAL, 0, MF_Nothing << 5,
		{0, 0, 0, 0, 0}, FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [4] Vine Whip
	{"Vine Whip", 45, 100, 6, PLANT, PHYSICAL, 0, MF_Nothing << 5,
		{0, 0, 0, 0, 0},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [5] Ember
	{"Ember", 40, 100, 4, FIRE, SPECIAL, 0, MF_OTHERSTATUS << 5,
		{STATUS_BURN, 10, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [6] Quick Attack
	{"Quick Attack", 40, 100, 5, NORMAL, PHYSICAL, 1, MF_Nothing << 5,
		{0, 0, 0, 0, 0},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [7] Super Attack
	{"Super Attack", 120, 75, 2, NORMAL, PHYSICAL, 0, MF_Nothing << 5,
		{0, 0, 0, 0, 0},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [8] Stone Edge
	{"Stone Edge", 100, 80, 0, ROCK, PHYSICAL, 0, MF_Nothing << 5,
		{0, 0, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED | FLAG_HIGH_CRIT},
	// [9] Gust
	{"Gust", 40, 100, 6, AIR, SPECIAL, 0, MF_Nothing << 5, {0, 0, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [10] Thunder Shock
	{"Thunder Shock", 40, 100, 5, ELECTRIC, SPECIAL, 0, MF_OTHERSTATUS << 5,
		{STATUS_PARALYSIS, 10, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [11] Thunder Wave
	{"Thunder Wave", 0, 90, 3, ELECTRIC, STATUS, 0, MF_OTHERSTATUS << 5,
		{STATUS_PARALYSIS, 100, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [12] Swords Dance
	{"Swords Dance", 0, 101, 3, NORMAL, STATUS, 0, MF_STATMOD << 5,
		{STAT1_2_STAT2_0, 0, 0, 0, 100}, 0},
	// [13] Spirit Dance
	{"Spirit Dance", 0, 101, 3, GHOST, STATUS, 0, MF_STATMOD << 5,
		{STAT1_1_STAT2_0, 0, STAT1_1_STAT2_0, 0, 100}, 0},
	// [14] Will-O-Wisp
	{"Will-O-Wisp", 0, 90, 2, FIRE, STATUS, 0, MF_OTHERSTATUS << 5,
		{STATUS_BURN, 100, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [15] Spore
	{"Spore", 0, 100, 1, PLANT, STATUS, 0, MF_OTHERSTATUS << 5,
		{STATUS_SLEEP, 100, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED | FLAG_POWDER_MOVE},
	// [16] Toxic
	{"Toxic", 0, 90, 1, POISON, STATUS, 0, MF_OTHERSTATUS << 5,
		{STATUS_POISON, 100, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [17] Freeze
	{"Freeze", 0, 60, 1, ICE, STATUS, 0, MF_OTHERSTATUS << 5,
		{STATUS_FREEZE, 100, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [18] Bulk Up
	{"Bulk Up", 0, 101, 3, MARTIAL, STATUS, 0, MF_STATMOD << 5,
		{STAT1_1_STAT2_1, 0, 0, 0, 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [19] Puppy Dog Eyes
	{"Puppy Dog Eyes", 0, 100, 3, NORMAL, STATUS, 0, MF_STATMOD << 5,
		{STAT1_n2_STAT2_0, 0, 0, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [20] Growl
	{"Growl", 0, 100, 3, NORMAL, STATUS, 0, MF_STATMOD << 5,
		{9, 0, 0, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [21] Leer
	{"Leer", 0, 100, 3, NORMAL, STATUS, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [22] Kinesis
	{"Kinesis", 0, 85, 2, MAGIC, STATUS, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [23] Leaf Tornado
	{"Leaf Tornado", 65, 90, 1, PLANT, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 148},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [24] Mirror Shot
	{"Mirror Shot", 65, 85, 1, METAL, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 158},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [25] Mud Bomb
	{"Mud Bomb", 65, 85, 1, GROUND, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 158},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [26] Mud Slap
	{"Mud Slap", 20, 100, 1, GROUND, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [27] Muddy Water
	{"Muddy Water", 95, 85, 1, WATER, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 158},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [28] Night Daze
	{"Night Daze", 85, 95, 1, DARK, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 168},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [29] Octazooka
	{"Octazooka", 65, 85, 1, WATER, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 178},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [30] Sand Attack
	{"Sand Attack", 0, 100, 2, GROUND, STATUS, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, OTHER | 100}, FLAG_PROTECT_AFFECTED},
	// [31] Smoke Screen
	{"Smoke Screen", 0, 100, 3, NORMAL, STATUS, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, OTHER | 100}, FLAG_PROTECT_AFFECTED},
	// [32] Aurora Beam
	{"Aurora Beam", 65, 100, 3, ICE, SPECIAL, 0, MF_STATMOD << 5,
		{STAT1_n1_STAT2_0, 0, 0, 0, 138},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [33] Charm
	{"Charm", 0, 100, 5, NORMAL, STATUS, 1, MF_STATMOD << 5,
		{STAT1_n1_STAT2_0, 0, 0, 0, OTHER | 100}, FLAG_PROTECT_AFFECTED},
	// [34] Breaking Swipe
	{"Breaking Swipe", 60, 100, 2, MARTIAL, PHYSICAL, 0, MF_STATMOD << 5,
		{STAT1_n1_STAT2_0, 0, 0, 0, OTHER | 100},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [35] Protect
	{"Protect", 0, 101, 1, NORMAL, STATUS, 4, MF_PROTECT << 5, {0, 0, 0, 0, 0},
		0},
	// [36] Mercury Shot
	{"Mercury Shot", 70, 90, 2, METAL, SPECIAL, 0, MF_OTHERSTATUS << 5,
		{STATUS_POISON, 20, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [37] Superpower
	{"Superpower", 120, 100, 0, MARTIAL, PHYSICAL, 0, MF_STATMOD << 5,
		{STAT1_n1_STAT2_n1, 0, 0, 0, 100},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [38] Gale Blade
	{"Gale Blade", 60, 95, 1, AIR, PHYSICAL, -6, MF_ROAR << 5, {0, 0, 0, 0, 0},
		FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED |
			FLAG_TYPE_IMMUNITY_AFFECTED},
	// [39] Roar
	{"Roar", 0, 101, 3, NORMAL, STATUS, -6, MF_ROAR << 5, {0, 0, 0, 0, 0}, 0},
	// [40] Icicle Crash
	{"Icicle Crash", 85, 90, 1, ICE, PHYSICAL, 0, MF_OTHERSTATUS << 5,
		{STATE_FLINCH, 30}, FLAG_PROTECT_AFFECTED},
	// [41] Confuse Ray
	{"Confuse Ray", 0, 100, 1, GHOST, STATUS, 0, MF_OTHERSTATUS << 5,
		{EFFECT_STATUS_MAX + EFFECT_CONFUSION, 100}, FLAG_PROTECT_AFFECTED},
	// [42] Feather Dance
	{"Feather Dance", 0, 101, 2, AIR, STATUS, 0, MF_STATMOD << 5,
		{STAT1_n2_STAT2_0, 0, 0, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [43] Growl
	{"Growl", 0, 101, 2, NORMAL, STATUS, 0, MF_STATMOD << 5,
		{STAT1_n1_STAT2_0, 0, 0, 0, OTHER | 100},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [44] Luminous Glow
	{"Luminous Glow", 0, 101, 4, LIGHT, STATUS, 0, MF_STATMOD << 5,
		{0, STAT1_1_STAT2_0, STAT1_1_STAT2_0, 0, 100}, 0},
	// [45] Earthquake
	{"Earthquake", 100, 100, 1, GROUND, PHYSICAL, 0, MF_Nothing << 5,
		{0, 0, 0, 0, 0}, FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [46] Giga Drain
	{"Giga Drain", 75, 100, 1, PLANT, SPECIAL, 0, MF_DRAININGMOVE << 5, {50},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [47] Blinding Flash
	{"Blinding Flash", 120, 101, 0, LIGHT, SPECIAL, 0, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 178},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [48] Blindstrike
	{"Blindstrike", 75, 90, 2, LIGHT, PHYSICAL, 5, MF_STATMOD << 5,
		{0, 0, STAT1_0_STAT2_n1, 0, 178},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [49] Web Blast
	{"Web Blast", 80, 100, 2, BUG, SPECIAL, 0,
		(MF_STATMOD << 5) | MF_OTHERSTATUS,
		{0, 0, STAT1_n1_STAT2_0, 0, 178, EFFECT_STATUS_MAX + EFFECT_CONFUSION,
			50, 0, 0, 0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [50] Illusion Field
	{"Illusion Field", 0, 101, 3, NOTYPE, STATUS, 0,
		(MF_STATMOD << 5) | MF_OTHERSTATUS,
		{STAT1_n1_STAT2_n1, STAT1_n1_STAT2_n1, STAT1_n1_STAT2_n1,
			STAT1_n1_STAT2_n1, OTHER | 100,
			EFFECT_STATUS_MAX + EFFECT_CONFUSION, 100, 0, 0, 0},
		0},
	// [51] Double Edge
	{"Double Edge", 120, 100, 1, NORMAL, PHYSICAL, 0, (MF_DRAININGMOVE << 5),
		{33, 128}, FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [54] Flash Stream
	{"Flash Stream", 65, 101, 2, LIGHT, SPECIAL, 0, MF_Nothing, {0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [55] Photon Blast
	{"Photon Blast", 100, 90, 2, LIGHT, SPECIAL, 0, MF_Nothing, {0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	// [56] Photon Slash
	{"Photon Slash", 65, 90, 3, LIGHT, PHYSICAL, 0, MF_Nothing, {0},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
	{"Tremor", 75, 95, 2, GROUND, PHYSICAL, 0, MF_OTHERSTATUS << 5,
		{STATE_FLINCH, 50},
		FLAG_PROTECT_AFFECTED | FLAG_TYPE_IMMUNITY_AFFECTED},
};

MoveSlot Empty_slot = {Nothing, 1, 1};
MoveSlot Struggle_Slot = {Struggle, 1, 1};