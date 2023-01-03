#ifndef POKEMON_H
#define POKEMON_H

#include "enumdefs.h"
#include "definitions.h"

extern const struct PokemonDex POKEMONDEX [POKEMON_MAX];
struct MyPokemon* pokemon_create();
struct MyPokemon* pokemon_clear(struct MyPokemon* pokemon);
struct MyPokemon* pokemon_randomize(struct MyPokemon* pokemon);
#define pokemon_delete(pokepointer) free(pokepointer); pokepointer = NULL

#endif // POKEMON_H //