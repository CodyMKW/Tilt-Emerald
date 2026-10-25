@ Cody's Gym (Littleroot Town, west side) - scripts for the yard, the pad-maze gym, the guard quiz,
@ the four gym trainers and the gym leader Cody.
@
@ Nobody here can be battled until the player holds all 8 badges. Everyone can be talked to.
@ Flags (all previously unused):
@   FLAG_UNUSED_0x02D = guard has stepped aside (quiz solved)  [also the guard's object hide flag]
@   FLAG_UNUSED_0x02E = Cody reward 1 given (TM02)
@   FLAG_UNUSED_0x02F = Cody reward 2 given (Rare Candies)
@   FLAG_UNUSED_0x030 = Cody reward 3 given (Dragon Fang)

LittlerootTown_West_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_West_OnTransition
	.byte 0

LittlerootTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_Gym_OnTransition
	.byte 0

@ Gym trainers spot you and walk over once you hold all 8 badges. Before that they are marked as
@ "already battled" so they stay put (FLAG_UNUSED_0x03E = that mark is automatic, clear it at 8 badges).
LittlerootTown_Gym_OnTransition::
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_Gym_ArmTrainers
	goto_if_set FLAG_UNUSED_0x03E, LittlerootTown_Gym_OnTransitionEnd
	setflag FLAG_UNUSED_0x03E
	settrainerflag TRAINER_TILT_DRACO
	settrainerflag TRAINER_TILT_SANDRA
	settrainerflag TRAINER_TILT_RYU
	settrainerflag TRAINER_TILT_MIRA
LittlerootTown_Gym_OnTransitionEnd::
	end

LittlerootTown_Gym_ArmTrainers::
	goto_if_unset FLAG_UNUSED_0x03E, LittlerootTown_Gym_OnTransitionEnd
	clearflag FLAG_UNUSED_0x03E
	cleartrainerflag TRAINER_TILT_DRACO
	cleartrainerflag TRAINER_TILT_SANDRA
	cleartrainerflag TRAINER_TILT_RYU
	cleartrainerflag TRAINER_TILT_MIRA
	end

@ ---------------- Statues ----------------

TiltGym_EventScript_Statue::
	goto_if_defeated TRAINER_TILT_CODY, TiltGym_EventScript_StatueWon
	msgbox TiltGym_Text_Statue, MSGBOX_SIGN
	end

TiltGym_EventScript_StatueWon::
	msgbox TiltGym_Text_StatueWon, MSGBOX_SIGN
	end

TiltGym_Text_Statue:
	.string "LITTLEROOT POKéMON GYM\n"
	.string "LEADER: CODY\p"
	.string "WINNING TRAINERS:\n"
	.string "???$"

TiltGym_Text_StatueWon:
	.string "LITTLEROOT POKéMON GYM\n"
	.string "LEADER: CODY\p"
	.string "WINNING TRAINERS:\n"
	.string "{PLAYER}$"

@ ---------------- Badge check: VAR_RESULT = TRUE only with all 8 badges ----------------

TiltGym_EventScript_CheckBadges::
	setvar VAR_RESULT, FALSE
	goto_if_unset FLAG_BADGE01_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE02_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE03_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE04_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE05_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE06_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE07_GET, TiltGym_EventScript_CheckBadgesEnd
	goto_if_unset FLAG_BADGE08_GET, TiltGym_EventScript_CheckBadgesEnd
	setvar VAR_RESULT, TRUE
TiltGym_EventScript_CheckBadgesEnd::
	return

@ ---------------- Yard ----------------

TiltGym_EventScript_YardSign::
	msgbox TiltGym_Text_YardSign, MSGBOX_SIGN
	end

TiltGym_EventScript_YardGreeter::
	msgbox TiltGym_Text_YardGreeter, MSGBOX_NPC
	end

@ ---------------- Gym guide (entrance room) ----------------

TiltGym_EventScript_Guide::
	lock
	faceplayer
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, TRUE, TiltGym_EventScript_GuideReady
	msgbox TiltGym_Text_GuideLocked1, MSGBOX_DEFAULT
	msgbox TiltGym_Text_GuideLocked2, MSGBOX_DEFAULT
	release
	end

TiltGym_EventScript_GuideReady::
	msgbox TiltGym_Text_GuideReady, MSGBOX_DEFAULT
	release
	end

@ ---------------- Guard (blocks the last pad; asks for the motto) ----------------

TiltGym_EventScript_Guard::
	lock
	faceplayer
	msgbox TiltGym_Text_GuardHalt, MSGBOX_DEFAULT
	message TiltGym_Text_GuardAsk
	waitmessage
	multichoice 0, 0, MULTI_TILT_QUIZ, FALSE
	switch VAR_RESULT
	case 1, TiltGym_EventScript_GuardCorrect
	goto TiltGym_EventScript_GuardWrong
	end

TiltGym_EventScript_GuardCorrect::
	msgbox TiltGym_Text_GuardCorrect, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_TILTGYM_GUARD, Common_Movement_FaceUp
	waitmovement 0
	removeobject LOCALID_TILTGYM_GUARD
	setflag FLAG_UNUSED_0x02D
	msgbox TiltGym_Text_GuardOpen, MSGBOX_DEFAULT
	release
	end

TiltGym_EventScript_GuardWrong::
	msgbox TiltGym_Text_GuardWrong, MSGBOX_DEFAULT
	closemessage
	warp MAP_LITTLEROOT_TOWN_GYM, 16, 37
	waitstate
	end

@ ---------------- Gym trainers ----------------

TiltGym_EventScript_Draco::
	trainerbattle_single TRAINER_TILT_DRACO, TiltGym_Text_DracoIntro, TiltGym_Text_DracoDefeat
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_DracoLocked
	msgbox TiltGym_Text_DracoPost, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_DracoLocked::
	msgbox TiltGym_Text_DracoLocked, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_Sandra::
	trainerbattle_single TRAINER_TILT_SANDRA, TiltGym_Text_SandraIntro, TiltGym_Text_SandraDefeat
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_SandraLocked
	msgbox TiltGym_Text_SandraPost, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_SandraLocked::
	msgbox TiltGym_Text_SandraLocked, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_Ryu::
	trainerbattle_single TRAINER_TILT_RYU, TiltGym_Text_RyuIntro, TiltGym_Text_RyuDefeat
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_RyuLocked
	msgbox TiltGym_Text_RyuPost, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_RyuLocked::
	msgbox TiltGym_Text_RyuLocked, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_Mira::
	trainerbattle_single TRAINER_TILT_MIRA, TiltGym_Text_MiraIntro, TiltGym_Text_MiraDefeat
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_MiraLocked
	msgbox TiltGym_Text_MiraPost, MSGBOX_AUTOCLOSE
	end

TiltGym_EventScript_MiraLocked::
	msgbox TiltGym_Text_MiraLocked, MSGBOX_AUTOCLOSE
	end

@ ---------------- Gym leader Cody ----------------

TiltGym_EventScript_Cody::
	lock
	faceplayer
	call TiltGym_EventScript_CheckBadges
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_CodyLocked
	trainerbattle_single TRAINER_TILT_CODY, TiltGym_Text_CodyIntro, TiltGym_Text_CodyDefeat, TiltGym_EventScript_CodyDefeated
	goto_if_unset FLAG_UNUSED_0x02E, TiltGym_EventScript_CodyGiveRewards
	goto_if_unset FLAG_UNUSED_0x02F, TiltGym_EventScript_CodyGiveRewards
	goto_if_unset FLAG_UNUSED_0x030, TiltGym_EventScript_CodyGiveRewards
	msgbox TiltGym_Text_CodyPost, MSGBOX_DEFAULT
	release
	end

TiltGym_EventScript_CodyLocked::
	msgbox TiltGym_Text_CodyLocked1, MSGBOX_DEFAULT
	msgbox TiltGym_Text_CodyLocked2, MSGBOX_DEFAULT
	release
	end

TiltGym_EventScript_CodyDefeated::
	msgbox TiltGym_Text_CodyWin, MSGBOX_DEFAULT
	goto TiltGym_EventScript_CodyGiveRewards
	end

@ Rewards are given one by one and remembered with flags, so nothing is lost if the bag is full.
TiltGym_EventScript_CodyGiveRewards::
	goto_if_set FLAG_UNUSED_0x02E, TiltGym_EventScript_CodyReward2
	checkitemspace ITEM_TM02
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_CodyBagFull
	giveitem ITEM_TM02
	setflag FLAG_UNUSED_0x02E
TiltGym_EventScript_CodyReward2::
	goto_if_set FLAG_UNUSED_0x02F, TiltGym_EventScript_CodyReward3
	checkitemspace ITEM_RARE_CANDY, 5
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_CodyBagFull
	giveitem ITEM_RARE_CANDY, 5
	setflag FLAG_UNUSED_0x02F
TiltGym_EventScript_CodyReward3::
	goto_if_set FLAG_UNUSED_0x030, TiltGym_EventScript_CodyRewardsDone
	checkitemspace ITEM_DRAGON_FANG
	goto_if_eq VAR_RESULT, FALSE, TiltGym_EventScript_CodyBagFull
	giveitem ITEM_DRAGON_FANG
	setflag FLAG_UNUSED_0x030
TiltGym_EventScript_CodyRewardsDone::
	msgbox TiltGym_Text_CodyRewards, MSGBOX_DEFAULT
	release
	end

TiltGym_EventScript_CodyBagFull::
	msgbox TiltGym_Text_CodyBagFull, MSGBOX_DEFAULT
	release
	end

@ ---------------- Text: yard ----------------

TiltGym_Text_YardSign:
	.string "LITTLEROOT GYM\n"
	.string "LEADER: CODY\p"
	.string "The Dragon Master of the tilted\n"
	.string "region. Challengers need all\l"
	.string "8 BADGES!$"

TiltGym_Text_YardGreeter:
	.string "That's CODY'S GYM, the toughest\n"
	.string "in the whole region.\p"
	.string "Only trainers with all 8 BADGES\n"
	.string "may challenge anyone inside.\p"
	.string "But anyone can go in and look\n"
	.string "around. Just mind the pads!$"

@ ---------------- Text: guide ----------------

TiltGym_Text_GuideLocked1:
	.string "Welcome to CODY'S GYM!\p"
	.string "Nobody here will battle you\n"
	.string "unless you hold all 8 BADGES.\p"
	.string "But you can still wander around\n"
	.string "and talk to everyone!$"

TiltGym_Text_GuideLocked2:
	.string "The glowing pads teleport you from\n"
	.string "room to room. Some lead onward,\l"
	.string "some send you back.\p"
	.string "Start with the pad to the north.\p"
	.string "The GUARD in the last hall asks for\n"
	.string "our gym's motto. Ask the trainers!$"

TiltGym_Text_GuideReady:
	.string "You hold all 8 BADGES!\p"
	.string "Then everyone here will battle you.\n"
	.string "Good luck reaching CODY!$"

@ ---------------- Text: guard ----------------

TiltGym_Text_GuardHalt:
	.string "Halt! Only those who know our\n"
	.string "gym's creed may pass.$"

TiltGym_Text_GuardAsk:
	.string "What is the motto of this gym?$"

TiltGym_Text_GuardCorrect:
	.string "Correct! You've been listening to\n"
	.string "the trainers. Well done.$"

TiltGym_Text_GuardOpen:
	.string "The pad ahead leads to CODY.\n"
	.string "Go on, trainer.$"

TiltGym_Text_GuardWrong:
	.string "Wrong! Go back and learn our\n"
	.string "creed!$"

@ ---------------- Text: Draco (first half of the motto) ----------------

TiltGym_Text_DracoLocked:
	.string "I'm DRACO. I can't battle you\n"
	.string "unless you have all 8 BADGES.\p"
	.string "But I'll tell you this: our motto\n"
	.string "begins with BOUNCE HIGH...\p"
	.string "And a tip: the pad closest to where\n"
	.string "you arrive in here leads deeper.$"

TiltGym_Text_DracoIntro:
	.string "All 8 BADGES? Then show me how\n"
	.string "high you can bounce!$"

TiltGym_Text_DracoDefeat:
	.string "My DRAGONAIR and FLYGON...\n"
	.string "Beaten!$"

TiltGym_Text_DracoPost:
	.string "Bounce high, and never let\n"
	.string "the ball drain.$"

@ ---------------- Text: Sandra (second half of the motto) ----------------

TiltGym_Text_SandraLocked:
	.string "I'm SANDRA. No 8 BADGES, no\n"
	.string "battle. Those are the rules.\p"
	.string "But our motto ends with...\n"
	.string "...FLY HIGHER!\p"
	.string "CODY shouts it every morning.$"

TiltGym_Text_SandraIntro:
	.string "You have all 8 BADGES? Then fly\n"
	.string "higher than my ALTARIA!$"

TiltGym_Text_SandraDefeat:
	.string "VIBRAVA and ALTARIA couldn't\n"
	.string "stop you...$"

TiltGym_Text_SandraPost:
	.string "You really do fly higher.\n"
	.string "CODY will be thrilled.$"

@ ---------------- Text: Ryu ----------------

TiltGym_Text_RyuLocked:
	.string "I'm RYU. Come back with all\n"
	.string "8 BADGES if you want a fight.\p"
	.string "Two pads sit side by side in the\n"
	.string "north of this room.\p"
	.string "Take the left one. The right one\n"
	.string "just throws you back.$"

TiltGym_Text_RyuIntro:
	.string "All 8 BADGES! Finally, a real\n"
	.string "challenge!$"

TiltGym_Text_RyuDefeat:
	.string "GYARADOS and KINGDRA... washed\n"
	.string "away!$"

TiltGym_Text_RyuPost:
	.string "Water or sky, a dragon is a\n"
	.string "dragon. Keep going!$"

@ ---------------- Text: Mira ----------------

TiltGym_Text_MiraLocked:
	.string "I'm MIRA. I'd battle you, but\n"
	.string "you don't have 8 BADGES yet.\p"
	.string "FLYGON is the heart of CODY'S team.\n"
	.string "He trains it in the desert.\p"
	.string "The pad in the middle of this room\n"
	.string "leads to the last hall.$"

TiltGym_Text_MiraIntro:
	.string "8 BADGES! Let's see if you can\n"
	.string "handle my FLYGON!$"

TiltGym_Text_MiraDefeat:
	.string "SHELGON and FLYGON...\n"
	.string "both down!$"

TiltGym_Text_MiraPost:
	.string "CODY's FLYGON is far stronger\n"
	.string "than mine. Be careful!$"

@ ---------------- Text: Cody ----------------

TiltGym_Text_CodyLocked1:
	.string "So you made it through the pads.\n"
	.string "Impressive.\p"
	.string "I am CODY, the Dragon Master. My\n"
	.string "team revolves around FLYGON,\l"
	.string "the spirit of the desert.$"

TiltGym_Text_CodyLocked2:
	.string "But I only battle trainers who\n"
	.string "hold all 8 BADGES.\p"
	.string "The pad by the wall behind me takes\n"
	.string "you back to the entrance.\p"
	.string "Prove yourself across the region.\n"
	.string "Then come back. I'll be waiting.$"

TiltGym_Text_CodyIntro:
	.string "You hold all 8 BADGES!\p"
	.string "Then you have earned this fight.\p"
	.string "I am CODY, the Dragon Master!\n"
	.string "Bounce high, fly higher!\p"
	.string "Let's see if you can keep your\n"
	.string "combo alive against my FLYGON!$"

TiltGym_Text_CodyDefeat:
	.string "Incredible...\p"
	.string "My FLYGON, beaten. You truly bounce\n"
	.string "high, trainer.$"

TiltGym_Text_CodyWin:
	.string "CODY: You are a true champion.\p"
	.string "A dragon master rewards a worthy\n"
	.string "rival. Take these.$"

TiltGym_Text_CodyRewards:
	.string "CODY: DRAGON CLAW is the move my\n"
	.string "FLYGON trusts the most.\p"
	.string "The DRAGON FANG carries the power\n"
	.string "of a true dragon.\p"
	.string "The pad by the wall behind me takes\n"
	.string "you back to the entrance.\p"
	.string "Come back anytime. FLYGON and I\n"
	.string "would love a rematch!$"

TiltGym_Text_CodyBagFull:
	.string "Your BAG is full!\n"
	.string "Make room and talk to me again.$"

TiltGym_Text_CodyPost:
	.string "FLYGON and I are training for\n"
	.string "our next rematch.\p"
	.string "The pad by the wall behind me takes\n"
	.string "you back to the entrance.\p"
	.string "Bounce high, fly higher!$"
