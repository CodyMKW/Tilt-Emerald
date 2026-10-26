@ Tilt Emerald: JOSEPH, the PIKACHU trainer in the Littleroot yard, and the Team Aqua tag-team story.
@
@   VAR_TILT_JOSEPH (VAR_UNUSED_0x40B8): 0 = not beaten yet, 1 = beaten (story available), 2 = story done
@   FLAG_UNUSED_0x033 = the two Aqua grunts are hidden (re-set on every map load)
@   VAR_TILT_JOSEPH 2 = Aqua story done (Joseph + Pikachu move to Petalburg City), 3 = Petalburg reunion with Cody seen
@   FLAG_UNUSED_0x036 = Petalburg reunion group (Cody, Flygon, Joseph, Pikachu) hidden
@   FLAG_UNUSED_0x037 = Joseph + Pikachu hidden in the Littleroot yard
@   FLAG_UNUSED_0x035 = story reward part 1 given (Rare Candies), FLAG_UNUSED_0x034 = reward fully given (PP Max)
@   Trainer slots 860 (JOSEPH), 861/862 (Aqua grunts, used only in the tag battle)
@
@ Nothing here starts unless the player has at least one Pokemon in the party.

TiltJoseph_EventScript_Joseph::
	lock
	faceplayer
	getpartysize
	goto_if_eq VAR_RESULT, 0, TiltJoseph_EventScript_NoMon
	goto_if_defeated TRAINER_TILT_JOSEPH, TiltJoseph_EventScript_AfterDefeat
	goto_if_ne VAR_TILT_JOSEPH, 0, TiltJoseph_EventScript_RematchPrompt
	@ Joseph is as strong as the gym leader: no battle until CODY has been beaten (talking is fine)
	goto_if_not_defeated TRAINER_TILT_CODY, TiltJoseph_EventScript_NeedCody
	msgbox TiltJoseph_Text_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltJoseph_EventScript_Decline
	trainerbattle_single TRAINER_TILT_JOSEPH, TiltJoseph_Text_Intro, TiltJoseph_Text_Defeat, TiltJoseph_EventScript_Won
	release
	end

TiltJoseph_EventScript_NeedCody::
	msgbox TiltJoseph_Text_NeedCody1, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_NeedCody2, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_NoMon::
	msgbox TiltJoseph_Text_NoMon, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_Decline::
	msgbox TiltJoseph_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_Won::
	goto_if_ne VAR_TILT_JOSEPH, 0, TiltJoseph_EventScript_RematchWon
	setvar VAR_TILT_JOSEPH, 1
	msgbox TiltJoseph_Text_Win, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_RematchWon::
	msgbox TiltJoseph_Text_RematchWin, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_AfterDefeat::
	goto_if_eq VAR_TILT_JOSEPH, 1, TiltJoseph_EventScript_StoryOffer
	goto TiltJoseph_EventScript_LorePrompt
	end

@ After the story: offer the Holy City legend, then the rematch.
TiltJoseph_EventScript_LorePrompt::
	msgbox TiltJoseph_Text_LoreAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltJoseph_EventScript_RematchPrompt
	msgbox TiltJoseph_Text_Lore1, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Lore2, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Lore3, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Lore4, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Lore5, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_RematchPrompt::
	msgbox TiltJoseph_Text_RematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltJoseph_EventScript_RematchNo
	cleartrainerflag TRAINER_TILT_JOSEPH
	trainerbattle_single TRAINER_TILT_JOSEPH, TiltJoseph_Text_RematchIntro, TiltJoseph_Text_Defeat, TiltJoseph_EventScript_Won
	release
	end

TiltJoseph_EventScript_RematchNo::
	msgbox TiltJoseph_Text_RematchNo, MSGBOX_DEFAULT
	release
	end

@ ---- Story: the Team Aqua ambush ----

