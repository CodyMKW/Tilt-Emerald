@ Oldale Town mini story: "The TILT-O-TRON Incident"
@ Story state is VAR_UNUSED_0x409B:
@   0 = not started        1 = intro done (go see Dr. Glitch)
@   2 = boss beaten        3 = Voltorb received from Nova
@   4 = story complete (Nova's Bumper Spin and Glitch rematches unlock)
@ VAR_UNUSED_0x408B = Ball Savers owned

@ ---------------- Cutscene trigger (steps onto Oldale's south crossing) ----------------

TiltEmerald_EventScript_StoryTrigger::
	lockall
	applymovement LOCALID_TILT_NOVA, Common_Movement_ExclamationMark
	waitmovement 0
	@ Nova runs up to wherever the player is standing on the crossing
	getplayerxy VAR_0x8004, VAR_0x8005
	switch VAR_0x8004
	case 2, TiltEmerald_EventScript_NovaRush2
	case 3, TiltEmerald_EventScript_NovaRush3
	case 4, TiltEmerald_EventScript_NovaRush4
	case 9, TiltEmerald_EventScript_NovaRush9
	case 10, TiltEmerald_EventScript_NovaRush10
	case 11, TiltEmerald_EventScript_NovaRush11
	case 12, TiltEmerald_EventScript_NovaRush12
	case 13, TiltEmerald_EventScript_NovaRush13
	goto TiltEmerald_EventScript_NovaRush11

TiltEmerald_EventScript_NovaRush2::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush2
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush3::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush3
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush4::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush4
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush9::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush9
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush10::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush10
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush11::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush11
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush12::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush12
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaRush13::
	applymovement LOCALID_TILT_NOVA, TiltEmerald_Movement_NovaRush13
	waitmovement 0
	goto TiltEmerald_EventScript_NovaArrived

TiltEmerald_EventScript_NovaArrived::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_TILT_NOVA, Common_Movement_FaceDown
	waitmovement 0
	call TiltEmerald_EventScript_IntroBody
	releaseall
	end

TiltEmerald_Movement_NovaRush2:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

TiltEmerald_Movement_NovaRush3:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

TiltEmerald_Movement_NovaRush4:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

TiltEmerald_Movement_NovaRush9:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

TiltEmerald_Movement_NovaRush10:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	step_end

TiltEmerald_Movement_NovaRush11:
	walk_fast_down
	walk_fast_down
	step_end

TiltEmerald_Movement_NovaRush12:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

TiltEmerald_Movement_NovaRush13:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	step_end

TiltEmerald_EventScript_IntroBody::
	msgbox TiltEmerald_Text_NovaMeet1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_NovaMeet2, MSGBOX_DEFAULT
	applymovement LOCALID_TILT_BUMPER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox TiltEmerald_Text_BumperMeet, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_NovaLore1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_NovaLore2, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_NovaAsk, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message TiltEmerald_Text_GotSaver
	waitmessage
	waitfanfare
	addvar VAR_UNUSED_0x408B, 1
	msgbox TiltEmerald_Text_NovaGo, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x409B, 1
	return

@ ---------------- Nova ----------------

TiltEmerald_EventScript_Nova::
	lock
	faceplayer
	switch VAR_UNUSED_0x409B
	case 0, TiltEmerald_EventScript_NovaIntro
	case 1, TiltEmerald_EventScript_NovaGoGlitch
	case 2, TiltEmerald_EventScript_NovaReward
	case 3, TiltEmerald_EventScript_NovaGoBumper
	case 4, TiltEmerald_EventScript_NovaSpin
	release
	end

TiltEmerald_EventScript_NovaIntro::
	call TiltEmerald_EventScript_IntroBody
	release
	end

TiltEmerald_EventScript_NovaGoGlitch::
	msgbox TiltEmerald_Text_NovaReminder, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_NovaGoBumper::
	msgbox TiltEmerald_Text_NovaGoBumper, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_NovaReward::
	msgbox TiltEmerald_Text_NovaProud, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VOLTORB
	givemon SPECIES_VOLTORB, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, TiltEmerald_EventScript_VoltorbParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, TiltEmerald_EventScript_VoltorbPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

TiltEmerald_EventScript_VoltorbParty::
	call TiltEmerald_EventScript_VoltorbFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_VoltorbDone
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto TiltEmerald_EventScript_VoltorbDone
	end

TiltEmerald_EventScript_VoltorbPC::
	call TiltEmerald_EventScript_VoltorbFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_VoltorbToPC
	call Common_EventScript_NameReceivedBoxMon
	goto TiltEmerald_EventScript_VoltorbToPC
	end

TiltEmerald_EventScript_VoltorbToPC::
	call Common_EventScript_TransferredToPC
	goto TiltEmerald_EventScript_VoltorbDone
	end

TiltEmerald_EventScript_VoltorbFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message TiltEmerald_Text_ObtainedVoltorb
	waitmessage
	waitfanfare
	return

TiltEmerald_EventScript_VoltorbDone::
	setvar VAR_UNUSED_0x409B, 3
	msgbox TiltEmerald_Text_NovaVoltorbDone, MSGBOX_DEFAULT
	release
	end

@ ---------------- Nova's Bumper Spin (after the story) ----------------

TiltEmerald_EventScript_NovaSpin::
	msgbox TiltEmerald_Text_SpinIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_SpinBye
TiltEmerald_EventScript_SpinStart::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, 50, TiltEmerald_EventScript_SpinNoCoins
	random 6
	switch VAR_RESULT
	case 0, TiltEmerald_EventScript_Prize0
	case 1, TiltEmerald_EventScript_Prize1
	case 2, TiltEmerald_EventScript_Prize2
	case 3, TiltEmerald_EventScript_Prize3
	case 4, TiltEmerald_EventScript_Prize4
	case 5, TiltEmerald_EventScript_Prize5
	goto TiltEmerald_EventScript_SpinBye
	end

TiltEmerald_EventScript_Prize0::
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_SpinBagFull
	removecoins 50
	msgbox TiltEmerald_Text_SpinRolling, MSGBOX_DEFAULT
	playse SE_PIN
	giveitem ITEM_NUGGET
	goto TiltEmerald_EventScript_SpinAgain
	end

TiltEmerald_EventScript_Prize1::
	checkitemspace ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_SpinBagFull
	removecoins 50
	msgbox TiltEmerald_Text_SpinRolling, MSGBOX_DEFAULT
	playse SE_PIN
	giveitem ITEM_RARE_CANDY
	goto TiltEmerald_EventScript_SpinAgain
	end

TiltEmerald_EventScript_Prize2::
	checkitemspace ITEM_PP_UP
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_SpinBagFull
	removecoins 50
	msgbox TiltEmerald_Text_SpinRolling, MSGBOX_DEFAULT
	playse SE_PIN
	giveitem ITEM_PP_UP
	goto TiltEmerald_EventScript_SpinAgain
	end

TiltEmerald_EventScript_Prize3::
	checkitemspace ITEM_MAX_REVIVE
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_SpinBagFull
	removecoins 50
	msgbox TiltEmerald_Text_SpinRolling, MSGBOX_DEFAULT
	playse SE_PIN
	giveitem ITEM_MAX_REVIVE
	goto TiltEmerald_EventScript_SpinAgain
	end

TiltEmerald_EventScript_Prize4::
	removecoins 50
	msgbox TiltEmerald_Text_SpinRolling, MSGBOX_DEFAULT
	playse SE_PIN
	addvar VAR_UNUSED_0x408B, 1
	msgbox TiltEmerald_Text_SpinSaver, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_SpinAgain
	end

TiltEmerald_EventScript_Prize5::
	removecoins 50
	msgbox TiltEmerald_Text_SpinRolling, MSGBOX_DEFAULT
	addcoins 25
	msgbox TiltEmerald_Text_SpinDud, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_SpinAgain
	end

TiltEmerald_EventScript_SpinAgain::
	msgbox TiltEmerald_Text_SpinAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TiltEmerald_EventScript_SpinStart
	goto TiltEmerald_EventScript_SpinBye
	end

TiltEmerald_EventScript_SpinNoCoins::
	msgbox TiltEmerald_Text_SpinNoCoins, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_SpinBagFull::
	msgbox TiltEmerald_Text_SpinBagFull, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_SpinBye::
	msgbox TiltEmerald_Text_SpinBye, MSGBOX_DEFAULT
	release
	end

@ ---------------- Bumper ----------------

TiltEmerald_EventScript_Bumper::
	lock
	faceplayer
	switch VAR_UNUSED_0x409B
	case 0, TiltEmerald_EventScript_Bumper0
	case 1, TiltEmerald_EventScript_Bumper1
	case 2, TiltEmerald_EventScript_Bumper2
	case 3, TiltEmerald_EventScript_BumperReward
	case 4, TiltEmerald_EventScript_BumperTips
	release
	end

TiltEmerald_EventScript_Bumper0::
	msgbox TiltEmerald_Text_Bumper0, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_Bumper1::
	msgbox TiltEmerald_Text_Bumper1, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_Bumper2::
	msgbox TiltEmerald_Text_Bumper2, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_BumperReward::
	msgbox TiltEmerald_Text_BumperReward1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message TiltEmerald_Text_GotThreeSavers
	waitmessage
	waitfanfare
	addvar VAR_UNUSED_0x408B, 3
	setvar VAR_UNUSED_0x409B, 4
	msgbox TiltEmerald_Text_BumperReward2, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_BumperTips::
	random 4
	switch VAR_RESULT
	case 0, TiltEmerald_EventScript_BumperTip0
	case 1, TiltEmerald_EventScript_BumperTip1
	case 2, TiltEmerald_EventScript_BumperTip2
	case 3, TiltEmerald_EventScript_BumperTip3
	release
	end

TiltEmerald_EventScript_BumperTip0::
	msgbox TiltEmerald_Text_BumperTip0, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_BumperTip1::
	msgbox TiltEmerald_Text_BumperTip1, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_BumperTip2::
	msgbox TiltEmerald_Text_BumperTip2, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_BumperTip3::
	msgbox TiltEmerald_Text_BumperTip3, MSGBOX_DEFAULT
	release
	end

@ ---------------- Dr. Glitch ----------------

TiltEmerald_EventScript_Glitch::
	lock
	faceplayer
	switch VAR_UNUSED_0x409B
	case 0, TiltEmerald_EventScript_Glitch0
	case 1, TiltEmerald_EventScript_GlitchBoss
	case 2, TiltEmerald_EventScript_GlitchAfter
	case 3, TiltEmerald_EventScript_GlitchAfter
	case 4, TiltEmerald_EventScript_GlitchRematch
	release
	end

TiltEmerald_EventScript_Glitch0::
	msgbox TiltEmerald_Text_Glitch0, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_GlitchAfter::
	msgbox TiltEmerald_Text_GlitchAfter, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_GlitchBoss::
	msgbox TiltEmerald_Text_GlitchIntro1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_GlitchIntro2, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_GlitchIntro3, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MAGNEMITE, 8
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltEmerald_EventScript_GlitchBeaten
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltEmerald_EventScript_GlitchBeaten
	msgbox TiltEmerald_Text_GlitchRetry, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_GlitchBeaten::
	msgbox TiltEmerald_Text_GlitchLose1, MSGBOX_DEFAULT
	msgbox TiltEmerald_Text_GlitchLose2, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	setvar VAR_UNUSED_0x409B, 2
	msgbox TiltEmerald_Text_GlitchLose3, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_GlitchRematch::
	msgbox TiltEmerald_Text_GlitchRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltEmerald_EventScript_GlitchRematchNo
	waitse
	playmoncry SPECIES_MAGNETON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MAGNETON, 22
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltEmerald_EventScript_GlitchRematchWon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltEmerald_EventScript_GlitchRematchWon
	msgbox TiltEmerald_Text_GlitchRematchLost, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_GlitchRematchWon::
	addmoney 2000
	msgbox TiltEmerald_Text_GlitchRematchWon, MSGBOX_DEFAULT
	release
	end

TiltEmerald_EventScript_GlitchRematchNo::
	msgbox TiltEmerald_Text_GlitchRematchNo, MSGBOX_DEFAULT
	release
	end

@ ---------------- Text ----------------

TiltEmerald_Text_NovaMeet1:
	.string "H-hey! You there!\p"
	.string "Are you {PLAYER}? The trainer the\n"
	.string "PINBALL WIZARD told me about?$"

TiltEmerald_Text_NovaMeet2:
	.string "I'm NOVA, the Wizard's apprentice!\p"
	.string "And that grumpy guy over there\n"
	.string "is BUMPER, keeper of the tables.$"

TiltEmerald_Text_BumperMeet:
	.string "BUMPER: Hmph. Another kid with\n"
	.string "a combo dream.\p"
	.string "...Fine. This one might actually\n"
	.string "have the nerve for it.$"

TiltEmerald_Text_NovaLore1:
	.string "Listen, {PLAYER}. Have you noticed\n"
	.string "the wild POKéMON acting weird?\p"
	.string "That's no accident! Everything\n"
	.string "has been TILTED.$"

TiltEmerald_Text_NovaLore2:
	.string "It's a machine called the\n"
	.string "TILT-O-TRON.\p"
	.string "DR. GLITCH built it to prove the\n"
	.string "world is one giant pinball table.\p"
	.string "He shook the whole region, and\n"
	.string "now every POKéMON bounces around!$"

TiltEmerald_Text_NovaAsk:
	.string "He's waiting at the north end of\n"
	.string "town, by the ROUTE 103 exit.\p"
	.string "Please, make him shut it off!\n"
	.string "Here, take this. You'll need it.$"

TiltEmerald_Text_GotSaver:
	.string "{PLAYER} received a BALL SAVER!$"

TiltEmerald_Text_NovaGo:
	.string "A BALL SAVER blocks one drain, so\n"
	.string "your combo survives. Use it wisely!\p"
	.string "Go find DR. GLITCH. I believe\n"
	.string "in you!$"

TiltEmerald_Text_NovaReminder:
	.string "DR. GLITCH is at the north end of\n"
	.string "town. Mind his TILT-BOT!\p"
	.string "Go heal up first if you need to.$"

TiltEmerald_Text_NovaProud:
	.string "You did it?! You beat the\n"
	.string "TILT-BOT?!\p"
	.string "I knew it! The Wizard picks the\n"
	.string "right people.\p"
	.string "Here, a thank-you from me.\n"
	.string "He's a real bumper at heart!$"

TiltEmerald_Text_ObtainedVoltorb:
	.string "{PLAYER} received VOLTORB!$"

TiltEmerald_Text_NovaVoltorbDone:
	.string "VOLTORB looks like a ball, but it\n"
	.string "bounces like a champ.\p"
	.string "Go show BUMPER. He wants to say\n"
	.string "something to you.$"

TiltEmerald_Text_NovaGoBumper:
	.string "BUMPER wants a word with you.\n"
	.string "Don't make him wait!$"

TiltEmerald_Text_SpinIntro:
	.string "Welcome back, {PLAYER}!\p"
	.string "Want to spin the BUMPER WHEEL?\n"
	.string "It costs 50 COINS a spin.$"

TiltEmerald_Text_SpinRolling:
	.string "Round and round it goes...$"

TiltEmerald_Text_SpinSaver:
	.string "You won a BALL SAVER!$"

TiltEmerald_Text_SpinDud:
	.string "TILT! The wheel jammed.\n"
	.string "Here's 25 COINS back.$"

TiltEmerald_Text_SpinAgain:
	.string "Spin again for 50 COINS?$"

TiltEmerald_Text_SpinNoCoins:
	.string "You need 50 COINS to spin.\n"
	.string "The GAME CORNER can help!$"

TiltEmerald_Text_SpinBagFull:
	.string "Your BAG is full! Make some room\n"
	.string "and I'll spin it for you.$"

TiltEmerald_Text_SpinBye:
	.string "Come back anytime. The wheel\n"
	.string "never sleeps!$"

TiltEmerald_Text_Bumper0:
	.string "BUMPER: Hmph.\p"
	.string "Talk to NOVA first, kid.\n"
	.string "She does the explaining.$"

TiltEmerald_Text_Bumper1:
	.string "BUMPER: GLITCH is up north.\p"
	.string "His TILT-BOT is rough, but you\n"
	.string "can run if it gets bad.$"

TiltEmerald_Text_Bumper2:
	.string "BUMPER: Beat him already?\n"
	.string "Then go see NOVA.$"

TiltEmerald_Text_BumperReward1:
	.string "BUMPER: So you shut that machine\n"
	.string "up. Not bad.\p"
	.string "I've kept these tables running\n"
	.string "for forty years.\p"
	.string "Take these. A table keeper always\n"
	.string "rewards a good player.$"

TiltEmerald_Text_GotThreeSavers:
	.string "{PLAYER} received 3 BALL SAVERS!$"

TiltEmerald_Text_BumperReward2:
	.string "BUMPER: Now the whole region is\n"
	.string "a pinball table, and you're the\l"
	.string "ball. Don't drain.\p"
	.string "NOVA runs the BUMPER WHEEL now,\n"
	.string "and GLITCH wants a rematch.$"

TiltEmerald_Text_BumperTip0:
	.string "BUMPER: Past combo 20, wild\n"
	.string "POKéMON get mean. Bring healing.$"

TiltEmerald_Text_BumperTip1:
	.string "BUMPER: A MULTIBALL shiny always\n"
	.string "follows the 7th hit. Count!$"

TiltEmerald_Text_BumperTip2:
	.string "BUMPER: Save your BALL SAVERS for\n"
	.string "high combos. That's where it hurts.$"

TiltEmerald_Text_BumperTip3:
	.string "BUMPER: GLITCH pays for rematches.\n"
	.string "Don't ask me why.$"

TiltEmerald_Text_Glitch0:
	.string "Shoo, kid! I'm calibrating!\p"
	.string "...Did NOVA send you? Go talk\n"
	.string "to her first.$"

TiltEmerald_Text_GlitchIntro1:
	.string "Hm? Ah, the famous combo kid.\p"
	.string "I am DR. GLITCH! Do you know what\n"
	.string "the universe really is?$"

TiltEmerald_Text_GlitchIntro2:
	.string "One giant PINBALL TABLE!\p"
	.string "And my TILT-O-TRON gave it a\n"
	.string "magnificent shake!\p"
	.string "Now every POKéMON bounces\n"
	.string "wherever it likes!$"

TiltEmerald_Text_GlitchIntro3:
	.string "You want it fixed? Then defeat\n"
	.string "my prototype, the TILT-BOT!\p"
	.string "Behold, MAGNEMITE, charged to\n"
	.string "the max!$"

TiltEmerald_Text_GlitchRetry:
	.string "Running away? How unbecoming.\p"
	.string "Come back when you're ready.\n"
	.string "The TILT-BOT will wait.$"

TiltEmerald_Text_GlitchLose1:
	.string "Impossible!\p"
	.string "My beautiful TILT-BOT, bested by\n"
	.string "a kid?!$"

TiltEmerald_Text_GlitchLose2:
	.string "Fine, fine. The TILT-O-TRON can't\n"
	.string "be un-tilted anyway.\p"
	.string "But admit it, the wild POKéMON are\n"
	.string "more fun this way. Free cash!\p"
	.string "Take this prototype as an apology.$"

TiltEmerald_Text_GlitchLose3:
	.string "Now go tell NOVA the good news.\n"
	.string "I'll be here, recalibrating.$"

TiltEmerald_Text_GlitchAfter:
	.string "Recalibrating... Don't mind me.\p"
	.string "Go tell NOVA, and maybe BUMPER\n"
	.string "too.$"

TiltEmerald_Text_GlitchRematchAsk:
	.string "Back for more? My new MAGNETON\n"
	.string "is stronger than ever!\p"
	.string "Win and I'll pay you ¥2000.\n"
	.string "Want a rematch?$"

TiltEmerald_Text_GlitchRematchWon:
	.string "Gah! Another loss!\p"
	.string "Here's your ¥2000. My research\n"
	.string "grant is cursed...$"

TiltEmerald_Text_GlitchRematchLost:
	.string "Hahaha! The universe bounces\n"
	.string "back! Try again anytime.$"

TiltEmerald_Text_GlitchRematchNo:
	.string "Coward! The table awaits...$"
