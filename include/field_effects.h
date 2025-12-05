#ifndef FIELD_EFFECTS_H
#define FIELD_EFFECTS_H

#include "types.h"

/**
 * @file field_effects.h
 * @brief Field effect values
 *
 * Define the values that represent the effects that can
 * be triggered in battle, that affect the whole field.
 */

typedef enum Weather {
  WEATHER_NULL = 0x0,
  WEATHER_SUN = 0x1,
  WEATHER_RAIN = 0x2,
  WEATHER_HAIL = 0x3,
  WEATHER_SANDSTORM = 0x4,
  WEATHER_MAX = 0x5,
} Weather;

typedef enum FieldEffect {
  FLDEFF_WEATHER = 0x0,
  FLDEFF_TRICK_ROOM = 0x1,
  FLDEFF_GRAVITY = 0x2,
  FLDEFF_IMPRISON = 0x3,
  FLDEFF_WATER_SPORT = 0x4,
  FLDEFF_MUD_SPORT = 0x5,
  FLDEFF_WONDER_ROOM = 0x6,
  FLDEFF_MAGIC_ROOM = 0x7,
  FLDEFF_MAX = 0x8,
} FieldEffect;

#endif // FIELD_EFFECTS_H
