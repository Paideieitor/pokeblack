#ifndef BOX_POKEMON_H
#define BOX_POKEMON_H

#include "types.h"

/**
 * @file box_pokemon.h
 * @brief Box pokemon structures
 *
 * Defines the structures that represent Pokémon outside of battle.
 * The data is compressed into buffers in order to be stored in the
 * save file, then it can be decompressed into blocks for easier use.
 */

typedef struct PokemonBufferChunk {
    u8 data[32];
} PokemonBufferChunk;

typedef struct PokemonBuffer {
    PokemonBufferChunk chunks[4];
} PokemonBuffer;

typedef struct BoxPokemon {
    u32 pid;
    u16 sanityFlags;
    u16 checksum;
    PokemonBuffer ContentBuffer;
} BoxPokemon;

typedef struct BoxPokemonBlock0 {
    u16 species;
    u16 heldItem;
    u32 trainerIDAndSecretID;
    u32 experience;
    u8 happiness;
    u8 ability;
    u8 markings;
    u8 region;
    u8 evHP;
    u8 evATK;
    u8 evDEF;
    u8 evSPE;
    u8 evSPA;
    u8 evSPD;
    u8 contestCool;
    u8 contestBeauty;
    u8 contestCute;
    u8 contestSmart;
    u8 contestTough;
    u8 contestSheen;
    u32 ribbons1;
} BoxPokemonBlock0;

typedef struct BoxPokemonBlock1 {
    u16 moves[4];
    u8 movePPs[4];
    u8 movePPUpStages[4];
    u32 ivBits;
    u32 ribbons2;
    u8 sexAndForm;
    u8 nature;
    u16 hiddenAbilityAndNPokemon;
    u32 field_1C;
} BoxPokemonBlock1;

typedef struct BoxPokemonBlock2 {
    wchar_t nickname[11];
    u8 field_16;
    u8 originGame;
    u64 ribbons3;
} BoxPokemonBlock2;

typedef struct BoxPokemonBlock3 {
    u16 OTName[8];
    u8 hatchDateYear;
    u8 hatchDateMonth;
    u8 hatchDateDay;
    u8 metYear;
    u8 metMonth;
    u8 metDay;
    u16 hatchLocation;
    u16 metLocation;
    u8 pokerus;
    u8 pokeball;
    u8 metLevelAndOTGender;
    u8 catchTerrainTileType;
    u8 field_1E;
    u8 pokeStarFame;
} BoxPokemonBlock3;

#endif // BOX_POKEMON_H
