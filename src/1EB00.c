#include "common.h"

extern s32 D_8015762C;
extern OSMesgQueue D_80182158;

typedef struct unkMesg_80110F00 {
    s16 unk0;
    OSMesgQueue *mq;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} unkMesg_80110F00;


void func_80110F00(s32 arg0, s32 arg1, s32 arg2) {
    OSMesgQueue mq;
    unkMesg_80110F00 mesg;
    OSMesg dummy[1];

    if (D_8015762C == 0) {
        return;
    }

    osCreateMesgQueue(&mq, dummy, 1);
    mesg.unk8 = arg0;
    mesg.unk0 = 0x2005;
    mesg.mq = &mq;
    mesg.unkC = arg1;
    mesg.unk10 = arg2;
    osSendMesg(&D_80182158, &mesg, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}
