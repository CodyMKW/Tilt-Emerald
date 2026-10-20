#ifndef GUARD_CONSTANTS_TILT_H
#define GUARD_CONSTANTS_TILT_H

#include "constants/vars.h"

// Tilt mode save variables (all previously unused vars, saved with the game)
#define VAR_TILT_COMBO VAR_UNUSED_0x404E // current combo
#define VAR_TILT_BEST  VAR_UNUSED_0x4083 // best combo ever reached
#define VAR_TILT_SAVER VAR_UNUSED_0x408B // number of Ball Savers owned
#define VAR_TILT_STORY VAR_UNUSED_0x409B // Oldale mini story state (0-4)
#define VAR_TILT_WIZARD_MET VAR_UNUSED_0x40A1 // has talked to the Pinball Wizard

// Result types passed to the post-battle message script
#define TILT_RESULT_HIT      0
#define TILT_RESULT_COINS    1
#define TILT_RESULT_CANDY    2
#define TILT_RESULT_SUPER    3
#define TILT_RESULT_DRAIN    4
#define TILT_RESULT_SAVED    5

#endif // GUARD_CONSTANTS_TILT_H
