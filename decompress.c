#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <malloc.h>
#include <limits.h>

#include "predefs/queue.h"
#include "predefs/stringfuncs.h"
#include "predefs/gnrltxt.h"
#include "predefs/gnrlfuncs.h"
#include "definitions/enumdefs.h"
#include "definitions/definitions.h"
#include "pokemon/pokedata.h"

int main(int argc,char** argv)
{
	if (argc != 2) {
		fprintf(stderr,"usage: %s output.txt",argv[0]);
		exit(-1);
	}
	FILE* output = fopen(argv[1],"w");
	fprintf(output,"const struct PokemonDex POKEMONDEX [] = {\n");
	for (int i = 0;i < POKEMON_MAX;i++) {
		fprintf(output,"{\"%s\",%u,%u,%u,%u,%u,%u,%s,%s},\n",str_decompress_format_prealloc(POKEMONDEX[i].Name,TempTextBuffer2),POKEMONDEX[i].Hp,POKEMONDEX[i].Atk,POKEMONDEX[i].Def,POKEMONDEX[i].SpA,POKEMONDEX[i].SpD,POKEMONDEX[i].Spe,TypeNames[POKEMONDEX[i].Type1],TypeNames[POKEMONDEX[i].Type2]);
	}
	fprintf(output,"};");
	fclose(output);
	return 0;
}