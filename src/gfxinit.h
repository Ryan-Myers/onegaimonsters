#ifndef _GFXINIT_H
#define _GFXINIT_H

#include "common.h"

extern LookAt gfxLookAt[2];
extern Vp D_80152990;
extern Lights1 D_801529A0;
extern s32 D_801529B8[];
extern Gfx D_801529C0[];
extern Gfx D_80152A38[];

extern Gfx *D_80189064;
extern Gfx *D_80189090;
extern Mtx D_80126370;

// Mtx D_80126370 = {
//     { 0x10000, 0, 1, 0 },
//     { 0, 0x10000, 0, 1 },
//     { 0, 0, 0, 0 },
//     { 0, 0, 0, 0 },
// };

extern u32 D_80171B20;
extern s32 D_801880C0;
extern void __assert(const char *, const char *, int);

void func_800FF7A0(s32 isOpaque);
void func_800FF9D8(void);
void func_800FFABC(Mtx *mtx, f32 arg1, f32 arg2);

#endif
