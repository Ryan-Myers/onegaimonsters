#include "common.h"

typedef unsigned int OSIntMask;
int func_801106B0();
OSIntMask osSetIntMask(OSIntMask);
extern int D_80157640;
#define OS_IM_NONE      0x00000001

void func_80110610(int arg0) {
    OSIntMask temp_v0;

    func_801106B0();
    temp_v0 = osSetIntMask(OS_IM_NONE);
    D_80157640 = arg0;
    osSetIntMask(temp_v0);
}
