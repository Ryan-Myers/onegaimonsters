#include "common.h"
#include "1F3B0.h"
#include <ultra64.h>

extern void func_80111A50(unk801821A0 *);
s32 func_80110908(void *);
extern unk801821A0 D_80157628;

void func_801108C0(void) {
    func_801119D0(&D_80157628, func_80110908);
}


void func_801108E8(void) {
    func_80111A50(&D_80157628);
}

INCLUDE_ASM("asm/nonmatchings/1E4C0", func_80110908);

typedef struct unkMesg {
    s16 unk0;
    OSMesgQueue *unk4;
    s32 unk8;
} unkMesg;
typedef struct unk80110B10 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} unk80110B10;
extern s32 D_8015762C;
extern unk801821A0 D_80188E90[];

void func_80110B10(void **arg0, s32 arg1) {
    OSMesgQueue mq;
    unkMesg sp28;
    OSMesg dummy[1];
    unk80110B10 *temp_v0;

    if (D_8015762C != 0) {
        osCreateMesgQueue(&mq, dummy, 1);
        temp_v0 = (arg1 * 13) + D_80188E90;
        *arg0 = temp_v0;
        temp_v0->unk8 = arg1;
        sp28.unk0 = 0x2001;
        sp28.unk8 = arg0;
        sp28.unk4 = &mq;
        osSendMesg(&D_80182158, &sp28, OS_MESG_BLOCK);
        osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
    }
}
