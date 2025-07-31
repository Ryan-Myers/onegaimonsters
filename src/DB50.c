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
    u32 overlaySize;

    overlaySize = &o3_ROM_START - &o2_ROM_START;
    osInvalICache(&o2_VRAM, overlaySize);
    loadOverlayAtAddress(&o2_ROM_START, &o2_VRAM, overlaySize);
    bzero(&o2_BSS_START, (u32) &o2_BSS_END - (u32) &o2_BSS_START);
}

/**
 * Loads Overlay 3 into memory
 */
void loadOverlay3(void) {
    u32 overlaySize;

    overlaySize = &o4_ROM_START - &o3_ROM_START;
    osInvalICache(&o3_VRAM, overlaySize);
    loadOverlayAtAddress(&o3_ROM_START, &o3_VRAM, overlaySize);
    bzero(&o3_BSS_START, (u32) &o3_BSS_END - (u32) &o3_BSS_START);
}

/**
 * Loads Overlay 4 into memory
 */
void loadOverlay4(void) {
    u32 overlaySize;

    overlaySize = &o5_ROM_START - &o4_ROM_START;
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

extern s32 D_801883B0;
extern s32 D_80188E74;

void func_801001C4(s32 newVal) {
    s32 oldVal;

    oldVal = D_801883B0;
    D_801883B0 = newVal;
    D_80188E74 = oldVal;
}

void func_801001E4(void) {
    // Load Overlay code_1B4070
    {
        u32 devAddr;
        u32 size;
        void *dramAddr;

        osInvalICache(&code_1B10E0_VRAM, &code_1B7D00_ROM_START - &code_1B4070_ROM_START); // Bug? Invalidates the previous overlay VRAM address
        devAddr = &code_1B4070_ROM_START;
        size = &code_1B7D00_ROM_START - &code_1B4070_ROM_START;
        dramAddr = &code_1B4070_VRAM;
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
    
    bzero(&code_1B4070_BSS_START, (u32) &code_1B4070_BSS_END - (u32) &code_1B4070_BSS_START);

    // Load Overlay code_1B4070
    {
        u32 devAddr;
        u32 size;
        void *dramAddr;

        osInvalICache(&code_1B10E0_VRAM, &code_682020_ROM_END - &code_682020_ROM_START); // Bug? Invalidates the same old VRAM address
        devAddr = &code_682020_ROM_START;
        size = &code_682020_ROM_END - &code_682020_ROM_START;
        dramAddr = &code_682020_VRAM;
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

    // Load Overlay code_60A840 
    {
        u32 devAddr;
        u32 size;
        void *dramAddr;

        osInvalICache(&code_60A840_VRAM, &code_60A840_ROM_END - &code_60A840_ROM_START);
        devAddr = &code_60A840_ROM_START;
        size = &code_60A840_ROM_END - &code_60A840_ROM_START;
        dramAddr = &code_60A840_VRAM;
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
}

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
