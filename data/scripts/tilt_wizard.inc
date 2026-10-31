@ Pinball Wizard NPC (Littleroot Town): rules, stats with rank, coin shop, free heal.
@ VAR_UNUSED_0x404E = combo, VAR_UNUSED_0x4083 = best combo, VAR_UNUSED_0x408B = Ball Savers,
@ VAR_UNUSED_0x40A1 = has met the Wizard

TiltEmerald_EventScript_Wizard::
	lock
	faceplayer
	goto_if_eq VAR_UNUSED_0x40A1, 0, TiltEmerald_EventScript_WizardFirst
	msgbox TiltEmerald_Text_WizardAgain, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_WizardFirst::
	msgbox TiltEmerald_Text_WizardIntro1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_WizardIntro2, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x40A1, 1
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_WizardMenu::
	message TiltEmerald_Text_WizardAsk
	waitmessage
	multichoice 0, 0, MULTI_TILT_MAIN, FALSE
	switch VAR_RESULT
	case 0, TiltEmerald_EventScript_Rules
	case 1, TiltEmerald_EventScript_Stats
	case 2, TiltEmerald_EventScript_Shop
	case 3, TiltEmerald_EventScript_Buffs
	case 4, TiltEmerald_EventScript_Scores
	case 5, TiltEmerald_EventScript_Daily
	case 6, TiltEmerald_EventScript_Heal
	case 7, TiltEmerald_EventScript_Train
	case 8, TiltEmerald_EventScript_Bye
	case MULTI_B_PRESSED, TiltEmerald_EventScript_Bye
	goto TiltEmerald_EventScript_Bye
	end

TiltEmerald_EventScript_Bye::
	msgbox TiltEmerald_Text_Goodbye, MSGBOX_DEFAULT
	release
	end

@ ---- Rules ----

TiltEmerald_EventScript_Rules::
	msgbox TiltEmerald_Text_Rules1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules2, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules3, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules4, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules5, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules6, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules7, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

@ ---- Stats and rank ----

TiltEmerald_EventScript_Stats::
	copyvar VAR_0x8004, VAR_UNUSED_0x404E
	copyvar VAR_0x8005, VAR_UNUSED_0x4083
	copyvar VAR_0x8006, VAR_UNUSED_0x408B
	buffernumberstring STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	buffernumberstring STR_VAR_3, VAR_0x8006
	msgbox TiltEmerald_Text_Stats, MSGBOX_DEFAULT
	goto_if_ge VAR_UNUSED_0x4083, 100, TiltEmerald_EventScript_Rank5
	goto_if_ge VAR_UNUSED_0x4083, 50, TiltEmerald_EventScript_Rank4
	goto_if_ge VAR_UNUSED_0x4083, 25, TiltEmerald_EventScript_Rank3
	goto_if_ge VAR_UNUSED_0x4083, 10, TiltEmerald_EventScript_Rank2
	bufferstring STR_VAR_1, TiltEmerald_Text_Rank1
	goto TiltEmerald_EventScript_ShowRank
	end

TiltEmerald_EventScript_Rank2::
	bufferstring STR_VAR_1, TiltEmerald_Text_Rank2
	goto TiltEmerald_EventScript_ShowRank
	end

TiltEmerald_EventScript_Rank3::
	bufferstring STR_VAR_1, TiltEmerald_Text_Rank3
	goto TiltEmerald_EventScript_ShowRank
	end

TiltEmerald_EventScript_Rank4::
	bufferstring STR_VAR_1, TiltEmerald_Text_Rank4
	goto TiltEmerald_EventScript_ShowRank
	end

TiltEmerald_EventScript_Rank5::
	bufferstring STR_VAR_1, TiltEmerald_Text_Rank5
	goto TiltEmerald_EventScript_ShowRank
	end

TiltEmerald_EventScript_ShowRank::
	msgbox TiltEmerald_Text_RankLine, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

@ ---- Free heal ----

