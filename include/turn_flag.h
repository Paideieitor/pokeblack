#ifndef TURN_FLAG_H
#define TURN_FLAG_H

/**
 * @file turn_flag.h
 * @brief Turn flag values
 *
 * Define the values that represent the different relevant states
 * a Pokémon can have each turn.
 * This flags get reset when the turn ends.
 */

/**
 * @brief Side effect enumerator
 */
typedef enum TurnFlag {
    TURN_FLAG_ACTION_START = 0x0,
    TURN_FLAG_ACTION_DONE = 0x1,
    TURN_FLAG_DAMAGED = 0x2,
    TURN_FLAG_MOVE_PROC_DONE = 0x3,
    TURN_FLAG_FLINCH = 0x4,
    TURN_FLAG_FOCUS_PUNCH_READY = 0x5,
    TURN_FLAG_FOCUS_PUNCH_FAIL = 0x6,
    TURN_FLAG_PROTECT = 0x7,
    TURN_FLAG_ITEM_CONSUMED = 0x8,
    TURN_FLAG_CANT_USE_ITEM = 0x9,
    TURN_FLAG_COMBO_MOVE_READY = 0xA,
    TURN_FLAG_HIDE_MOVE_OFF = 0xB,
    TURN_FLAG_MOVED = 0xC,
    TURN_FLAG_TURN_CHECK_CONDITION_PASSED = 0xD,
    TURN_FLAG_ACCURACY_UP = 0xE,
    TURN_FLAG_USING_FLING = 0xF,
} TurnFlag;

#endif // TURN_FLAG_H