TiltJoseph_EventScript_StoryOffer::
	msgbox TiltJoseph_Text_StoryOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltJoseph_EventScript_StoryNo
	msgbox TiltJoseph_Text_StoryLookOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TILTJOSEPH, Common_Movement_ExclamationMark
	waitmovement 0
	fadescreen FADE_TO_BLACK
	@ JOSEPH and the player line up side by side, both facing the grunts
	setobjectxy LOCALID_TILTJOSEPH, 11, 12
	setobjectxy OBJ_EVENT_ID_PLAYER, 11, 13
	turnobject LOCALID_TILTJOSEPH, DIR_WEST
	turnobject LOCALID_TILTJOSEPH_PIKACHU, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	clearflag FLAG_UNUSED_0x033
	addobject LOCALID_TILTJOSEPH_GRUNT1
	addobject LOCALID_TILTJOSEPH_GRUNT2
	fadescreen FADE_FROM_BLACK
	playse SE_PIN
	applymovement LOCALID_TILTJOSEPH_GRUNT1, Common_Movement_ExclamationMark
	applymovement LOCALID_TILTJOSEPH_GRUNT2, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox TiltJoseph_Text_Grunt1Taunt, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Grunt2Taunt, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_JosephReady, MSGBOX_DEFAULT
	goto TiltJoseph_EventScript_ReadyPrompt
	end

TiltJoseph_EventScript_StoryNo::
	msgbox TiltJoseph_Text_StoryNo, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_ReadyPrompt::
	msgbox TiltJoseph_Text_TeamUpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltJoseph_EventScript_ChooseParty
	msgbox TiltJoseph_Text_GruntsWait, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_UNUSED_0x033
	removeobject LOCALID_TILTJOSEPH_GRUNT1
	removeobject LOCALID_TILTJOSEPH_GRUNT2
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_TILTJOSEPH, Common_Movement_FaceDown
	applymovement LOCALID_TILTJOSEPH_PIKACHU, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox TiltJoseph_Text_HealFirst, MSGBOX_DEFAULT
	release
	end

TiltJoseph_EventScript_ChooseParty::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, TiltJoseph_EventScript_DoTagBattle
	special LoadPlayerParty
	goto TiltJoseph_EventScript_ReadyPrompt
	end

TiltJoseph_EventScript_DoTagBattle::
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_JOSEPH
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, TiltJoseph_EventScript_TagWon
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	end

TiltJoseph_EventScript_TagWon::
	msgbox TiltJoseph_Text_GruntsLose, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_UNUSED_0x033
	removeobject LOCALID_TILTJOSEPH_GRUNT1
	removeobject LOCALID_TILTJOSEPH_GRUNT2
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_TILTJOSEPH, Common_Movement_FaceDown
	applymovement LOCALID_TILTJOSEPH_PIKACHU, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox TiltJoseph_Text_TagThanks, MSGBOX_DEFAULT
	setvar VAR_TILT_JOSEPH, 2
	setvar VAR_0x8009, 0
	goto TiltJoseph_EventScript_GiveReward
	end

@ Given one at a time and remembered with a flag, so nothing is lost if the bag is full.
TiltJoseph_EventScript_GiveReward::
	goto_if_set FLAG_UNUSED_0x034, TiltJoseph_EventScript_RewardAlreadyDone
	goto_if_set FLAG_UNUSED_0x035, TiltJoseph_EventScript_RewardPPMax
	checkitemspace ITEM_RARE_CANDY, 3
	goto_if_eq VAR_RESULT, FALSE, TiltJoseph_EventScript_RewardBagFull
	giveitem ITEM_RARE_CANDY, 3
	setflag FLAG_UNUSED_0x035
TiltJoseph_EventScript_RewardPPMax::
	checkitemspace ITEM_PP_MAX
	goto_if_eq VAR_RESULT, FALSE, TiltJoseph_EventScript_RewardBagFull
	giveitem ITEM_PP_MAX
	setflag FLAG_UNUSED_0x034
	goto TiltJoseph_EventScript_Depart
	end

