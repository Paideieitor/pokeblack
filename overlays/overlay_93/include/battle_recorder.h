#ifndef BATTLE_RECORDER_H
#define BATTLE_RECORDER_H

#include "types.h"

typedef struct ALIGNED(4) BattleRecorder {
  u8 field_0;
  u8 field_1;
  u8 gap_2[3078];
  u32 field_C08;
} BattleRecorder;

#endif // !BATTLE_RECORDER_H
