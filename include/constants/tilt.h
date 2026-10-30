#ifndef GUARD_CONSTANTS_TILT_H
#define GUARD_CONSTANTS_TILT_H

#include "constants/vars.h"

// Tilt mode save variables (all previously unused vars, saved with the game)
#define VAR_TILT_COMBO VAR_UNUSED_0x404E // current combo
#define VAR_TILT_BEST  VAR_UNUSED_0x4083 // best combo ever reached
#define VAR_TILT_SAVER VAR_UNUSED_0x408B // number of Ball Savers owned
#define VAR_TILT_STORY VAR_UNUSED_0x409B // Oldale mini story state (0-4)
#define VAR_TILT_TICKET VAR_UNUSED_0x40F7 // HEAL TICKETS owned (free Pinball Wizard heal)
#define VAR_TILT_WIZARD_MET VAR_UNUSED_0x40A1 // has talked to the Pinball Wizard

#define VAR_TILT_STEVEN VAR_UNUSED_0x40A8 // Steven Route 102 scene (0 = not seen, 1 = done)
#define FLAG_TILT_STEVEN_HIDE FLAG_UNUSED_0x020 // set = Steven hidden
// FLAG_UNUSED_0x022..0x02C are used by the scattered Tilt NPCs (tilt_npcs.inc)

// Cody's Gym: FLAG_UNUSED_0x02D (guard gone), 0x02E/0x02F/0x030 (Cody rewards 1-3 given)

// Littleroot Pokémon Center: FLAG_UNUSED_0x031 (clerk intro seen)

// Littleroot Poké Mart: FLAG_UNUSED_0x038 (clerk intro in the new MART seen), 0x039 (clerk hidden in the Pokémon Center, set on every load)

// FLAG_UNUSED_0x032: Pinball Wizard's old spot in Littleroot is hidden (he lives in the Pokémon Center 2F now)

// Joseph (Pikachu trainer, Littleroot yard): VAR_TILT_JOSEPH 0 = not beaten, 1 = beaten (story available), 2 = story done
#define VAR_TILT_JOSEPH VAR_UNUSED_0x40B8
// FLAG_UNUSED_0x033 = Aqua grunts hidden, 0x034 = Joseph reward complete, 0x035 = Joseph reward part 1 given

// Pinball Wizard intro scene (first exit from the house): VAR_UNUSED_0x40F8 0 = never queued (old saves), 2 = queued after the clock/Mom scene, 1 = seen; FLAG_UNUSED_0x03A hides the scene actor

// v17 mechanics (all previously unused vars/flags)
#define VAR_TILT_STEPS      VAR_UNUSED_0x4091 // steps since the last combo hit (combo decay)
#define VAR_TILT_BUFF       VAR_UNUSED_0x409D // steps left on the Wizard's buff
#define VAR_TILT_BUFFTYPE   VAR_UNUSED_0x40BB // 1 = double EXP, 2 = catch boost
#define VAR_TILT_DAYSTAMP   VAR_UNUSED_0x40DB // RTC day the daily challenge was last rolled
#define VAR_TILT_DAILYMAX   VAR_UNUSED_0x40DC // best combo reached today
#define VAR_TILT_PRIZES     VAR_UNUSED_0x40E5 // bitmask of claimed high-score prizes
#define VAR_TILT_REMATCH    VAR_UNUSED_0x40F9 // Dream Island rematch tier (+3 levels per tier)
#define VAR_TILT_DAILYCLAIM VAR_UNUSED_0x40FA // RTC day the daily reward was claimed
#define FLAG_TILT_RARE_USED FLAG_UNUSED_0x03B // rare bounce already used this combo run
#define FLAG_TILT_BERRY     FLAG_UNUSED_0x03C // next berry pick is a jackpot
#define FLAG_TILT_STORM     FLAG_UNUSED_0x03D // a Tilt Storm is raging on this route

// Result types passed to the post-battle message script
#define TILT_RESULT_HIT      0
#define TILT_RESULT_COINS    1
#define TILT_RESULT_CANDY    2
#define TILT_RESULT_SUPER    3
#define TILT_RESULT_DRAIN    4
#define TILT_RESULT_SAVED    5
#define TILT_RESULT_TILT     6

// PINBALL PHONE side quest (Petalburg City): VAR_TILT_PHONE 0 = not started, 1 = hunting parts, 2 = parts handed in (needs a combo of 3 for the signal test), 3 = phone given
#define VAR_TILT_PHONE      VAR_UNUSED_0x40FB
#define FLAG_TILT_PART_1    FLAG_UNUSED_0x040
#define FLAG_TILT_PART_2    FLAG_UNUSED_0x041
#define FLAG_TILT_PART_3    FLAG_UNUSED_0x042

#endif // GUARD_CONSTANTS_TILT_H
