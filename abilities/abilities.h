const Ability AbilityList [] = {
{"NoAbility",AF_NOABILITY},
{"Overgrow",AF_TYPE_BASED_BOOST,{PLANT,3}},
{"Blaze",AF_TYPE_BASED_BOOST,{FIRE,3}},
{"Torrent",AF_TYPE_BASED_BOOST,{WATER,3}},
{"Swarm",AF_TYPE_BASED_BOOST,{BUG,3}},
{"Clear Body",AF_IMMUNE_TO_STAT_DECREASE,{255,2}},
{"Big Pecks",AF_IMMUNE_TO_STAT_DECREASE,{2,2}},
{"Hyper Cutter",AF_IMMUNE_TO_STAT_DECREASE,{1,2}},
{"Aerilate",AF_TYPECHANGE,{NORMAL << 5,134}},
{"Pixilate",AF_TYPECHANGE,{LIGHT << 5,134}},
{"Frozen Wing",AF_TYPECHANGE,{(AIR << 5) | (ICE >> 5),(ICE << 6) | 64}},
{"Galvanize",AF_TYPECHANGE,{ELECTRIC << 5,12}},
{"Hover",AF_TYPEIMMUNITY,{(GROUND << 3) | 0,0}},
{"Water Absorb",AF_TYPEIMMUNITY,{(WATER << 3) | 1,25}},
{"Motor Drive",AF_TYPEIMMUNITY,{(ELECTRIC << 3) | 2,129}},
{"Sap Sipper",AF_TYPEIMMUNITY,{(PLANT << 3) | 2,1}},
};