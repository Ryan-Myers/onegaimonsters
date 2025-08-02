#include "common.h"

// Looks like it could be a memory pool allocator.

#ifdef NON_EQUIVALENT

#define ALIGN(s, align) (((unsigned int) (s) + ((align) - 1)) & ~((align) - 1))

typedef struct MemoryPool {
    u32 baseAddress;
    u32 currentAllocationOffset;
    u32 poolSize;
} MemoryPool;

u32 func_80115210(s32 arg0, s32 arg1, MemoryPool *memPool, u32 count, u32 elementSize) {
    u32 nextOffset;
    u32 curOffset;
    u32 ret;

    ret = 0;
    curOffset = memPool->currentAllocationOffset;
    nextOffset = memPool->currentAllocationOffset + ALIGN((count * elementSize), 16);
    if ((memPool->baseAddress + memPool->poolSize) >= nextOffset) {
        ret = curOffset;
        memPool->currentAllocationOffset = nextOffset;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/22E10", func_80115210);
#endif
