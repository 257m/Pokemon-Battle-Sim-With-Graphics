#ifndef POKEMON_H
#define POKEMON_H

extern const struct PokemonDex POKEMONDEX [];
struct MyPokemon* pokemon_create();
struct MyPokemon* pokemon_clear(struct MyPokemon* pokemon);
struct MyPokemon* pokemon_randomize(struct MyPokemon* pokemon);
#define pokemon_delete(pokepointer) free(pokepointer); pokepointer = NULL
extern struct Party Parties [2];

#endif // POKEMON_H //