@ The PINBALL TABLE: a pinball-hall maze reached through the Attendant in the Pinball Wizard's room.
@ Needs a best combo of 10+. Flags: FLAG_UNUSED_0x03F = this visit's bumper bonus used (cleared on entry).
@ Trainer slots reused: 485 (BUMPER BOB), 486 (FLIPPER FAY), 854 (TABLE KING).

PinballTable_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PinballTable_OnTransition
	.byte 0

PinballTable_OnTransition::
	clearflag FLAG_UNUSED_0x03F
	end

@ ---------------- Attendant (Pinball Wizard's room) ----------------

PinballTable_EventScript_Attendant::
	lock
	faceplayer
	goto_if_defeated TRAINER_TILT_KING, PinballTable_EventScript_AttendantBeaten
	goto_if_lt VAR_TILT_BEST, 10, PinballTable_EventScript_AttendantLocked
	msgbox PinballTable_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PinballTable_EventScript_AttendantNo
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	warp MAP_PINBALL_TABLE, 7, 13
	waitstate
	release
	end

PinballTable_EventScript_AttendantBeaten::
	msgbox PinballTable_Text_AttendantBeaten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PinballTable_EventScript_AttendantNo
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	warp MAP_PINBALL_TABLE, 7, 13
	waitstate
	release
	end

PinballTable_EventScript_AttendantLocked::
	msgbox PinballTable_Text_AttendantLocked, MSGBOX_DEFAULT
	release
	end

PinballTable_EventScript_AttendantNo::
	msgbox PinballTable_Text_AttendantNo, MSGBOX_DEFAULT
	release
	end

@ ---------------- Table pieces ----------------

PinballTable_EventScript_Exit::
	lockall
	msgbox PinballTable_Text_ExitAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PinballTable_EventScript_ExitStay
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	warp MAP_LITTLEROOT_TOWN_POKEMON_CENTER_2F, 11, 4
	waitstate
	releaseall
	end

PinballTable_EventScript_ExitStay::
	applymovement LOCALID_PLAYER, PinballTable_Movement_StepUp
	waitmovement 0
	releaseall
	end

PinballTable_Movement_StepUp:
	walk_up
	step_end

PinballTable_EventScript_Bumper::
	lockall
	playse SE_BALL_BOUNCE_1
	goto_if_set FLAG_UNUSED_0x03F, PinballTable_EventScript_BumperDone
	setflag FLAG_UNUSED_0x03F
	addvar VAR_TILT_COMBO, 3
	msgbox PinballTable_Text_Bumper, MSGBOX_DEFAULT
PinballTable_EventScript_BumperDone::
	releaseall
	end

PinballTable_EventScript_FlipperA::
	lockall
	playse SE_M_FLY
	msgbox PinballTable_Text_Flipper, MSGBOX_DEFAULT
	closemessage
	warp MAP_PINBALL_TABLE, 2, 2
	waitstate
	releaseall
	end

PinballTable_EventScript_FlipperB::
	lockall
	playse SE_M_FLY
	msgbox PinballTable_Text_Flipper, MSGBOX_DEFAULT
	closemessage
	warp MAP_PINBALL_TABLE, 12, 6
	waitstate
	releaseall
	end

PinballTable_EventScript_FlipperC::
	lockall
	playse SE_M_FLY
	msgbox PinballTable_Text_Flipper, MSGBOX_DEFAULT
	closemessage
	warp MAP_PINBALL_TABLE, 1, 8
	waitstate
	releaseall
	end

PinballTable_EventScript_Sign::
	msgbox PinballTable_Text_Sign, MSGBOX_SIGN
	end

@ ---------------- Trainers ----------------

PinballTable_EventScript_TrainerA::
	trainerbattle_single TRAINER_TILT_TABLE_A, PinballTable_Text_AIntro, PinballTable_Text_ADefeat
	msgbox PinballTable_Text_APost, MSGBOX_AUTOCLOSE
	end

PinballTable_EventScript_TrainerB::
	trainerbattle_single TRAINER_TILT_TABLE_B, PinballTable_Text_BIntro, PinballTable_Text_BDefeat
	msgbox PinballTable_Text_BPost, MSGBOX_AUTOCLOSE
	end

PinballTable_EventScript_King::
	lock
	faceplayer
	trainerbattle_single TRAINER_TILT_KING, PinballTable_Text_KingIntro, PinballTable_Text_KingDefeat, PinballTable_EventScript_KingWon
	msgbox PinballTable_Text_KingPost, MSGBOX_DEFAULT
	release
	end

PinballTable_EventScript_KingWon::
	msgbox PinballTable_Text_KingPrize, MSGBOX_DEFAULT
	giveitem ITEM_PP_MAX, 3
	giveitem ITEM_LUCKY_EGG
	addvar VAR_TILT_SAVER, 3
	msgbox PinballTable_Text_KingSavers, MSGBOX_DEFAULT
	release
	end

@ ---------------- Text ----------------

PinballTable_Text_AttendantAsk:
	.string "Welcome to the PINBALL TABLE!\p"
	.string "A giant machine in the back, with a\n"
	.string "maze, bumpers, flippers and a boss.\p"
	.string "Want to roll in?$"

PinballTable_Text_AttendantBeaten:
	.string "The TABLE KING is beaten, but the\n"
	.string "bumpers still pay out!\p"
	.string "Roll in again?$"

PinballTable_Text_AttendantLocked:
	.string "The PINBALL TABLE only takes players\n"
	.string "who have hit a combo of 10 or more.\p"
	.string "Come back when you are warmed up!$"

PinballTable_Text_AttendantNo:
	.string "No problem. The table will wait.$"

PinballTable_Text_ExitAsk:
	.string "Leave the PINBALL TABLE?$"

PinballTable_Text_Bumper:
	.string "BUMPER! COMBO +3!\p"
	.string "(Only the first bumper on each visit\n"
	.string "pays out.)$"

PinballTable_Text_Flipper:
	.string "A FLIPPER launches you across the\n"
	.string "table!$"

PinballTable_Text_Sign:
	.string "PINBALL TABLE\p"
	.string "Bumpers add to your COMBO. FLIPPERS\n"
	.string "in the corners fling you around.\p"
	.string "The TABLE KING waits in the top-left.$"

PinballTable_Text_AIntro:
	.string "I live for the bumpers!\n"
	.string "Let's see your reflexes!$"

PinballTable_Text_ADefeat:
	.string "Bounced right out...$"

PinballTable_Text_APost:
	.string "The corners FLIP you across the\n"
	.string "table. Try them for a shortcut!$"

PinballTable_Text_BIntro:
	.string "Flip, flip, FLIP! You're mine!$"

PinballTable_Text_BDefeat:
	.string "My flippers failed me...$"

PinballTable_Text_BPost:
	.string "The TABLE KING is in the top-left\n"
	.string "pocket. He never loses a ball.$"

PinballTable_Text_KingIntro:
	.string "TABLE KING: Every ball you've ever\n"
	.string "won, I've watched it roll.\p"
	.string "Show me a combo that can beat my\n"
	.string "perfect table!$"

PinballTable_Text_KingDefeat:
	.string "A ball past my flippers...\n"
	.string "Incredible!$"

PinballTable_Text_KingPrize:
	.string "TABLE KING: The table is yours.\n"
	.string "Take the jackpot!$"

PinballTable_Text_KingSavers:
	.string "You also got 3 BALL SAVERS!$"

PinballTable_Text_KingPost:
	.string "TABLE KING: Keep your combo alive,\n"
	.string "champion. The table never tilts for\l"
	.string "someone like you.$"
