#ifndef STRING_H
#define STRING_H

#include "types.h"

typedef struct ALIGNED(2) String {
  u16 capacity;
  u16 count;
  u32 magic;
  u16 str[];
} String;

#endif // !STRING_H
#define STRING_H
