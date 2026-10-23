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
	case 3, TiltEmerald_EventScript_Heal
	case 4, TiltEmerald_EventScript_Bye
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
	goto_if_lt VAR_RESULT, 50, TiltEmerald_EventScript_HealNoCoins
	msgbox TiltEmerald_Text_HealPayAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_WizardMenu
	removecoins 50
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

@ ---- Coin shop ----

TiltEmerald_EventScript_Shop::
	message TiltEmerald_Text_ShopAsk
	waitmessage
	multichoice 0, 0, MULTI_TILT_SHOP, FALSE
	switch VAR_RESULT
	case 0, TiltEmerald_EventScript_BuyCandy
	case 1, TiltEmerald_EventScript_BuySaver
	case 2, TiltEmerald_EventScript_BuyPPMax
	case 3, TiltEmerald_EventScript_BuyLuckyEgg
	case 4, TiltEmerald_EventScript_BuyMasterBall
	case 5, TiltEmerald_EventScript_WizardMenu
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
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 350, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_PP_MAX
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 350
	giveitem ITEM_PP_MAX
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuyLuckyEgg::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 500, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_LUCKY_EGG
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 500
	giveitem ITEM_LUCKY_EGG
	goto TiltEmerald_EventScript_Shop
	end

TiltEmerald_EventScript_BuyMasterBall::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 2000, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 2000
	giveitem ITEM_MASTER_BALL
	goto TiltEmerald_EventScript_Shop
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
	.string "Every wild POKéMON is random now.\n"
	.string "Any species, anywhere!\p"
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
	.string "A team tune-up costs 50 COINS.\n"
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
	.string "A tune-up costs 50 COINS.\n"
	.string "Want one?$"

TiltEmerald_Text_HealNoCoins:
	.string "No COINS, no tune-up!\p"
	.string "Win some at the GAME CORNER, or\n"
	.string "get lucky and find a HEAL TICKET.$"

TiltEmerald_Text_HealDone:
	.string "All fixed up! Your POKéMON are in\n"
	.string "perfect shape.$"

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
