#ifndef _15A30_H
#define _15A30_H

#include "common.h"
#include "libaudio.h"

typedef struct unk80107E30 {
    u16 unk0;
    s16 unk2;
} unk80107E30;

extern ALSeqFile *D_80175AB8;
extern ALHeap D_8016FC40;

void func_80107E30(u32 devAddr);

#endif
