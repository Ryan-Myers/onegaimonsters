#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/timerintr", __osTimerServicesInit);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/timerintr", __osTimerInterrupt);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/timerintr", __osSetTimerIntr);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/timerintr", __osInsertTimer);
