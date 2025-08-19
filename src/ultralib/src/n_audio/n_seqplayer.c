#include "common.h"

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", n_alSeqpNew);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_seqpVoiceHandler);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_handleNextSeqEvent);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_HandleMIDIMsg);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __handleMetaMsg);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_unmapVoice);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_seqpReleaseVoice);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_voiceNeedsNoteKill);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_setUsptFromTempo_seqplayer);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_mapVoice);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_lookupVoice);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_lookupSoundQuick);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_vsVol);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_vsDelta);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_vsPan);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_initFromBank);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_initChanState);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_resetPerfChanState);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_setInstChanState);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_seqpStopOsc);

INCLUDE_ASM("asm/nonmatchings/ultralib/src/n_audio/n_seqplayer", __n_postNextSeqEvent);
