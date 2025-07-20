#include "common.h"

int func_801106B0();                                  /* extern */
int func_80114110(int);                             /* extern */
extern int D_80157640;

void func_80110610(int arg0) {
    int temp_v0;

    func_801106B0();
    temp_v0 = func_80114110(1);
    D_80157640 = arg0;
    func_80114110(temp_v0);
}
