@ Generated NPC scripts for Tilt mode (scattered NPCs across the region).
TiltNpc_CoinMimi_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x022, TiltNpc_CoinMimi_EventScript_Done
	msgbox TiltNpc_CoinMimi_Text_Intro, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message TiltNpc_CoinMimi_Text_GotCoins
	waitmessage
	waitfanfare
	addcoins 100
	setflag FLAG_UNUSED_0x022
	release
	end

TiltNpc_CoinMimi_EventScript_Done::
	msgbox TiltNpc_CoinMimi_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_CoinMimi_EventScript_Full::
	msgbox TiltNpc_CoinMimi_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_CoinMimi_Text_Intro:
	.string "Oh! A trainer with a COIN CASE?\nI have way too many COINS.\p"
	.string "Here, take 100 of them!$"

TiltNpc_CoinMimi_Text_After:
	.string "The ball loves a big COMBO.\nKeep that streak alive!$"

TiltNpc_CoinMimi_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_CoinMimi_Text_GotCoins:
	.string "{PLAYER} received 100 COINS!$"

TiltNpc_RookiePip_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x023, TiltNpc_RookiePip_EventScript_Done
	checkitemspace ITEM_POTION, 3
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_RookiePip_EventScript_Full
	msgbox TiltNpc_RookiePip_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_RookiePip_EventScript_Decline
	msgbox TiltNpc_RookiePip_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RATTATA, 5
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_RookiePip_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_RookiePip_EventScript_Won
	msgbox TiltNpc_RookiePip_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_RookiePip_EventScript_Won::
	msgbox TiltNpc_RookiePip_Text_Won, MSGBOX_DEFAULT
	addmoney 500
	giveitem ITEM_POTION, 3
	setflag FLAG_UNUSED_0x023
	release
	end

TiltNpc_RookiePip_EventScript_Decline::
	msgbox TiltNpc_RookiePip_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_RookiePip_EventScript_Done::
	msgbox TiltNpc_RookiePip_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_RookiePip_EventScript_Full::
	msgbox TiltNpc_RookiePip_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_RookiePip_Text_Ask:
	.string "Hey! Want to test your combo?\nOne bounce, one battle!$"

TiltNpc_RookiePip_Text_Pre:
	.string "Go, my trusty RATTATA!$"

TiltNpc_RookiePip_Text_Lost:
	.string "Ha! The ball drained!\nHeal up and try again!$"

TiltNpc_RookiePip_Text_Won:
	.string "Wow, what a bounce!\nTake these, you earned them.$"

TiltNpc_RookiePip_Text_Decline:
	.string "Scared of a little RATTATA?\nCome back when you're ready!$"

TiltNpc_RookiePip_Text_After:
	.string "I'll beat you next time!\nI'm training with my RATTATA.$"

TiltNpc_RookiePip_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_BargainKid_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x024, TiltNpc_BargainKid_EventScript_Done
	msgbox TiltNpc_BargainKid_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_BargainKid_EventScript_Full
	giveitem ITEM_POKE_BALL, 5
	setflag FLAG_UNUSED_0x024
	release
	end

TiltNpc_BargainKid_EventScript_Done::
	msgbox TiltNpc_BargainKid_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_BargainKid_EventScript_Full::
	msgbox TiltNpc_BargainKid_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_BargainKid_Text_Intro:
	.string "My dad runs the MART here.\nHe gave me too much stock.\p"
	.string "Take some POKé BALLS!\nCatch lots of weird POKéMON!$"

TiltNpc_BargainKid_Text_After:
	.string "Everything is random now,\nso catch whatever shows up!$"

