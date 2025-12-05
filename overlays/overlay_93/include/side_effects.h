#ifndef SIDE_EFFECTS_H
#define SIDE_EFFECTS_H

#include "types.h"

/**
 * @file side_effects.h
 * @brief Side effect values
 *
 * Define the values that represent the effects that can
 * be triggered in battle, that affect the one side of the field.
 */

/**
 * @brief Side effect enumerator
 */
typedef enum SideEffect {
  SIDEEFF_REFLECT = 0x0,
  SIDEEFF_LIGHT_SCREEN = 0x1,
  SIDEEFF_SAFEGUARD = 0x2,
  SIDEEFF_MIST = 0x3,
  SIDEEFF_TAILWIND = 0x4,
  SIDEEFF_LUCKY_CHANT = 0x5,
  SIDEEFF_SPIKES = 0x6,
  SIDEEFF_TOXIC_SPIKES = 0x7,
  SIDEEFF_STEALTH_ROCK = 0x8,
  SIDEEFF_WIDE_GUARD = 0x9,
  SIDEEFF_QUICK_GUARD = 0xA,
  SIDEEFF_RAINBOW = 0xB,
  SIDEEFF_SEA_OF_FIRE = 0xC,
  SIDEEFF_SWAMP = 0xD,
} SideEffect;

/**
 * @brief Side effect removal macros
 *
 * When removing the side effects this macros are useful, this should
 * be moved with the relevant Battle Handler
 */
#define REMOVE_SIDE_EFFECT_SETUP(flags)                                        \
  flags[0] = 3;                                                                \
  flags[1] = 0;                                                                \
  flags[2] = 0
#define SET_REMOVE_SIDE_EFFECT_FLAG(sideEffect, flags)                         \
  flags[(sideEffect >> 3) + 1] =                                               \
      flags[(sideEffect >> 3) + 1] | (1 << (sideEffect & 7))

#endif // SIDE_EFFECTS_H
