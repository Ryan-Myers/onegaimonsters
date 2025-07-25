#include "common.h"
#include "PR/sched.h"

void swap_vi_buffer(OSScTask *t) {
    osViSwapBuffer(t->framebuffer);
}