TiltNpc_BargainKid_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_BrawlerRick_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x025, TiltNpc_BrawlerRick_EventScript_Done
	checkitemspace ITEM_GREAT_BALL, 3
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_BrawlerRick_EventScript_Full
	msgbox TiltNpc_BrawlerRick_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_BrawlerRick_EventScript_Decline
	msgbox TiltNpc_BrawlerRick_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MACHOP, 9
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_BrawlerRick_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_BrawlerRick_EventScript_Won
	msgbox TiltNpc_BrawlerRick_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_BrawlerRick_EventScript_Won::
	msgbox TiltNpc_BrawlerRick_Text_Won, MSGBOX_DEFAULT
	addmoney 1000
	giveitem ITEM_GREAT_BALL, 3
	setflag FLAG_UNUSED_0x025
	release
	end

TiltNpc_BrawlerRick_EventScript_Decline::
	msgbox TiltNpc_BrawlerRick_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_BrawlerRick_EventScript_Done::
	msgbox TiltNpc_BrawlerRick_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_BrawlerRick_EventScript_Full::
	msgbox TiltNpc_BrawlerRick_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_BrawlerRick_Text_Ask:
	.string "HOO-HAH! My MACHOP is pumped!\nCare for a quick bout?$"

TiltNpc_BrawlerRick_Text_Pre:
	.string "MACHOP, show them your guts!$"

TiltNpc_BrawlerRick_Text_Lost:
	.string "Ha! Your combo got dropped!\nTrain and return!$"

TiltNpc_BrawlerRick_Text_Won:
	.string "Incredible! Pure muscle!\nTake this, champ.$"

TiltNpc_BrawlerRick_Text_Decline:
	.string "Too soft for the ring, eh?$"

TiltNpc_BrawlerRick_Text_After:
	.string "My MACHOP and I train daily.\nNext time, I won't lose!$"

TiltNpc_BrawlerRick_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_Backpacker_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x026, TiltNpc_Backpacker_EventScript_Done
	msgbox TiltNpc_Backpacker_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_ESCAPE_ROPE, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_Backpacker_EventScript_Full
	giveitem ITEM_ESCAPE_ROPE, 1
	setflag FLAG_UNUSED_0x026
	release
	end

TiltNpc_Backpacker_EventScript_Done::
	msgbox TiltNpc_Backpacker_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_Backpacker_EventScript_Full::
	msgbox TiltNpc_Backpacker_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_Backpacker_Text_Intro:
	.string "I got lost in a cave once.\nNever again!\p"
	.string "Take this ESCAPE ROPE.\nYou never know when you'll need it.$"

TiltNpc_Backpacker_Text_After:
	.string "Caves are where the\nstrongest POKéMON hide.$"

TiltNpc_Backpacker_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_OldHand_EventScript::
	msgbox TiltNpc_OldHand_Text_Main, MSGBOX_NPC
	end

TiltNpc_OldHand_Text_Main:
	.string "A silver-haired fellow walked\nthrough here just now.\p"
	.string "He was talking about stones\nand something called a TILT.\p"
	.string "Odd fellow. Very polite, though.$"

TiltNpc_SurferSue_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x027, TiltNpc_SurferSue_EventScript_Done
	checkitemspace ITEM_MIRACLE_SEED, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_SurferSue_EventScript_Full
	msgbox TiltNpc_SurferSue_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_SurferSue_EventScript_Decline
	msgbox TiltNpc_SurferSue_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_SHROOMISH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SHROOMISH, 10
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_SurferSue_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_SurferSue_EventScript_Won
	msgbox TiltNpc_SurferSue_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_SurferSue_EventScript_Won::
	msgbox TiltNpc_SurferSue_Text_Won, MSGBOX_DEFAULT
	addmoney 1000
	giveitem ITEM_MIRACLE_SEED, 1
	setflag FLAG_UNUSED_0x027
	release
	end

TiltNpc_SurferSue_EventScript_Decline::
	msgbox TiltNpc_SurferSue_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_SurferSue_EventScript_Done::
	msgbox TiltNpc_SurferSue_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_SurferSue_EventScript_Full::
	msgbox TiltNpc_SurferSue_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_SurferSue_Text_Ask:
	.string "I bet my SHROOMISH can out-\nbounce any POKéMON in town!\p"
	.string "Want to try?$"

