#include "1F3B0.h"
#include "common.h"
#include "PR/sched.h"
#include "PRinternal/macros.h"

extern void thread3_main(void *);
extern void osViSetSpecialFeatures(u32);
extern void osCreateScheduler_alt(u8 mode, u8 numFields);
extern void (*D_801842F0)(void);
extern STACK(entrypointThreadStack, 0x2000) ALIGNED(0x10);

static void thread1_main(void *);

// These must be static to prevent bss reordering of the stack
static OSThread thread1_thread;
static OSThread thread3_thread;
static STACK(thread1_stack, 0x2000) ALIGNED(0x10);

/**
 * The first function loaded from the entrypoint. It just sets up the idle thread
 */
void mainproc(void) {
    osInitialize();
    osCreateThread(&thread1_thread, 1, thread1_main, NULL, STACK_START(thread1_stack), 10);
    osStartThread(&thread1_thread);
}

/**
 * Idle thread, set up the pi manager, scheduler, and vi features, then start thread 3 and go idle.
 */
static void thread1_main(void *unused) {
    D_801842F0 = NULL;
    setupPiManager();
    osCreateScheduler_alt(OS_VI_NTSC_HAF1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    osCreateThread(&thread3_thread, 3, thread3_main, NULL, STACK_START(entrypointThreadStack), 10);
    osStartThread(&thread3_thread);
    osSetThreadPri(&thread1_thread, OS_PRIORITY_IDLE);
    // Inifinitely loops and executes whatever function is in D_801842F0
    // Haven't found what sets it, but it might be an overlay.
    while (1) {
        void (*func)(void) = D_801842F0;
        do {
        } while (func == NULL);
        func();
    }
}
