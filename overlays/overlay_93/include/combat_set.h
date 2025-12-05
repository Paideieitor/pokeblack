#ifndef COMBAT_SET_H
#define COMBAT_SET_H

#include "types.h"

#include "battle_pokemon.h"

struct MainModule;
typedef struct CombatSet {
  MainModule *mainModule;
  BattleParty battleParties[4];
  PokemonParty *sourceParties[4];
  BattlePokemon *activeMons[24];
  u32 forServer;
} CombatSet;

#endif // COMBAT_SET_H
