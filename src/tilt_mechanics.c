#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "coins.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "item.h"
#include "money.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "script.h"
#include "string_util.h"
#include "tilt_mechanics.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/opponents.h"
#include "constants/tilt.h"
#include "constants/weather.h"

extern const struct Tileset gTileset_General;
extern const u8 TiltEmerald_EventScript_FlowerBumper[];
extern const u8 TiltEmerald_EventScript_Decay[];
extern const u8 TiltEmerald_EventScript_BuffEnded[];

EWRAM_DATA u8 gTiltFlipMsg = 0;
EWRAM_DATA bool8 gTiltMultiballActive = FALSE;

// Non-saved bookkeeping
static u8 sBumperCooldown;
static u8 sBumpsSinceHit;
static u8 sHits;
static u8 sSuperEffective;
static bool8 sSaverUsed;
static bool8 sFlipUsed;
static bool8 sForceShiny;

#define METATILE_GENERAL_FLOWERS 0x004
#define DECAY_STEPS              300
#define BUMPER_COOLDOWN_STEPS    40
#define BUMPS_PER_HIT            3

// --------------------------------------------------------------------------------------------
// Combo helpers
// --------------------------------------------------------------------------------------------

void TiltResetCombo(void)
{
    VarSet(VAR_TILT_COMBO, 0);
    VarSet(VAR_TILT_STEPS, 0);
    FlagClear(FLAG_TILT_RARE_USED);
    sBumpsSinceHit = 0;
}

void TiltDailyRoll(void)
{
    u16 day = (u16)RtcGetLocalDayCount();

    if (VarGet(VAR_TILT_DAYSTAMP) != day)
    {
        VarSet(VAR_TILT_DAYSTAMP, day);
        VarSet(VAR_TILT_DAILYMAX, 0);
    }
}

// Called whenever the combo has just gone up (battle win, bumper)
void TiltOnComboHit(u16 prev, u16 combo)
{
    TiltDailyRoll();
    if (combo > VarGet(VAR_TILT_DAILYMAX))
        VarSet(VAR_TILT_DAILYMAX, combo);
    if (combo > VarGet(VAR_TILT_BEST))
        VarSet(VAR_TILT_BEST, combo);
    VarSet(VAR_TILT_STEPS, 0);
    sBumpsSinceHit = 0;
    if ((prev < 10 && combo >= 10) || (prev < 20 && combo >= 20) || (prev < 30 && combo >= 30))
        FlagSet(FLAG_TILT_BERRY);
}

void TiltAddCombo(u16 amount)
{
    u16 prev = VarGet(VAR_TILT_COMBO);
    u16 combo = prev;

    if (combo + amount > 9999)
        combo = 9999;
    else
        combo += amount;
    VarSet(VAR_TILT_COMBO, combo);
    TiltOnComboHit(prev, combo);
}

void TiltForceShinyNext(void)
{
    sForceShiny = TRUE;
}

bool8 TiltTakeForceShiny(void)
{
    bool8 result = sForceShiny;

    sForceShiny = FALSE;
    return result;
}

// --------------------------------------------------------------------------------------------
// Catch rate / EXP buffs
// --------------------------------------------------------------------------------------------

// Percent added to the catch odds: +2.5% per combo (max +50%, about a Great Ball at 20), plus the Wizard's buff
u16 TiltCatchBonus(void)
{
    u16 bonus = VarGet(VAR_TILT_COMBO) * 5 / 2;

    if (bonus > 50)
        bonus = 50;
    if (VarGet(VAR_TILT_BUFF) > 0 && VarGet(VAR_TILT_BUFFTYPE) == 2)
        bonus += 50;
    return bonus;
}

u16 TiltExpPercent(void)
{
    if (VarGet(VAR_TILT_BUFF) > 0 && VarGet(VAR_TILT_BUFFTYPE) == 1)
        return 200;
    return 100;
}

// --------------------------------------------------------------------------------------------
// Steps: buff timer, combo decay, flower bumpers
// --------------------------------------------------------------------------------------------