TiltNpc_SurferSue_Text_Pre:
	.string "SHROOMISH, spore the dance floor!$"

TiltNpc_SurferSue_Text_Lost:
	.string "Bounced right off! Try again!$"

TiltNpc_SurferSue_Text_Won:
	.string "Oh wow, you're tough!\nHere, a lucky charm.$"

TiltNpc_SurferSue_Text_Decline:
	.string "Aw, no fun!$"

TiltNpc_SurferSue_Text_After:
	.string "That MIRACLE SEED boosts\nGRASS-type moves!$"

TiltNpc_SurferSue_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_BeachBum_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x028, TiltNpc_BeachBum_EventScript_Done
	msgbox TiltNpc_BeachBum_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_SOFT_SAND, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_BeachBum_EventScript_Full
	giveitem ITEM_SOFT_SAND, 1
	setflag FLAG_UNUSED_0x028
	release
	end

TiltNpc_BeachBum_EventScript_Done::
	msgbox TiltNpc_BeachBum_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_BeachBum_EventScript_Full::
	msgbox TiltNpc_BeachBum_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_BeachBum_Text_Intro:
	.string "I've been digging sand all day.\nFound this pretty SOFT SAND.\p"
	.string "Want it? It's yours!$"

TiltNpc_BeachBum_Text_After:
	.string "It powers up GROUND-type moves.\nI just like the feel of it.$"

TiltNpc_BeachBum_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_ArtistLore_EventScript::
	msgbox TiltNpc_ArtistLore_Text_Main, MSGBOX_NPC
	end

TiltNpc_ArtistLore_Text_Main:
	.string "I'm painting the TILT!\nEverything bounces so beautifully.\p"
	.string "They say DR. GLITCH was once a\nworld-class pinball champion.\p"
	.string "He lost one tournament, and now\nhe wants the whole world to bounce.$"

TiltNpc_GymFan_EventScript::
	msgbox TiltNpc_GymFan_Text_Main, MSGBOX_NPC
	end

TiltNpc_GymFan_Text_Main:
	.string "The GYM LEADER here, NORMAN,\nhas a very bouncy style.\p"
	.string "He says the best trainers keep\ntheir combos alive.\p"
	.string "Don't let the ball drain!$"

TiltNpc_SuperLass_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x029, TiltNpc_SuperLass_EventScript_Done
	msgbox TiltNpc_SuperLass_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_SUPER_POTION, 3
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_SuperLass_EventScript_Full
	giveitem ITEM_SUPER_POTION, 3
	setflag FLAG_UNUSED_0x029
	release
	end

TiltNpc_SuperLass_EventScript_Done::
	msgbox TiltNpc_SuperLass_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_SuperLass_EventScript_Full::
	msgbox TiltNpc_SuperLass_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_SuperLass_Text_Intro:
	.string "You look like you battle a lot.\nYour POKéMON must be tired.\p"
	.string "Here, take some SUPER POTIONS!$"

TiltNpc_SuperLass_Text_After:
	.string "Healing up between fights\nkeeps combos safe.$"

TiltNpc_SuperLass_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_MazeRunner_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02A, TiltNpc_MazeRunner_EventScript_Done
	checkitemspace ITEM_AMULET_COIN, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_MazeRunner_EventScript_Full
	msgbox TiltNpc_MazeRunner_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_MazeRunner_EventScript_Decline
	msgbox TiltNpc_MazeRunner_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_MAKUHITA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MAKUHITA, 14
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_MazeRunner_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_MazeRunner_EventScript_Won
	msgbox TiltNpc_MazeRunner_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_MazeRunner_EventScript_Won::
	msgbox TiltNpc_MazeRunner_Text_Won, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN, 1
	setflag FLAG_UNUSED_0x02A
	release
	end

