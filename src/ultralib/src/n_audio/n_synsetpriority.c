#include "common.h"
#include "PR/n_synthInternals.h"

void n_alSynSetPriority(N_ALVoice *voice, s16 priority) {
    voice->priority = priority;
}
