
#ifndef _DB50_H
#define _DB50_H

#include "common.h"

// Overlay 2
extern u8 o2_ROM_START;
extern u32 o2_VRAM;
extern u32 o2_BSS_START;
extern u32 o2_BSS_END;

// Overlay 3
extern u8 o3_ROM_START;
extern u32 o3_VRAM;
extern u32 o3_BSS_START;
extern u32 o3_BSS_END;

// Overlay 4
extern u8 o4_ROM_START;
extern u32 o4_VRAM;
extern u32 o4_BSS_START;
extern u32 o4_BSS_END;

// Overlay 5
extern u8 o5_ROM_START;

// Overlay code_1B10E0
extern u32 code_1B10E0_VRAM;

// Overlay code_1B4070
extern u8 code_1B4070_ROM_START;
extern u8 code_1B4070_ROM_END;
extern u32 code_1B4070_VRAM;
extern u32 code_1B4070_BSS_START;
extern u32 code_1B4070_BSS_END;

// Overlay code_1B7D00
extern u8 code_1B7D00_ROM_START;

// Overlay code_682020
extern u8 code_682020_ROM_START;
extern u8 code_682020_ROM_END;
extern u32 code_682020_VRAM;

// Overlay code_60A840
extern u8 code_60A840_ROM_START;
extern u8 code_60A840_ROM_END;
extern u32 code_60A840_VRAM;


// Overlay code_728410
extern u8 code_728410_ROM_START;

/**
 * This has VRAM and DRAM seperated as for some reason, sometimes they invalidate I cache and dma different addresses in VRAM
 * That could be a bug though.
 */
#define LOAD_OVERLAY_ALT(overlay_name, vram_name) \
    { \
        u32 devAddr; \
        u32 size; \
        void *dramAddr; \
        \
        osInvalICache(&(vram_name##_VRAM), &(overlay_name##_ROM_END) - &(overlay_name##_ROM_START)); \
        devAddr = (u32)&(overlay_name##_ROM_START); \
        size = (u32)&(overlay_name##_ROM_END) - (u32)&(overlay_name##_ROM_START); \
        dramAddr = &(overlay_name##_VRAM); \
        while (size != 0) { \
            if (size < 0x18000) { \
                dmaOverlay(devAddr, dramAddr, size); \
                size = 0; \
            } else { \
                dmaOverlay(devAddr, dramAddr, 0x18000); \
                size -= 0x18000; \
                devAddr += 0x18000; \
                dramAddr = (void*)((u32)dramAddr + 0x18000); \
            } \
        } \
    }

#define LOAD_OVERLAY(overlay_name) LOAD_OVERLAY_ALT(overlay_name, overlay_name)
#define ZERO_OVERLAY_BSS(overlay_name) bzero(&overlay_name##_BSS_START, (u32) &overlay_name##_BSS_END - (u32) &overlay_name##_BSS_START);

void func_800FFF50(void);
void loadOverlayAtAddress(u32 devAddr, void *dramAddr, u32 size);
void loadOverlay2(void);
void loadOverlay3(void);
void loadOverlay4(void);
void func_801001C4(s32 newVal);
void func_801001E4(void);
void func_801003EC(s32 arg0);
s32 getAbs(s32 value);

#endif
