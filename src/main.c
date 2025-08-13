#include "main.h"
#include "1F3B0.h"
#include "common.h"
#include "PR/sched.h"
#include "PRinternal/macros.h"

static void idle(void *);

// These must be static to prevent bss reordering of the stack
static OSThread idleThread;
static OSThread mainThread;
static STACK(idleThreadStack, 0x2000) ALIGNED(0x10);

/**
 * The first function loaded from the entrypoint. It just sets up the idle thread
 */
void boot(void) {
    osInitialize();
    osCreateThread(&idleThread, 1, idle, NULL, STACK_START(idleThreadStack), 10);
    osStartThread(&idleThread);
}

/**
 * Idle thread, set up the pi manager, scheduler, and vi features, then start thread 3 and go idle.
 */
static void idle(void *unused) {
    D_801842F0 = NULL;
    setupPiManager();
    osCreateScheduler_alt(OS_VI_NTSC_HAF1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    osCreateThread(&mainThread, 3, mainproc, NULL, STACK_START(mainThreadStack), 10);
    osStartThread(&mainThread);
    osSetThreadPri(&idleThread, OS_PRIORITY_IDLE);
    // Inifinitely loops and executes whatever function is in D_801842F0
    // Haven't found what sets it, but it might be an overlay.
    while (1) {
        void (*func)(void) = D_801842F0;
        do {
        } while (func == NULL);
        func();
    }
}