TiltEmerald_EventScript_Heal::
	goto_if_ge VAR_UNUSED_0x40F7, 1, TiltEmerald_EventScript_HealTicketAsk
	goto TiltEmerald_EventScript_HealPay
	end

TiltEmerald_EventScript_HealTicketAsk::
	buffernumberstring STR_VAR_1, VAR_UNUSED_0x40F7
	msgbox TiltEmerald_Text_HealTicketAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_HealPay
	subvar VAR_UNUSED_0x40F7, 1
	goto TiltEmerald_EventScript_HealDo
	end

TiltEmerald_EventScript_HealPay::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 250, TiltEmerald_EventScript_HealNoCoins
	msgbox TiltEmerald_Text_HealPayAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_WizardMenu
	removecoins 250
	goto TiltEmerald_EventScript_HealDo
	end

TiltEmerald_EventScript_HealNoCoins::
	msgbox TiltEmerald_Text_HealNoCoins, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_HealDo::
	msgbox TiltEmerald_Text_HealStart, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	msgbox TiltEmerald_Text_HealDone, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

@ ---- Training: max all EVs (252) and IVs (31) of one party Pokemon for 1500 coins ----

TiltEmerald_EventScript_Train::
	msgbox TiltEmerald_Text_TrainIntro, MSGBOX_DEFAULT
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 1500, TiltEmerald_EventScript_TrainNoCoins
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, TiltEmerald_EventScript_WizardMenu
	specialvar VAR_RESULT, TiltSpecialMonIsMaxed
	goto_if_eq VAR_RESULT, TRUE, TiltEmerald_EventScript_TrainAlready
	msgbox TiltEmerald_Text_TrainAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_WizardMenu
	removecoins 1500
	msgbox TiltEmerald_Text_TrainStart, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special TiltSpecialMaxMon
	playfanfare MUS_LEVEL_UP
	waitfanfare
	fadescreen FADE_FROM_BLACK
	msgbox TiltEmerald_Text_TrainDone, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_TrainNoCoins::
	msgbox TiltEmerald_Text_TrainNoCoins, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_TrainAlready::
	msgbox TiltEmerald_Text_TrainAlready, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

@ ---- Coin shop ----

TiltEmerald_EventScript_Shop::
	message TiltEmerald_Text_ShopAsk
	waitmessage
	multichoice 0, 0, MULTI_TILT_SHOP, FALSE
	switch VAR_RESULT
	case 0, TiltEmerald_EventScript_BuyCandy
	case 1, TiltEmerald_EventScript_BuySaver
	case 2, TiltEmerald_EventScript_BuyTicket
	case 3, TiltEmerald_EventScript_BuyPPMax
	case 4, TiltEmerald_EventScript_BuyLuckyEgg
	case 5, TiltEmerald_EventScript_BuyMasterBall
	case 6, TiltEmerald_EventScript_WizardMenu
	case MULTI_B_PRESSED, TiltEmerald_EventScript_WizardMenu
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_BuyCandy::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 100, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 100
	giveitem ITEM_RARE_CANDY
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuySaver::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 200, TiltEmerald_EventScript_NotEnoughCoins
	goto_if_ge VAR_UNUSED_0x408B, 9, TiltEmerald_EventScript_TooManySavers
	removecoins 200
	addvar VAR_UNUSED_0x408B, 1
	msgbox TiltEmerald_Text_SaverBought, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuyPPMax::
	goto_if_lt VAR_UNUSED_0x4083, 10, TiltEmerald_EventScript_Locked10
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 350, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_PP_MAX
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 350
	giveitem ITEM_PP_MAX
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuyLuckyEgg::
	goto_if_lt VAR_UNUSED_0x4083, 25, TiltEmerald_EventScript_Locked25
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 500, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_LUCKY_EGG
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 500
	giveitem ITEM_LUCKY_EGG
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuyMasterBall::
	goto_if_lt VAR_UNUSED_0x4083, 50, TiltEmerald_EventScript_Locked50
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 2000, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 2000
	giveitem ITEM_MASTER_BALL
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuyTicket::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 400, TiltEmerald_EventScript_NotEnoughCoins
	goto_if_ge VAR_UNUSED_0x40F7, 9, TiltEmerald_EventScript_TooManyTickets
	removecoins 400
	addvar VAR_UNUSED_0x40F7, 1
	msgbox TiltEmerald_Text_TicketBought, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_TooManyTickets::
	msgbox TiltEmerald_Text_TooManyTickets, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_Locked10::
	msgbox TiltEmerald_Text_Locked10, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_Locked25::
	msgbox TiltEmerald_Text_Locked25, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_Locked50::
	msgbox TiltEmerald_Text_Locked50, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

