#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "types.h"

#include "battle_event.h"
#include "conditions.h"
#include "field_effects.h"

/**
 * @file battlefield.h
 * @brief Battlefield structure
 *
 * Defines the data that manages the battlefield and its effects.
 */

typedef struct Battlefield {
  Weather weather;
  u32 weatherTurns;
  BattleEventItem *battleEventItems[FLDEFF_MAX];
  ConditionData conditionData[FLDEFF_MAX];
  u32 turnCount[FLDEFF_MAX];
  u32 dependPokeID[FLDEFF_MAX][6];
  u32 dependPokeCount[FLDEFF_MAX];
  u32 effectEnableFlags[FLDEFF_MAX];
} Battlefield;

#endif // BATTLEFIELD_H
