#include "common.h"

extern s32 D_8015762C;
extern OSMesgQueue D_80182158;
void func_801120A0(void *arg0, u8 *arg1, u32 arg2);

typedef struct unkMesg_80110FA0 {
    s16 unk0;
    OSMesgQueue *mq;
    s32 unk8;
    u8 *unkC;
    u8 *unk10;
    s32 unk14;
    s32 unk18;
} unkMesg_80110FA0;

// arg1 is rodata "ONEGAI MONSTER"
// arg2 is rodata "B"
void func_80110FA0(s32 arg0, char *arg1, char *arg2) {
    OSMesgQueue mq;
    OSMesg dummy[1];
    unkMesg_80110FA0 mesg;
    u8 sp48[16];
    u8 sp58[3];
    s32 i;

    if (D_8015762C == 0) {
        return;
    }

    bzero(&sp48, ARRAY_COUNT(sp48));
    bzero(&sp58, ARRAY_COUNT(sp58));
    for (i = 0; arg1[i] != '\0'; i++) {}
    func_801120A0(arg1, sp48, i);
    func_801120A0(arg2, sp58, 1);
    osCreateMesgQueue(&mq, dummy, 1);
    mesg.unk0 = 0x2005;
    mesg.unk8 = arg0;
    mesg.mq = &mq;
    mesg.unkC = sp48;
    mesg.unk10 = sp58;
    osSendMesg(&D_80182158, &mesg, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}
