#ifndef _MAIN_H
#define _MAIN_H

#include "common.h"
#include "PRinternal/macros.h"

extern void mainproc(void *);
extern void osCreateScheduler_alt(u8 mode, u8 numFields);
extern void (*D_801842F0)(void);
extern STACK(mainThreadStack, 0x2000) ALIGNED(0x10);

void boot(void);

#endif
