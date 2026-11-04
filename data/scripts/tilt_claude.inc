@ v31.2 "Claude update": LUCKY DICE key item, the CLAUDE cameo NPC in Slateport, the Lavaridge hot spring.
@ NPC gift/battle scripts for this update are generated into tilt_claude_npcs.inc (flags 0x4B0-0x4BC).

@ ---- LUCKY DICE (key item, 100 COINS a roll) ----

TiltClaude_EventScript_DiceUse::
	msgbox TiltClaude_Text_DiceAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltClaude_EventScript_DiceEnd
TiltClaude_EventScript_DiceRoll::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 100, TiltClaude_EventScript_DiceNoCoins
	removecoins 100
	playse SE_PIN
	msgbox TiltClaude_Text_DiceRolling, MSGBOX_DEFAULT
	random 12
	switch VAR_RESULT
	case 0, TiltClaude_EventScript_DiceMiss
	case 1, TiltClaude_EventScript_DiceMiss
	case 2, TiltClaude_EventScript_DiceMiss
	case 3, TiltClaude_EventScript_DiceMiss
	case 4, TiltClaude_EventScript_DiceBack
	case 5, TiltClaude_EventScript_DiceBack
	case 6, TiltClaude_EventScript_DiceBack
	case 7, TiltClaude_EventScript_DiceBerry
	case 8, TiltClaude_EventScript_DiceBall
	case 9, TiltClaude_EventScript_DicePPUp
	case 10, TiltClaude_EventScript_DiceCandy
	case 11, TiltClaude_EventScript_DiceJackpot
	goto TiltClaude_EventScript_DiceMiss
	end

TiltClaude_EventScript_DiceMiss::
	playse SE_FAILURE
	msgbox TiltClaude_Text_DiceMiss, MSGBOX_DEFAULT
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DiceBack::
	playse SE_SUCCESS
	addcoins 100
	msgbox TiltClaude_Text_DiceBack, MSGBOX_DEFAULT
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DiceBerry::
	playse SE_SUCCESS
	msgbox TiltClaude_Text_DicePrize, MSGBOX_DEFAULT
	giveitem ITEM_SITRUS_BERRY, 2
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DiceBall::
	playse SE_SUCCESS
	msgbox TiltClaude_Text_DicePrize, MSGBOX_DEFAULT
	giveitem ITEM_ULTRA_BALL, 3
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DicePPUp::
	playse SE_SUCCESS
	msgbox TiltClaude_Text_DicePrize, MSGBOX_DEFAULT
	giveitem ITEM_PP_UP, 1
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DiceCandy::
	playse SE_SUCCESS
	msgbox TiltClaude_Text_DicePrize, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 2
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DiceJackpot::
	playfanfare MUS_OBTAIN_ITEM
	msgbox TiltClaude_Text_DiceJackpot, MSGBOX_DEFAULT
	waitfanfare
	addcoins 500
	goto TiltClaude_EventScript_DiceAgain
	end

TiltClaude_EventScript_DiceAgain::
	msgbox TiltClaude_Text_DiceAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltClaude_EventScript_DiceRoll
TiltClaude_EventScript_DiceEnd::
	releaseall
	end

TiltClaude_EventScript_DiceNoCoins::
	msgbox TiltClaude_Text_DiceNoCoins, MSGBOX_DEFAULT
	goto TiltClaude_EventScript_DiceEnd
	end

TiltClaude_Text_DiceAsk:
	.string "Roll the LUCKY DICE?\n"
	.string "It costs 100 COINS a roll.$"

TiltClaude_Text_DiceRolling:
	.string "The dice tumble across the ground...$"

TiltClaude_Text_DiceMiss:
	.string "Snake eyes! Nothing this time.$"

TiltClaude_Text_DiceBack:
	.string "A small win! Your 100 COINS are\n"
	.string "returned!$"

TiltClaude_Text_DicePrize:
	.string "A lucky roll! You won a prize!$"

TiltClaude_Text_DiceJackpot:
	.string "JACKPOT!!\n"
	.string "The dice shine... 500 COINS!$"

TiltClaude_Text_DiceAgain:
	.string "Roll again?$"

TiltClaude_Text_DiceNoCoins:
	.string "You don't have 100 COINS.$"

@ ---- CLAUDE (Slateport City): gives the LUCKY DICE ----

TiltClaude_EventScript_ClaudeCameo::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4BC, TiltClaude_EventScript_ClaudeDone
	msgbox TiltClaude_Text_ClaudeIntro, MSGBOX_DEFAULT
	checkitemspace ITEM_LUCKY_DICE
	goto_if_eq VAR_RESULT, FALSE, TiltClaude_EventScript_ClaudeFull
	giveitem ITEM_LUCKY_DICE
	setflag FLAG_UNUSED_0x4BC
	msgbox TiltClaude_Text_ClaudeGave, MSGBOX_DEFAULT
	release
	end

TiltClaude_EventScript_ClaudeDone::
	msgbox TiltClaude_Text_ClaudeAfter, MSGBOX_DEFAULT
	release
	end

TiltClaude_EventScript_ClaudeFull::
	msgbox TiltClaude_Text_ClaudeFull, MSGBOX_DEFAULT
	release
	end

TiltClaude_Text_ClaudeIntro:
	.string "Hi there! I'm CLAUDE.\n"
	.string "No, not a trainer. I just help out.\p"
	.string "I built a lot of this region's\n"
	.string "bounce when nobody was looking.\p"
	.string "The pinball table, the island, even\n"
	.string "the PHONE. A fun project, really.\p"
	.string "You seem to be enjoying it, so\n"
	.string "here's something I made for you.$"

TiltClaude_Text_ClaudeGave:
	.string "That's my LUCKY DICE! Use it from\n"
	.string "the BAG, 100 COINS a roll.\p"
	.string "Fortune favors the curious.\n"
	.string "Good luck out there!$"

TiltClaude_Text_ClaudeAfter:
	.string "Thanks for playing. Roll the dice\n"
	.string "now and then, you never know!$"

TiltClaude_Text_ClaudeFull:
	.string "Your BAG is full! Make some room\n"
	.string "and talk to me again.$"

@ ---- Lavaridge hot spring granny: free full heal, any time ----

TiltClaude_EventScript_LavaGranny::
	lock
	faceplayer
	msgbox TiltClaude_Text_GrannyAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltClaude_EventScript_GrannyNo
	msgbox TiltClaude_Text_GrannyHeal, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	msgbox TiltClaude_Text_GrannyDone, MSGBOX_DEFAULT
	release
	end

TiltClaude_EventScript_GrannyNo::
	msgbox TiltClaude_Text_GrannyNo, MSGBOX_DEFAULT
	release
	end

TiltClaude_Text_GrannyAsk:
	.string "Ahh, the springs are lovely today.\p"
	.string "Shall I tend to your POKéMON?\n"
	.string "No charge, dear.$"

TiltClaude_Text_GrannyHeal:
	.string "Let the warm waters work their\n"
	.string "magic...$"

TiltClaude_Text_GrannyDone:
	.string "There we are. All better!\n"
	.string "Come back any time.$"

TiltClaude_Text_GrannyNo:
	.string "Another time, then. The springs\n"
	.string "will be here.$"
