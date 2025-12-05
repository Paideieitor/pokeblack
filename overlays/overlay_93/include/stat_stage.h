#ifndef STAT_STAGE_H
#define STAT_STAGE_H

/**
 * @file stat_stage.h
 * @brief Stat stage values
 *
 * Define the values that represent the stats that can be
 * boosted or decreased mid-battle.
 */

/**
 * @brief Stat stage enumerator
 */
typedef enum StatStage {
  STAT_STAGE_NULL = 0x0,
  STAT_STAGE_ATTACK = 0x1,
  STAT_STAGE_DEFENSE = 0x2,
  STAT_STAGE_SPECIAL_ATTACK = 0x3,
  STAT_STAGE_SPECIAL_DEFENSE = 0x4,
  STAT_STAGE_SPEED = 0x5,
  STAT_STAGE_ACCURACY = 0x6,
  STAT_STAGE_EVASION = 0x7,
} StatStage;

#endif // STAT_STAGE_H
