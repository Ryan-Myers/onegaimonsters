#ifndef _LANGUAGE_C
// Hack as vs code just wasn't seeing this defined for some reason
#define _LANGUAGE_C
#endif

#include <ultra64.h>
#include "include_asm.h"

#define ARRAY_COUNT(x) ((s32)(sizeof(x) / sizeof(x[0])))
