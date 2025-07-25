#include "common.h"
#include "PR/sched.h"

extern void (*D_801574D4)(OSScTask *);

void func_80110650(void (*func)(OSScTask *)) {
    OSIntMask savedMask;

    savedMask = osSetIntMask(OS_IM_NONE);
    D_801574D4 = func;
    osSetIntMask(savedMask);
}
