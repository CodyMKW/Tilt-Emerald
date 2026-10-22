#ifndef GUARD_CONSTANTS_TILT_H
#define GUARD_CONSTANTS_TILT_H

#include "constants/vars.h"

// Tilt mode save variables (all previously unused vars, saved with the game)
#define VAR_TILT_COMBO VAR_UNUSED_0x404E // current combo
#define VAR_TILT_BEST  VAR_UNUSED_0x4083 // best combo ever reached
#define VAR_TILT_SAVER VAR_UNUSED_0x408B // number of Ball Savers owned
#define VAR_TILT_STORY VAR_UNUSED_0x409B // Oldale mini story state (0-4)
#define VAR_TILT_WIZARD_MET VAR_UNUSED_0x40A1 // has talked to the Pinball Wizard

#define VAR_TILT_STEVEN VAR_UNUSED_0x40A8 // Steven Route 102 scene (0 = not seen, 1 = done)
#define FLAG_TILT_STEVEN_HIDE FLAG_UNUSED_0x020 // set = Steven hidden
// FLAG_UNUSED_0x022..0x02C are used by the scattered Tilt NPCs (tilt_npcs.inc)

// Cody's Gym: FLAG_UNUSED_0x02D (guard gone), 0x02E/0x02F/0x030 (Cody rewards 1-3 given)

// Littleroot Pokémon Center: FLAG_UNUSED_0x031 (clerk intro seen)

// FLAG_UNUSED_0x032: Pinball Wizard's old spot in Littleroot is hidden (he lives in the Pokémon Center 2F now)

// Joseph (Pikachu trainer, Littleroot yard): VAR_TILT_JOSEPH 0 = not beaten, 1 = beaten (story available), 2 = story done
#define VAR_TILT_JOSEPH VAR_UNUSED_0x40B8
// FLAG_UNUSED_0x033 = Aqua grunts hidden, 0x034 = Joseph reward complete, 0x035 = Joseph reward part 1 given

// Result types passed to the post-battle message script
#define TILT_RESULT_HIT      0
#define TILT_RESULT_COINS    1
#define TILT_RESULT_CANDY    2
#define TILT_RESULT_SUPER    3
#define TILT_RESULT_DRAIN    4
#define TILT_RESULT_SAVED    5

#endif // GUARD_CONSTANTS_TILT_H
