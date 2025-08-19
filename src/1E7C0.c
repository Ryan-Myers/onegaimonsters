#include "1E7C0.h"
#include "common.h"

// Passed &D_801830C8 into arg0
// Returns into D_o1_801AAA50_6AB70 which seems to be passed to func_800FE990 arg0
// Definitely seems to be an integer return, and not an address.
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
