#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", n_alSynNew);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", n_alAudioFrame);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", __n_allocParam);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", _n_freeParam);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", _n_collectPVoices);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", _n_freePVoice);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", _n_timeToSamplesNoRound);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", _n_timeToSamples);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_synthesizer", __n_nextSampleTime);
