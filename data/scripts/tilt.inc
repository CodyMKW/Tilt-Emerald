@ Tilt mode scripts: post-battle combo messages and the Pinball Wizard NPC.
@ VAR_0x8004 = combo, VAR_0x8005 = payout, VAR_0x8006 = result type, VAR_0x8007 = multiball next
@ VAR_UNUSED_0x404E = combo, VAR_UNUSED_0x4083 = best combo, VAR_UNUSED_0x408B = Ball Savers

TiltEmerald_EventScript_ComboMessage::
	lockall
	buffernumberstring STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	switch VAR_0x8006
	case 0, TiltEmerald_EventScript_MsgHit
	case 1, TiltEmerald_EventScript_MsgCoins
	case 2, TiltEmerald_EventScript_MsgCandy
	case 3, TiltEmerald_EventScript_MsgSuper
	case 4, TiltEmerald_EventScript_MsgDrain
	case 5, TiltEmerald_EventScript_MsgSaved
	releaseall
	end

TiltEmerald_EventScript_MsgHit::
	msgbox TiltEmerald_Text_Hit, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgCoins::
	msgbox TiltEmerald_Text_Coins, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgCandy::
	msgbox TiltEmerald_Text_Candy, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgSuper::
	msgbox TiltEmerald_Text_Super, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgDrain::
	msgbox TiltEmerald_Text_Drain, MSGBOX_DEFAULT
	releaseall
	end

TiltEmerald_EventScript_MsgSaved::
	msgbox TiltEmerald_Text_Saved, MSGBOX_DEFAULT
	releaseall
	end

TiltEmerald_EventScript_MultiballCheck::
	goto_if_eq VAR_0x8007, 1, TiltEmerald_EventScript_Multiball
	releaseall
	end

TiltEmerald_EventScript_Multiball::
	msgbox TiltEmerald_Text_Multiball, MSGBOX_DEFAULT
	releaseall
	end

@ ---------------- Pinball Wizard NPC ----------------

TiltEmerald_EventScript_Wizard::
	lock
	faceplayer
	msgbox TiltEmerald_Text_WizardIntro, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_AskRules, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltEmerald_EventScript_Rules
TiltEmerald_EventScript_AskStats::
	msgbox TiltEmerald_Text_AskStats, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltEmerald_EventScript_Stats
TiltEmerald_EventScript_AskCandy::
	msgbox TiltEmerald_Text_AskCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltEmerald_EventScript_BuyCandy
TiltEmerald_EventScript_AskSaver::
	msgbox TiltEmerald_Text_AskSaver, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltEmerald_EventScript_BuySaver
	msgbox TiltEmerald_Text_Goodbye, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_Rules::
	msgbox TiltEmerald_Text_Rules1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules2, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules3, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules4, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules5, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Rules6, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_AskStats
	end

TiltEmerald_EventScript_Stats::
	copyvar VAR_0x8004, VAR_UNUSED_0x404E
	copyvar VAR_0x8005, VAR_UNUSED_0x4083
	copyvar VAR_0x8006, VAR_UNUSED_0x408B
	buffernumberstring STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	buffernumberstring STR_VAR_3, VAR_0x8006
	msgbox TiltEmerald_Text_Stats, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_AskCandy
	end

TiltEmerald_EventScript_BuyCandy::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 100, TiltEmerald_EventScript_NotEnoughCoins
	checkitemspace ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BagFull
	removecoins 100
	giveitem ITEM_RARE_CANDY
	msgbox TiltEmerald_Text_Thanks, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_AskSaver
	end

TiltEmerald_EventScript_BuySaver::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 200, TiltEmerald_EventScript_NotEnoughCoins
	removecoins 200
	addvar VAR_UNUSED_0x408B, 1
	msgbox TiltEmerald_Text_SaverBought, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_NotEnoughCoins::
	msgbox TiltEmerald_Text_NotEnoughCoins, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_BagFull::
	msgbox TiltEmerald_Text_BagFull, MSGBOX_DEFAULT
	release
	end

@ ---------------- Text ----------------

