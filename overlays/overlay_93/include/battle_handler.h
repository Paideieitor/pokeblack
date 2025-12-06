#ifndef BATTLE_HANDLER_H
#define BATTLE_HANDLER_H

#include "types.h"

#include "conditions.h"
#include "counters.h"
#include "delayed_effects.h"
#include "field_effects.h"
#include "side_effects.h"
#include "stat_stage.h"
#include "turn_flag.h"

typedef enum BattleHandlerEffect {
  EFFECT_USE_HELD_ITEM = 0x0,
  EFFECT_USE_HELD_ITEM_ANIMATION = 0x1,
  EFFECT_ABILITY_POPUP_ADD = 0x2,
  EFFECT_ABILITY_POPUP_REMOVE = 0x3,
  EFFECT_MESSAGE = 0x4,
  EFFECT_RECOVER_HP = 0x5,
  EFFECT_DRAIN = 0x6,
  EFFECT_DAMAGE = 0x7,
  EFFECT_CHANGE_HP = 0x8,
  EFFECT_RESTORE_PP = 0x9,
  EFFECT_DECREMENT_PP = 0xA,
  EFFECT_CURE_STATUS = 0xB,
  EFFECT_ADD_CONDITION = 0xC,
  EFFECT_CHANGE_STAT_STAGE = 0xE,
  EFFECT_SET_STAT_STAGE = 0xF,
  EFFECT_RESET_STAT_STAGE = 0x10,
  EFFECT_SET_STAT = 0x11,
  EFFECT_RESTORE_STAT_STAGE = 0x12,
  EFFECT_FAINT = 0x13,
  EFFECT_CHANGE_TYPE = 0x14,
  EFFECT_SET_TURN_FLAG = 0x15,
  EFFECT_RESET_TURN_FLAG = 0x16,
  EFFECT_SET_CONDITION_FLAG = 0x17,
  EFFECT_RESET_CONDITION_FLAG = 0x18,
  EFFECT_ADD_SIDE_EFFECT = 0x19,
  EFFECT_REMOVE_SIDE_EFFECT = 0x1A,
  EFFECT_ADD_FIELD_EFFECT = 0x1B,
  EFFECT_REMOVE_FIELD_EFFECT = 0x1C,
  EFFECT_CHANGE_WEATHER = 0x1D,
  EFFECT_ADD_POS_EFFECT = 0x1E,
  EFFECT_CHANGE_ABILITY = 0x1F,
  EFFECT_SET_HELD_ITEM = 0x20,
  EFFECT_CHECK_HELD_ITEM = 0x21,
  EFFECT_FORCE_USE_HELD_ITEM = 0x22,
  EFFECT_CONSUME_ITEM = 0x23,
  EFFECT_SWAP_ITEM = 0x24,
  EFFECT_UPDATE_MOVE = 0x25,
  EFFECT_COUNTER = 0x26,
  EFFECT_DELAY_MOVE_DAMAGE = 0x27,
  EFFECT_QUIT_BATTLE = 0x28,
  EFFECT_SWITCH = 0x29,
  EFFECT_BATON_PASS = 0x2A,
  EFFECT_FLINCH = 0x2B,
  EFFECT_REVIVE = 0x2C,
  EFFECT_SET_WEIGHT = 0x2D,
  EFFECT_FORCE_SWITCH = 0x2E,
  EFFECT_INTERRUPT_ACTION = 0x2F,
  EFFECT_INTERRUPT_MOVE = 0x30,
  EFFECT_SEND_LAST = 0x31,
  EFFECT_SWAP_POKE = 0x32,
  EFFECT_TRANSFORM = 0x33,
  EFFECT_ILLUSION_BREAK = 0x34,
  EFFECT_GRAVITY_CHECK = 0x35,
  EFFECT_HIDE_TURN_CANCEL = 0x36,
  EFFECT_ADD_ANIMATION = 0x37,
  EFFECT_REMOVE_MESSAGE_WINDOW = 0x38,
  EFFECT_CHANGE_FORM = 0x39,
  EFFECT_SET_ANIMATION_ID = 0x3A,
  EFFECT_PLAY_ANIMATION = 0x3B,
} BattleHandlerEffect;

