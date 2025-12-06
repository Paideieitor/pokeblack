#ifndef SERVER_FLOW_H
#define SERVER_FLOW_H

#include "server_params.h"
#include "types.h"

#include "battle_handler.h"
#include "main_module.h"
#include "moves.h"
#include "pokemon_set.h"
#include "server_command.h"

typedef struct ALIGNED(4) ActionOrderData {
  BattlePokemon *battleMon;
  BattleActionParam action;
  u32 speed;
  u8 partyID;
  u8 done;
  u8 field_E;
  u8 field_F;
} ActionOrderData;

#define ACTION_ORDER_GET_PRIO(actionOrder, idx)                                \
  (actionOrder[idx].speed >> 16) & 0x3FFFFF
#define ACTION_ORDER_GET_SPECIAL_PRIO(actionOrder, idx)                        \
  ((actionOrder[idx].speed >> 13) & 0x7)

typedef enum ActionIgnoreReason {
  REASON_NONE = 0x0,
  REASON_OTHER_MOVE = 0x1,
  REASON_FALL_ASLEEP = 0x2,
  REASON_CONFUSION = 0x3,
  REASON_OVERLEVELED = 0x4,
  REASON_ASLEEP = 0x5,
} ActionIgnoreReason;

struct ArcTool; // TODO: define archive processing structures

typedef struct ServerFlow {
  BattleServer *server;
  MainModule *mainModule;
  CombatSet *combatSet;
  ServerCommandQueue *serverCommandQueue;
  u32 turnCount;
  u32 flowResult;
  u32 heapHandle;
  MoveRecord moveRecord;
  FaintRecord faintRecord;
  ArcTool *evolutionDataPtr;
  MoveAnimation *moveAnimation;
  MoveStealParams *moveStealParams;
  MoveStealParams *magicCoatParams;
  HitCheckParams *hitCheckParams;
  EscapeInfo escapeInfo;
  u32 field_4C0;
  u32 field_4C4;
  u32 field_4C8;
  u16 field_4CC;
  u16 field_4CE;
  u32 field_4D0;
  u8 field_4D4[672];
  u32 simulationCounter;
  u32 moveSerial;
  u8 cmdBuildStep;
  u8 field_77D;
  u8 turnCheckSeq;
  u8 defaultTargetPos;
  HEAP_ID heapID;
  u8 numActOrder;
  u8 numEndActOrder;
  u8 field_784;
  u8 revivedPokeCount;
  u8 field_786;
  u8 field_787;
  u8 field_788;
  u8 thruDeadMsgPokeID;
  u8 field_78A;
  u8 gap_78B;
  u8 field_78C;
  u8 field_78D;
  u8 field_78E;
  u8 field_78F;
  u8 field_790;
  u8 revivePokeID[24];
  u8 pokeInFlag[24];
  u8 afterTurnStartSlots[24];
  u8 switchCount[4];
  u8 field_7DD;
  u8 field_7DE;
  u8 field_7DF;
  ActionOrderData actionOrder[6];
  ActionOrderData tempActionOrderData;
  PokemonSet *originalTargetSet;
  PokemonSet *targetSet;
  PokemonSet *allySet;
  PokemonSet *enemySet;
  PokemonSet *damagedSet;
  PokemonSet *stealTargetSet;
  PokemonSet *tmpSet;
  DmgCalcRecord *allyDmgCalc;
  DmgCalcRecord *enemyDmgCalc;
  PokemonSetStack pokesetUnit[7];
  u32 pokeSetStackPtr;
  PokemonSet currentSet;
  MoveParams *moveParam;
  MoveParams *moveParamOriginal;
  PokemonPosition pokemonPosition;
  u8 field_1AE2;
  u8 field_1AE3;
  HandlerParam_String strParam;
  ExpCalcParams *levelUpInfo;
  u8 gap_1B10[68];
  u32 field_1B54;
  u8 gap_1B58[316];
  u8 field_1C88;
  u8 field_1C89;
  u8 field_1C8A;
  u8 field_1C97;
  u8 gap1C98[224];
  u32 HEManager;
  u8 gap_1D7C[8];
  u8 field_1D84;
  u8 field_1D85;
  u8 field_1D86;
  u8 field_1D87;
  u8 field_1D88;
  u8 field_1D89;
  u8 field_1D8A;
  u8 gap_1D8B[481];
  u8 field_1F6C;
  u8 gap_1F6D[11];
  u16 prevUsedMove;
  u8 field_1F7A;
  u8 field_1F7B;
  ActionIgnoreReason actionIgnoreReason;
  EffectivenessParams effectivenessCounter;
  u32 dmgAffRec;
  u8 gap_1F90[8];
  u8 field_1F98;
  u8 gap_1F99[83];
  u8 field_1FEC[4];
  u8 tmpWork;
  u8 field_1FF1;
  u8 gap_1FF2[318];
  u32 field_2130;
  u8 gap_2134[8];
  u8 field_213C;
  u8 field_213D;
  u8 field_213E;
  u8 field_213F;
} ServerFlow;

#endif // !SERVER_FLOW_H
