#include "common.h"
#include "1F3B0.h"
#include "DB50.h"

void func_80105A80(void *);
s32 func_80105F00(s32 arg0);
extern void *D_80157120;

void func_800FFF50(void) {
    func_80105A80(&D_80157120);
    while (func_80105F00(0) != 1) {}
}

/**
 * Loads Overlay 2 into memory
 */
void loadOverlay2(void) {
    s32 overlaySize;

    overlaySize = &o3_ROM_START - &o2_ROM_START;
    osInvalICache(&o2_VRAM, overlaySize);
    loadOverlayAtAddress(&o2_ROM_START, &o2_VRAM, overlaySize);
    bzero(&o2_BSS_START, (u32) &o2_BSS_END - (u32) &o2_BSS_START);
}

INCLUDE_ASM("asm/nonmatchings/DB50", func_80100010);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80100090);

/**
 * Loads an overlay of a given size into memory.
 * It can only load 0x18000 at a time, so this will do it in chunks if needed.
 * @param devAddr The offset in ROM where the new code lives
 * @param dramAddr The RAM address to load the code into
 * @param size The size of overlay.
 */
void loadOverlayAtAddress(u32 devAddr, void *dramAddr, u32 size) {
    while (size != 0){
        if (size < 0x18000) {
            dmaOverlay(devAddr, dramAddr, size);
            size = 0;
        } else {
            dmaOverlay(devAddr, dramAddr, 0x18000);
            size -= 0x18000;
            devAddr += 0x18000;
            dramAddr += 0x18000;
        }
    }
}

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
