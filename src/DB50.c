#include "common.h"

void func_80105A80(void *);
s32 func_80105F00(s32 arg0);
extern void *D_80157120;

void func_800FFF50(void) {
    func_80105A80(&D_80157120);
    while (func_80105F00(0) != 1) {}
}

void func_80100110(u32 devAddr, void *dramAddr, s32 size);
extern u8 D_6A960;
extern u32 D_801CF9F0;
extern u8 D_911F0;
extern void func_801A9160();
extern void func_801DC8D0();

void func_800FFF90(void) {
    s32 size;

    size = &D_911F0 - &D_6A960;
    osInvalICache(&func_801A9160, size);
    func_80100110(&D_6A960, &func_801A9160, size);
    bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
}

// Warning, the above function could potentially be in a different file,
// and it needs -g2 to compile.

INCLUDE_ASM("asm/nonmatchings/DB50", func_80100010);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80100090);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80100110);

INCLUDE_ASM("asm/nonmatchings/DB50", func_801001C4);

INCLUDE_ASM("asm/nonmatchings/DB50", func_801001E4);

INCLUDE_ASM("asm/nonmatchings/DB50", func_801003EC);

INCLUDE_ASM("asm/nonmatchings/DB50", thread3_main);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104C38);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104CE0);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104D3C);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104E48);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104FD4);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80105164);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80105364);

INCLUDE_ASM("asm/nonmatchings/DB50", func_801057D4);
