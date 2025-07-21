#include "common.h"

s32 func_801106B0(void);
extern s32 D_80157640;

void func_80110610(s32 arg0) {
    OSIntMask mask;

    func_801106B0();
    mask = osSetIntMask(OS_IM_NONE);
    D_80157640 = arg0;
    osSetIntMask(mask);
}
