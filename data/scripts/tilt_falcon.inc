@ Falcon vs Dax: a scripted exhibition battle on Route 104 (west of Petalburg City). The player only watches.
@ VAR_UNUSED_0x40FC: 0 not seen, 1 seen. FLAG_UNUSED_0x043 hides both trainers afterwards.

TiltFalcon_EventScript_Trigger::
	lockall
	setvar VAR_UNUSED_0x40FC, 1
	applymovement LOCALID_TILT_FALCON, Common_Movement_FaceLeft
	applymovement LOCALID_TILT_DAX, Common_Movement_FaceRight
	waitmovement 0
	msgbox TiltFalcon_Text_Notice, MSGBOX_DEFAULT
	applymovement LOCALID_TILT_DAX, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox TiltFalcon_Text_Pre1, MSGBOX_DEFAULT
	msgbox TiltFalcon_Text_Pre2, MSGBOX_DEFAULT
	msgbox TiltFalcon_Text_Pre3, MSGBOX_DEFAULT
	playbgm MUS_VS_TRAINER, FALSE
	playse SE_BALL_OPEN
	showmonpic SPECIES_METAGROSS, 20, 3
	playmoncry SPECIES_METAGROSS, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B1, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_HERACROSS, 2, 3
	playmoncry SPECIES_HERACROSS, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B2, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_HERACROSS, 2, 3
	playmoncry SPECIES_HERACROSS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_NOT_EFFECTIVE
	msgbox TiltFalcon_Text_B3, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_METAGROSS, 20, 3
	playmoncry SPECIES_METAGROSS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B4, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_HERACROSS, 2, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B5, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_SNORLAX, 2, 3
	playmoncry SPECIES_SNORLAX, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B6, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_METAGROSS, 20, 3
	playmoncry SPECIES_METAGROSS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_EFFECTIVE
	msgbox TiltFalcon_Text_B7, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SNORLAX, 2, 3
	playmoncry SPECIES_SNORLAX, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B8, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_METAGROSS, 20, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B9, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_SALAMENCE, 20, 3
	playmoncry SPECIES_SALAMENCE, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B10, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SALAMENCE, 20, 3
	playmoncry SPECIES_SALAMENCE, CRY_MODE_NORMAL
	waitmoncry
	playse SE_EFFECTIVE
	msgbox TiltFalcon_Text_B11, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SNORLAX, 2, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B12, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_GYARADOS, 2, 3
	playmoncry SPECIES_GYARADOS, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B13, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SALAMENCE, 20, 3
	playmoncry SPECIES_SALAMENCE, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B14, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_GYARADOS, 2, 3
	playmoncry SPECIES_GYARADOS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B15, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SALAMENCE, 20, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B16, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_GENGAR, 20, 3
	playmoncry SPECIES_GENGAR, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B17, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_GENGAR, 20, 3
	playmoncry SPECIES_GENGAR, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B18, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_GYARADOS, 2, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B19, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_SKARMORY, 2, 3
	playmoncry SPECIES_SKARMORY, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B20, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SKARMORY, 2, 3
	playmoncry SPECIES_SKARMORY, CRY_MODE_NORMAL
	waitmoncry
	playse SE_EFFECTIVE
	msgbox TiltFalcon_Text_B21, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_GENGAR, 20, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B22, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_STARMIE, 20, 3
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B23, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_STARMIE, 20, 3
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B24, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_SKARMORY, 2, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B25, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_BLISSEY, 2, 3
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B26, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_STARMIE, 20, 3
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	waitmoncry
	playse SE_EFFECTIVE
	msgbox TiltFalcon_Text_B27, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_BLISSEY, 2, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B28, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_FORRETRESS, 2, 3
	playmoncry SPECIES_FORRETRESS, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B29, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_FORRETRESS, 2, 3
	playmoncry SPECIES_FORRETRESS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_SUPER_EFFECTIVE
	msgbox TiltFalcon_Text_B30, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_STARMIE, 20, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B31, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	showmonpic SPECIES_FORRETRESS, 2, 3
	playse SE_FAINT
	msgbox TiltFalcon_Text_B32, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	playse SE_BALL_OPEN
	showmonpic SPECIES_TYRANITAR, 20, 3
	playmoncry SPECIES_TYRANITAR, CRY_MODE_NORMAL
	waitmoncry
	msgbox TiltFalcon_Text_B33, MSGBOX_DEFAULT
	hidemonpic
	delay 10
	fadedefaultbgm
	msgbox TiltFalcon_Text_Won, MSGBOX_DEFAULT
	msgbox TiltFalcon_Text_DaxEnd, MSGBOX_DEFAULT
	applymovement LOCALID_TILT_DAX, TiltFalcon_Movement_DaxLeave
	waitmovement LOCALID_TILT_DAX
	removeobject LOCALID_TILT_DAX
	applymovement LOCALID_TILT_FALCON, Common_Movement_FacePlayer
	waitmovement 0
	msgbox TiltFalcon_Text_ToPlayer1, MSGBOX_DEFAULT
	msgbox TiltFalcon_Text_ToPlayer2, MSGBOX_DEFAULT
	applymovement LOCALID_TILT_FALCON, TiltFalcon_Movement_FalconLeave
	waitmovement LOCALID_TILT_FALCON
	removeobject LOCALID_TILT_FALCON
	setflag FLAG_UNUSED_0x043
	releaseall
	end

