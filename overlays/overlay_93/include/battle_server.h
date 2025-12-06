#ifndef BATTLE_SERVER_H
#define BATTLE_SERVER_H

#include "types.h"

#include "heap.h"
#include "string.h"

#include "adapter.h"
#include "battle_pokemon.h"
#include "escape_info.h"

typedef struct ServerClient {
  Adapter *adapter;
  BattleParty *party;
  u8 field_8;
  u8 field_9;
  u8 field_A;
  u8 ID;
} ServerClient;

struct ServerFlow;
typedef struct ALIGNED(4) BattleServer {
  u32 field_0;
  u32 field_4;
  u8 field_8;
  u8 field_9;
  u8 field_A;
  u8 field_B;
  u8 *mainModule;
  u32 pokeCon;
  ServerClient client[4];
  ServerFlow *serverFlow;
  u32 serverTurnState;
  u32 field_4C;
  u32 field_50;
  u32 field_54;
  u32 field_58;
  u32 field_5C;
  u32 field_60;
  u32 field_64;
  u8 field_68;
  u8 gap69;
  u8 gap6A[62];
  u16 field_A8;
  u16 field_AA;
  String *field_AC;
  EscapeInfo *escapeInfo;
  u32 clientAction;
  u8 gapB8[40];
  u32 field_E0;
  u8 field_E4[4];
  u32 field_E8;
  u8 nextEnemyForSwitchMode;
  u8 field_ED;
  u8 field_EE;
  u8 field_EF;
  u32 field_F0;
  u8 gapF4[3004];
  u8 *field_CB0;
  u8 field_CB4;
  u8 field_CB5;
  u8 field_CB6;
  u8 field_CB7;
  u8 field_CB8;
  u8 field_CB9;
  u8 field_CBA;
  u8 field_CBB;
  u8 field_CBC;
  u8 field_CBD;
  u8 field_CBE;
  u8 field_CBF;
  HEAP_ID heapID;
  u8 field_CC2;
  u8 field_CC3;
} BattleServer;

#endif // !BATTLE_SERVER_H