@ ---- Buffs (500 steps) ----

TiltEmerald_EventScript_Buffs::
	message TiltEmerald_Text_BuffAsk
	waitmessage
	multichoice 0, 0, MULTI_TILT_BUFF, FALSE
	switch VAR_RESULT
	case 0, TiltEmerald_EventScript_BuyBuffExp
	case 1, TiltEmerald_EventScript_BuyBuffCatch
	case 2, TiltEmerald_EventScript_WizardMenu
	case MULTI_B_PRESSED, TiltEmerald_EventScript_WizardMenu
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_BuyBuffExp::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 100, TiltEmerald_EventScript_BuffNoCoins
	removecoins 100
	setvar VAR_UNUSED_0x40BB, 1
	setvar VAR_UNUSED_0x409D, 500
	msgbox TiltEmerald_Text_BuffExpOn, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_BuyBuffCatch::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 100, TiltEmerald_EventScript_BuffNoCoins
	removecoins 100
	setvar VAR_UNUSED_0x40BB, 2
	setvar VAR_UNUSED_0x409D, 500
	msgbox TiltEmerald_Text_BuffCatchOn, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_BuffNoCoins::
	msgbox TiltEmerald_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Buffs
	end

@ ---- Score board: best combo, prizes at 10/25/50/100, nightly jackpot route ----

TiltEmerald_EventScript_Scores::
	copyvar VAR_0x8005, VAR_UNUSED_0x4083
	buffernumberstring STR_VAR_1, VAR_0x8005
	msgbox TiltEmerald_Text_ScoreBest, MSGBOX_DEFAULT
	setvar VAR_0x8007, 0
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, TiltSpecialClaimPrize
	call_if_eq VAR_RESULT, 1, TiltEmerald_EventScript_PrizeGot
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, TiltSpecialClaimPrize
	call_if_eq VAR_RESULT, 1, TiltEmerald_EventScript_PrizeGot
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, TiltSpecialClaimPrize
	call_if_eq VAR_RESULT, 1, TiltEmerald_EventScript_PrizeGot
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, TiltSpecialClaimPrize
	call_if_eq VAR_RESULT, 1, TiltEmerald_EventScript_PrizeGot
	special TiltSpecialLuckyRoute
	msgbox TiltEmerald_Text_ScoreLucky, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_PrizeGot::
	playfanfare MUS_OBTAIN_ITEM
	msgbox TiltEmerald_Text_PrizeGot, MSGBOX_DEFAULT
	waitfanfare
	return

@ ---- Daily challenge ----

TiltEmerald_EventScript_Daily::
	specialvar VAR_RESULT, TiltSpecialDailyStatus
	buffernumberstring STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	goto_if_eq VAR_RESULT, 2, TiltEmerald_EventScript_DailyDone
	goto_if_eq VAR_RESULT, 1, TiltEmerald_EventScript_DailyClaim
	msgbox TiltEmerald_Text_DailyProgress, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_DailyDone::
	msgbox TiltEmerald_Text_DailyDone, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_DailyClaim::
	special TiltSpecialClaimDaily
	playfanfare MUS_OBTAIN_ITEM
	msgbox TiltEmerald_Text_DailyClaim, MSGBOX_DEFAULT
	waitfanfare
	goto TiltEmerald_EventScript_WizardMenu
	end

