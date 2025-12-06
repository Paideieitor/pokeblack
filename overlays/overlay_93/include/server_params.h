#ifndef SERVER_PARAMS_H
#define SERVER_PARAMS_H

#include "types.h"

#include "moves.h"

typedef struct PokemonPositionState {
  u8 enable;
  u8 clientID;
  u8 existPokeID;
} PokemonPositionState;

typedef struct PokemonPosition {
  PokemonPositionState state[6];
  u8 lastPos[24];
} PokemonPosition;

typedef struct MoveAnimation {
  u16 move;
  u8 attackerPos;
  u8 targetPos;
  u8 effectIdx;
  u8 flags;
  u16 subEff;
} MoveAnimation;

typedef struct PACKED ALIGNED(1) MoveStealParams {
  u8 count;
  u8 stealSlot[6];
  u8 targetPos[6];
  u8 targetSlot[6];
} MoveStealParams;

typedef struct HitCheckParams {
  u8 countMax;
  u8 count;
  u8 checkEveryTime;
  u8 multiHitMove;
  u8 putAnimCmd;
  u8 multiHitEffectiveness;
} HitCheckParams;

typedef struct MoveParams {
  u16 move;
  u16 originalMove;
  u16 userType;
  u8 moveType;
  u8 damageType;
  MoveCategory category;
  MoveTarget target;
  u32 flags;
} MoveParams;

typedef struct ALIGNED(2) ExpCalcParams {
  u32 level;
  u8 isBoosted;
  u8 hp;
  u8 atk;
  u8 def;
  u8 spAtk;
  u8 spDef;
  u8 spe;
} ExpCalcParams;

typedef struct EffectivenessParams {
  u16 noEffectHits;
  u16 superEffectiveHits;
  u16 notVeryEffectiveHits;
  u16 opponentNoEffectHits;
  u16 opponentSuperEffectiveHits;
  u16 opponentNotVeryEffectiveHits;
} EffectivenessParams;

#endif // !SERVER_PARAMS_H
