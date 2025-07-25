#include "common.h"

s32 func_801106B0(void);
extern void (*D_80157640)(s32);

void func_80110610(void (*func)(s32)) {
    OSIntMask savedMask;

    func_801106B0();
    savedMask = osSetIntMask(OS_IM_NONE);
    D_80157640 = func;
    osSetIntMask(savedMask);
}