TiltEmerald_EventScript_NotEnoughCoins::
	msgbox TiltEmerald_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BagFull::
	msgbox TiltEmerald_Text_BagFull, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_TooManySavers::
	msgbox TiltEmerald_Text_TooManySavers, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_Shop
	end

@ ---------------- Text ----------------

TiltEmerald_Text_WizardIntro1:
	.string "Ahaha! A fresh ball for the table!\p"
	.string "I'm the PINBALL WIZARD. This\n"
	.string "region is in TILT MODE now.$"

TiltEmerald_Text_WizardIntro2:
	.string "If you're heading to OLDALE TOWN,\n"
	.string "say hi to my apprentice NOVA.\p"
	.string "Something strange is going on\n"
	.string "out there...$"

TiltEmerald_Text_WizardAgain:
	.string "Welcome back to the table!$"

TiltEmerald_Text_WizardAsk:
	.string "What'll it be?$"

TiltEmerald_Text_Rules1:
	.string "Wild POKéMON are the usual ones,\n"
	.string "but a long COMBO bounces the\l"
	.string "rare ones out of hiding!\p"
	.string "And about 1 in 32 is a shiny!$"

TiltEmerald_Text_Rules2:
	.string "Win or catch a wild POKéMON to\n"
	.string "build a COMBO.\p"
	.string "Each hit pays ¥100 times your\n"
	.string "combo. Bigger combo, more cash!$"

TiltEmerald_Text_Rules3:
	.string "Every 5th hit is a JACKPOT:\n"
	.string "50 COINS!\p"
	.string "Every 10th is a MEGA JACKPOT:\n"
	.string "RARE CANDY, 100 COINS, full heal!\p"
	.string "Every 25th is a SUPER JACKPOT:\n"
	.string "MASTER BALL and 250 COINS!$"

TiltEmerald_Text_Rules4:
	.string "After every 7th hit, MULTIBALL!\p"
	.string "The next wild POKéMON is a\n"
	.string "guaranteed SHINY.$"

TiltEmerald_Text_Rules5:
	.string "But watch out! Every 3 combo\n"
	.string "levels, wild POKéMON get 1 level\l"
	.string "stronger, up to 20 levels extra.$"

TiltEmerald_Text_Rules6:
	.string "Run away or lose, and the ball\n"
	.string "drains. Your combo drops to zero!\p"
	.string "A BALL SAVER blocks one drain\n"
	.string "when you run. Whiting out still\l"
	.string "resets your combo.$"

TiltEmerald_Text_Rules7:
	.string "You can buy BALL SAVERS and more\n"
	.string "in my COIN SHOP.\p"
	.string "A team tune-up costs 250 COINS.\n"
	.string "The POKéMON CENTERS are broke!\p"
	.string "But lucky combos can drop a\n"
	.string "HEAL TICKET. That heals for free!$"

TiltEmerald_Text_Stats:
	.string "Current COMBO: x{STR_VAR_1}\n"
	.string "Best COMBO: x{STR_VAR_2}\p"
	.string "BALL SAVERS: {STR_VAR_3}$"

TiltEmerald_Text_RankLine:
	.string "Your rank is {STR_VAR_1}!$"

TiltEmerald_Text_Rank1:
	.string "BALL ROOKIE$"

TiltEmerald_Text_Rank2:
	.string "FLIPPER$"

TiltEmerald_Text_Rank3:
	.string "BUMPER BOSS$"

TiltEmerald_Text_Rank4:
	.string "TABLE WIZARD$"

TiltEmerald_Text_Rank5:
	.string "TILT LORD$"

TiltEmerald_Text_HealStart:
	.string "Hold still! Time for a flipper\n"
	.string "tune-up!$"

TiltEmerald_Text_HealTicketAsk:
	.string "You have {STR_VAR_1} HEAL TICKET(S)!\n"
	.string "Use one for a free tune-up?$"

TiltEmerald_Text_HealPayAsk:
	.string "A tune-up costs 250 COINS.\n"
	.string "Want one?$"

