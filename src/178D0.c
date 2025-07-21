#include "common.h"

#if 0
void func_8010A964(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void func_80109CD0(ALCSPlayer *seqp, s16 vol)
{
    ALEvent       evt;

    evt.type            = AL_SEQP_VOL_EVT;
    evt.msg.spvol.vol   = vol;
    
    func_8010A964(&seqp->evtq, &evt, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/178D0", func_80109CD0);
#endif
