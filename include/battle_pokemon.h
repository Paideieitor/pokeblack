#ifndef BATTLE_POKEMON_H
#define BATTLE_POKEMON_H

#include "types.h"

#include "items.h"
#include "conditions.h"
#include "pokemon_types.h"
#include "species.h"
#include "stat_stage.h"
#include "moves.h"
#include "counters.h"

#include "pokemon_party.h"

/**
 * @file battle_pokemon.h
 * @brief Battle pokemon data structure
 *
 * Stores the data of a Pokémon while in a battle, this is the object
 * that the battle engine is build around.
 */

typedef struct PokemonStatStages {
    u8 attack;
    u8 defense;
    u8 spAttack;
    u8 spDefense;
    u8 speed;
    u8 accuracy;
    u8 evasion;
} PokemonStatStages;

typedef struct MoveCore {
    u16 move;
    u8 currentPP;
    u8 maxPP;
    u8 PPUpCount;
    u8 usedFlag;
} MoveCore;

/**
 * @brief Complete move structure
 *
 * Stores the data in a move slot while in a battle.
 */
typedef struct MoveSet {
    MoveCore truth; // Original move of the Pokémon
    MoveCore surface; // Actual move that can be selected at the moment (this can happen because of Transform and other interactions)
    u8 isLinked; // True if truth and surface are the same move
} MoveSet;

typedef struct MoveDamageRecord {
    u16 move;
    u16 damage;
    u8 moveCategory;
    u8 moveType;
    u8 battleSlot;
    u8 battlePos;
} MoveDamageRec;

typedef struct BattlePokemon {
    PartyPokemon* partySrc;
    PartyPokemon* disguiseSrc;
    u32 experience;
    u16 species;
    u16 maxHP;
    u16 currentHP;
    u16 heldItem;
    u16 usedItem;
    u16 ability;
    u8 level;
    u8 battleSlot;
    u8 baseAttack;
    u8 flags;
    // 1000 0000 unk
    // 0100 0000 mon is disguised by Illusion
    // 0010 0000 mon has transformed using Transform or Impostor
    // 0001 1111 form when battle started
    ConditionData conditions[36];
    u8 moveConditionCounter[36];
    u8 confrontRecCount;
    u8 confrontRec[24];
    u8 gap_E9[5];
    u16 attack;
    u16 defense;
    u16 specialAttack;
    u16 specialDefense;
    u16 speed;
    u8 Type1;
    u8 Type2;
    u8 Sex;
    u8 field_FB;
    PokemonStatStages statStages;
    u8 field_103;
    MoveSet moves[4];
    u16 currentAbility;
    u16 weight;
    u8 moveCount; // 0 to 4, amount of move slots that are not empty
    u8 form;
    u8 critStage;
    u8 usedMoveCount; // 0 to 4, amount of moves used from the 4 it has
    u8 prevMoveType;
    u8 field_145;
    u16 turnCount;
    u16 appearedTurn;
    u16 previousMove;
    u16 previousMoveID;
    u16 consecutiveMoveCounter;
    u16 field_150;
    u8 prevTargetPos;
    u16 turnFlags;
    u16 conditionFlags;
    u8 counters[5];
    MoveDamageRecord damageRecord[3][6];
    u8 damageRecordCount[3];
    u8 damageRecordTurn;
    u8 damageRecordPtr;
    u8 field_1F1;
    u16 substituteHP;
    u16 comboMoveID;
    u8 comboBattleSlot;
    u8 field_1F7;
} BattlePokemon;

typedef enum BattlePokemonValue {
    VALUE_NULL = 0x0,
    VALUE_ATTACK_STAGE = 0x1,
    VALUE_DEFENSE_STAGE = 0x2,
    VALUE_SPECIAL_ATTACK_STAGE = 0x3,
    VALUE_SPECIAL_DEFENSE_STAGE = 0x4,
    VALUE_SPEED_STAGE = 0x5,
    VALUE_ACCURACY_STAGE = 0x6,
    VALUE_EVASION_STAGE = 0x7,
    VALUE_ATTACK_STAT = 0x8,
    VALUE_DEFENSE_STAT = 0x9,
    VALUE_SPECIAL_ATTACK_STAT = 0xA,
    VALUE_SPECIAL_DEFENSE_STAT = 0xB,
    VALUE_SPEED_STAT = 0xC,
    VALUE_CURRENT_HP = 0xD,
    VALUE_MAX_HP = 0xE,
    VALUE_LEVEL = 0xF,
    VALUE_ABILITY = 0x10,
    VALUE_EFFECTIVE_ABILITY = 0x11, // Returns the current active ability, acounting for Gastro Acid
    VALUE_SEX = 0x12,
    VALUE_FORM = 0x13,
    VALUE_EXPERIENCE = 0x14,
    VALUE_BASE_ATTACK = 0x15,
} BattlePokemonValue;

struct BattleParty
{
    BattlePokemon* members[6];
    u8 memberCount;
    u8 numCoverPos;
};

#endif // BATTLE_POKEMON_H
