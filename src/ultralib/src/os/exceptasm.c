#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osExceptionPreamble);

INCLUDE_RODATA("asm/nonmatchings/ultralib/src/os/exceptasm", __osIntOffTable);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osException);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", send_mesg);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", handle_CpU);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osEnqueueAndYield);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osEnqueueThread);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osPopThread);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osDispatchThread);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/os/exceptasm", __osCleanupThread);
