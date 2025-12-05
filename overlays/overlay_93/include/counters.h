#ifndef COUNTERS_H
#define COUNTERS_H

#include "types.h"

/**
 * @file counters.h
 * @brief Pokémon counter values
 *
 * Define the values that represent the counters a move can trigger.
 */

typedef enum Counter {
  COUNTER_STOCKPILE = 0x0,
  COUNTER_STOCKPILE_DEF = 0x1,
  COUNTER_STOCKPILE_SPDEF = 0x2,
  COUNTER_PROTECT = 0x3,
  COUNTER_SKYDROP = 0x4,
} Counter;

#endif // COUNTERS_H
