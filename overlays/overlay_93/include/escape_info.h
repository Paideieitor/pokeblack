#ifndef ESCAPE_INFO_H
#define ESCAPE_INFO_H

#include "types.h"

typedef struct EscapeInfo {
  u32 count;
  u8 clientID[4];
} EscapeInfo;

#endif // !ESCAPE_INFO_H