static bool8 IsOnFlowerTile(void)
{
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    if (gMapHeader.mapLayout->primaryTileset != &gTileset_General)
        return FALSE;
    return MapGridGetMetatileIdAt(x, y) == METATILE_GENERAL_FLOWERS;
}

bool8 TiltStepUpdate(void)
{
    u16 combo = VarGet(VAR_TILT_COMBO);
    u16 steps;

    if (VarGet(VAR_TILT_BUFF) > 0)
    {
        VarSet(VAR_TILT_BUFF, VarGet(VAR_TILT_BUFF) - 1);
        if (VarGet(VAR_TILT_BUFF) == 0)
        {
            VarSet(VAR_TILT_BUFFTYPE, 0);
            ScriptContext_SetupScript(TiltEmerald_EventScript_BuffEnded);
            return TRUE;
        }
    }

    if (sBumperCooldown != 0)
        sBumperCooldown--;

    if (combo == 0)
        return FALSE;

    // BUMPER: flowers bounce you and add to the combo (cooldown + cap so it can't be farmed)
    if (sBumperCooldown == 0 && sBumpsSinceHit < BUMPS_PER_HIT && IsOnFlowerTile())
    {
        u8 bumps = sBumpsSinceHit + 1;

        sBumperCooldown = BUMPER_COOLDOWN_STEPS;
        TiltAddCombo(1);
        sBumpsSinceHit = bumps; // TiltOnComboHit cleared it
        ScriptContext_SetupScript(TiltEmerald_EventScript_FlowerBumper);
        return TRUE;
    }

    // DECAY: the ball slows down if you wander without a fight
    steps = VarGet(VAR_TILT_STEPS) + 1;
    if (steps >= DECAY_STEPS)
    {
        VarSet(VAR_TILT_STEPS, 0);
        VarSet(VAR_TILT_COMBO, combo - 1);
        if (combo - 1 == 0)
            TiltResetCombo();
        ScriptContext_SetupScript(TiltEmerald_EventScript_Decay);
        return TRUE;
    }
    VarSet(VAR_TILT_STEPS, steps);
    return FALSE;
}

// --------------------------------------------------------------------------------------------
// Battle hooks
// --------------------------------------------------------------------------------------------

void TiltBattleStart(void)
{
    sHits = 0;
    sSuperEffective = 0;
    sSaverUsed = FALSE;
    sFlipUsed = FALSE;
    gTiltFlipMsg = 0;
}

// Ball Saver Revive: a fainting player mon bounces back with half HP once per battle
bool8 TiltTryBallSaverRevive(u8 battler)
{
    if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        return FALSE;
    if (sSaverUsed || VarGet(VAR_TILT_SAVER) == 0)
        return FALSE;
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED | BATTLE_TYPE_FRONTIER))
        return FALSE;

    sSaverUsed = TRUE;
    VarSet(VAR_TILT_SAVER, VarGet(VAR_TILT_SAVER) - 1);
    gBattleMoveDamage = -(s32)(gBattleMons[battler].maxHP / 2);
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = -1;
    gBattleScripting.battler = battler;
    return TRUE;
}

// Slingshot: every 5th damaging hit from the player is a guaranteed critical hit
bool8 TiltSlingshotCrit(void)
{
    if (GetBattlerSide(gBattlerAttacker) != B_SIDE_PLAYER || gBattleMoves[gCurrentMove].power == 0)
        return FALSE;
    sHits++;
    if (sHits >= 5)
    {
        sHits = 0;
        return TRUE;
    }
    return FALSE;
}

void TiltOnSuperEffective(void)
{
    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER && sSuperEffective < 3)
        sSuperEffective++;
}

// Bank Shot: super effective hits (max 3) add to the combo; +1 if the lead is at full HP
u8 TiltTakeBankBonus(void)
{
    u8 bonus = sSuperEffective;

    sSuperEffective = 0;
    if (bonus != 0 && GetMonData(&gPlayerParty[0], MON_DATA_HP) == GetMonData(&gPlayerParty[0], MON_DATA_MAX_HP))
        bonus++;
    return bonus;
}

