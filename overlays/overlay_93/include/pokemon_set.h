#ifndef POKEMON_SET_H
#define POKEMON_SET_H

#include "types.h"

#include "battle_pokemon.h"
#include "server_params.h"
#include "server_records.h"

typedef struct ALIGNED(4) PokemonSet {
  BattlePokemon *battleMon[6];
  u16 damage[6];
  u16 substituteDamage[6];
  u8 damageType[6];
  u16 sortWork[6];
  u8 count;
  u8 countMax;
  u8 getIdx;
  u8 targetPosCount;
} PokemonSet;

typedef struct PokemonSetStack {
  PokemonSet targetOriginal;
  PokemonSet target;
  PokemonSet ally;
  PokemonSet enemy;
  PokemonSet damaged;
  PokemonSet stealTarget;
  PokemonSet tmp;
  MoveAnimation moveAnimCtrl;
  MoveParams moveParam;
  MoveParams moveParamOriginal;
  HitCheckParams hitCheck;
  MoveStealParams moveStealParam;
  MoveStealParams magicCoatParam;
  DmgCalcRecord allyDmgCalc;
  DmgCalcRecord enemyDmgCalc;
  u8 defaultTargetPos;
  u8 field_28D;
  u8 field_28E;
  u8 field_28F;
} PokemonSetStack;

#endif // !POKEMON_SET_H
