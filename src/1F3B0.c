#include "common.h"
#include "PR/sched.h"
#include "PRinternal/macros.h"
#include "1F3B0.h"

static void thread5_main(void *);

// These must be static to prevent bss reordering of the stack
static OSMesgQueue piMQ ALIGNED(0x8);
static OSMesg piMsgs[50] ALIGNED(0x8);
static OSMesg siMsgs[8] ALIGNED(0x8);
static OSThread thread5_thread;
static STACK(thread5_stack, 0x2000) ALIGNED(0x10);

void func_801117B0(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &piMQ, piMsgs, ARRAY_COUNT(piMsgs));
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

    D_801821A0 = NULL;
    D_801821A4 = 0;
    osCreateMesgQueue(&siEventQueue, siMsgs, ARRAY_COUNT(siMsgs));
    osSetEventMesg(OS_EVENT_SI, &siEventQueue, NULL);
    func_801163C0(&siEventQueue, &ioMesg.size, &ioMesg);
    osCreateThread(&thread5_thread, 5, thread5_main, NULL, STACK_START(thread5_stack), 115);
    osStartThread(&thread5_thread);
    return ioMesg.size >> 24;
}

static void thread5_main(void *unused) {
    OSScClient client;
    volatile s32 pad;  // TODO: Fix this
    OSMesg msgs[8];
    volatile s32 pad1[2]; // TODO: Fix this
    unk801821A0 *var_s0;

    osCreateMesgQueue(&D_80182158, msgs, ARRAY_COUNT(msgs));
    osScAddClient_alt(&client, &D_80182158, 3);
    while (1) {
        osRecvMesg(&D_80182158, &msgs[8], OS_MESG_BLOCK);
        var_s0 = D_801821A0;
        while (var_s0 != NULL) {
            if (var_s0->func != NULL && var_s0->func(msgs[8]) != 0) {
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
    arg0->next = var_s0->next; // @bug: var_s0 can be unassigned.
    arg0->func = func;
    var_s0->next = arg0;
    osSetIntMask(savedMask);
}
