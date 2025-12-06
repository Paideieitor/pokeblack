#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H

#include "types.h"

typedef struct ServerCommandQueue {
  u32 writePtr;
  u32 readPtr;
  u8 buffer[3000];
} ServerCommandQueue;

#endif // !SERVER_COMMAND_H
