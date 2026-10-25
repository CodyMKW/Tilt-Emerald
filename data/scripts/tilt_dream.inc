@ Dream Island - recreated from CodyMKW's old FireRed hack (Pallet Town's mystery island).
@ Late game: the SAILOR next to the Ever Grande Pokemon Center sails you out once you are Champion.
@ Three leaders (MrBean, Chadderz, Vantox) have to be beaten in that order.
@ Trainer slots reused from the unused RED / LEAF / BRENDAN placeholder entries (no new flag space).

DreamIsland_MapScripts::
	.byte 0

@ ---------------- Sailor (Ever Grande City, near the Pokemon Center) ----------------

DreamIsland_EventScript_SailorEverGrande::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, DreamIsland_EventScript_SailorNotYet
	msgbox DreamIsland_Text_SailorAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DreamIsland_EventScript_SailorNo
	msgbox DreamIsland_Text_SailorGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	warp MAP_DREAM_ISLAND, 9, 14
	waitstate
	release
	end

DreamIsland_EventScript_SailorNotYet::
	msgbox DreamIsland_Text_SailorNotYet, MSGBOX_DEFAULT
	release
	end

DreamIsland_EventScript_SailorNo::
	msgbox DreamIsland_Text_SailorNo, MSGBOX_DEFAULT
	release
	end

@ ---------------- Sailor (on the island) ----------------

DreamIsland_EventScript_SailorIsland::
	lock
	faceplayer
	msgbox DreamIsland_Text_SailorBackAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DreamIsland_EventScript_SailorNo
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	warp MAP_EVER_GRANDE_CITY, 20, 50
	waitstate
	release
	end

@ ---------------- Signs ----------------

DreamIsland_EventScript_IslandSign::
	msgbox DreamIsland_Text_IslandSign, MSGBOX_SIGN
	end

DreamIsland_EventScript_SignBean::
	msgbox DreamIsland_Text_SignBean, MSGBOX_SIGN
	end

DreamIsland_EventScript_SignChadderz::
	msgbox DreamIsland_Text_SignChadderz, MSGBOX_SIGN
	end

DreamIsland_EventScript_SignVantox::
	msgbox DreamIsland_Text_SignVantox, MSGBOX_SIGN
	end

@ ---------------- Leader 1: MrBean ----------------

DreamIsland_EventScript_Bean::
	lock
	faceplayer
	trainerbattle_single TRAINER_TILT_BEAN, DreamIsland_Text_BeanIntro, DreamIsland_Text_BeanDefeat, DreamIsland_EventScript_BeanWon
	msgbox DreamIsland_Text_BeanPost, MSGBOX_DEFAULT
	release
	end

DreamIsland_EventScript_BeanWon::
	msgbox DreamIsland_Text_BeanPost, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 3
	release
	end

@ ---------------- Leader 2: Chadderz ----------------

DreamIsland_EventScript_Chadderz::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_TILT_BEAN, DreamIsland_EventScript_ChadderzLocked
	trainerbattle_single TRAINER_TILT_CHADDERZ, DreamIsland_Text_ChadderzIntro, DreamIsland_Text_ChadderzDefeat, DreamIsland_EventScript_ChadderzWon
	msgbox DreamIsland_Text_ChadderzPost, MSGBOX_DEFAULT
	release
	end

DreamIsland_EventScript_ChadderzLocked::
	msgbox DreamIsland_Text_ChadderzLocked, MSGBOX_DEFAULT
	release
	end

DreamIsland_EventScript_ChadderzWon::
	msgbox DreamIsland_Text_ChadderzPost, MSGBOX_DEFAULT
	giveitem ITEM_PP_MAX, 2
	release
	end

@ ---------------- Leader 3: Vantox ----------------

DreamIsland_EventScript_Vantox::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_TILT_BEAN, DreamIsland_EventScript_VantoxLocked
	goto_if_not_defeated TRAINER_TILT_CHADDERZ, DreamIsland_EventScript_VantoxLocked
	trainerbattle_single TRAINER_TILT_VANTOX, DreamIsland_Text_VantoxIntro, DreamIsland_Text_VantoxDefeat, DreamIsland_EventScript_VantoxWon
	msgbox DreamIsland_Text_VantoxPost, MSGBOX_DEFAULT
	release
	end

DreamIsland_EventScript_VantoxLocked::
	msgbox DreamIsland_Text_VantoxLocked, MSGBOX_DEFAULT
	release
	end

DreamIsland_EventScript_VantoxWon::
	msgbox DreamIsland_Text_VantoxPost, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	release
	end

@ ---------------- Text ----------------

DreamIsland_Text_SailorNotYet:
	.string "Ahoy! The sea is far too rough.\p"
	.string "Come back once you are the\n"
	.string "POKéMON LEAGUE CHAMPION.$"

DreamIsland_Text_SailorAsk:
	.string "Ahoy, CHAMPION!\p"
	.string "Want a ride to DREAM ISLAND?\n"
	.string "Every POKéMON Master trains there!$"

DreamIsland_Text_SailorGo:
	.string "All aboard!$"

DreamIsland_Text_SailorNo:
	.string "Just say the word when you are\n"
	.string "ready.$"

DreamIsland_Text_SailorBackAsk:
	.string "Ready to head back to\n"
	.string "EVER GRANDE CITY?$"

DreamIsland_Text_IslandSign:
	.string "DREAM ISLAND\n"
	.string "A place where every POKéMON Master\l"
	.string "comes to train to get even stronger!$"

DreamIsland_Text_SignBean:
	.string "DREAM ISLAND\n"
	.string "Leader 1: MrBean\p"
	.string "The skilled POKéMON Master!$"

DreamIsland_Text_SignChadderz:
	.string "DREAM ISLAND\n"
	.string "Leader 2: Chadderz\p"
	.string "The smart POKéMON Master!$"

DreamIsland_Text_SignVantox:
	.string "DREAM ISLAND\n"
	.string "Leader 3: Vantox\p"
	.string "The legendary POKéMON Master!$"

DreamIsland_Text_BeanIntro:
	.string "MrBean: HaHa, I shall beat you!\n"
	.string "So prepare to lose!!$"

DreamIsland_Text_BeanDefeat:
	.string "What? How did I lose!!!$"

DreamIsland_Text_BeanPost:
	.string "MrBean: I shall become even stronger\n"
	.string "so next time I will win.$"

DreamIsland_Text_ChadderzLocked:
	.string "Chadderz: Hmm? You have not even\n"
	.string "beaten MrBean yet.\p"
	.string "Come back when you have.$"

DreamIsland_Text_ChadderzIntro:
	.string "Chadderz: Hmm... you can't win,\n"
	.string "but let's battle anyways.\l"
	.string "I am bored!$"

DreamIsland_Text_ChadderzDefeat:
	.string "WHAT!!!!! HOW... I NEVER LOSE...$"

DreamIsland_Text_ChadderzPost:
	.string "Chadderz: Guess I need to\n"
	.string "train harder.$"

DreamIsland_Text_VantoxLocked:
	.string "Vantox: Beat MrBean and Chadderz\n"
	.string "first. Then we will talk.$"

DreamIsland_Text_VantoxIntro:
	.string "Vantox: You managed to beat\n"
	.string "MrBean and Chadderz, but I won't\l"
	.string "be so easy to defeat.\p"
	.string "Bring it on!$"

DreamIsland_Text_VantoxDefeat:
	.string "O O Wow... you're strong!!$"

DreamIsland_Text_VantoxPost:
	.string "Vantox: I will train more and beat\n"
	.string "you the next time we meet!$"
