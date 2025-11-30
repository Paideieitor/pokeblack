#ifndef CONDITIONS_H
#define CONDITIONS_H

#include "types.h"

/**
 * @file conditions.h
 * @brief Move condition values and structures
 *
 * Define the values and structures that represent the conditions
 * that can be applied to a Pokémon.
 */

/**
 * @brief Move condition enumerator
 *
 * Before CONDITION_CONFUSION (0x6) all conditons are non-volatile and
 * can be refered as status conditions.
 * CONDITION_24 (0x24) is used to refer to all conditions when healing.
 */
typedef enum MoveCondition {
    CONDITION_NONE = 0x0,
    CONDITION_PARALYSIS = 0x1,
    CONDITION_SLEEP = 0x2,
    CONDITION_FREEZE = 0x3,
    CONDITION_BURN = 0x4,
    CONDITION_POISON = 0x5,
    CONDITION_CONFUSION = 0x6,
    CONDITION_ATTRACT = 0x7,
    CONDITION_BIND = 0x8,
    CONDITION_NIGHTMARE = 0x9,
    CONDITION_CURSE = 0xA,
    CONDITION_TAUNT = 0xB,
    CONDITION_TORMENT = 0xC,
    CONDITION_DISABLE = 0xD,
    CONDITION_YAWN = 0xE,
    CONDITION_HEALBLOCK = 0xF,
    CONDITION_GASTROACID = 0x10,
    CONDITION_FORESIGHT = 0x11,
    CONDITION_LEECHSEED = 0x12,
    CONDITION_EMBARGO = 0x13,
    CONDITION_PERISHSONG = 0x14,
    CONDITION_INGRAIN = 0x15,
    CONDITION_BLOCK = 0x16,
    CONDITION_ENCORE = 0x17,
    CONDITION_ROOST = 0x18,
    CONDITION_MOVELOCK = 0x19,
    CONDITION_CHARGELOCK = 0x1A,
    CONDITION_CHOICELOCK = 0x1B,
    CONDITION_MUSTHIT = 0x1C,
    CONDITION_LOCKON = 0x1D,
    CONDITION_FLOATING = 0x1E,
    CONDITION_KNOCKEDDOWN = 0x1F,
    CONDITION_TELEKINESIS = 0x20,
    CONDITION_SKYDROP = 0x21,
    CONDITION_ACCURACYUP = 0x22,
    CONDITION_AQUARING = 0x23,
    CONDITION_24 = 0x24,
} MoveCondition;

/**
 * @brief Move condition flag enumerator
 *
 * Flags that are set on a Pokémon when using certain moves or items
 * that persist for some turns of the battle.
 */
typedef enum ConditionFlag {
    CONDITIONFLAG_ACTIONDONE = 0x0,    // Used by Sucker Punch
    CONDITIONFLAG_NOSWITCH = 0x1,    // Used by switch-blocking moves
    CONDITIONFLAG_CHARGE = 0x2,
    CONDITIONFLAG_FLY = 0x3,
    CONDITIONFLAG_DIVE = 0x4,
    CONDITIONFLAG_DIG = 0x5,
    CONDITIONFLAG_SHADOWFORCE = 0x6,
    CONDITIONFLAG_DEFENSECURL = 0x7,
    CONDITIONFLAG_MINIMIZE = 0x8,
    CONDITIONFLAG_FOCUSENERGY = 0x9,
    CONDITIONFLAG_POWERTRICK = 0xA,
    CONDITIONFLAG_MICLEBERRY = 0xB,
    CONDITIONFLAG_NOACTION = 0xC,    // Used by Truant
    CONDITIONFLAG_FLASHFIRE = 0xD,
    CONDITIONFLAG_BATONPASS = 0xE,
    CONDITIONFLAG_NULL = 0xF,
} ConditionFlag;

/**
 * @brief Move condition data structure
 *
 * Stores the required data to apply a move condition.
 * Needs more research since diferent conditions use diferent bit
 * configurations. This one is the default for status.
 */
typdedef struct ConditionData {
    u32 status : 3;
    u32 turncount : 3;
    u32 field7 : 3;
    u32 param : 3;
    u32 rest : 20;
} ConditionData;

#endif // CONDITIONS_H
