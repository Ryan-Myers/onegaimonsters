#include "1E250.h"
#include "common.h"
#include "PR/sched.h"

void func_80110650(void (*func)(OSScTask *)) {
    OSIntMask savedMask;

    savedMask = osSetIntMask(OS_IM_NONE);
    D_801574D4 = func;
    osSetIntMask(savedMask);
}
