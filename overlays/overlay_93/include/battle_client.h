#ifndef BATTLE_CLIENT_H
#define BATTLE_CLIENT_H

#include "types.h"

#include "heap.h"
#include "scripting.h"

#include "adapter.h"
#include "battle_action.h"
#include "battle_recorder.h"
#include "battlefield.h"
#include "combat_set.h"

/**
 * @file battle_client.h
 * @brief Battle client structures
 *
 * Defines the data of each player in the battle, it relies on
 * the BattleServer to handle combat logic.
 */

typedef struct RecPlayerControl {
  u8 field_0;
  u8 field_1;
  u8 field_2;
  u8 field_3;
  u16 field_4;
  u16 field_6;
  u16 field_8;
  u16 field_A;
  u16 field_C;
} RecPlayerControl;

typedef struct EscapeInfo {
  u32 count;
  u8 clientID[4];
} EscapeInfo;

typedef struct BattleString {
  u16 strID;
  u8 wait;
  u8 strTypeAndArgCount;
  u32 args[8];
} BattleString;

typedef struct PokemonSelect {
  BattleParty *party;
  u8 numSelect;
  u8 prohibit[6];
  u8 disabledPutPosSequence;
} PokemonSelect;

typedef struct PokemonSelectResult {
  u8 selIdx[3];
  u8 outPokeIdx[3];
  u8 count;
  u8 field_7;
  u8 cancel;
} PokemonSelectResult;

struct MainModule;
struct BattleCore;
typedef struct PACKED ALIGNED(4) BattleClient {
  MainModule *mainModule;
  CombatSet *combatSet;
  BattlePokemon *procMon;
  BattleActionParam *procAction;
  BattleRecorder *battleRecord;
  u32 battleRecordReader;
  RecPlayerControl recordPlayer;
  ALIGNED(4) u32 field_28;
  EscapeInfo escapeInfo;
  Battlefield *battleField;
  u8 gap_38[24];
  Adapter *adapter;
  BattleCore *battleCore;
  BattleString battleStr_58;
  u32 field_7C;
  BattleString battleStr_80;
  u8 gap_A4[4];
  u32 cmdCheckServer;
  BattlePokemon *battleParty[6];
  u32 field_C4;
  u32 field_C8;
  u8 field_CC;
  u32 (*callback_D0)(BattleClient *, u32 *) ALIGNED(4);
  u32 field_D4;
  u32 (*actionSelectProc)(BattleClient *, u32 *);
  u32 actionSelectSeq;
  BattleActionParam *returnDataActionSelect;
  u32 returnDataActionSelectCount;
  u32 field_E8;
  u16 cmdLimitTime;
  u16 field_EE;
  u16 AIBagItems[4];
  ScriptVM *scriptVM;
  u64 rand1;
  u64 rand2;
  u64 rand3;
  u8 field_114[6];
  u8 field_11A[4];
  ALIGNED(4) BattleParty *actBattleParty;
  u8 myCoverPosNum;
  u8 procPokeIdx;
  u8 prevPokeIdx;
  u8 firstPokeIdx;
  u8 stdMsgChanged;
  u8 field_129;
  u8 field_12A;
  ALIGNED(2) BattleActionParam actionParam[3];
  u8 field_138[4];
  u32 cmdQueue;
  u32 serverCmdArgs;
  u8 gap_144[60];
  u32 serverCmd;
  u32 serverCmd2;
  u32 serverCmdSeq;
  PokemonSelect pokeSelectParam;
  PokemonSelectResult pokeSelectResult;
  u8 field_1A1;
  HEAP_ID trainerMsgHeapID;
  u8 field_1A4;
  ALIGNED(2) u16 field_1A6;
  u16 selectItemWork[3];
  u8 myID;
  u8 field_1AF;
  u8 gap_1B0;
  u8 commWaitInfoOn;
  u8 field_1B2;
  u8 field_1B3;
  u8 field_1B4;
  u8 forceQuitActionSelect;
  u8 cmdCheckTimingCode;
  u8 currentActionCount;
  u8 moveInfoPokeIdx;
  u8 moveInfoMoveIdx;
  u8 actionSelectFlags;
  u8 myChangePokeCount;
  u8 field_1BC;
  u8 field_1BD;
  u8 myChangePokePos[6];
  u8 field_1C4;
  u8 field_1C5;
  u8 field_1C6;
  u8 field_1C7;
  u8 field_1C8;
  u8 field_1C9;
  u8 field_1CA;
  ALIGNED(2) u32 field_1CC;
  u32 field_1D0;
  u8 gap_1D4[20];
  u16 field_1E8;
  u16 field_1EA;
  u32 field_1EC;
  u32 field_1F0;
  u8 gap_1F4[16];
  u32 field_204;
  u8 gap_208[12];
  u32 field_214;
  u8 gap_218[4];
  u16 field_21C;
  ALIGNED(4) u32 field_220;
  u16 gap_224[22];
  u8 field_250;
} BattleClient;

#endif // BATTLE_CLIENT_H
