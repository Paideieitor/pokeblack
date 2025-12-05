#ifndef BATTLE_ACTION_H
#define BATTLE_ACTION_H

#include "types.h"

/**
 * @file battle_action.h
 * @brief Battle action structures
 *
 * Define the behavior that the player or the AI have decided over a Pokémon.
 * Each fit the required data to perform that action in order to be stored
 * and used in the apropiate turn order.
 * The "cmd" field stores a number that identifies the action when its used:
 * 	Fight [1]
 * 	Use Item [2]
 *	Switch [3]
 *	Run [4]
 *	5, 6 and 7 are valid ActionIDs but they need to be researched
 *
 *	Check this document for more details:
 *	https://docs.google.com/document/d/1OKfd_iODjx2WewVxfE8QuP3O7oMPC-8rdrTC_BBi_QY/edit?usp=sharing
 */

typedef struct BattleActionFight {
  u32 cmd : 4;
  u32 targetPos : 3;
  u32 move : 16;
  u32 pad : 9;
} BattleActionFight;

typedef struct BattleActionItem {
  u32 cmd : 4;
  u32 targetPos : 3;
  u32 item : 16;
  u32 param : 8; // Example: Used for X items boost amout
  u32 pad : 1;
} BattleActionItem;

typedef struct BattleActionSwitch {
  u32 cmd : 4;
  u32 switchSlot : 3;
  u32 memberIdx : 3;
  u32 depleteFlag : 1;
  u32 pad : 21;
} BattleActionSwitch;

typedef struct BattleActionRun {
  u32 cmd : 4;
  u32 pad : 28;
} BattleActionRun;

typedef struct BattleActionDefault {
  u32 cmd : 4;
  u32 param : 28;
} BattleActionDefault;

typedef union BattleActionParam {
  BattleActionFight actFight;
  BattleActionItem actItem;
  BattleActionSwitch actSwitch;
  BattleActionRun actRun;
  BattleActionDefault actDefault;
} BattleActionParam;

#endif // BATTLE_ACTION_H