TiltJoseph_EventScript_RewardAlreadyDone::
	release
	end

@ Joseph and Pikachu head off to Petalburg City
TiltJoseph_EventScript_Depart::
	goto_if_eq VAR_0x8009, 1, TiltJoseph_EventScript_RewardAlreadyDone
	msgbox TiltJoseph_Text_RewardDone, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_UNUSED_0x037
	removeobject LOCALID_TILTJOSEPH
	removeobject LOCALID_TILTJOSEPH_PIKACHU
	fadescreen FADE_FROM_BLACK
	release
	end

TiltJoseph_EventScript_RewardBagFull::
	msgbox TiltJoseph_Text_BagFull, MSGBOX_DEFAULT
	release
	end

@ Trainer entries used by the tag battle (see SPECIAL_BATTLE_JOSEPH in battle_tower.c)
TiltJoseph_EventScript_Grunt1Trainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_TILT_AQUA_GRUNT_A, LOCALID_NONE, TiltJoseph_Text_Grunt1Intro, TiltJoseph_Text_Grunt1Defeat
	end

TiltJoseph_EventScript_Grunt2Trainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_TILT_AQUA_GRUNT_B, LOCALID_NONE, TiltJoseph_Text_Grunt2Intro, TiltJoseph_Text_Grunt2Defeat
	end

@ The grunts are never standing there when the map loads (also covers whiteouts mid-scene).
LittlerootTown_West_OnTransition:
	setflag FLAG_UNUSED_0x033
	clearflag FLAG_UNUSED_0x037
	call_if_ge VAR_TILT_JOSEPH, 2, TiltJoseph_EventScript_HideLittlerootJoseph
	end

TiltJoseph_EventScript_HideLittlerootJoseph::
	setflag FLAG_UNUSED_0x037
	return

@ Petalburg City: Cody, Flygon, Joseph and Pikachu only stand there once the Aqua story is done.
TiltJoseph_EventScript_PetalburgInit::
	setflag FLAG_UNUSED_0x036
	call_if_ge VAR_TILT_JOSEPH, 2, TiltJoseph_EventScript_ShowReunionGroup
	return

TiltJoseph_EventScript_ShowReunionGroup::
	clearflag FLAG_UNUSED_0x036
	return

@ JOSEPH's PIKACHU, waiting beside him
TiltJoseph_EventScript_Pikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox TiltJoseph_Text_PikachuCry, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_TILTJOSEPH_PIKACHU, DIR_SOUTH
	release
	end

TiltJoseph_Text_PikachuCry:
	.string "PIKACHU: Pika pika!$"

@ The grunts themselves do nothing if the player somehow talks to them.
TiltJoseph_EventScript_GruntIdle::
	msgbox TiltJoseph_Text_GruntIdle, MSGBOX_NPC
	end

TiltJoseph_Text_NeedCody1:
	.string "Yo! I'm JOSEPH. I train POKéMON.\n"
	.string "Mostly the electric kind.\p"
	.string "You can feel it, right? My PIKACHU\n"
	.string "and I are fully charged.$"

TiltJoseph_Text_NeedCody2:
	.string "But I'm just as strong as CODY, the\n"
	.string "GYM LEADER next door.\p"
	.string "I only battle trainers who have\n"
	.string "beaten CODY first.\p"
	.string "Come find me after you take him\n"
	.string "down. I'll be warming up!$"

TiltJoseph_Text_Challenge:
	.string "Yo! I'm JOSEPH. I train POKéMON.\n"
	.string "Mostly the electric kind.\p"
	.string "My PIKACHU and I are always up for\n"
	.string "a battle...\p"
	.string "But no pressure! Want to battle?$"

TiltJoseph_Text_Decline:
	.string "No worries! The offer stands.\n"
	.string "Come find me whenever you're ready.$"

