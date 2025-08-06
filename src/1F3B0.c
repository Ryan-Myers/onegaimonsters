#include "1F3B0.h"
#include "common.h"
#include "PR/sched.h"
#include "PRinternal/macros.h"

static void thread5_main(void *);

// These must be static to prevent bss reordering of the stack
static OSMesgQueue piMQ ALIGNED(0x8);
static OSMesg piMsgs[50] ALIGNED(0x8);
static OSMesg siMsgs[8] ALIGNED(0x8);
static OSThread thread5_thread;
static STACK(thread5_stack, 0x2000) ALIGNED(0x10);

/**
 * Just runs osCreatePiManager
 */
void setupPiManager(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &piMQ, piMsgs, ARRAY_COUNT(piMsgs));
}

/**
 * Handles loading new code from the ROM for overlays.
 * @param devAddr The offset in ROM where the new code lives
 * @param dramAddr The RAM address to load the code into
 * @param size The size of overlay. Max 0x18000 at a time.
 */
void dmaOverlay(u32 devAddr, void *dramAddr, u32 size) {
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

/**
 * Sets up si events, and starts thread 5
 * @return controller bit pattern
 */
u8 func_80111890(void) {
    OSContStatus controllers[MAXCONTROLLERS];
    u8 bitpattern;

    D_801821A0 = NULL;
    D_801821A4 = 0;
    osCreateMesgQueue(&siEventQueue, siMsgs, ARRAY_COUNT(siMsgs));
    osSetEventMesg(OS_EVENT_SI, &siEventQueue, NULL);
    osContInit(&siEventQueue, &bitpattern, controllers);
    osCreateThread(&thread5_thread, 5, thread5_main, NULL, STACK_START(thread5_stack), 115);
    osStartThread(&thread5_thread);
    return bitpattern;
}

static void thread5_main(void *unused) {
    OSScClient client;
    volatile s32 pad; // TODO: Fix this
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
