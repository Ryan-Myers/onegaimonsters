#include "common.h"

extern OSMesgQueue D_80182158;
extern s32 D_8015762C;

typedef struct unkMesg_80110BC0 {
    s16 unk0;
    OSMesgQueue *mq;
    s32 unk8;
    s32 unkC;
} unkMesg_80110BC0;

s32 func_80110BC0(s32 arg0) {
    OSMesgQueue mq;
    unkMesg_80110BC0 mesg;
    OSMesg dummy[1];

    if (D_8015762C == 0) {
        return 0;
    }

    osCreateMesgQueue(&mq, dummy, 1);
    mesg.unk8 = arg0;
    mesg.unk0 = 0x2002;
    mesg.mq = &mq;
    osSendMesg(&D_80182158, &mesg, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);

    return mesg.unkC;
}
