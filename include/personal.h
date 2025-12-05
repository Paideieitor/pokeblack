#ifndef PERSONAL_H
#define PERSONAL_H

#include "types.h"

/**
 * @file personal.h
 * @brief Pokémon personal values and structures
 *
 * Define the values and structures that represent a Pokémon.
 */

typedef enum EggGroup {
  EGG_NONE = 0x0,
  EGG_MONSTER = 0x1,
  EGG_WATER_1 = 0x2,
  EGG_BUG = 0x3,
  EGG_FLYING = 0x4,
  EGG_FIELD = 0x5,
  EGG_FAIRY = 0x6,
  EGG_GRASS = 0x7,
  EGG_HUMAN_LIKE = 0x8,
  EGG_WATER_3 = 0x9,
  EGG_MINERAL = 0xA,
  EGG_AMORPHOUS = 0xB,
  EGG_WATER_2 = 0xC,
  EGG_DITTO = 0xD,
  EGG_DRAGON = 0xE,
  EGG_UNKNOWN = 0xF,
} EggGroup;

/**
 * @brief Personal data structure
 *
 * Stores the data of a Pokémon, this is the data layout of the files in the
 * narc "a/0/1/6"
 */
typedef struct PersonalData {
  u8 baseHP;
  u8 baseATK;
  u8 baseDEF;
  u8 baseSPE;
  u8 baseSPA;
  u8 baseSPD;
  u8 types[2];
  u8 captureRate;
  u8 stage;
  u16 evYield;
  u16 wildItem50;
  u16 wildItem5;
  u16 wildItem1;
  u8 sexProbability;
  u8 eggHappiness;
  u8 baseHappiness;
  u8 expGrowthRate;
  u8 eggGroups[2];
  u8 Abilities[3];
  u8 escapeRate;
  u16 formDataOffset;
  u16 formSpriteOffset;
  u8 formCount;
  u8 color;
  u16 baseEXP;
  u16 height; // Decimeters
  u16 weight; // Hectograms
  u32 TMs_HMs[4];
  u32 unknown; // In BW2 this is occupied by move tutor flags, needs research
} PersonalData;

/**
 * @brief Personal field enumerator
 *
 * Values of the fields in the personal data layout
 */
typedef enum PersonalField {
  PERSONAL_HP = 0x0,
  PERSONAL_ATK = 0x1,
  PERSONAL_DEF = 0x2,
  PERSONAL_SPE = 0x3,
  PERSONAL_SPA = 0x4,
  PERSONAL_SPD = 0x5,
  PERSONAL_TYPE_1 = 0x6,
  PERSONAL_TYPE_2 = 0x7,
  PERSONAL_CAPTURE_RATE = 0x8,
  PERSONAL_BASE_EXP = 0x9,
  PERSONAL_EV_HP = 0xA,  // evYield (0x0003)
  PERSONAL_EV_ATK = 0xB, // evYield (0x000C)
  PERSONAL_EV_DEF = 0xC, // evYield (0x0030)
  PERSONAL_EV_SPE = 0xD, // evYield (0x00C0)
  PERSONAL_EV_SPA = 0xE, // evYield (0x0300)
  PERSONAL_EV_SPD = 0xF, // evYield (0x0C00)
  PERSONAL_GROUNDED_SPRITE =
      0x10, // evYield (0x1000) [Used by Diglett and Dugtrio]
  PERSONAL_WILD_ITEM_50 = 0x11, // 50% chance
  PERSONAL_WILD_ITEM_5 = 0x12,  // 5% chance
  PERSONAL_WILD_ITEM_1 = 0x13,  // 1% chance
  PERSONAL_SEX_PROBABILITY = 0x14,
  PERSONAL_EGG_HAPPINESS = 0x15,
  PERSONAL_BASE_HAPPINESS = 0x16,
  PERSONAL_EXP_GROWTH_RATE = 0x17,
  PERSONAL_EGG_GROUP_1 = 0x18,
  PERSONAL_EGG_GROUP_2 = 0x19,
  PERSONAL_ABILITY_1 = 0x1A,
  PERSONAL_ABILITY_2 = 0x1B,
  PERSONAL_ABILITY_HIDDEN = 0x1C,
  PERSONAL_ESCAPE_RATE = 0x1D,
  PERSONAL_FORM_DATA_OFFSET =
      0x1E, // Offset after the last data file where the form files are located
            // (narcs a/0/0/16, a/0/0/18, a/0/0/19)
  PERSONAL_FORM_SPRITE_OFFSET =
      0x1F, // Offset after the sprite files where the form sprite files are
            // located (narc a/0/0/4)
  PERSONAL_FORM_COUNT = 0x20,  // Base form included
  PERSONAL_COLOR = 0x21,       // color (0x3F)
  PERSONAL_SPRITE_FLIP = 0x22, // color (0x40)
  PERSONAL_SPRITE_FORM = 0x23, // color (0x80)
  PERSONAL_STAGE = 0x24,
  PERSONAL_HEIGHT = 0x25,
  PERSONAL_WEIGHT = 0x26,
  PERSONAL_TM_HM_1 = 0x27,
  PERSONAL_TM_HM_2 = 0x28,
  PERSONAL_TM_HM_3 = 0x29,
  PERSONAL_TM_HM_4 = 0x2A,
  PERSONAL_UNKNOWN = 0x2B
} PersonalField;

#endif // PERSONAL_H