TiltEmerald_Text_Hit:
	.string "COMBO x{STR_VAR_1}!\n"
	.string "You earned ¥{STR_VAR_2}!$"

TiltEmerald_Text_Coins:
	.string "COMBO x{STR_VAR_1}! You earned\n"
	.string "¥{STR_VAR_2}!\p"
	.string "JACKPOT! You won 50 COINS!$"

TiltEmerald_Text_Candy:
	.string "COMBO x{STR_VAR_1}! You earned\n"
	.string "¥{STR_VAR_2}!\p"
	.string "MEGA JACKPOT! A RARE CANDY,\n"
	.string "100 COINS and a full heal!$"

TiltEmerald_Text_Super:
	.string "SUPER JACKPOT! COMBO x{STR_VAR_1}!\p"
	.string "You won a MASTER BALL, 250 COINS,\n"
	.string "¥{STR_VAR_2} and a full heal!$"

TiltEmerald_Text_Drain:
	.string "The ball drained!\n"
	.string "Your combo was lost...$"

TiltEmerald_Text_Saved:
	.string "The BALL SAVER kicked in!\n"
	.string "Your combo is safe!$"

TiltEmerald_Text_Multiball:
	.string "MULTIBALL!\p"
	.string "The next wild POKéMON will be\n"
	.string "SHINY!$"

TiltEmerald_Text_WizardIntro:
	.string "Ahaha! A fresh ball for the table!\p"
	.string "I'm the PINBALL WIZARD. This region\n"
	.string "is in TILT MODE now.$"

TiltEmerald_Text_AskRules:
	.string "Want to hear the rules?$"

TiltEmerald_Text_Rules1:
	.string "Every wild POKéMON is random now.\n"
	.string "Any species, anywhere!$"

TiltEmerald_Text_Rules2:
	.string "Win or catch a wild POKéMON to\n"
	.string "build a COMBO.\p"
	.string "Each hit pays ¥100 times your\n"
	.string "combo. Bigger combo, bigger cash!$"

TiltEmerald_Text_Rules3:
	.string "Every 5th hit is a JACKPOT:\n"
	.string "50 COINS!\p"
	.string "Every 10th is a MEGA JACKPOT:\n"
	.string "RARE CANDY, 100 COINS, full heal!\p"
	.string "Every 25th is a SUPER JACKPOT:\n"
	.string "a MASTER BALL and 250 COINS!$"

TiltEmerald_Text_Rules4:
	.string "Every 7th hit sets up a MULTIBALL.\p"
	.string "The next wild POKéMON after that\n"
	.string "is guaranteed SHINY!$"

TiltEmerald_Text_Rules5:
	.string "But watch out! Every 3 combo\n"
	.string "levels, wild POKéMON get 1 level\l"
	.string "stronger, up to 20 levels extra.$"

TiltEmerald_Text_Rules6:
	.string "Run away or lose, and the ball\n"
	.string "drains. Your combo drops to zero!\p"
	.string "A BALL SAVER blocks one drain.\n"
	.string "I sell them for 200 COINS.$"

TiltEmerald_Text_AskStats:
	.string "Want to check your table stats?$"

TiltEmerald_Text_Stats:
	.string "Current COMBO: x{STR_VAR_1}\n"
	.string "Best COMBO: x{STR_VAR_2}\p"
	.string "BALL SAVERS: {STR_VAR_3}$"

TiltEmerald_Text_AskCandy:
	.string "Trade 100 COINS for a RARE CANDY?$"

TiltEmerald_Text_AskSaver:
	.string "Buy a BALL SAVER for 200 COINS?$"

TiltEmerald_Text_Thanks:
	.string "Pleasure doing business!$"

TiltEmerald_Text_SaverBought:
	.string "One BALL SAVER, coming up!\n"
	.string "It blocks your next drain.$"

TiltEmerald_Text_NotEnoughCoins:
	.string "You don't have enough COINS.\n"
	.string "Try the GAME CORNER!$"

TiltEmerald_Text_BagFull:
	.string "Your BAG is full!$"

TiltEmerald_Text_Goodbye:
	.string "Keep that combo rolling!$"