// Flipper: the first voluntary switch of a battle (with a combo of 3+) is free; the foe loses its turn
bool8 TiltTryFlip(void)
{
    if (sFlipUsed || VarGet(VAR_TILT_COMBO) < 3)
        return FALSE;
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED | BATTLE_TYPE_FRONTIER))
        return FALSE;
    sFlipUsed = TRUE;
    gTiltFlipMsg = 1;
    return TRUE;
}

// --------------------------------------------------------------------------------------------
// Tilt Storm and the nightly jackpot route
// --------------------------------------------------------------------------------------------

void TiltRollStorm(void)
{
    u8 weather = gSaveBlock1Ptr->weather;

    if (gMapHeader.mapType == MAP_TYPE_ROUTE && (weather == WEATHER_SUNNY || weather == WEATHER_SUNNY_CLOUDS || weather == WEATHER_NONE)
     && Random() % 12 == 0)
    {
        FlagSet(FLAG_TILT_STORM);
        SetSavedWeather(WEATHER_RAIN_THUNDERSTORM);
    }
    else if (gMapHeader.mapType == MAP_TYPE_ROUTE && FlagGet(FLAG_TILT_STORM)
          && (weather == WEATHER_RAIN_THUNDERSTORM))
    {
        // still the same storm after a short hop between routes: keep it
    }
    else
    {
        FlagClear(FLAG_TILT_STORM);
    }
}

bool8 TiltIsStorm(void)
{
    return FlagGet(FLAG_TILT_STORM);
}

static const u16 sLuckyRoutes[] =
{
    MAP_ROUTE101, MAP_ROUTE102, MAP_ROUTE103, MAP_ROUTE104, MAP_ROUTE105, MAP_ROUTE106,
    MAP_ROUTE107, MAP_ROUTE108, MAP_ROUTE109, MAP_ROUTE110, MAP_ROUTE111, MAP_ROUTE112,
    MAP_ROUTE113, MAP_ROUTE114, MAP_ROUTE115, MAP_ROUTE116, MAP_ROUTE117, MAP_ROUTE118,
    MAP_ROUTE119, MAP_ROUTE120, MAP_ROUTE121, MAP_ROUTE122, MAP_ROUTE123, MAP_ROUTE124,
    MAP_ROUTE125, MAP_ROUTE126, MAP_ROUTE127, MAP_ROUTE128, MAP_ROUTE129, MAP_ROUTE130,
    MAP_ROUTE131, MAP_ROUTE132, MAP_ROUTE133, MAP_ROUTE134,
};

static u8 GetLuckyRouteIndex(void)
{
    u32 day = RtcGetLocalDayCount();

    return (day * 13 + 5) % ARRAY_COUNT(sLuckyRoutes);
}

bool8 TiltOnLuckyRoute(void)
{
    u16 map = sLuckyRoutes[GetLuckyRouteIndex()];

    return gSaveBlock1Ptr->location.mapGroup == (map >> 8) && gSaveBlock1Ptr->location.mapNum == (map & 0xFF);
}

// --------------------------------------------------------------------------------------------
// Specials used by the Wizard / scripts
// --------------------------------------------------------------------------------------------

void TiltSpecialLuckyRoute(void)
{
    ConvertIntToDecimalStringN(gStringVar1, 101 + GetLuckyRouteIndex(), STR_CONV_MODE_LEADING_ZEROS, 3);
}

static const u8 sDailyTargets[] = { 5, 8, 12, 15 };

static u8 GetDailyTarget(void)
{
    return sDailyTargets[RtcGetLocalDayCount() % ARRAY_COUNT(sDailyTargets)];
}

