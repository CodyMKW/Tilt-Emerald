@ PINBALL PHONE: key item that calls the Pinball Wizard's menu from anywhere.
@ Side quest in Petalburg City: a gadget tinkerer lost 3 phone parts (shiny balls lying around town).
@ VAR_TILT_PHONE: 0 not started, 1 hunting parts, 2 parts handed in (signal test needs combo 3+), 3 done

@ ---- Using the phone ----

TiltEmerald_EventScript_PhoneUse::
	msgbox TiltEmerald_Text_PhoneDial, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_WizardMenu
	end

@ ---- The tinkerer ----

TiltPhone_EventScript_Tinkerer::
	lock
	faceplayer
	goto_if_eq VAR_TILT_PHONE, 3, TiltPhone_EventScript_TinkererDone
	goto_if_eq VAR_TILT_PHONE, 2, TiltPhone_EventScript_TinkererTest
	goto_if_eq VAR_TILT_PHONE, 1, TiltPhone_EventScript_TinkererParts
	msgbox TiltPhone_Text_Intro1, MSGBOX_DEFAULT
	msgbox TiltPhone_Text_Intro2, MSGBOX_DEFAULT
	setvar VAR_TILT_PHONE, 1
	release
	end

TiltPhone_EventScript_TinkererParts::
	goto_if_unset FLAG_TILT_PART_1, TiltPhone_EventScript_StillLooking
	goto_if_unset FLAG_TILT_PART_2, TiltPhone_EventScript_StillLooking
	goto_if_unset FLAG_TILT_PART_3, TiltPhone_EventScript_StillLooking
	msgbox TiltPhone_Text_GotParts, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playse SE_PIN
	delay 40
	playse SE_PIN
	delay 40
	playse SE_SHINY
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox TiltPhone_Text_Assembled, MSGBOX_DEFAULT
	setvar VAR_TILT_PHONE, 2
	release
	end

TiltPhone_EventScript_StillLooking::
	msgbox TiltPhone_Text_StillLooking, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_TinkererTest::
	goto_if_lt VAR_TILT_COMBO, 3, TiltPhone_EventScript_TestNotYet
	msgbox TiltPhone_Text_TestPass, MSGBOX_DEFAULT
	giveitem ITEM_PINBALL_PHONE
	goto_if_eq VAR_RESULT, FALSE, TiltPhone_EventScript_NoRoom
	setvar VAR_TILT_PHONE, 3
	msgbox TiltPhone_Text_HowTo, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_NoRoom::
	msgbox TiltPhone_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_TestNotYet::
	buffernumberstring STR_VAR_1, VAR_TILT_COMBO
	msgbox TiltPhone_Text_TestNotYet, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_TinkererDone::
	msgbox TiltPhone_Text_Done, MSGBOX_DEFAULT
	release
	end

@ ---- The three glowing parts ----

TiltPhone_EventScript_Part1::
	lock
	goto_if_eq VAR_TILT_PHONE, 1, TiltPhone_EventScript_Part1Get
	msgbox TiltPhone_Text_Junk, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_Part1Get::
	setflag FLAG_TILT_PART_1
	playfanfare MUS_OBTAIN_ITEM
	msgbox TiltPhone_Text_Part1, MSGBOX_DEFAULT
	waitfanfare
	removeobject LOCALID_TILT_PART_1
	release
	end

TiltPhone_EventScript_Part2::
	lock
	goto_if_eq VAR_TILT_PHONE, 1, TiltPhone_EventScript_Part2Get
	msgbox TiltPhone_Text_Junk, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_Part2Get::
	setflag FLAG_TILT_PART_2
	playfanfare MUS_OBTAIN_ITEM
	msgbox TiltPhone_Text_Part2, MSGBOX_DEFAULT
	waitfanfare
	removeobject LOCALID_TILT_PART_2
	release
	end

TiltPhone_EventScript_Part3::
	lock
	goto_if_eq VAR_TILT_PHONE, 1, TiltPhone_EventScript_Part3Get
	msgbox TiltPhone_Text_Junk, MSGBOX_DEFAULT
	release
	end

TiltPhone_EventScript_Part3Get::
	setflag FLAG_TILT_PART_3
	playfanfare MUS_OBTAIN_ITEM
	msgbox TiltPhone_Text_Part3, MSGBOX_DEFAULT
	waitfanfare
	removeobject LOCALID_TILT_PART_3
	release
	end

@ ---- Text ----

TiltEmerald_Text_PhoneDial:
	.string "Dialing the PINBALL WIZARD...\p"
	.string "…Bzzt… Click!\p"
	.string "WIZARD: Ha! I knew it was you!\n"
	.string "The signal is crystal clear!$"

TiltPhone_Text_Intro1:
	.string "Hey, you! You look like someone who\n"
	.string "plays the table!\p"
	.string "I'm a gadget tinkerer. The PINBALL\n"
	.string "WIZARD hired me to build a phone so\l"
	.string "trainers can call him from anywhere.$"

TiltPhone_Text_Intro2:
	.string "But a TILT STORM blew through and\n"
	.string "scattered the three parts: the\l"
	.string "ANTENNA, the DIAL and the BATTERY!\p"
	.string "They're lying around town, glowing\n"
	.string "like little balls. Could you find\l"
	.string "them for me?$"

TiltPhone_Text_StillLooking:
	.string "Still missing some parts!\p"
	.string "They glow like little balls lying\n"
	.string "around Petalburg. Check the corners\l"
	.string "of town.$"

TiltPhone_Text_GotParts:
	.string "The ANTENNA, the DIAL and the\n"
	.string "BATTERY! You found them all!\p"
	.string "Hold on, let me put it together...$"

TiltPhone_Text_Assembled:
	.string "…And done! It lights up!\p"
	.string "But a phone needs a field test.\n"
	.string "The signal runs off the TILT combo.\p"
	.string "Win or catch wild Pokémon until you\n"
	.string "have a combo of 3 or more, then come\l"
	.string "back and I'll test it!$"

TiltPhone_Text_TestNotYet:
	.string "Your combo is only {STR_VAR_1}.\p"
	.string "I need 3 or more for a strong\n"
	.string "signal. Keep the ball rolling!$"

TiltPhone_Text_TestPass:
	.string "Whoa, the signal is strong! That\n"
	.string "combo does the trick!\p"
	.string "It works perfectly. Please take it,\n"
	.string "you earned it!$"

TiltPhone_Text_NoRoom:
	.string "Your bag is full! Make room in the\n"
	.string "KEY ITEMS pocket and talk to me\l"
	.string "again.$"

TiltPhone_Text_HowTo:
	.string "That's the PINBALL PHONE! Use it from\n"
	.string "your bag to call the PINBALL WIZARD.\p"
	.string "Rules, shop, heal, scores, all from\n"
	.string "anywhere! Register it to SELECT for\l"
	.string "one-button calls.$"

TiltPhone_Text_Done:
	.string "How's the phone working out?\p"
	.string "The WIZARD says it's the best\n"
	.string "thing since the flipper!$"

TiltPhone_Text_Junk:
	.string "A shiny scrap of metal. Probably\n"
	.string "just junk.$"

TiltPhone_Text_Part1:
	.string "{PLAYER} found the ANTENNA!$"

TiltPhone_Text_Part2:
	.string "{PLAYER} found the DIAL!$"

TiltPhone_Text_Part3:
	.string "{PLAYER} found the BATTERY!$"