typedef struct HandlerParam_String {
  u16 ID;
  u16 flags;
  u32 subProcID;
  u32 args[8];
} HandlerParam_String;

typedef struct HandlerParam_Header {
  u32 flags;
} HandlerParam_Header;

typedef struct HandlerParam_UseItem {
  HandlerParam_Header header;
  u32 flags;
} HandlerParam_UseItem;

typedef struct HandlerParam_Message {
  HandlerParam_Header header;
  HandlerParam_String str;
} HandlerParam_Message;

typedef struct HandlerParam_RecoverHP {
  HandlerParam_Header header;
  u16 recoverHP;
  u8 battleSlot;
  u8 failCheckThru;
  HandlerParam_String extraStr;
} HandlerParam_RecoverHP;

struct ALIGNED(4) HandlerParam_Drain {
  HandlerParam_Header header;
  u16 recoverHP;
  u8 recoverSlot;
  u8 damagedSlot;
  HandlerParam_String extraStr;
};

typedef struct ALIGNED(4) HandlerParam_Damage {
  HandlerParam_Header header;
  u16 damage;
  u8 battleSlot;
  u8 flags;
  u16 effectNo;
  u8 posFrom;
  u8 posTo;
  HandlerParam_String extraStr;
} HandlerParam_Damage;

typedef struct HandlerParam_ChangeHP {
  HandlerParam_Header header;
  u8 pokemonCount;
  u8 effectDisable;
  u8 itemReactionDisable;
  u8 battleSlot[6];
  u32 volume[6];
  u32 damageCause;
} HandlerParam_ChangeHP;

typedef struct HandlerParam_PP {
  HandlerParam_Header header;
  u8 volume;
  u8 battleSlot;
  u8 moveSlot;
  u8 flags;
  HandlerParam_String extraStr;
} HandlerParam_PP;

typedef struct HandlerParam_CureCondition {
  HandlerParam_Header header;
  MoveCondition condition;
  u8 battleSlot[12];
  u8 pokemonCount;
  u8 msgDisable;
  HandlerParam_String extraStr;
} HandlerParam_CureCondition;

typedef struct ALIGNED(4) HandlerParam_AddCondition {
  HandlerParam_Header header;
  MoveCondition condition;
  ConditionData condData;
  u8 almost;
  u8 reserved;
  u8 overwriteMode;
  u8 battleSlot;
  u8 overwriteMode2;
  HandlerParam_String extraStr;
} HandlerParam_AddCondition;

typedef struct HandlerParam_ChangeStatStage {
  HandlerParam_Header header;
  StatStage stat;
  u32 pad;
  s8 volume;
  u8 pad2;
  u8 moveAnimation;
  u8 pokemonCount;
  u8 battleSlot[6];
  HandlerParam_String extaStr;
} HandlerParam_ChangeStatStage;

typedef struct ALIGNED(4) HandlerParam_SetStatStage {
  HandlerParam_Header header;
  u8 battleSlot;
  u8 attack;
  u8 defense;
  u8 spAttack;
  u8 spDefense;
  u8 speed;
  u8 accuracy;
  u8 evasion;
  u8 critStage;
} HandlerParam_SetStatStage;

typedef struct ALIGNED(2) HandlerParam_ResetStatStage {
  HandlerParam_Header header;
  u8 pokemonCount;
  u8 battleSlot[6];
} HandlerParam_ResetStatStage;

typedef struct HandlerParam_SetStat {
  HandlerParam_Header header;
  u16 attack;
  u16 defense;
  u16 spAttack;
  u16 spDefense;
  u16 speed;
  u8 battleSlot;
  u8 flags;
  HandlerParam_String extraStr;
} HandlerParam_SetStat;

typedef struct HandlerParam_RestoreStatStage {
  HandlerParam_Header header;
  u8 battleSlot;
} HandlerParam_RestoreStatStage;

