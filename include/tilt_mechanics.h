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
void TiltForceShinyNext(void);
bool8 TiltTakeForceShiny(void);

u8 TiltTrainerLevel(u16 trainerNum, u8 level);

#endif // GUARD_TILT_MECHANICS_H
