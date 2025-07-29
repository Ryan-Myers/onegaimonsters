#include "common.h"

INCLUDE_ASM("asm/nonmatchings/1F3B0", func_801117B0);

void func_801117E0(u32 devAddr, void *dramAddr, s32 size) {
    OSIoMesg ioMesg;
    OSMesgQueue queue;
    OSMesg mesg;
    OSPiHandle *romHandle;

    romHandle = osCartRomInit();
    osCreateMesgQueue(&queue, &mesg, OS_MESG_BLOCK);
    osInvalDCache(dramAddr, size);
    ioMesg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMesg.hdr.retQueue = &queue;
    ioMesg.dramAddr = dramAddr;
    ioMesg.devAddr = devAddr;
    ioMesg.size = size;
    osEPiStartDma(romHandle, &ioMesg, OS_READ);
    osRecvMesg(&queue, &mesg, OS_MESG_BLOCK);
}

INCLUDE_ASM("asm/nonmatchings/1F3B0", func_80111890);

INCLUDE_ASM("asm/nonmatchings/1F3B0", func_80111938);

INCLUDE_ASM("asm/nonmatchings/1F3B0", func_801119D0);