TiltEmerald_Text_HealNoCoins:
	.string "No COINS, no tune-up!\p"
	.string "Win some at the GAME CORNER, or\n"
	.string "get lucky and find a HEAL TICKET.$"

TiltEmerald_Text_HealDone:
	.string "All fixed up! Your POKéMON are in\n"
	.string "perfect shape.$"

TiltEmerald_Text_TicketBought:
	.string "A HEAL TICKET! Hand it in for a\n"
	.string "free heal.$"

TiltEmerald_Text_TooManyTickets:
	.string "You're holding the max of 9\n"
	.string "HEAL TICKETS.$"

TiltEmerald_Text_Locked10:
	.string "Reach a COMBO of 10 once to\n"
	.string "unlock that.$"

TiltEmerald_Text_Locked25:
	.string "Reach a COMBO of 25 once to\n"
	.string "unlock that.$"

TiltEmerald_Text_Locked50:
	.string "Reach a COMBO of 50 once to\n"
	.string "unlock that.$"

TiltEmerald_Text_BuffAsk:
	.string "A buff lasts 500 steps.$"

TiltEmerald_Text_BuffExpOn:
	.string "Double EXP for the next 500 steps!$"

TiltEmerald_Text_BuffCatchOn:
	.string "Catch rates are boosted for the\n"
	.string "next 500 steps!$"

TiltEmerald_Text_ScoreBest:
	.string "Your best COMBO is {STR_VAR_1}.\p"
	.string "Prizes wait at 10, 25, 50 and\n"
	.string "100!$"

TiltEmerald_Text_PrizeGot:
	.string "You hit a high score milestone!\n"
	.string "Here's your prize!$"

TiltEmerald_Text_ScoreLucky:
	.string "Tonight's JACKPOT ROUTE is\n"
	.string "ROUTE {STR_VAR_1}. It pays triple!$"

TiltEmerald_Text_DailyProgress:
	.string "Today's challenge: reach a COMBO\n"
	.string "of {STR_VAR_1}.\p"
	.string "Your best today: {STR_VAR_2}.$"

TiltEmerald_Text_DailyDone:
	.string "You already cashed in today's\n"
	.string "challenge. Come back tomorrow!$"

TiltEmerald_Text_DailyClaim:
	.string "Challenge complete!\p"
	.string "Here are 200 COINS, 2 RARE CANDIES\n"
	.string "and a HEAL TICKET!$"

TiltEmerald_Text_ShopAsk:
	.string "Spend COINS on what?$"

TiltEmerald_Text_SaverBought:
	.string "One BALL SAVER, coming up!\n"
	.string "It blocks your next drain.$"

TiltEmerald_Text_TooManySavers:
	.string "You already have 9 BALL SAVERS.\n"
	.string "That's the most I can allow!$"

TiltEmerald_Text_NotEnoughCoins:
	.string "You don't have enough COINS.\n"
	.string "Try the GAME CORNER!$"

TiltEmerald_Text_BagFull:
	.string "Your BAG is full!$"

TiltEmerald_Text_Goodbye:
	.string "Keep that combo rolling!$"


@ ---- Intro scene: first time you leave your house after setting the clock ----
@ VAR_UNUSED_0x40F8: 0 = never queued (old saves), 2 = queued (set when Mom sends you next door), 1 = seen.

TiltWizIntro_EventScript_Run::
	lockall
	setvar VAR_UNUSED_0x40F8, 1
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, TiltWizIntro_EventScript_RunMale
	clearflag FLAG_UNUSED_0x03A
	addobject LOCALID_TILT_WIZARD_INTRO
	delay 20
	applymovement LOCALID_PLAYER, TiltWizIntro_Movement_PlayerFaceDown
	waitmovement 0
	applymovement LOCALID_TILT_WIZARD_INTRO, TiltWizIntro_Movement_ComeFemale
	waitmovement 0
	goto TiltWizIntro_EventScript_Talk
	end

