@ Route 102: STEVEN walks by after you leave Oldale heading west, chats, gives a TM and "flies" away.
@ VAR_UNUSED_0x40A8 = 0: not seen yet, 1: done
@ FLAG_UNUSED_0x020 = Steven hidden (set on new game, cleared for the scene, set again when he leaves)

TiltEmerald_EventScript_StevenTriggerNorth::
	lockall
	setvar VAR_TEMP_1, 1
	goto TiltEmerald_EventScript_StevenScene
	end

TiltEmerald_EventScript_StevenTriggerSouth::
	lockall
	setvar VAR_TEMP_1, 2
	goto TiltEmerald_EventScript_StevenScene
	end

TiltEmerald_EventScript_StevenScene::
	clearflag FLAG_UNUSED_0x020
	addobject LOCALID_TILT_STEVEN
	delay 20
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TILT_STEVEN, TiltEmerald_Movement_StevenStep1
	waitmovement 0
	goto_if_eq VAR_TEMP_1, 2, TiltEmerald_EventScript_StevenStepMore
	goto TiltEmerald_EventScript_StevenTalk
	end

TiltEmerald_EventScript_StevenStepMore::
	applymovement LOCALID_TILT_STEVEN, TiltEmerald_Movement_StevenStep2
	waitmovement 0
	goto TiltEmerald_EventScript_StevenTalk
	end

TiltEmerald_Movement_StevenStep1:
	walk_right
	walk_right
	step_end

TiltEmerald_Movement_StevenStep2:
	walk_down
	step_end

TiltEmerald_EventScript_StevenTalk::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_TILT_STEVEN, Common_Movement_FaceRight
	waitmovement 0
	msgbox TiltEmerald_Text_Steven1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Steven2, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Steven3, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_Steven4, MSGBOX_DEFAULT
	checkitemspace ITEM_TM47
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_StevenBagFull
	giveitem ITEM_TM47
	msgbox TiltEmerald_Text_Steven5, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_StevenLeave
	end

TiltEmerald_EventScript_StevenBagFull::
	msgbox TiltEmerald_Text_StevenNoRoom, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_StevenLeave
	end

TiltEmerald_EventScript_StevenLeave::
	msgbox TiltEmerald_Text_Steven6, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_SKARMORY, CRY_MODE_NORMAL
	applymovement LOCALID_TILT_STEVEN, TiltEmerald_Movement_StevenTakeoff
	waitmovement 0
	waitmoncry
	playse SE_M_FLY
	applymovement LOCALID_TILT_STEVEN, TiltEmerald_Movement_StevenVanish
	waitmovement 0
	removeobject LOCALID_TILT_STEVEN
	setflag FLAG_UNUSED_0x020
	setvar VAR_UNUSED_0x40A8, 1
	delay 30
	msgbox TiltEmerald_Text_StevenGone, MSGBOX_DEFAULT
	releaseall
	end

TiltEmerald_Movement_StevenTakeoff:
	face_up
	delay_8
	jump_in_place_up
	delay_4
	jump_in_place_up
	delay_4
	step_end

TiltEmerald_Movement_StevenVanish:
	jump_in_place_up
	walk_fast_up
	set_invisible
	step_end

TiltEmerald_Text_Steven1:
	.string "STEVEN: Well, well. A trainer with\n"
	.string "real bounce in their step.\p"
	.string "You must be {PLAYER}. I've heard\n"
	.string "the rumors.$"

TiltEmerald_Text_Steven2:
	.string "I'm STEVEN. I collect rare stones\n"
	.string "from all over the region.\p"
	.string "But lately, my stones have been\n"
	.string "rattling in my pocket...$"

TiltEmerald_Text_Steven3:
	.string "That TILT-O-TRON shook the very\n"
	.string "ground beneath us.\p"
	.string "Rocks, caves, even POKéMON, all of\n"
	.string "them bounce a little differently.$"

TiltEmerald_Text_Steven4:
	.string "Some call it chaos. I call it\n"
	.string "a chance to see the region fresh.\p"
	.string "A good trainer keeps their combo\n"
	.string "and their composure.\p"
	.string "Here. A little gift from one\n"
	.string "collector to another.$"

TiltEmerald_Text_Steven5:
	.string "That's STEEL WING. My SKARMORY\n"
	.string "taught me the move.\p"
	.string "It's hard like steel and quick\n"
	.string "like a ball off a bumper.$"

TiltEmerald_Text_StevenNoRoom:
	.string "Oh, your BAG is full. A pity.\n"
	.string "Make some room if we meet again.$"

TiltEmerald_Text_Steven6:
	.string "Now, I must be going. There's a\n"
	.string "cave with my name on it.\p"
	.string "Keep bouncing, {PLAYER}!\p"
	.string "SKARMORY, let's fly!$"

TiltEmerald_Text_StevenGone:
	.string "...He's gone!\p"
	.string "A silver feather drifts down\n"
	.string "where he stood.$"
