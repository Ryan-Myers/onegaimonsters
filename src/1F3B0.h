
#ifndef _1F3B0_H
#define _1F3B0_H

#include "common.h"
#include "PR/sched.h"

typedef struct unk801821A0 {
    struct unk801821A0 *next;
    s32 (*func)(void *);
} unk801821A0;

// Functions we use from other files
void osScAddClient_alt(OSScClient *c, OSMesgQueue *msgQ, s16 id);
void func_801163C0(OSMesgQueue *, u32 *, OSIoMesg *);

// These BSS vars are defined in another file
extern OSMesgQueue D_80182158;  // bss6
extern unk801821A0 *D_801821A0; // bss6
extern s32 D_801821A4;  // bss6
extern OSMesgQueue siEventQueue; // bss6

void setupPiManager(void);
void dmaOverlay(u32 devAddr, void *dramAddr, u32 size);
u8 func_80111890(void);
void func_801119D0(unk801821A0 *arg0, s32 (*func)(void *));

#endif
