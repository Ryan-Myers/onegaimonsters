
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

void func_800FFF50(void);
void loadOverlayAtAddress(u32 devAddr, void *dramAddr, u32 size);
void loadOverlay2(void);

#endif
