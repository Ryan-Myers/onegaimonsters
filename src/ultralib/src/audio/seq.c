#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqNew);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqNextEvent);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", __alSeqNextDelta);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqTicksToSec);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqSecToTicks);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqNewMarker);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqGetTicks);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqSetLoc);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", alSeqGetLoc);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", read8_seq);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", read16_seq);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", read32_seq);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/seq", readVarLen_seq);
