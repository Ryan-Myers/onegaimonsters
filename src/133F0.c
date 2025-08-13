#include "133F0.h"
#include "common.h"

#ifdef NON_EQUIVALENT
extern s32 D_80171AF4;
extern s32 D_80173600;
extern s32 D_80174C00;
extern s32 D_80175888;
extern s32 D_80175870[16];
extern u16 D_80184504;
extern s32 D_80184518;
extern s32 D_8018451C;
extern s16 D_80184524;
extern u16 D_80184526;
extern s32 D_8018903C;
extern s32 D_801A9100;

void func_801057F0(void) {
    s32 *var_v0;
    s32 var_v0_2;
    s32 var_v1;

    for (var_v1 = 0; var_v1 < 16; var_v1++) {
        D_80175870[var_v1] = 0;
    }
    if (D_80184504 == 0) {
        D_8018903C = 3;
        D_80184524 = 3;
        D_80184518 = -0x3C0;
        D_8018451C = -0x320;
        D_80175870[6] = 0x1FA;
    } else {
        D_8018903C = 2;
        D_80184524 = 2;
        D_80184518 = -0x3C0;
        D_8018451C = -0xA0;
        D_80175870[6] = 0x1FB;
    }
    D_80184526 = 0;
    D_80173600 = 0;
    D_80174C00 = D_80184518;
    D_801A9100 = D_8018451C;
    D_80171AF4 = D_80184526;
}
#else
INCLUDE_ASM("asm/nonmatchings/133F0", func_801057F0);
#endif
