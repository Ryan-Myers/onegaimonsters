#ifndef _1E7C0_H
#define _1E7C0_H

#include "common.h"

extern OSMesgQueue D_80182158;
extern s32 D_8015762C;

typedef struct unkMesg_80110BC0 {
    s16 unk0;
    OSMesgQueue *mq;
    s32 unk8;
    s32 unkC;
} unkMesg_80110BC0;

s32 func_80110BC0(s32 arg0);

#endif