typedef struct ALIGNED(4) HandlerParam_Faint {
  HandlerParam_Header header;
  u8 battleSlot;
  char flags;
  char field_6;
  char field_7;
  HandlerParam_String extraStr;
} HandlerParam_Faint;

typedef struct ALIGNED(4) HandlerParam_ChangeType {
  HandlerParam_Header header;
  u16 newType;
  u8 battleSlot;
  u8 field_7;
} HandlerParam_ChangeType;

typedef struct ALIGNED(4) HandlerParam_TurnFlag {
  HandlerParam_Header header;
  TurnFlag flag;
  u8 battleSlot;
} HandlerParam_TurnFlag;

typedef struct ALIGNED(4) HandlerParam_SetConditionFlag {
  HandlerParam_Header header;
  ConditionFlag flag;
  u8 battleSlot;
} HandlerParam_SetConditionFlag;

typedef struct HandlerParam_AddSideEffect {
  HandlerParam_Header header;
  SideEffect sideEffect;
  ConditionData condData;
  u8 side;
  HandlerParam_String extraStr;
} HandlerParam_AddSideEffect;

typedef struct ALIGNED(4) HandlerParam_RemoveSideEffect {
  HandlerParam_Header header;
  u8 flags[3];
  u8 side;
} HandlerParam_RemoveSideEffect;

typedef struct ALIGNED(4) HandlerParam_AddFieldEffect {
  HandlerParam_Header header;
  FieldEffect fieldEffect;
  ConditionData condData;
  u8 addDependPokemon;
  u8 field_D;
  u8 field_E;
  u8 field_F;
  HandlerParam_String extraStr;
} HandlerParam_AddFieldEffect;

typedef struct HandlerParam_RemoveFieldEffect {
  HandlerParam_Header header;
  FieldEffect fieldEffect;
} HandlerParam_RemoveFieldEffect;

typedef struct ALIGNED(4) HandlerParam_ChangeWeather {
  HandlerParam_Header header;
  u8 weather;
  u8 turns;
  u8 airLock;
  u8 field_7;
  HandlerParam_String extraStr;
} HandlerParam_ChangeWeather;

typedef struct ALIGNED(4) HandlerParam_AddDelayedEffect {
  HandlerParam_Header header;
  DelayedEffect delayedEffect;
  u32 targetPos;
  u32 workToCopy[4];
  u32 workCount;
} HandlerParam_AddDelayedEffect;

typedef struct HandlerParam_ChangeAbility {
  HandlerParam_Header header;
  u16 ability;
  u8 battleSlot;
  u8 sameAbilityEffective;
  u8 skipSwitchInEvent;
  HandlerParam_String extraStr;
} HandlerParam_ChangeAbility;

typedef struct HandlerParam_SetItem {
  HandlerParam_Header header;
  u16 item;
  u8 battleSlot;
  u8 clearConsume;
  u8 clearConsumeOtherPokemon;
  u8 clearConsumeBattleSlot;
  u8 callConsumedEvent;
  HandlerParam_String extraStr;
} HandlerParam_SetItem;

typedef struct ALIGNED(4) HandlerParam_CheckHeldItem {
  HandlerParam_Header header;
  u8 battleSlot;
  u32 reaction;
} HandlerParam_CheckHeldItem;

typedef struct HandlerParam_ForceUseItem {
  HandlerParam_Header header;
  u8 battleSlot;
  u16 item;
} HandlerParam_ForceUseItem;

typedef struct ALIGNED(4) HandlerParam_ConsumeItem {
  HandlerParam_Header header;
  u32 dontUse;
  HandlerParam_String extraStr;
} HandlerParam_ConsumeItem;

typedef struct HandlerParam_SwapItem {
  HandlerParam_Header header;
  u8 battleSlot;
  u8 incRecordCount;
  HandlerParam_String extraStr;
  HandlerParam_String extraSubStr1;
  HandlerParam_String extraSubStr2;
} HandlerParam_SwapItem;

typedef struct HandlerParam_UpdateMove {
  HandlerParam_Header header;
  u8 battleSlot;
  u8 moveSlot;
  u8 ppMax;
  u8 permanent;
  u16 move;
} HandlerParam_UpdateMove;

