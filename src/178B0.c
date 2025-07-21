#include "common.h"
struct Unk80109CB0 {
    u8 pad[0x2C];
    s32 unk2C;
};
// Could be alCSPGetState
s32 func_80109CB0(ALCSPlayer *seqp)
{
    return seqp->state;
}