TiltFalcon_Movement_DaxLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TiltFalcon_Movement_FalconLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TiltFalcon_Text_Notice:
	.string "Two trainers are facing off in the\n"
	.string "middle of the road...$"

TiltFalcon_Text_Pre1:
	.string "DAX: Heh! You're the famous FALCON,\n"
	.string "right? I've swept every trainer in\l"
	.string "this region!$"

TiltFalcon_Text_Pre2:
	.string "FALCON: Six Pokémon each, all at\n"
	.string "level 100. No items, no tricks.\p"
	.string "Show me what you've got, DAX.$"

TiltFalcon_Text_Pre3:
	.string "DAX: Gladly! Here we go!$"

TiltFalcon_Text_Won:
	.string "DAX is out of usable Pokémon!\p"
	.string "FALCON wins the battle!$"

TiltFalcon_Text_DaxEnd:
	.string "DAX: Wow... Not a single one of my\n"
	.string "six could stop you.\p"
	.string "That was incredible, FALCON! I'm\n"
	.string "going back to train. I'll beat you\l"
	.string "next time!$"

TiltFalcon_Text_ToPlayer1:
	.string "FALCON: Hm? You were watching the\n"
	.string "whole thing?\p"
	.string "Don't just stand there, kid. A real\n"
	.string "battle teaches you more than any\l"
	.string "book.$"

TiltFalcon_Text_ToPlayer2:
	.string "Keep your combos going, learn your\n"
	.string "types, and trust your team.\p"
	.string "Maybe we'll cross paths again. See\n"
	.string "you around!$"

TiltFalcon_Text_B1:
	.string "FALCON sent out METAGROSS!$"

TiltFalcon_Text_B2:
	.string "DAX sent out HERACROSS!$"

TiltFalcon_Text_B3:
	.string "DAX's HERACROSS used\nMEGAHORN!\pIt's not very effective...$"

TiltFalcon_Text_B4:
	.string "FALCON's METAGROSS used\nPSYCHIC!\pIt's super effective!$"

TiltFalcon_Text_B5:
	.string "DAX's HERACROSS fainted!$"

TiltFalcon_Text_B6:
	.string "DAX sent out SNORLAX!$"

TiltFalcon_Text_B7:
	.string "FALCON's METAGROSS used\nMETEOR MASH!\pA critical hit!$"

TiltFalcon_Text_B8:
	.string "DAX's SNORLAX used\nEARTHQUAKE!\pIt's super effective!$"

TiltFalcon_Text_B9:
	.string "FALCON's METAGROSS fainted!$"

TiltFalcon_Text_B10:
	.string "FALCON sent out SALAMENCE!$"

TiltFalcon_Text_B11:
	.string "FALCON's SALAMENCE used\nDRAGON CLAW!\pA critical hit!$"

TiltFalcon_Text_B12:
	.string "DAX's SNORLAX fainted!$"

TiltFalcon_Text_B13:
	.string "DAX sent out GYARADOS!$"

TiltFalcon_Text_B14:
	.string "FALCON's SALAMENCE used\nROCK SLIDE!\pIt's super effective!$"

TiltFalcon_Text_B15:
	.string "DAX's GYARADOS used\nTHUNDERBOLT!\pIt's super effective!$"

TiltFalcon_Text_B16:
	.string "FALCON's SALAMENCE fainted!$"

TiltFalcon_Text_B17:
	.string "FALCON sent out GENGAR!$"

TiltFalcon_Text_B18:
	.string "FALCON's GENGAR used\nTHUNDERBOLT!\pIt's super effective!$"

TiltFalcon_Text_B19:
	.string "DAX's GYARADOS fainted!$"

TiltFalcon_Text_B20:
	.string "DAX sent out SKARMORY!$"

TiltFalcon_Text_B21:
	.string "DAX's SKARMORY used\nDRILL PECK!\pA critical hit!$"

TiltFalcon_Text_B22:
	.string "FALCON's GENGAR fainted!$"

TiltFalcon_Text_B23:
	.string "FALCON sent out STARMIE!$"

TiltFalcon_Text_B24:
	.string "FALCON's STARMIE used\nTHUNDERBOLT!\pIt's super effective!$"

TiltFalcon_Text_B25:
	.string "DAX's SKARMORY fainted!$"

TiltFalcon_Text_B26:
	.string "DAX sent out BLISSEY!$"

TiltFalcon_Text_B27:
	.string "FALCON's STARMIE used\nHYDRO PUMP!\pA critical hit!$"

TiltFalcon_Text_B28:
	.string "DAX's BLISSEY fainted!$"

TiltFalcon_Text_B29:
	.string "DAX sent out FORRETRESS!$"

TiltFalcon_Text_B30:
	.string "DAX's FORRETRESS used\nEXPLOSION!\pIt's super effective!$"

TiltFalcon_Text_B31:
	.string "FALCON's STARMIE fainted!$"

TiltFalcon_Text_B32:
	.string "DAX's FORRETRESS fainted!$"

TiltFalcon_Text_B33:
	.string "FALCON sent out TYRANITAR!$"

@ Poking a trainer before the show starts
TiltFalcon_EventScript_Watch::
	msgbox TiltFalcon_Text_Busy, MSGBOX_NPC
	end

TiltFalcon_Text_Busy:
	.string "...$"
