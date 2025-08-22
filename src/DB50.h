#ifndef _DB50_H
#define _DB50_H

#include "common.h"
#include "segment_symbols.h"

#define MAX_DMA_SIZE 0x18000

#define LOAD_CODE_SEGMENT(overlay_name) \
    { \
        osInvalICache(SEGMENT_VRAM_START(overlay_name), SEGMENT_ROM_SIZE(overlay_name)); \
        loadOverlayAtAddress(SEGMENT_ROM_START(overlay_name), SEGMENT_VRAM_START(overlay_name), SEGMENT_ROM_SIZE(overlay_name)); \
        ZERO_OVERLAY_BSS(overlay_name); \
    }

/**
 * This has VRAM and DRAM seperated as for some reason, sometimes they invalidate I cache and dma different addresses in VRAM
 * That could be a bug though.
 */
#define LOAD_DATA_SEGMENT_ALT(overlay_name, vram_name) \
    { \
        u32 devAddr; \
        u32 size; \
        void *dramAddr; \
        \
        osInvalICache(SEGMENT_VRAM_START(vram_name), SEGMENT_ROM_SIZE(overlay_name)); \
        devAddr = SEGMENT_ROM_START(overlay_name); \
        size = SEGMENT_ROM_SIZE(overlay_name); \
        dramAddr = SEGMENT_VRAM_START(overlay_name); \
        while (size != 0) { \
            if (size < MAX_DMA_SIZE) { \
                dmaOverlay(devAddr, dramAddr, size); \
                size = 0; \
            } else { \
                dmaOverlay(devAddr, dramAddr, MAX_DMA_SIZE); \
                size -= MAX_DMA_SIZE; \
                devAddr += MAX_DMA_SIZE; \
                dramAddr += MAX_DMA_SIZE; \
            } \
        } \
    }

#define LOAD_DATA_SEGMENT(overlay_name) LOAD_DATA_SEGMENT_ALT(overlay_name, overlay_name)
#define ZERO_OVERLAY_BSS(overlay_name) bzero(SEGMENT_BSS_START(overlay_name), SEGMENT_BSS_SIZE(overlay_name));

#define LOAD_OVERLAY(overlay_name) \
    LOAD_DATA_SEGMENT(overlay_name); \
    ZERO_OVERLAY_BSS(overlay_name); \


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
