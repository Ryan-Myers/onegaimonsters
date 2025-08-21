#include "DB50.h"
#include "1E210.h"
#include "1F3B0.h"
#include "common.h"

extern void func_800FF7A0(s32);
extern void func_800FF9D8(void);
extern void func_800FFABC(void *, f32, f32);
extern void func_80106140(void);
void func_80105A80(void *);
s32 func_80105F00(s32);

extern void *D_80157120;
extern s32 D_801529B8; // Almost definitely something like a struct or an array.
extern s32 D_80171E98;
extern s32 D_80174374;
extern s32 D_80184310; // Almost definitely something like a struct or an array.

void func_800FFF50(void) {
    func_80105A80(&D_80157120);
    while (func_80105F00(0) != 1) {}
}

/**
 * Loads Overlay 2 into memory
 */
void loadOverlay2(void) {
    u32 overlaySize;

    overlaySize = o2_ROM_END - o2_ROM_START;
    osInvalICache(&o2_VRAM, overlaySize);
    loadOverlayAtAddress(&o2_ROM_START, &o2_VRAM, overlaySize);
    bzero(&o2_BSS_START, (u32) &o2_BSS_END - (u32) &o2_BSS_START);
}

/**
 * Loads Overlay 3 into memory
 */
void loadOverlay3(void) {
    u32 overlaySize;

    overlaySize = o3_ROM_END - o3_ROM_START;
    osInvalICache(&o3_VRAM, overlaySize);
    loadOverlayAtAddress(&o3_ROM_START, &o3_VRAM, overlaySize);
    bzero(&o3_BSS_START, (u32) &o3_BSS_END - (u32) &o3_BSS_START);
}

/**
 * Loads Overlay 4 into memory
 */
void loadOverlay4(void) {
    u32 overlaySize;

    overlaySize = o4_ROM_END - o4_ROM_START;
    osInvalICache(&o4_VRAM, overlaySize);
    loadOverlayAtAddress(&o4_ROM_START, &o4_VRAM, overlaySize);
    bzero(&o4_BSS_START, (u32) &o4_BSS_END - (u32) &o4_BSS_START);
}

/**
 * Loads an overlay of a given size into memory.
 * It can only load 0x18000 at a time, so this will do it in chunks if needed.
 * @param devAddr The offset in ROM where the new code lives
 * @param dramAddr The RAM address to load the code into
 * @param size The size of overlay.
 */
void loadOverlayAtAddress(u32 devAddr, void *dramAddr, u32 size) {
    while (size != 0) {
        if (size < MAX_DMA_SIZE) {
            dmaOverlay(devAddr, dramAddr, size);
            size = 0;
        } else {
            dmaOverlay(devAddr, dramAddr, MAX_DMA_SIZE);
            size -= MAX_DMA_SIZE;
            devAddr += MAX_DMA_SIZE;
            dramAddr += MAX_DMA_SIZE;
        }
    }
}

extern s32 D_801883B0;
extern s32 D_80188E74;

void func_801001C4(s32 newVal) {
    s32 oldVal;

    oldVal = D_801883B0;
    D_801883B0 = newVal;
    D_80188E74 = oldVal;
}

/**
 * Loads overlays at code_1B4070, code_682020, and code_60A840
 */
void func_801001E4(void) {
    LOAD_OVERLAY_ALT(o67, o66); // Bug? Invalidates the previous overlay VRAM address
    ZERO_OVERLAY_BSS(o67);
    LOAD_OVERLAY_ALT(code_682020, o66); // Bug? Invalidates the same old VRAM address
    LOAD_OVERLAY(code_60A840);
}

void func_801003EC(s32 arg0) {
    void *temp_s0;

    if (arg0 < 2) {
        temp_s0 = (D_801529B8 << 5) + &D_80184310;
        func_800FF7A0(1);
        func_800FFABC(temp_s0, 0.0f, 2000.0f);
        func_800FF9D8();
    }
    if ((D_80188E74 == D_801883B0) || (func_80105F00(0) == 1)) {
        func_80110610(NULL);
        D_80174374 = D_80171E98;
    }
    func_80106140();
}

INCLUDE_ASM("asm/nonmatchings/DB50", mainproc);

const char D_8015AF0C[] = "9H";
extern void func_80110B10(void *, s32);
extern s32 D_801830C8[][4];
extern s32 D_801830D0[][4];
extern s32 D_801830D4[][4];
extern s32 D_801A90E0[];

void func_80104C38(s32 arg0) {
    func_80110B10(&D_801830C8[arg0], arg0);
    func_80110B10(&D_801830C8[arg0], arg0);
    if (D_801830D4[arg0][0] == 2) {
        D_801A90E0[arg0] = 300;
    } else {
        D_801A90E0[arg0] = D_801830D0[arg0][0];
    }
}

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104CE0);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104D3C);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104E48);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104FD4);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80105164);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80105364);

s32 abs(s32 value) {
    return (value < 0) ? -value : value;
}
