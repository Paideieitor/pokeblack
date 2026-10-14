	.include "macros/function.inc"

	.extern ADDR_02074A6C
	.extern FUN_02005f5c
	.extern FUN_02006118
	.extern FUN_0200f2d4
	.extern FUN_02030DA8
	.extern FUN_02030d28
	.extern FUN_020312b4
	.extern FUN_02034f5c
	.extern FUN_0203630c
	.extern FUN_0203f034
	.extern FUN_0203f3f0
	.extern FUN_020419e4
	.extern FUN_0204e638
	.extern FUN_02050a70
	.extern FUN_020726d0
	.extern FUN_02072db0
	.extern FUN_02072e9c
	.extern FUN_02072ea8
	.extern FUN_02073FB8
	.extern FUN_02074518
	.extern FUN_020746E8
	.extern FUN_0207482C
	.extern FUN_02074894
	.extern FUN_020748E0
	.extern FUN_02074A54
	.extern FUN_02074AC4
	.extern FUN_020754C4
	.extern FUN_02085D3C
	.extern FUN_0209C054
	.extern _02030D28
	.extern _0203508C
	.extern _02035108
	.extern _0203F258
	.extern _02072788
	.extern _020A6C58
	.extern _020A7010
	.extern _020AA194
	.extern _020AA1AC
	.extern _020AA1B8
	.extern _020AA1BC
	.extern _020AA1C4
	.extern _020AA1C8
	.extern _020AA1CC
	.extern _020AA1D0
	.extern _020AA260
	.extern _020AA270
	.extern _020AA2BC
	.extern _020AA9B4

	.text

	thumb_func_start FUN_020055f8
FUN_020055f8: ; 0x020055F8
	push {r3, lr}
	blx FUN_02034f5c
	bl FUN_0200f2d4
	blx FUN_020312b4
	blx FUN_0203f3f0
	pop {r3, pc}
	thumb_func_end FUN_020055f8

	thumb_func_start FUN_0200560c
FUN_0200560c: ; 0x0200560C
	bx lr
	.balign 4, 0
	thumb_func_end FUN_0200560c
_02005610:
	.byte 0x02, 0x48, 0x03, 0x4B, 0x00, 0x69, 0x80, 0x69, 0x18, 0x47, 0xC0, 0x46
	.word _020AA194
	.word _02030D28

	thumb_func_start FUN_02005624
