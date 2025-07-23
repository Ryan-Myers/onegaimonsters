#include "common.h"

extern volatile s32 D_801821A8;

/**
 * Poor mans thread synchronization
 * Waits until another thread marks the variable as 1
 */
void func_801106B0(void) {
    while (D_801821A8 != 0) {}
}
