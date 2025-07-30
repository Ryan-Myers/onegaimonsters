#include "1F3B0.h"
#include "common.h"
#include "PR/sched.h"
#include "PRinternal/macros.h"

void thread1_main(void *);
extern OSThread thread1_thread;
extern STACK(thread1_stack, 0x2000) ALIGNED(0x10);

void mainproc(void) {
    osInitialize();
    osCreateThread(&thread1_thread, 1, thread1_main, NULL, STACK_START(thread1_stack), 10);
    osStartThread(&thread1_thread);
}

void thread3_main(void *);
void osViSetSpecialFeatures(u32);
void osCreateScheduler_alt(u8 mode, u8 numFields);
extern OSThread D_8015C010;
extern s32 (*D_801842F0)();
extern OSThread thread1_thread;

extern OSThread thread3_thread;
extern STACK(entrypointThreadStack, 0x2000) ALIGNED(0x10);

void thread1_main(void *unused) {
    s32 (*func)();
    D_801842F0 = NULL;
    func_801117B0();
    osCreateScheduler_alt(OS_VI_NTSC_HAF1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    osCreateThread(&thread3_thread, 3, thread3_main, NULL, STACK_START(entrypointThreadStack), 10);
    osStartThread(&thread3_thread);
    osSetThreadPri(&thread1_thread, 0);
    while (1) {
        func = D_801842F0;
        do {
        } while (func == NULL);
        func();
    }
}
