#ifndef ADAPTER_H
#define ADAPTER_H

#include "types.h"

typedef struct SendData {
  u32 serialNumber;
  u32 cmd;
  u32 serverSeq;
  u8 flags;
  u8 unk2;
  u8 state;
  u8 processingCmd;
  u8 unk5;
  u8 unk6;
  u16 size;
  u8 data[3000];
} SendData;

typedef struct Adapter {
  SendData sendData;
  SendData returnData;
  u32 processingCmd;
  u8 myID;
  u8 myState;
  u8 flags;
} Adapter;

#endif // !ADAPTER_H
