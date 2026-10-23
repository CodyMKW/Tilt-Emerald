@ Littleroot Town's brand new POKéMON CENTER (west side, below the gym).
@ Includes a POKé MART clerk working inside it, since Littleroot has no real mart yet.
@ Flags (previously unused): FLAG_UNUSED_0x031 = clerk has given his full intro

LittlerootTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LittlerootTown_PokemonCenter_1F_OnTransition:
	setflag FLAG_UNUSED_0x039
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_POKEMON_CENTER
	end

@ The upstairs is now the Pinball Wizard's cozy room (no Cable Club here).
LittlerootTown_PokemonCenter_2F_MapScripts::
	.byte 0

TiltPC_EventScript_Nurse::
	lock
	faceplayer
	getpartysize
	goto_if_eq VAR_RESULT, 0, TiltPC_EventScript_NurseNoMon
	setvar VAR_0x800B, LOCALID_TILTPC_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

@ No POKéMON yet: the healing machine would have nothing to heal (and can soft-lock), so she waits.
TiltPC_EventScript_NurseNoMon::
	msgbox TiltPC_Text_NurseNoMon, MSGBOX_DEFAULT
	release
	end

@ ---------------- POKé MART clerk ----------------

TiltPC_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x038, TiltPC_EventScript_ClerkShop
	msgbox TiltPC_Text_ClerkIntro1, MSGBOX_DEFAULT
	msgbox TiltPC_Text_ClerkIntro2, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x038
TiltPC_EventScript_ClerkShop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart TiltPC_Pokemart_Items
	msgbox TiltPC_Text_ClerkBye, MSGBOX_DEFAULT
	release
	end

	.align 2
TiltPC_Pokemart_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

@ ---------------- Excited townsfolk ----------------

TiltPC_EventScript_ExcitedWoman::
	msgbox TiltPC_Text_ExcitedWoman, MSGBOX_NPC
	end

TiltPC_EventScript_ExcitedBoy::
	msgbox TiltPC_Text_ExcitedBoy, MSGBOX_NPC
	end

TiltPC_EventScript_OldMan::
	msgbox TiltPC_Text_OldMan, MSGBOX_NPC
	end

TiltPC_EventScript_LittleGirl::
	msgbox TiltPC_Text_LittleGirl, MSGBOX_NPC
	end

TiltPC_EventScript_YardKid::
	msgbox TiltPC_Text_YardKid, MSGBOX_NPC
	end

@ ---------------- Text ----------------

TiltPC_Text_NurseNoMon:
	.string "Welcome to our POKéMON CENTER!\p"
	.string "Oh? You don't have a POKéMON with\n"
	.string "you yet.\p"
	.string "Come back once you have a partner\n"
	.string "and I'll be happy to heal them!$"

TiltPC_Text_ClerkIntro1:
	.string "Welcome to the brand-new LITTLEROOT\n"
	.string "POKé MART!\p"
	.string "You might remember me from the\n"
	.string "POKéMON CENTER.$"

TiltPC_Text_ClerkIntro2:
	.string "I used to work from a corner of the\n"
	.string "CENTER, because this town had no\l"
	.string "real MART yet.\p"
	.string "Now I finally have a proper shop\n"
	.string "with my own counter!\p"
	.string "Thanks for stopping by. Take a\n"
	.string "look around!$"

TiltPC_Text_ClerkBye:
	.string "Thank you! Come again!\n"
	.string "I'm not going anywhere. Really!$"

TiltPC_Text_ExcitedWoman:
	.string "Isn't it wonderful?\p"
	.string "LITTLEROOT finally has its very own\n"
	.string "POKéMON CENTER!\p"
	.string "I've been waiting for this day for\n"
	.string "years! I even came in just to look!$"

TiltPC_Text_ExcitedBoy:
	.string "I was the very first kid to watch\n"
	.string "the healing machine work!\p"
	.string "Ding-ding-ding! All my POKéMON were\n"
	.string "fully healed in no time!$"

TiltPC_Text_OldMan:
	.string "In my day, we had to trek all the\n"
	.string "way to PETALBURG to heal up.\p"
	.string "Now it's right down the road.\n"
	.string "Splendid. Simply splendid.$"

TiltPC_Text_LittleGirl:
	.string "The clerk moved out of the CENTER!\p"
	.string "He has his very own POKé MART across\n"
	.string "the path now.\p"
	.string "I used to say hi to him every day.\n"
	.string "Now I have to walk over there!$"

TiltPC_Text_YardKid:
	.string "They built a POKé MART right across\n"
	.string "from the POKéMON CENTER!\p"
	.string "I watched the whole time.\n"
	.string "Hammer, hammer, hammer!\p"
	.string "Now you can buy POKé BALLS and heal\n"
	.string "up in the same spot!$"

@ ---------------- LITTLEROOT POKé MART (interior) ----------------

LittlerootTown_Mart_MapScripts::
	.byte 0

TiltMart_EventScript_Woman::
	msgbox TiltMart_Text_Woman, MSGBOX_NPC
	end

TiltMart_EventScript_Boy::
	msgbox TiltMart_Text_Boy, MSGBOX_NPC
	end

TiltMart_Text_Woman:
	.string "I used to run all the way to OLDALE\n"
	.string "for supplies.\p"
	.string "A real MART in LITTLEROOT? Wonderful!$"

TiltMart_Text_Boy:
	.string "The clerk used to work in the\n"
	.string "POKéMON CENTER.\p"
	.string "Now he has his own shop. I think he\n"
	.string "likes the extra elbow room!$"
