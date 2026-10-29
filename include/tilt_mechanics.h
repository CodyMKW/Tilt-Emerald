#ifndef GUARD_TILT_MECHANICS_H
#define GUARD_TILT_MECHANICS_H

void TiltResetCombo(void);
void TiltAddCombo(u16 amount);
u16 TiltCatchBonus(void);
u16 TiltExpPercent(void);
bool8 TiltStepUpdate(void);
void TiltBattleStart(void);
bool8 TiltTryBallSaverRevive(u8 battler);
bool8 TiltSlingshotCrit(void);
void TiltOnSuperEffective(void);
u8 TiltTakeBankBonus(void);
bool8 TiltTryFlip(void);
void TiltRollStorm(void);
bool8 TiltIsStorm(void);
bool8 TiltOnLuckyRoute(void);
void TiltDailyRoll(void);
void TiltOnComboHit(u16 prev, u16 combo);
extern bool8 gTiltMultiballActive;
extern u8 gTiltFlipMsg;
bool8 TiltBonusEncounter(void);
bool8 TiltAddSecondBall(void);
extern bool8 gTiltDoubleBall;
extern u8 gTiltCatchChain;
void TiltForceShinyNext(void);
bool8 TiltTakeForceShiny(void);

u8 TiltTrainerLevel(u16 trainerNum, u8 level);

// ---- options pages 3-5 (bit-packed in gSaveBlock2Ptr->tiltOpts) ----
enum
{
    TILTOPT_INSTANT_TEXT,
    TILTOPT_EXP_BOOST,    // 0 = 1x, 1 = 1.5x, 2 = 2x
    TILTOPT_CATCH_BOOST,  // 0 = 1x, 1 = 1.5x, 2 = 2x
    TILTOPT_AUTO_HEAL,
    TILTOPT_NO_SWITCH,
    TILTOPT_NUZLOCKE,
    TILTOPT_COMBO_DIFF,   // 0 = easy, 1 = normal, 2 = hard
    TILTOPT_MB_FREQ,      // 0 = low, 1 = mid, 2 = high
    TILTOPT_BIG_BAG,
    TILTOPT_LEVEL_CAP,
    TILTOPT_COMBO_EXP,    // 1 = combo EXP buff allowed (default)
    TILTOPT_SKIP_LEARN,
    TILTOPT_SKIP_NICK,
    TILTOPT_COUNT
};
u8 TiltOpt(u8 id);
u8 TiltOptMax(u8 id);
void TiltOptSet(u8 id, u8 value);
u8 TiltMultiballPeriod(void);
u8 TiltLevelCap(void);
bool8 TiltNzAreaUsed(void);
void TiltNzMarkArea(void);
void TiltNzReleaseFainted(void);
extern bool8 gTiltNzNoCatch;

#endif // GUARD_TILT_MECHANICS_H