@ The male house is close to the west edge, so the Wizard would be seen popping in:
@ hide that behind a fade and start him just a couple of tiles from the player.
TiltWizIntro_EventScript_RunMale::
	applymovement LOCALID_PLAYER, TiltWizIntro_Movement_PlayerFaceDown
	waitmovement 0
	fadescreen FADE_TO_BLACK
	clearflag FLAG_UNUSED_0x03A
	addobject LOCALID_TILT_WIZARD_INTRO
	setobjectxy LOCALID_TILT_WIZARD_INTRO, 3, 10
	delay 15
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_TILT_WIZARD_INTRO, TiltWizIntro_Movement_ComeMale
	waitmovement 0
	goto TiltWizIntro_EventScript_Talk
	end

TiltWizIntro_EventScript_Talk::
	playse SE_PIN
	applymovement LOCALID_TILT_WIZARD_INTRO, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox TiltWizIntro_Text_1, MSGBOX_DEFAULT
	msgbox TiltWizIntro_Text_2, MSGBOX_DEFAULT
	msgbox TiltWizIntro_Text_3, MSGBOX_DEFAULT
	msgbox TiltWizIntro_Text_4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_UNUSED_0x40A1, 1
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, TiltWizIntro_EventScript_LeaveMale
	applymovement LOCALID_TILT_WIZARD_INTRO, TiltWizIntro_Movement_LeaveFemale
	waitmovement 0
	goto TiltWizIntro_EventScript_Gone
	end

TiltWizIntro_EventScript_LeaveMale::
	applymovement LOCALID_TILT_WIZARD_INTRO, TiltWizIntro_Movement_LeaveMale
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TILT_WIZARD_INTRO
	setflag FLAG_UNUSED_0x03A
	fadescreen FADE_FROM_BLACK
	releaseall
	end

TiltWizIntro_EventScript_Gone::
	removeobject LOCALID_TILT_WIZARD_INTRO
	setflag FLAG_UNUSED_0x03A
	releaseall
	end

TiltWizIntro_Movement_PlayerFaceDown:
	face_down
	step_end

TiltWizIntro_Movement_ComeMale:
	walk_fast_right
	walk_fast_right
	face_up
	step_end

TiltWizIntro_Movement_ComeFemale:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

TiltWizIntro_Movement_LeaveMale:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

TiltWizIntro_Movement_LeaveFemale:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

TiltWizIntro_Text_1:
	.string "Ahaha! Hold it right there, kid!\p"
	.string "I felt a fresh ball drop into\n"
	.string "this town. I'm the PINBALL WIZARD!$"

TiltWizIntro_Text_2:
	.string "This whole region is in TILT MODE.\p"
	.string "Wild POKéMON are the usual ones,\n"
	.string "but a long COMBO bounces the\l"
	.string "rare ones out of hiding!$"

TiltWizIntro_Text_3:
	.string "Win or catch one to start a COMBO.\n"
	.string "The longer it runs, the bigger\l"
	.string "the payout!\p"
	.string "Just don't let the ball drain!$"

TiltWizIntro_Text_4:
	.string "I'm setting up shop upstairs in\n"
	.string "the POKéMON CENTER, west of here.\p"
	.string "Rules, a COIN SHOP and tune-ups.\n"
	.string "Come play, {PLAYER}!$"

TiltEmerald_Text_TrainIntro:
	.string "My TRAINING service!\p"
	.string "For 1500 COINS I'll max out every EV\n"
	.string "and IV on one of your POKéMON.$"

TiltEmerald_Text_TrainNoCoins:
	.string "You need 1500 COINS for that.$"

TiltEmerald_Text_TrainAsk:
	.string "Max out {STR_VAR_1} for 1500 COINS?$"

TiltEmerald_Text_TrainStart:
	.string "Hold tight... this won't take long!$"

TiltEmerald_Text_TrainDone:
	.string "{STR_VAR_1} is now in peak condition!\n"
	.string "All EVs and IVs are maxed out!$"

TiltEmerald_Text_TrainAlready:
	.string "{STR_VAR_1} is already maxed out!\n"
	.string "No charge for that one.$"
