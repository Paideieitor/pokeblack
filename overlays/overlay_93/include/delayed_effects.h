#ifndef DELAYED_EFFECTS_H
#define DELAYED_EFFECTS_H

#include "types.h"

/**
 * @file delayed_effects.h
 * @brief Delayed effect values
 *
 * Define the values that represent the effects of moves that linger
 * after they were used.
 * The behavior of a move is loaded at the start of the fight action
 * and unloaded when it ends, so if a move needs to last longer the
 * delayed effect stores and executes that behavior.
 */

typedef enum DelayedEffect {
  DELEFF_WISH = 0x0,
  DELEFF_LUNAR_DANCE = 0x1,
  DELEFF_HEALING_WISH = 0x2,
  DELEFF_FUTURE_SIGHT = 0x3,
  DELEFF_BATON_PASS = 0x4,
} DelayedEffects;

#endif // DELAYED_EFFECTS_H
