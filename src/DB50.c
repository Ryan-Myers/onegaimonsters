#include "common.h"

void func_80105A80(void *);
s32 func_80105F00(s32 arg0);
extern void *D_80157120;

void func_800FFF50(void) {
    func_80105A80(&D_80157120);
    while (func_80105F00(0) != 1) {}
}

void func_80100110(u32 devAddr, void *dramAddr, s32 size);
extern u8 o2_ROM_START;
extern u32 o2_BSS_START;
extern u8 o3_ROM_START;
extern u32 o2_VRAM;
extern u32 o2_BSS_END;

/**
 * Loads Overlay 2
 */
void loadOverlay2(void) {
    s32 overlaySize;

    overlaySize = &o3_ROM_START - &o2_ROM_START;
    osInvalICache(&o2_VRAM, overlaySize);
    func_80100110(&o2_ROM_START, &o2_VRAM, overlaySize);
    bzero(&o2_BSS_START, (u32) &o2_BSS_END - (u32) &o2_BSS_START);
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
