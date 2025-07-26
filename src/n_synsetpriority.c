#include "common.h"

/*
 * Synthesis driver stuff
 */
typedef struct N_ALVoice_s {
    ALLink              node;
    struct N_PVoice_s     *pvoice;
    ALWaveTable         *table;
    void                *clientPrivate;
    s16                 state;
    s16                 priority;
    s16                 fxBus;
    s16                 unityPitch;
} N_ALVoice;

void n_alSynSetPriority(N_ALVoice *voice, s16 priority) {
    voice->priority = priority;
}
