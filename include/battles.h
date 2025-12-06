#ifndef BATTLES_H
#define BATTLES_H

typedef enum BattleType {
  BTL_TYPE_WILD = 0x0,
  BTL_TYPE_TRAINER = 0x1,
  BTL_TYPE_FACILITY = 0x2,
  BTL_TYPE_ONLINE = 0x3,
  BTL_TYPE_DEMO = 0x4,
  BTL_TYPE_MAX = 0x5,
} BattleType;

typedef enum BattleStyle {
  BTL_STYLE_SINGLE = 0x0,
  BTL_STYLE_DOUBLE = 0x1,
  BTL_STYLE_TRIPLE = 0x2,
  BTL_STYLE_ROTATION = 0x3,
} BattleStyle;

typedef enum BattleResult {
  BTL_RESULT_DEFEAT = 0x0,
  BTL_RESULT_VICTORY = 0x1,
  BTL_RESULT_DRAW = 0x2,
  BTL_RESULT_FLEE = 0x3,
  BTL_RESULT_FLEE_FOE = 0x4,
  BTL_RESULT_CAPTURE = 0x5,
  BTL_RESULT_6 = 0x6,
} BattleResult;

#endif // !BATTLES_H
