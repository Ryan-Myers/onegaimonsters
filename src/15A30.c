#include "1F3B0.h"
#include "common.h"
#include "DB50.h"

typedef struct MemoryPool {
    u32 baseAddress;
    u32 currentAllocationOffset;
    u32 poolSize;
} MemoryPool;

typedef struct unk80107E30 {
    u16 unk0;
    s16 unk2;
} unk80107E30;

void alSeqFileNew(ALSeqFile *file, u8 *base);
// void *alHeapDBAlloc(s32 arg0, s32 arg1, MemoryPool *memPool, u32 count, u32 elementSize);
extern ALSeqFile *D_80175AB8;
extern ALHeap *D_8016FC40;

/**
 * This function seems to only be called from func_80105A80, which itself seems to called from
 * func_800FFF50. This means D_80157120 has a struct where unk2C is the devAddr for this function.
 * So this is loading an overlay from D_80157120->unk2C I think that means it's loading from E42C50
 */
void func_80107E30(u32 devAddr) {
    u8 buffer[32];
    unk80107E30 *dramAddr;
    u32 size;
    void *temp_v0;

    // Get a 16-byte aligned address from the buffer.
    dramAddr = (u32) (buffer + 15) >> 4 << 4;
    // Confirmed with deubgger that devAddr is 0xE42C50 and dramAddr is 0x80177D80
    // Loads value 0x533100B2? So unk2 is 0x14C?
    dmaOverlay(devAddr, dramAddr, 4);
    size = (dramAddr->unk2 * 8) + 4; // So size is A64?
    D_80175AB8 = alHeapDBAlloc(0, 0, &D_8016FC40, 1, size);
    // We then dma the same 0xE42C50 to 800EC500? But this time it's 0xA64 bytes?
    // Making us load to E436B4?
    dmaOverlay(devAddr, D_80175AB8, size);
    alSeqFileNew(D_80175AB8, devAddr);
}
