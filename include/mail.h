#ifndef MAIL_H
#define MAIL_H

#include "types.h"

typedef struct MailData {
  u32 trainerID;
  u8 trainerGender;
  u8 region;
  u8 gameVersion;
  u8 field_7;
  char stringContent[16];
  u16 field_18;
  u16 field_1A;
  u16 field_1C;
  u16 field_1E;
  u32 field_20;
  u32 field_24;
  u32 field_28;
  u32 field_2C;
  u32 field_30;
  u32 field_34;
} MailData;

#endif // MAIL_H
