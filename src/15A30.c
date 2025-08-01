#include "common.h"
#include "DB50.h"
#include "1F3B0.h"

typedef struct MemoryPool {
    u32 baseAddress;
    u32 currentAllocationOffset;
    u32 poolSize;
} MemoryPool;

typedef struct unk80107E30 {
  u16 unk0;
  s16 unk2;  
} unk80107E30;

void func_80114860(void *, u32);
void *func_80115210(s32 arg0, s32 arg1, MemoryPool *memPool, u32 count, u32 elementSize);
extern void *D_80175AB8;
extern MemoryPool *D_8016FC40;

void func_80107E30(u32 devAddr) {
    u8 sp27[28]; // TODO: What is this?
    unk80107E30 *dramAddr;
    u32 size;
    void *temp_v0;

    dramAddr = ((u32) &sp27[15] >> 4) * 0x10;
    dmaOverlay(devAddr, dramAddr, 4);
    size = (dramAddr->unk2 * 8) + 4;
    D_80175AB8 = func_80115210(0, 0, &D_8016FC40, 1, size);
    dmaOverlay(devAddr, D_80175AB8, size);
    func_80114860(D_80175AB8, devAddr);
}
