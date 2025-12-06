#ifndef MAIN_MODULE_H
#define MAIN_MODULE_H

#include "types.h"

#include "battle_client.h"
#include "battle_server.h"
#include "battle_setup.h"
/**
 * @file main_module.h
 * @brief Main structure to manage the battle system
 *
 * Defines the data structure that manages the whole battle engine,
 */

typedef struct ALIGNED(32) MainModule {
  BattleSetup *btlSetup;
  u32 field_4;
  BattleServer *server;
  ALIGNED(8) BattleClient *clients[4];
  u32 field_20;
  u32 field_24;
  TrainerData trainerData[4];
  u8 gap78[55];
  u8 field_AF;
  u32 field_B0;
  u32 field_B4;
  u32 field_B8;
  u32 field_BC;
  u32 playerInfo;
  u8 field_C4[4];
  CombatSet clientCombatSet;
  CombatSet serverCombatSet;
  PokemonParty *srcParties[4];
  PokemonParty *srcServerParties[4];
  PokemonParty *tmpParty;
  u32 field_2BC;
  PartyPokemon *tmpPartyPokemon;
  u32 field_2C4;
  u32 field_2C8;
  u32 field_2CC;
  u32 field_2D0;
  u32 field_2D4;
  u8 gap_2D8[260];
  u32 field_3DC;
  u32 chatotChatterBlock;
  u32 field_3E4;
  u32 field_3E8;
  u32 field_3EC;
  u32 randomSeed;
  u32 field_3F4;
  u32 field_3F8;
  u32 field_3FC;
  u32 field_400;
  u32 field_404;
  u32 field_408;
  u32 field_40C;
  u32 field_410;
  u32 field_414;
  u32 field_418;
  u32 field_41C;
  u16 field_420;
  PACKED ALIGNED(1) u32 field_422;
  u8 field_426;
  u8 field_427;
  u8 field_428[6];
  u8 field_42E;
  u8 field_42F;
  u32 winMoney;
  u32 bonusMoney;
  u32 loseMoney;
  u32 field_43C;
  u16 field_440;
  u16 field_442;
  u32 serverResult;
  EscapeInfo escapeInfo;
  u32 subproc;
  u32 field_454;
  u32 field_458;
  u32 field_45C;
  u32 subseq;
  u32 field_464;
  HEAP_ID heapID;
  u8 field_46A;
  u8 field_46B;
  u8 playerClientID;
  u8 field_46D;
  u8 field_46E;
  u8 field_46F;
  u8 field_470;
  u8 field_471;
  u8 field_472;
  u8 field_473;
  u32 pokestarScriptNarcPtr;
  u32 pokestarScriptHeapPtr;
  u32 field_47C;
} MainModule;

#endif // MAIN_MODULE_H