TiltNpc_MazeRunner_EventScript_Decline::
	msgbox TiltNpc_MazeRunner_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_MazeRunner_EventScript_Done::
	msgbox TiltNpc_MazeRunner_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_MazeRunner_EventScript_Full::
	msgbox TiltNpc_MazeRunner_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_MazeRunner_Text_Ask:
	.string "I train my MAKUHITA by slamming\ninto walls all day!\p"
	.string "Want to see the result?$"

TiltNpc_MazeRunner_Text_Pre:
	.string "MAKUHITA, harden up!$"

TiltNpc_MazeRunner_Text_Lost:
	.string "BOOM! You drained!\nTry again when you're ready.$"

TiltNpc_MazeRunner_Text_Won:
	.string "That was amazing!\nTake this AMULET COIN.$"

TiltNpc_MazeRunner_Text_Decline:
	.string "Come back when you're braver.$"

TiltNpc_MazeRunner_Text_After:
	.string "AMULET COIN doubles prize\nmoney from trainer battles.$"

TiltNpc_MazeRunner_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_NetFisher_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02B, TiltNpc_NetFisher_EventScript_Done
	msgbox TiltNpc_NetFisher_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_GREAT_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_NetFisher_EventScript_Full
	giveitem ITEM_GREAT_BALL, 5
	setflag FLAG_UNUSED_0x02B
	release
	end

TiltNpc_NetFisher_EventScript_Done::
	msgbox TiltNpc_NetFisher_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_NetFisher_EventScript_Full::
	msgbox TiltNpc_NetFisher_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_NetFisher_Text_Intro:
	.string "I netted way too many BALLS\nthis morning.\p"
	.string "Take 5 GREAT BALLS.\nThey catch things better!$"

TiltNpc_NetFisher_Text_After:
	.string "Random POKéMON mean random\nluck. Catch the good ones!$"

TiltNpc_NetFisher_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_NinjaTrav_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02C, TiltNpc_NinjaTrav_EventScript_Done
	checkitemspace ITEM_MAGNET, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_NinjaTrav_EventScript_Full
	msgbox TiltNpc_NinjaTrav_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_NinjaTrav_EventScript_Decline
	msgbox TiltNpc_NinjaTrav_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ELECTRIKE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ELECTRIKE, 14
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_NinjaTrav_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_NinjaTrav_EventScript_Won
	msgbox TiltNpc_NinjaTrav_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_NinjaTrav_EventScript_Won::
	msgbox TiltNpc_NinjaTrav_Text_Won, MSGBOX_DEFAULT
	addmoney 1500
	giveitem ITEM_MAGNET, 1
	setflag FLAG_UNUSED_0x02C
	release
	end

TiltNpc_NinjaTrav_EventScript_Decline::
	msgbox TiltNpc_NinjaTrav_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_NinjaTrav_EventScript_Done::
	msgbox TiltNpc_NinjaTrav_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_NinjaTrav_EventScript_Full::
	msgbox TiltNpc_NinjaTrav_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_NinjaTrav_Text_Ask:
	.string "My ELECTRIKE crackles with\nstatic. Fight me!$"

TiltNpc_NinjaTrav_Text_Pre:
	.string "ELECTRIKE, charge up!$"

TiltNpc_NinjaTrav_Text_Lost:
	.string "Shocked you! Try again.$"

TiltNpc_NinjaTrav_Text_Won:
	.string "Zap! You were too quick.\nTake this.$"

TiltNpc_NinjaTrav_Text_Decline:
	.string "Hmph. Coward.$"

TiltNpc_NinjaTrav_Text_After:
	.string "MAGNET powers up ELECTRIC\nmoves. Make it count.$"

TiltNpc_NinjaTrav_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_SongBard_EventScript::
	msgbox TiltNpc_SongBard_Text_Main, MSGBOX_NPC
	end

TiltNpc_SongBard_Text_Main:
	.string "The TILT! The TILT! It bounces\nthrough my song!\p"
	.string "Win, catch, cash in, repeat!\nThat's the ballad of this land!$"

