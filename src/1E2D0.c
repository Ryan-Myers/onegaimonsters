#include "common.h"

extern s32 D_801574D0;
extern s32 D_80172DF0;
extern s32 D_801880C0;
extern s32 *D_801882E0;

void func_801106D0(s32 *arg0, s32 arg1) {
    D_801882E0 = arg0;
    D_801574D0 = arg1;
    D_80172DF0 = 0;
    D_801880C0 = *arg0;
}
