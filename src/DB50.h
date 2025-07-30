
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


void func_800FFF50(void);
void loadOverlayAtAddress(u32 devAddr, void *dramAddr, u32 size);
void loadOverlay2(void);
void loadOverlay3(void);
void loadOverlay4(void);
void func_801001C4(s32 newVal);

#endif