TiltJoseph_Text_NoMon:
	.string "JOSEPH: Hey there! I'd love to chat\n"
	.string "and battle, but you don't have a\l"
	.string "POKéMON with you yet.\p"
	.string "Go get a partner first and then\n"
	.string "come find me!$"

TiltJoseph_Text_Intro:
	.string "Alright! Let's go!\p"
	.string "My PIKACHU's been charging up\n"
	.string "all day. Don't blink!$"

TiltJoseph_Text_Defeat:
	.string "Whoa! Fried by my own game!$"

TiltJoseph_Text_Win:
	.string "JOSEPH: That was electrifying!\p"
	.string "You've got real talent.\p"
	.string "Hey, come talk to me again.\n"
	.string "Something strange has been going on\l"
	.string "around town, and I could use a\l"
	.string "partner I can trust.$"

TiltJoseph_Text_RematchAsk:
	.string "JOSEPH: Back for more? My team's\n"
	.string "been training hard.\p"
	.string "Want a rematch?$"

TiltJoseph_Text_RematchNo:
	.string "JOSEPH: Sure thing. PIKACHU and I\n"
	.string "will keep charging up!$"

TiltJoseph_Text_RematchIntro:
	.string "Round two! PIKACHU, full power!$"

TiltJoseph_Text_RematchWin:
	.string "JOSEPH: Shocking! You win again!\p"
	.string "I'll get stronger. Count on it!$"

TiltJoseph_Text_StoryOffer:
	.string "JOSEPH: Hey, I'm glad you're here.\p"
	.string "I saw two shady people in blue\n"
	.string "bandanas sneaking around town.\p"
	.string "I think they're TEAM AQUA!\p"
	.string "Will you tag team with me and chase\n"
	.string "them off? Heal up first!$"

TiltJoseph_Text_StoryNo:
	.string "JOSEPH: Okay. Get ready and then\n"
	.string "talk to me again.\p"
	.string "I'll keep an eye out.$"

TiltJoseph_Text_StoryLookOut:
	.string "JOSEPH: Great! Let's...\p"
	.string "Wait. Did you hear that?$"

TiltJoseph_Text_Grunt1Taunt:
	.string "AQUA GRUNT: Hehehe! That PIKACHU is\n"
	.string "packing serious voltage!\p"
	.string "Our submarine could use a charge\n"
	.string "like that!$"

TiltJoseph_Text_Grunt2Taunt:
	.string "AQUA GRUNT: Hand over the PIKACHU,\n"
	.string "kid!\p"
	.string "Or we'll take it the hard way!$"

TiltJoseph_Text_JosephReady:
	.string "JOSEPH: Nobody's taking my buddy!\p"
	.string "Two against two. You with me?$"

TiltJoseph_Text_TeamUpAsk:
	.string "JOSEPH: Ready to team up?$"

TiltJoseph_Text_GruntsWait:
	.string "AQUA GRUNT: Hah, scared already?\n"
	.string "We'll be around, kid!$"

TiltJoseph_Text_HealFirst:
	.string "JOSEPH: They ran off. Heal up and\n"
	.string "talk to me when you're ready.$"

TiltJoseph_Text_Grunt1Intro:
	.string "Time to short-circuit you!$"

TiltJoseph_Text_Grunt1Defeat:
	.string "Gwaaah! Out of juice!$"

TiltJoseph_Text_Grunt2Intro:
	.string "Give us that PIKACHU!$"

TiltJoseph_Text_Grunt2Defeat:
	.string "This can't be! We lost!$"

TiltJoseph_Text_GruntsLose:
	.string "AQUA GRUNT: We'll tell the boss\n"
	.string "about this! You haven't seen the\l"
	.string "last of TEAM AQUA!\p"
	.string "AQUA GRUNT: Retreat! Retreat!$"

