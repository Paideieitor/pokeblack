#ifndef TRAINERS_H
#define TRAINERS_H

#include "types.h"

/**
 * @file trainers.h
 * @brief Trainer values and structures
 *
 * Define the values and structures that represent the trainers
 * and their parties.
 * A trainer can load 4 different data layouts for their Pokémon
 * depending on their trainer type.
 */

/**
 * @brief Trainer type enumerator
 */
typedef enum TrainerType {
  SIMPLE_TRAINER, // Each member uses the TeamMember data layout
  MOVES_TRAINER,  // Each member uses the MovesMember data layout
  ITEM_TRAINER,   // Each member uses the ItemMember data layout
  GOOD_TRAINER,   // Each member uses the GoodMember data layout
} TrainerType;

/**
 * @brief AI flags enumerator
 *
 * Defines the values that represent certain AI behaviors.
 * Check this document for more details:
 * https://docs.google.com/document/d/1AziiMPsY1TcABKIwl92677A4nYGtByvjFOR7p6PAXY0/edit?usp=sharing
 */
typedef enum AIFlags {
  AI_NO_EFFECT_CHECK = 0x0,
  AI_EVALUATE_MOVES = 0x1,
  AI_EXPERT = 0x2,
  AI_SET_UP = 0x3,
  AI_FIRST_RIVAL = 0x4,
  AI_N_S_FINAL_BATTLE = 0x5,
  AI_BATON_PASS = 0x6,
  AI_DOUBLE_TRIPLE_BATTLE = 0x7,
  AI_HP_BASED = 0x8,
  AI_WEATHER = 0x9,
  AI_DISRUPTION = 0xA,
  AI_ROAMING = 0xB,
  AI_SAFARI = 0xC,
  AI_TUTORIAL = 0xD,
} AIFlags;

/**
 * @brief Trainer data structure
 *
 * Stores the data of an trainer, this is the data layout of the files in the
 * narc "a/0/9/2".
 */
typedef struct TrainerData {
  u8 trainerType; // TrainerType
  u8 trainerClass;
  u8 battleType;
  u8 pokemonCount;
  u16 heldItems[4];
  u32 AI; // AIFlags
  u8 isHealer;
  u8 money;
  u16 itemAfterBattle;
} TrainerData;

/**
 * @brief Sex of a trainer member enumerator
 *
 * Defines the values that can be set to assign a sex to a trainers Pokémon.
 */
typedef enum MemberSex {
  MEMBER_SEX_RANDOM = 0x0,
  MEMBER_SEX_MALE = 0x1,
  MEMBER_SEX_FEMALE = 0x2,
  MEMBER_SEX_NONE = 0x3,
} MemberSex;

/**
 * @brief Ability of a trainer member enumerator
 *
 * Defines the values that can be set to assign an avility to a trainers
 * Pokémon.
 */
typedef enum MemberAbility {
  MEMBER_ABILITY_RANDOM = 0x0,
  MEMBER_ABILITY_1 = 0x1,
  MEMBER_ABILITY_ANY = 0x2,
  MEMBER_ABILITY_HIDDEN = 0x3,
} MemberAbility;

/**
 * @brief Team member data structure
 *
 * Stores the default data of an trainers Pokémon, this is the data layout of
 * the files in the narc "a/0/9/3". The file is comprised of consecutive
 * members, the amount is specified in the trainer data. Depending on the
 * trainer type this structure can have additional information.
 */
typedef struct TeamMember {
  u8 difficulty;    // Each IV value is set to "31 * difficulty / 255"
  u8 sexAndAbility; // MemberSex (0x0F) | MemberAbility (0xF0)
  u16 level;
  u16 species;
  u16 form;
} TeamMember;

/**
 * @brief Moves member data structure
 *
 * Team member that also specifies the moves the Pokémon has.
 */
typedef struct MovesMember {
  TeamMember header;
  u16 moves[4];
} MovesMember;

/**
 * @brief Item member data structure
 *
 * Team member that also specifies the held item the Pokémon has.
 */
typedef struct ItemMember {
  TeamMember header;
  u16 item;
} ItemMember;

/**
 * @brief Good member data structure
 *
 * Team member that also specifies the held item and the moves the Pokémon has.
 */
typedef struct GoodMember {
  TeamMember header;
  u16 item;
  u16 moves[4];
} GoodMember;

#endif // TRAINERS_H