// VAR_RESULT: 0 = in progress, 1 = ready to claim, 2 = already claimed today
// gSpecialVar_0x8004 = target combo, gSpecialVar_0x8005 = best combo today
void TiltSpecialDailyStatus(void)
{
    u16 day = (u16)RtcGetLocalDayCount();

    TiltDailyRoll();
    gSpecialVar_0x8004 = GetDailyTarget();
    gSpecialVar_0x8005 = VarGet(VAR_TILT_DAILYMAX);
    if (VarGet(VAR_TILT_DAILYCLAIM) == day && day != 0)
        gSpecialVar_Result = 2;
    else if (VarGet(VAR_TILT_DAILYMAX) >= GetDailyTarget())
        gSpecialVar_Result = 1;
    else
        gSpecialVar_Result = 0;
}

void TiltSpecialClaimDaily(void)
{
    VarSet(VAR_TILT_DAILYCLAIM, (u16)RtcGetLocalDayCount());
    AddCoins(200);
    AddBagItem(ITEM_RARE_CANDY, 2);
    if (VarGet(VAR_TILT_TICKET) < 9)
        VarSet(VAR_TILT_TICKET, VarGet(VAR_TILT_TICKET) + 1);
}

// High score prizes. gSpecialVar_0x8004 = prize index (0..3 for 10/25/50/100 combo).
// VAR_RESULT: 0 = not reached yet, 1 = claimed just now, 2 = already claimed
static const u8 sPrizeCombos[] = { 10, 25, 50, 100 };

void TiltSpecialClaimPrize(void)
{
    u8 i = gSpecialVar_0x8004;

    if (i >= ARRAY_COUNT(sPrizeCombos) || VarGet(VAR_TILT_BEST) < sPrizeCombos[i])
    {
        gSpecialVar_Result = 0;
        return;
    }
    if (VarGet(VAR_TILT_PRIZES) & (1 << i))
    {
        gSpecialVar_Result = 2;
        return;
    }
    VarSet(VAR_TILT_PRIZES, VarGet(VAR_TILT_PRIZES) | (1 << i));
    switch (i)
    {
    case 0:
        AddBagItem(ITEM_RARE_CANDY, 3);
        AddCoins(100);
        break;
    case 1:
        AddBagItem(ITEM_PP_MAX, 3);
        AddCoins(250);
        break;
    case 2:
        AddBagItem(ITEM_MASTER_BALL, 2);
        AddBagItem(ITEM_RARE_CANDY, 5);
        break;
    case 3:
        AddBagItem(ITEM_MASTER_BALL, 3);
        AddBagItem(ITEM_RARE_CANDY, 10);
        AddCoins(1000);
        break;
    }
    gSpecialVar_Result = 1;
}

// Jackpot Berries: gives a rare berry if the flag is set. VAR_RESULT = berry item id (0 = none)
void TiltSpecialBerryJackpot(void)
{
    static const u16 sRareBerries[] = { ITEM_LIECHI_BERRY, ITEM_GANLON_BERRY, ITEM_SALAC_BERRY, ITEM_PETAYA_BERRY, ITEM_APICOT_BERRY, ITEM_LANSAT_BERRY, ITEM_STARF_BERRY };

    if (!FlagGet(FLAG_TILT_BERRY))
    {
        gSpecialVar_Result = 0;
        return;
    }
    FlagClear(FLAG_TILT_BERRY);
    gSpecialVar_Result = sRareBerries[Random() % ARRAY_COUNT(sRareBerries)];
    AddBagItem(gSpecialVar_Result, 2);
}

// Dream Island rematches: each rematch tier adds 3 levels to the three leaders' teams
u8 TiltTrainerLevel(u16 trainerNum, u8 level)
{
    u16 bonus;

    if (trainerNum != TRAINER_TILT_BEAN && trainerNum != TRAINER_TILT_CHADDERZ && trainerNum != TRAINER_TILT_VANTOX)
        return level;
    bonus = VarGet(VAR_TILT_REMATCH) * 3;
    if (level + bonus > 100)
        return 100;
    return level + bonus;
}
