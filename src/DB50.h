#ifndef _DB50_H
#define _DB50_H

#include "common.h"
#include "segment_symbols.h"

#define MAX_DMA_SIZE 0x18000

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
        osInvalICache(&(vram_name##_VRAM), (overlay_name##_ROM_END) - (overlay_name##_ROM_START)); \
        devAddr = (u32)&(overlay_name##_ROM_START); \
        size = (u32)(overlay_name##_ROM_END) - (u32)(overlay_name##_ROM_START); \
        dramAddr = &(overlay_name##_VRAM); \
        while (size != 0) { \
            if (size < MAX_DMA_SIZE) { \
                dmaOverlay(devAddr, dramAddr, size); \
                size = 0; \
            } else { \
                dmaOverlay(devAddr, dramAddr, MAX_DMA_SIZE); \
                size -= MAX_DMA_SIZE; \
                devAddr += MAX_DMA_SIZE; \
                dramAddr = (void*)((u32)dramAddr + MAX_DMA_SIZE); \
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
s32 abs(s32 value);

#endif
