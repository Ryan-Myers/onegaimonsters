#include "common.h"
#include "PR/sched.h"

extern OSMesgQueue D_80169250;
extern void *D_80169268;

typedef struct unk801821A0 {
    struct unk801821A0 *next;
    s32 (*func)(void *);
} unk801821A0;

void func_80111938(void *);
void func_801163C0(OSMesgQueue *, u32 *, OSIoMesg *);
extern OSMesg D_80169330;
extern OSThread D_80169350;
extern void *D_8016B500;
extern unk801821A0 *D_801821A0;
extern s32 D_801821A4;
extern OSMesgQueue D_80189048;
void osScAddClient_alt(OSScClient *c, OSMesgQueue *msgQ, s16 id);

extern OSMesgQueue D_80182158;

void func_801117B0(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_80169250, &D_80169268, 50);
}

void func_801117E0(u32 devAddr, void *dramAddr, s32 size) {
    OSIoMesg ioMesg;
    OSMesgQueue queue;
    OSMesg mesg;
    OSPiHandle *romHandle;

    romHandle = osCartRomInit();
    osCreateMesgQueue(&queue, &mesg, 1);
    osInvalDCache(dramAddr, size);
    ioMesg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMesg.hdr.retQueue = &queue;
    ioMesg.dramAddr = dramAddr;
    ioMesg.devAddr = devAddr;
    ioMesg.size = size;
    osEPiStartDma(romHandle, &ioMesg, OS_READ);
    osRecvMesg(&queue, &mesg, OS_MESG_BLOCK);
}

u8 func_80111890(void) {
    OSIoMesg ioMesg;

    D_801821A0 = 0;
    D_801821A4 = 0;
    osCreateMesgQueue(&D_80189048, &D_80169330, 8);
    osSetEventMesg(5, &D_80189048, NULL);
    func_801163C0(&D_80189048, &ioMesg.size, &ioMesg);
    osCreateThread(&D_80169350, 5, func_80111938, NULL, &D_8016B500, 115);
    osStartThread(&D_80169350);
    return ioMesg.size >> 24;
}

void func_80111938(void *unused) {
    OSScClient client;
    volatile s32 pad;  // TODO: Fix this
    OSMesg sp20[8];
    volatile s32 pad1[2]; // TODO: Fix this
    unk801821A0 *var_s0;

    osCreateMesgQueue(&D_80182158, &sp20, ARRAY_COUNT(sp20));
    osScAddClient_alt(&client, &D_80182158, 3);
    while (1) {
        osRecvMesg(&D_80182158, &sp20[8], 1);
        var_s0 = D_801821A0;
        while (var_s0 != NULL) {
            if (var_s0->func != NULL && var_s0->func(sp20[8]) != 0) {
                break;
            }
            var_s0 = var_s0->next;
        } 
    }
}

void func_801119D0(unk801821A0 *arg0, s32 (*func)(void *)) {
    OSIntMask savedMask;
    unk801821A0 *var_s0;
    unk801821A0 *var_v1;

    var_v1 = &D_801821A0;
    if (var_v1 != NULL) {
        while (1) {
            if (var_v1->func != func) {
                var_s0 = var_v1;
                var_v1 = &var_v1->next->next;
                if (var_v1 == NULL) {
                    break;
                }
            } else {
                return;
            }
        }
    }
    savedMask = osSetIntMask(OS_IM_NONE);
    arg0->next = var_s0->next;
    arg0->func = func;
    var_s0->next = arg0;
    osSetIntMask(savedMask);
}