typedef struct ALIGNED(2) HandlerParam_SetCounter {
  HandlerParam_Header header;
  u8 battleSlot;
  Counter counter;
  u8 value;
} HandlerParam_SetCounter;

typedef struct ALIGNED(4) HandlerParam_DelayMoveDamage {
  HandlerParam_Header header;
  u8 attackingSlot;
  u8 targetSlot;
  u16 move;
} HandlerParam_DelayMoveDamage;

typedef struct HandlerParam_QuitBattle {
  HandlerParam_Header header;
  u8 forceRun;
} HandlerParam_QuitBattle;

typedef struct ALIGNED(4) HandlerParam_Switch {
  HandlerParam_Header header;
  HandlerParam_String preStr;
  HandlerParam_String extraStr;
  u8 battleSlot;
  u8 introDisable;
} HandlerParam_Switch;

typedef struct HandlerParam_BatonPass {
  HandlerParam_Header header;
  u8 userSlot;
  u8 targetSlot;
} HandlerParam_BatonPass;

typedef struct HandlerParam_Flinch {
  HandlerParam_Header header;
  u8 battleSlot;
  u8 chance;
} HandlerParam_Flinch;

typedef struct HandlerParam_Revive {
  HandlerParam_Header header;
  u8 battleSlot;
  u16 recoverHP;
  HandlerParam_String extraStr;
} HandlerParam_Revive;

typedef struct HandlerParam_SetWeight {
  HandlerParam_Header header;
  u8 battleSlot;
  u16 weight;
  HandlerParam_String extraStr;
} HandlerParam_SetWeight;

typedef struct ALIGNED(4) HandlerParam_ForceSwitch {
  HandlerParam_Header header;
  u16 animNo;
  u8 battleSlot;
  u8 flags;
  HandlerParam_String extraStr;
} HandlerParam_ForceSwitch;

typedef struct HandlerParam_InterruptAction {
  HandlerParam_Header header;
  u8 battleSlot;
  HandlerParam_String extraStr;
} HandlerParam_InterruptAction;

typedef struct HandlerParam_InterruptMove {
  HandlerParam_Header header;
  u16 move;
} HandlerParam_InterruptMove;

typedef struct HandlerParam_SendLast {
  HandlerParam_Header header;
  u8 battleSlot;
  HandlerParam_String extraStr;
} HandlerParam_SendLast;

typedef struct HandlerParam_SwapPokemon {
  HandlerParam_Header header;
  u8 battleSlot1;
  u8 battleSlot2;
  HandlerParam_String extraStr;
} HandlerParam_SwapPokemon;

typedef struct HandlerParam_Transform {
  HandlerParam_Header header;
  u8 battleSlot;
  HandlerParam_String extraStr;
} HandlerParam_Transform;

typedef struct HandlerParam_IllusionBreak {
  HandlerParam_Header header;
  u8 battleSlot;
  HandlerParam_String extraStr;
} HandlerParam_IllusionBreak;

typedef struct HandlerParam_HideTurnCancel {
  HandlerParam_Header header;
  u8 battleSlot;
  u32 flag;
  HandlerParam_String extraStr;
} HandlerParam_HideTurnCancel;

typedef struct HandlerParam_AddAnimation {
  HandlerParam_Header header;
  u16 animNo;
  u8 posFrom;
  u8 posTo;
  u16 reservedQueuePos;
  u8 queueReserve;
  u8 msgWinVanish;
  HandlerParam_String extraStr;
} HandlerParam_AddAnimation;

typedef struct HandlerParam_ChangeForm {
  HandlerParam_Header header;
  u8 battleSlot;
  u8 newForm;
  u8 dontResetOnSwitch;
  u8 pad;
  HandlerParam_String extraStr;
} HandlerParam_ChangeForm;

typedef struct HandlerParam_SetAnimation {
  HandlerParam_Header header;
  u32 effectIdx;
} HandlerParam_SetAnimation;

#endif // !BATTLE_HANDLER_H
