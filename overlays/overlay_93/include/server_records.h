#ifndef SERVER_RECORDS_H
#define SERVER_RECORDS_H

#include "types.h"

typedef struct MoveRecordUnit {
  u32 turn;
  u16 moveID;
  u8 pokeID;
  u8 effective;
} MoveRecordUnit;

typedef struct MoveRecord {
  u32 ptr;
  MoveRecordUnit record[120];
} MoveRecord;

typedef struct FaintRecordUnit {
  u8 count;
  u8 expChecked[24];
  u8 faintPokeID[24];
} FaintRecordUnit;

typedef struct FaintRecord {
  FaintRecordUnit turnRecord[4];
} FaintRecord;

typedef struct PACKED ALIGNED(1) DmgCalcData {
  u16 substituteFlag : 1;
  u16 fixedDamageFlag : 1;
  u16 critFlag : 1;
  u16 unknownFlags : 3;
  u16 endureFlag : 1;
  u16 effectiveness : 4;
  u16 targetSlot : 5;
} DmgCalcData;

typedef struct PACKED ALIGNED(1) DmgCalcRecordUnit {
  u16 damage;
  u16 pokeData; // CalcDmgPokeData
} DmgCalcRecordUnit;

typedef struct PACKED ALIGNED(2) DmgCalcRecord {
  u8 realHitCount;
  u8 substituteHitCount;
  u8 totalHitCount;
  u8 unknown;
  DmgCalcRecordUnit record[6];
} DmgCalcRecord;

#endif // !SERVER_RECORDS_H