TiltJoseph_Text_TagThanks:
	.string "JOSEPH: Yeah! We did it!\p"
	.string "PIKACHU's cheering too.\p"
	.string "Thanks, partner. Please take this.$"

TiltJoseph_Text_RewardDone:
	.string "JOSEPH: I'm meeting CODY in PETALBURG\n"
	.string "CITY. Come by and say hi!\p"
	.string "And if you want a rematch, just\n"
	.string "find me there. Stay charged!$"

TiltJoseph_Text_BagFull:
	.string "JOSEPH: Your BAG is full!\n"
	.string "Make room and talk to me again.$"

TiltJoseph_Text_GruntIdle:
	.string "...$"

@ ---- Petalburg City reunion: CODY + FLYGON, JOSEPH + PIKACHU ----

@ Walking up to them starts the chat the first time (VAR_TILT_JOSEPH == 2)
TiltJoseph_EventScript_ReunionTrigger::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, TiltJoseph_EventScript_ReunionSkip
	call TiltJoseph_EventScript_ReunionBody
	releaseall
	end

TiltJoseph_EventScript_ReunionSkip::
	releaseall
	end

TiltJoseph_EventScript_ReunionBody::
	msgbox TiltJoseph_Text_Reunion1, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion2, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion3, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion4, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion5, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion6, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion7, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion8, MSGBOX_DEFAULT
	msgbox TiltJoseph_Text_Reunion9, MSGBOX_DEFAULT
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
	applymovement LOCALID_TILTREUNION_FLYGON, Common_Movement_ExclamationMark
	waitmoncry
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	applymovement LOCALID_TILTREUNION_PIKACHU, Common_Movement_ExclamationMark
	waitmoncry
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TILTREUNION_CODY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TILTREUNION_CODY, Common_Movement_FacePlayer
	applymovement LOCALID_TILTREUNION_JOSEPH, Common_Movement_FacePlayer
	waitmovement 0
	msgbox TiltJoseph_Text_Reunion10, MSGBOX_DEFAULT
	setvar VAR_TILT_JOSEPH, 3
	return

@ Talking to either of them
TiltJoseph_EventScript_JosephPetalburg::
	lock
	faceplayer
	getpartysize
	goto_if_eq VAR_RESULT, 0, TiltJoseph_EventScript_NoMon
	goto_if_unset FLAG_UNUSED_0x034, TiltJoseph_EventScript_PetalburgReward
	goto_if_eq VAR_TILT_JOSEPH, 2, TiltJoseph_EventScript_JosephReunionTalk
	goto_if_defeated TRAINER_TILT_JOSEPH, TiltJoseph_EventScript_LorePrompt
	goto TiltJoseph_EventScript_RematchPrompt
	end

TiltJoseph_EventScript_PetalburgReward::
	setvar VAR_0x8009, 1
	goto TiltJoseph_EventScript_GiveReward
	end

TiltJoseph_EventScript_JosephReunionTalk::
	call TiltJoseph_EventScript_ReunionBody
	release
	end

TiltJoseph_EventScript_CodyPetalburg::
	lock
	faceplayer
	getpartysize
	goto_if_eq VAR_RESULT, 0, TiltJoseph_EventScript_NoMon
	goto_if_eq VAR_TILT_JOSEPH, 2, TiltJoseph_EventScript_JosephReunionTalk
	msgbox TiltJoseph_Text_CodyChat, MSGBOX_DEFAULT
	applymovement LOCALID_TILTREUNION_CODY, Common_Movement_FaceRight
	waitmovement 0
	release
	end

TiltJoseph_EventScript_FlygonPetalburg::
	lock
	playmoncry SPECIES_FLYGON, CRY_MODE_NORMAL
	msgbox TiltJoseph_Text_FlygonCry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

TiltJoseph_EventScript_PikachuPetalburg::
	lock
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox TiltJoseph_Text_PikachuCry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

