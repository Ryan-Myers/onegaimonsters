#include "1E210.h"
#include "common.h"

s32 func_801106B0(void);

void func_80110610(void (*func)(s32)) {
    OSIntMask savedMask;

    func_801106B0();
    savedMask = osSetIntMask(OS_IM_NONE);
    D_80157640 = func;
    osSetIntMask(savedMask);
}
