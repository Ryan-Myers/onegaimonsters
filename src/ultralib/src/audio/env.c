#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", alEnvmixerPull);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", alEnvmixerParam);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", _pullSubFrame);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", _frexpf);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", _ldexpf);

INCLUDE_RODATA("asm/nonmatchings/ultralib/src/audio/env", logtab);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", _getRate);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/env", _getVol);