TiltJoseph_Text_LoreAsk:
	.string "JOSEPH: Hey! Want to hear the legend\n"
	.string "of the HOLY CITY of PIKACHUS?$"

TiltJoseph_Text_Lore1:
	.string "JOSEPH: Three years ago, I followed\n"
	.string "a thunderstorm into a hidden valley.\p"
	.string "In the middle stood a city built by\n"
	.string "PIKACHU. Lightning rods for towers.\l"
	.string "Streets that hum with static.\p"
	.string "That's the HOLY CITY of PIKACHUS.$"

TiltJoseph_Text_Lore2:
	.string "JOSEPH: The legend says the first\n"
	.string "PIKACHU stole a spark from a storm\l"
	.string "to light a lamp for a lost traveler.\p"
	.string "That lamp is the ETERNAL SPARK.\n"
	.string "It still burns in the city's heart.$"

TiltJoseph_Text_Lore3:
	.string "JOSEPH: While I was there, a huge\n"
	.string "GYARADOS rose from the lake.\p"
	.string "It was furious, and it wanted to\n"
	.string "put out the ETERNAL SPARK!$"

TiltJoseph_Text_Lore4:
	.string "JOSEPH: So my PIKACHU and I stood\n"
	.string "at the gate for three nights.\p"
	.string "Thunderbolt after Thunderbolt!\n"
	.string "The whole valley lit up like day.$"

TiltJoseph_Text_Lore5:
	.string "JOSEPH: At dawn, the GYARADOS gave\n"
	.string "up and swam away.\p"
	.string "The ETERNAL SPARK was still burning.\n"
	.string "The elders named my buddy the\l"
	.string "city's guardian.\p"
	.string "Keep it secret. Only the lightning\n"
	.string "knows the way there.$"

TiltJoseph_Text_Reunion1:
	.string "CODY: Man, I still think about that\n"
	.string "FORTNITE match, Joseph.$"

TiltJoseph_Text_Reunion2:
	.string "JOSEPH: Don't remind me! Those two\n"
	.string "players completely destroyed us.$"

TiltJoseph_Text_Reunion3:
	.string "CODY: We got wiped in thirty seconds.\n"
	.string "Thirty! I counted!$"

TiltJoseph_Text_Reunion4:
	.string "JOSEPH: They were cheating.\n"
	.string "Probably. Nobody builds a tower\l"
	.string "that fast.$"

TiltJoseph_Text_Reunion5:
	.string "CODY: Totally cheating. No way that\n"
	.string "was legit.$"

TiltJoseph_Text_Reunion6:
	.string "JOSEPH: What if we ran into them\n"
	.string "again, though?$"

TiltJoseph_Text_Reunion7:
	.string "CODY: Easy. I'm a GYM LEADER.\n"
	.string "I'd beat them in a heartbeat.$"

TiltJoseph_Text_Reunion8:
	.string "JOSEPH: Ha! I'm the trainer who\n"
	.string "protected the HOLY CITY of PIKACHUS\l"
	.string "three years ago.\p"
	.string "They wouldn't stand a chance!$"

TiltJoseph_Text_Reunion9:
	.string "CODY: Bet you lunch we'd win.\p"
	.string "JOSEPH: You're on!$"

TiltJoseph_Text_Reunion10:
	.string "CODY: Oh! Didn't see you there.\p"
	.string "JOSEPH: We were just reminiscing.\n"
	.string "Long story.\p"
	.string "If you ever want to hear about the\n"
	.string "HOLY CITY of PIKACHUS, just ask me.\p"
	.string "And I'm always up for a rematch!$"

TiltJoseph_Text_CodyChat:
	.string "CODY: Joseph still owes me lunch.\n"
	.string "I'm sure of it.\p"
	.string "FLYGON and I are training hard.\n"
	.string "Come by the GYM anytime!$"

TiltJoseph_Text_FlygonCry:
	.string "FLYGON: Flyyy-gon!$"
