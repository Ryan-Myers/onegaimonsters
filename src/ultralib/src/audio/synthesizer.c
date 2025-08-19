#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", alSynNew);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", alAudioFrame);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", __allocParam);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", __freeParam);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", _collectPVoices);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", _freePVoice);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", _timeToSamplesNoRound);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", _timeToSamples);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/audio/synthesizer", __nextSampleTime);
