#ifndef POKEMON_PARTY_H
#define POKEMON_PARTY_H

#include "types.h"

#include "box_pokemon.h"
#include "conditions.h"
#include "mail.h"

/**
 * @file pokemon_party.h
 * @brief Pokemon party structures
 *
 * Defines the structures that represent Pokémon inside the players party.
 * This differ from boxed Pokémon by keeping track of their current stats,
 * status, etc.
 */

/**
 * @brief Party Pokémon structure
 *
 * Defines the data of a Pokémon in the player party.
 */
typedef struct PartyPokemon {
  BoxPokemon base;
  MoveCondition status;
  u8 level;
  u8 field_8D;
  u16 currentHP;
  u16 maxHP;
  u16 attack;
  u16 defense;
  u16 speed;
  u16 spAttack;
  u16 spDefense;
  MailData mailData;
  u32 field_D4;
  u32 field_D8;
} PartyPokemon;

/**
 * @brief Pokémon party structure
 *
 * Defines the data of the player party.
 */
typedef struct PokemonParty {
  u32 capacity;
  u32 count;
  PartyPokemon pokemon[6];
  u8 presentMemberBits;
  u8 field_531;
  u16 field_532;
} PokemonParty;

#endif // POKEMON_PARTY_H