FUN_02005624: ; 0x02005624
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0200563C ; =0x020AA194
	add r4, r1, #0
	ldr r0, [r0, #0x10]
	add r3, r2, #0
	ldr r0, [r0, #0x18]
	add r1, r5, #0
	add r2, r4, #0
	blx FUN_02030DA8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0200563C: .word _020AA194
	thumb_func_end FUN_02005624
FUN_02005640: ; 0x02005640
	.byte 0x08, 0xB5, 0x03, 0x48, 0x81, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x00, 0x68, 0x88, 0x47, 0x08, 0xBD
	.word _020AA194
	.byte 0x04, 0x4A, 0x93, 0x68, 0x00, 0x2B, 0x01, 0xD0, 0x00, 0x20, 0x70, 0x47, 0x90, 0x60, 0x11, 0x60
	.byte 0x01, 0x20, 0x70, 0x47
	.word _020AA194

	thumb_func_start FUN_0200566c
FUN_0200566c: ; 0x0200566C
	ldr r0, _02005678 ; =0x020AA194
	mov r1, #0
	str r1, [r0, #8]
	str r1, [r0]
	bx lr
	nop
_02005678: .word _020AA194
	thumb_func_end FUN_0200566c

	thumb_func_start FUN_0200567c
FUN_0200567c: ; 0x0200567C
	push {r4, lr}
	ldr r4, _0200569C ; =0x020AA194
	ldr r0, [r4, #0x10]
	ldr r0, [r0, #0x20]
	blx FUN_02030d28
	blx FUN_020419e4
	blx FUN_02050a70
	blx FUN_0204e638
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	pop {r4, pc}
	.balign 4, 0
_0200569C: .word _020AA194
	thumb_func_end FUN_0200567c

	thumb_func_start FUN_020056A0
FUN_020056A0: ; 0x020056A0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _020056B8 ; =0x020AA194
	add r4, r1, #0
	ldr r0, [r0, #0x10]
	add r3, r2, #0
	ldr r0, [r0, #0x20]
	add r1, r5, #0
	add r2, r4, #0
	blx FUN_02030DA8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_020056B8: .word _020AA194
	thumb_func_end FUN_020056A0
_020056BC:
	.byte 0x01, 0x48, 0x00, 0x69, 0x00, 0x6A, 0x70, 0x47
	.word _020AA194

	thumb_func_start thunk_FUN_0203f258
thunk_FUN_0203f258: ; 0x020056C8
	ldr r3, _020056CC ; =FUN_0203f258
	bx r3
	.balign 4, 0
_020056CC: .word _0203F258 ; was FUN_0203f258
	thumb_func_end thunk_FUN_0203f258

	thumb_func_start FUN_020056d0
FUN_020056d0: ; 0x020056D0
	push {r3, lr}
	ldr r0, _020056E8 ; =0x020AA194
	ldr r0, [r0, #0x10]
	bl thunk_FUN_0203f258
	mov r0, #0
	bl FUN_020056ec
	blx FUN_0203f034
	pop {r3, pc}
	nop
_020056E8: .word _020AA194
	thumb_func_end FUN_020056d0

	thumb_func_start FUN_020056ec
FUN_020056ec: ; 0x020056EC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _02005724 ; =0x020AA194
	ldr r4, [r0, #0x10]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r2, [r4]
	ldr r3, [r4, #4]
	blx FUN_0209C054
	ldr r2, [r4, #0x10]
	ldr r3, [r4, #0x14]
	add r0, r2, r0
	adc r3, r1
	str r0, [r4]
	str r3, [r4, #4]
	cmp r5, #0
	bne _02005714
	ldr r1, [r4, #4]
	b _02005720
_02005714:
	ldr r0, [r4, #4]
	mov r1, #0
	mov r3, #0
	add r2, r5, #0
	blx FUN_0209C054
_02005720:
	add r0, r1, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02005724: .word _020AA194
	thumb_func_end FUN_020056ec
_02005728:
	.byte 0x38, 0xB5, 0x05, 0x1C, 0x0A, 0x48, 0x04, 0x69, 0xA0, 0x68, 0xE1, 0x68, 0x22, 0x68, 0x63, 0x68
	blx FUN_0209C054
	.byte 0x22, 0x69, 0x63, 0x69, 0x10, 0x18, 0x4B, 0x41, 0x20, 0x60, 0x63, 0x60, 0x18, 0x1C, 0x00, 0x21
	.byte 0x00, 0x23, 0x2A, 0x1C
	blx FUN_0209C054
	.byte 0x08, 0x1C, 0x38, 0xBD
	.word _020AA194
	.byte 0x81, 0x00, 0x01, 0x48, 0x40, 0x58, 0x70, 0x47
	.word _020A6C58
	.byte 0xF8, 0xB5, 0x01, 0x27, 0x3F, 0x02, 0xBC, 0x00, 0xFE, 0x00, 0x7D, 0x00
	blx FUN_02034f5c
	blx FUN_0203630c
	.byte 0x01, 0x1C, 0x29, 0x42, 0xF8, 0xD0, 0x01, 0x1C, 0x39, 0x42, 0xF5, 0xD0, 0x01, 0x1C, 0x21, 0x42
	.byte 0xF2, 0xD0, 0x30, 0x42, 0xF0, 0xD0, 0xF8, 0xBD, 0x01, 0x4B, 0x00, 0x20, 0x18, 0x47, 0xC0, 0x46
	.word _02072788
	.byte 0x01, 0x4B, 0x7F, 0x20, 0x18, 0x47, 0xC0, 0x46
	.word _02072788

	thumb_func_start FUN_020057ac
FUN_020057ac: ; 0x020057AC
	ldr r0, _020057B8 ; =0x02005795
	ldr r1, _020057BC ; =0x020057A1
	ldr r3, _020057C0 ; =FUN_0203508C
	mov r2, #0
	bx r3
	nop
_020057B8: .word 0x02005795
_020057BC: .word 0x020057A1
_020057C0: .word _0203508C ; was FUN_0203508C
	thumb_func_end FUN_020057ac
_020057C4:
	.byte 0x08, 0xB5
	blx _02035108
	.byte 0x03, 0x49, 0x88, 0x42, 0x01, 0xD1, 0x01, 0x20, 0x08, 0xBD, 0x00, 0x20, 0x08, 0xBD, 0x95, 0x57
	.byte 0x00, 0x02

	thumb_func_start FUN_020057dc
FUN_020057dc: ; 0x020057DC
	ldr r1, _020057E4 ; =0x020AA1AC
	str r0, [r1, #8]
	bx lr
	nop
_020057E4: .word _020AA1AC
	thumb_func_end FUN_020057dc

	thumb_func_start FUN_020057e8
FUN_020057e8: ; 0x020057E8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r1, #0x1c
	mul r5, r1
	ldr r2, _02005818 ; =0x020AA1B8
	mov r4, #0
	ldr r1, _0200581C ; =0x0000FFFF
	ldr r0, _02005820 ; =0x020AA1BC
	str r4, [r2, r5]
	strh r1, [r0, r5]
	add r0, r2, r5
	add r0, #8
	blx FUN_02072ea8
	ldr r0, _02005824 ; =0x020AA1C4
	sub r1, r4, #1
	str r1, [r0, r5]
	ldr r0, _02005828 ; =0x020AA1C8
	str r1, [r0, r5]
	ldr r0, _0200582C ; =0x020AA1CC
	str r1, [r0, r5]
	ldr r0, _02005830 ; =0x020AA1D0
	str r1, [r0, r5]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02005818: .word _020AA1B8
_0200581C: .word 0x0000FFFF
_02005820: .word _020AA1BC
_02005824: .word _020AA1C4
_02005828: .word _020AA1C8
_0200582C: .word _020AA1CC
_02005830: .word _020AA1D0
	thumb_func_end FUN_020057e8

	thumb_func_start FUN_02005834
FUN_02005834: ; 0x02005834
	ldr r1, _02005850 ; =0x020AA1AC
	ldr r3, _02005854 ; =0x020AA1B8
	ldr r2, [r1, #4]
	mov r1, #0x1c
	mul r1, r2
	add r2, r3, r1
	str r0, [r2, #0xc]
	str r0, [r2, #0x10]
	str r0, [r2, #0x14]
	str r0, [r2, #0x18]
	mov r0, #1
	str r0, [r3, r1]
	bx lr
	nop
_02005850: .word _020AA1AC
_02005854: .word _020AA1B8
	thumb_func_end FUN_02005834
_02005858:
	.byte 0x38, 0xB5, 0x09, 0x4C, 0x09, 0x4A, 0x61, 0x68, 0x1C, 0x20, 0x48, 0x43, 0x15, 0x18, 0x28, 0x1C
	.byte 0x08, 0x30
	blx FUN_02072ea8
	.byte 0xA0, 0x68, 0xE9, 0x68, 0x00, 0x68
	blx FUN_020748E0
	.byte 0x60, 0x68, 0xFF, 0xF7, 0xB5, 0xFF, 0x38, 0xBD
	.word _020AA1AC
	.word _020AA1B8

	thumb_func_start FUN_02005888
FUN_02005888: ; 0x02005888
	push {r4, r5, r6, lr}
	ldr r1, _020058C8 ; =0x020AA1AC
	mov r5, #0
	strh r0, [r1]
	ldr r4, _020058CC ; =0x020AA1B8
	str r5, [r1, #4]
	mov r6, #0x1c
_02005896:
	add r0, r5, #0
	bl FUN_020057e8
	add r0, r5, #0
	mul r0, r6
	add r0, r4, r0
	add r0, #8
	blx FUN_02072e9c
	add r5, r5, #1
	cmp r5, #6
	blt _02005896
	ldr r4, _020058C8 ; =0x020AA1AC
	mov r1, #6
	ldrh r0, [r4]
	blx FUN_02072db0
	ldr r0, [r4, #8]
	ldr r0, [r0]
	blx FUN_02074894
	bl FUN_02005834
	pop {r4, r5, r6, pc}
	nop
_020058C8: .word _020AA1AC
_020058CC: .word _020AA1B8
	thumb_func_end FUN_02005888

	thumb_func_start FUN_020058d0
FUN_020058d0: ; 0x020058D0
	ldr r0, _020058F4 ; =0x020AA1AC
	ldr r2, _020058F8 ; =0x020AA1B8
	ldr r1, [r0, #4]
	mov r0, #0x1c
	mul r0, r1
	add r1, r2, r0
	ldr r0, [r2, r0]
	cmp r0, #0
	bne _020058E6
	mov r0, #0
	bx lr
_020058E6:
	ldrh r0, [r1, #4]
	ldr r1, _020058FC ; =0x0000FFFF
	cmp r0, r1
	bne _020058F0
	mov r0, #0
_020058F0:
	bx lr
	nop
_020058F4: .word _020AA1AC
_020058F8: .word _020AA1B8
_020058FC: .word 0x0000FFFF
	thumb_func_end FUN_020058d0
_02005900:
	.byte 0x01, 0x48, 0x40, 0x68, 0x70, 0x47, 0xC0, 0x46
	.word _020AA1AC

	thumb_func_start FUN_0200590c
FUN_0200590c: ; 0x0200590C
	ldr r0, _0200591C ; =0x020AA1AC
	ldr r2, _02005920 ; =0x020AA1B8
	ldr r1, [r0, #4]
	mov r0, #0x1c
	mul r0, r1
	add r0, r2, r0
	add r0, #8
	bx lr
	.balign 4, 0
_0200591C: .word _020AA1AC
_02005920: .word _020AA1B8
	thumb_func_end FUN_0200590c

	thumb_func_start FUN_02005924
FUN_02005924: ; 0x02005924
	push {r3, r4, r5, r6, r7, lr}
	ldr r6, _02005974 ; =0x020AA1AC
	mov r1, #0x1c
	ldr r2, [r6, #4]
	ldr r3, _02005978 ; =0x020AA1B8
	mul r1, r2
	ldr r2, [r6, #8]
	add r4, r3, r1
	ldr r2, [r2]
	mov r1, #3
	add r5, r0, #0
	blx FUN_02074AC4
	cmp r0, #0
	bne _02005946
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02005946:
	ldr r0, [r6, #8]
	ldr r0, [r0]
	blx FUN_02074894
	str r0, [r4, #0x14]
	ldr r2, [r6, #8]
	add r0, r5, #0
	ldr r2, [r2]
	mov r1, #4
	blx FUN_02074AC4
	add r7, r0, #0
	bne _02005964
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02005964:
	ldr r0, [r6, #8]
	ldr r0, [r0]
	blx FUN_02074894
	str r0, [r4, #0x18]
	strh r5, [r4, #4]
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02005974: .word _020AA1AC
_02005978: .word _020AA1B8
	thumb_func_end FUN_02005924

	thumb_func_start FUN_0200597c
FUN_0200597c: ; 0x0200597C
	push {r4, lr}
	ldr r1, _02005998 ; =0x020AA1AC
	ldr r3, _0200599C ; =0x020AA1B8
	ldr r2, [r1, #4]
	mov r0, #0x1c
	mul r0, r2
	add r4, r3, r0
	ldr r0, [r1, #8]
	ldr r0, [r0]
	blx FUN_02074894
	str r0, [r4, #0x14]
	pop {r4, pc}
	nop
_02005998: .word _020AA1AC
_0200599C: .word _020AA1B8
	thumb_func_end FUN_0200597c

	thumb_func_start FUN_020059a0
FUN_020059a0: ; 0x020059A0
	push {r3, r4, r5, lr}
	ldr r1, _020059C0 ; =0x020AA1AC
	add r5, r0, #0
	ldr r2, [r1, #4]
	mov r0, #0x1c
	ldr r3, _020059C4 ; =0x020AA1B8
	mul r0, r2
	add r4, r3, r0
	ldr r0, [r1, #8]
	ldr r0, [r0]
	blx FUN_02074894
	str r0, [r4, #0x18]
	strh r5, [r4, #4]
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_020059C0: .word _020AA1AC
_020059C4: .word _020AA1B8
	thumb_func_end FUN_020059a0

	thumb_func_start FUN_020059c8
FUN_020059c8: ; 0x020059C8
	push {r4, lr}
	ldr r1, _020059F4 ; =0x020AA1AC
	ldr r3, _020059F8 ; =0x020AA1B8
	ldr r2, [r1, #4]
	mov r0, #0x1c
	mul r0, r2
	add r4, r3, r0
	ldr r0, [r3, r0]
	cmp r0, #0
	beq _020059F2
	ldr r0, _020059FC ; =0x0000FFFF
	strh r0, [r4, #4]
	ldr r0, [r1, #8]
	ldr r1, [r4, #0x10]
	ldr r0, [r0]
	blx FUN_020748E0
	ldr r0, [r4, #0x10]
	str r0, [r4, #0x14]
	ldr r0, [r4, #0x10]
	str r0, [r4, #0x18]
_020059F2:
	pop {r4, pc}
	.balign 4, 0
_020059F4: .word _020AA1AC
_020059F8: .word _020AA1B8
_020059FC: .word 0x0000FFFF
	thumb_func_end FUN_020059c8
_02005A00:
	.byte 0x38, 0xB5, 0x10, 0x4A, 0x10, 0x49, 0x53, 0x68, 0x1C, 0x24, 0x18, 0x1C, 0x60, 0x43, 0x0D, 0x18
	.byte 0x05, 0x2B, 0x01, 0xDB, 0x00, 0x20, 0x38, 0xBD, 0x20, 0x1C, 0x69, 0x69, 0x1D, 0x38, 0x81, 0x42
	.byte 0x07, 0xD0, 0x90, 0x68, 0x00, 0x68
	blx FUN_020748E0
	.byte 0x1D, 0x3C, 0xAC, 0x61, 0x68, 0x69, 0x00, 0xE0, 0x28, 0x69, 0x03, 0x49, 0x4A, 0x68, 0x52, 0x1C
	.byte 0x4A, 0x60, 0xFF, 0xF7, 0xFA, 0xFE, 0x01, 0x20, 0x38, 0xBD
	.word _020AA1AC
	.word _020AA1B8
	.byte 0x38, 0xB5, 0x0F, 0x4C, 0x60, 0x68, 0x00, 0x28, 0x01, 0xDC, 0x00, 0x20, 0x38, 0xBD, 0xFF, 0xF7
	.byte 0xFD, 0xFE, 0x60, 0x68, 0x0B, 0x49, 0x42, 0x1E, 0x1C, 0x20, 0x50, 0x43, 0x0D, 0x18, 0xA8, 0x88
	.byte 0x09, 0x49, 0x62, 0x60, 0x88, 0x42, 0x09, 0xD0, 0xA2, 0x68, 0x06, 0x21, 0x12, 0x68
	blx FUN_02074AC4
	.byte 0xA0, 0x68, 0x00, 0x68
	blx FUN_02074894
	.byte 0xA8, 0x61, 0x01, 0x20, 0x38, 0xBD
	.word _020AA1AC
	.word _020AA1B8
	.byte 0xFF, 0xFF, 0x00, 0x00, 0xF0, 0xB5, 0x83, 0xB0, 0x17, 0x4F, 0x0D, 0x1C, 0x79, 0x68, 0x06, 0x1C
	.byte 0x1C, 0x20, 0x0A, 0x1C, 0x42, 0x43, 0x15, 0x48, 0x80, 0x18, 0xC0, 0x68, 0x01, 0x90, 0xFF, 0xF7
	.byte 0xD1, 0xFE, 0x00, 0x24, 0x00, 0x94, 0xB8, 0x68, 0x08, 0x21, 0x00, 0x68, 0x00, 0x22, 0x00, 0x23
	blx FUN_0207482C
	.byte 0x02, 0x90, 0x00, 0x2D, 0x08, 0xD9, 0xB9, 0x68, 0xA0, 0x00, 0x30, 0x58, 0x09, 0x68
	blx ADDR_02074A6C
	.byte 0x64, 0x1C, 0xAC, 0x42, 0xF6, 0xD3, 0x02, 0x98, 0x01, 0x99, 0x05, 0x60, 0x41, 0x60, 0x04, 0x48
	.byte 0x80, 0x68, 0x00, 0x68
	blx FUN_02074894
	.byte 0xFF, 0xF7, 0x9F, 0xFE, 0x02, 0x98, 0x03, 0xB0, 0xF0, 0xBD
	.word _020AA1AC
	.word _020AA1B8
	.byte 0x10, 0xB5, 0x44, 0x68, 0xFF, 0xF7, 0xA6, 0xFE, 0x04, 0x48, 0x21, 0x1C, 0x80, 0x68, 0x00, 0x68
	blx FUN_020748E0
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0x8B, 0xFE, 0x10, 0xBD
	.word _020AA1AC

	thumb_func_start FUN_02005b24
FUN_02005b24: ; 0x02005B24
	push {r3, lr}
	blx FUN_020726d0
	ldr r0, _02005B58 ; =0x020AA9B4
	ldr r1, _02005B5C ; =0x00095AD0
	blx FUN_020746E8
	add r2, r0, #0
	ldr r0, _02005B60 ; =0x020AA260
	ldr r1, _02005B64 ; =0x020A7010
	str r2, [r0, #0x10]
	ldr r0, _02005B68 ; =0x020AA2BC
	mov r3, #0
	blx FUN_02073FB8
	mov r0, #1
	bl FUN_02005b74
	blx FUN_02085D3C
	cmp r0, #1
	bne _02005B54
	blx thunk_EXT_FUN_02704364
_02005B54:
	pop {r3, pc}
	nop
_02005B58: .word _020AA9B4
_02005B5C: .word 0x00095AD0
_02005B60: .word _020AA260
_02005B64: .word _020A7010
_02005B68: .word _020AA2BC
	thumb_func_end FUN_02005b24

	arm_func_start thunk_EXT_FUN_02704364
thunk_EXT_FUN_02704364: ; 0x02005B6C
	ldr pc, _02005B70 ; =FUN_02704364
	.balign 4, 0
_02005B70: .word 0x02704364 ; was FUN_02704364
	arm_func_end thunk_EXT_FUN_02704364

	thumb_func_start FUN_02005b74
FUN_02005b74: ; 0x02005B74
	push {r3, r4, r5, lr}
	ldr r4, _02005BB8 ; =0x020AA260
	add r5, r0, #0
	ldr r0, [r4, #0x10]
	blx FUN_020754C4
	ldr r0, _02005BBC ; =0x020AA270
	bl FUN_020057dc
	cmp r5, #0
	beq _02005B9C
	mov r0, #0
	mov r5, #0
	blx FUN_02074518
	ldr r1, [r4, #0x10]
	mov r0, #0
	blx FUN_02074A54
	str r5, [r4, #0x18]
_02005B9C:
	bl FUN_02006118
	mov r0, #0
	mov r4, #0
	bl FUN_02005888
	bl FUN_02005f5c
	ldr r0, _02005BB8 ; =0x020AA260
	strh r4, [r0]
	str r4, [r0, #8]
	str r4, [r0, #0x14]
	str r4, [r0, #4]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02005BB8: .word _020AA260
_02005BBC: .word _020AA270
	thumb_func_end FUN_02005b74


