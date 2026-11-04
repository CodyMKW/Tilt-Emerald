@ Generated NPC scripts for Tilt mode (scattered NPCs across the region).
TiltNpc_RustboroGent_EventScript::
	msgbox TiltNpc_RustboroGent_Text_Main, MSGBOX_NPC
	end

TiltNpc_RustboroGent_Text_Main:
	.string "The DEVON CORPORATION holds the\npatent on the first TILT table.\p"
	.string "They say the inventor never lost\na ball. Not a single one.\p"
	.string "I find that hard to believe.$"

TiltNpc_RustboroSci_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B0, TiltNpc_RustboroSci_EventScript_Done
	msgbox TiltNpc_RustboroSci_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_MAX_REPEL, 3
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_RustboroSci_EventScript_Full
	giveitem ITEM_MAX_REPEL, 3
	setflag FLAG_UNUSED_0x4B0
	release
	end

TiltNpc_RustboroSci_EventScript_Done::
	msgbox TiltNpc_RustboroSci_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_RustboroSci_EventScript_Full::
	msgbox TiltNpc_RustboroSci_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_RustboroSci_Text_Intro:
	.string "I'm testing a new repellent\nformula. Results are mixed.\p"
	.string "Take these MAX REPELS.\nConsider it field research!$"

TiltNpc_RustboroSci_Text_After:
	.string "Repels keep wild POKéMON away,\nbut they can't stop a TILT.$"

TiltNpc_RustboroSci_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_SlateSailor_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B1, TiltNpc_SlateSailor_EventScript_Done
	checkitemspace ITEM_MYSTIC_WATER, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_SlateSailor_EventScript_Full
	msgbox TiltNpc_SlateSailor_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_SlateSailor_EventScript_Decline
	msgbox TiltNpc_SlateSailor_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_TENTACRUEL, 24
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_SlateSailor_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_SlateSailor_EventScript_Won
	msgbox TiltNpc_SlateSailor_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_SlateSailor_EventScript_Won::
	msgbox TiltNpc_SlateSailor_Text_Won, MSGBOX_DEFAULT
	addmoney 2000
	giveitem ITEM_MYSTIC_WATER, 1
	setflag FLAG_UNUSED_0x4B1
	release
	end

TiltNpc_SlateSailor_EventScript_Decline::
	msgbox TiltNpc_SlateSailor_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_SlateSailor_EventScript_Done::
	msgbox TiltNpc_SlateSailor_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_SlateSailor_EventScript_Full::
	msgbox TiltNpc_SlateSailor_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_SlateSailor_Text_Ask:
	.string "Ahoy! I've sailed every wave,\nbut never a bounce like this.\p"
	.string "Care for a battle on dry land?$"

TiltNpc_SlateSailor_Text_Pre:
	.string "TENTACRUEL, ride the tide!$"

TiltNpc_SlateSailor_Text_Lost:
	.string "Washed out! Come back when\nyou've found your sea legs.$"

TiltNpc_SlateSailor_Text_Won:
	.string "Shiver me timbers! Well fought!\nHere, a MYSTIC WATER.$"

TiltNpc_SlateSailor_Text_Decline:
	.string "Landlubber.$"

TiltNpc_SlateSailor_Text_After:
	.string "MYSTIC WATER boosts WATER\nmoves. Sail on, trainer!$"

TiltNpc_SlateSailor_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_SlateFisher_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B2, TiltNpc_SlateFisher_EventScript_Done
	msgbox TiltNpc_SlateFisher_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_NET_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_SlateFisher_EventScript_Full
	giveitem ITEM_NET_BALL, 5
	setflag FLAG_UNUSED_0x4B2
	release
	end

TiltNpc_SlateFisher_EventScript_Done::
	msgbox TiltNpc_SlateFisher_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_SlateFisher_EventScript_Full::
	msgbox TiltNpc_SlateFisher_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_SlateFisher_Text_Intro:
	.string "The fish don't bite today,\nbut my NET BALLS work fine.\p"
	.string "Take 5. They're great on\nWATER and BUG POKéMON!$"

TiltNpc_SlateFisher_Text_After:
	.string "Patience catches the best\nPOKéMON, my friend.$"

TiltNpc_SlateFisher_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_MauvilleFan_EventScript::
	msgbox TiltNpc_MauvilleFan_Text_Main, MSGBOX_NPC
	end

TiltNpc_MauvilleFan_Text_Main:
	.string "I saw the famous trainer FALCON\non ROUTE 104. Full level 100!\p"
	.string "Rumor says he travels to a\nhidden island after that.\p"
	.string "Only a CHAMPION can get there.\nI heard a SAILOR runs the trip.$"

TiltNpc_MauvilleBelt_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B3, TiltNpc_MauvilleBelt_EventScript_Done
	checkitemspace ITEM_QUICK_CLAW, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_MauvilleBelt_EventScript_Full
	msgbox TiltNpc_MauvilleBelt_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_MauvilleBelt_EventScript_Decline
	msgbox TiltNpc_MauvilleBelt_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_MANECTRIC, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MANECTRIC, 27
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_MauvilleBelt_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_MauvilleBelt_EventScript_Won
	msgbox TiltNpc_MauvilleBelt_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_MauvilleBelt_EventScript_Won::
	msgbox TiltNpc_MauvilleBelt_Text_Won, MSGBOX_DEFAULT
	addmoney 2500
	giveitem ITEM_QUICK_CLAW, 1
	setflag FLAG_UNUSED_0x4B3
	release
	end

TiltNpc_MauvilleBelt_EventScript_Decline::
	msgbox TiltNpc_MauvilleBelt_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_MauvilleBelt_EventScript_Done::
	msgbox TiltNpc_MauvilleBelt_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_MauvilleBelt_EventScript_Full::
	msgbox TiltNpc_MauvilleBelt_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_MauvilleBelt_Text_Ask:
	.string "My MANECTRIC runs on pure\nstatic and spite. Fight me!$"

TiltNpc_MauvilleBelt_Text_Pre:
	.string "MANECTRIC, discharge!$"

TiltNpc_MauvilleBelt_Text_Lost:
	.string "Fully charged! Try me again.$"

TiltNpc_MauvilleBelt_Text_Won:
	.string "Ow! You earned this.\nTake my QUICK CLAW.$"

TiltNpc_MauvilleBelt_Text_Decline:
	.string "Hah! Afraid of a shock?$"

TiltNpc_MauvilleBelt_Text_After:
	.string "QUICK CLAW sometimes lets you\nmove first. Use it wisely.$"

TiltNpc_MauvilleBelt_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_VerdanBloom_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B4, TiltNpc_VerdanBloom_EventScript_Done
	msgbox TiltNpc_VerdanBloom_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_LUM_BERRY, 3
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_VerdanBloom_EventScript_Full
	giveitem ITEM_LUM_BERRY, 3
	setflag FLAG_UNUSED_0x4B4
	release
	end

TiltNpc_VerdanBloom_EventScript_Done::
	msgbox TiltNpc_VerdanBloom_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_VerdanBloom_EventScript_Full::
	msgbox TiltNpc_VerdanBloom_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_VerdanBloom_Text_Intro:
	.string "The air here is so clean that\nmy berries grow extra well.\p"
	.string "Take some LUM BERRIES.\nThey cure any status problem!$"

TiltNpc_VerdanBloom_Text_After:
	.string "Hold a LUM BERRY and your\nPOKéMON can shrug off status.$"

TiltNpc_VerdanBloom_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_VerdanDream_EventScript::
	msgbox TiltNpc_VerdanDream_Text_Main, MSGBOX_NPC
	end

TiltNpc_VerdanDream_Text_Main:
	.string "Long ago I sailed to an island\nthat looked like a dream.\p"
	.string "Three masters wait on its\nrocky plateaus.\p"
	.string "Beat them in order, and a\nfourth challenger awaits...$"

TiltNpc_FallarborProf_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B5, TiltNpc_FallarborProf_EventScript_Done
	msgbox TiltNpc_FallarborProf_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_PP_UP, 2
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_FallarborProf_EventScript_Full
	giveitem ITEM_PP_UP, 2
	setflag FLAG_UNUSED_0x4B5
	release
	end

TiltNpc_FallarborProf_EventScript_Done::
	msgbox TiltNpc_FallarborProf_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_FallarborProf_EventScript_Full::
	msgbox TiltNpc_FallarborProf_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_FallarborProf_Text_Intro:
	.string "My research says moves are\nlike pinball bumpers.\p"
	.string "More power, more bounces!\nTake these PP UPS.$"

TiltNpc_FallarborProf_Text_After:
	.string "PP UP gives a move more\nuses. A busy trainer's friend.$"

TiltNpc_FallarborProf_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_LavaFlame_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B6, TiltNpc_LavaFlame_EventScript_Done
	checkitemspace ITEM_CHARCOAL, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_LavaFlame_EventScript_Full
	msgbox TiltNpc_LavaFlame_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_LavaFlame_EventScript_Decline
	msgbox TiltNpc_LavaFlame_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MAGMAR, 31
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_LavaFlame_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_LavaFlame_EventScript_Won
	msgbox TiltNpc_LavaFlame_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_LavaFlame_EventScript_Won::
	msgbox TiltNpc_LavaFlame_Text_Won, MSGBOX_DEFAULT
	addmoney 3000
	giveitem ITEM_CHARCOAL, 1
	setflag FLAG_UNUSED_0x4B6
	release
	end

TiltNpc_LavaFlame_EventScript_Decline::
	msgbox TiltNpc_LavaFlame_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_LavaFlame_EventScript_Done::
	msgbox TiltNpc_LavaFlame_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_LavaFlame_EventScript_Full::
	msgbox TiltNpc_LavaFlame_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_LavaFlame_Text_Ask:
	.string "The heat here forges strong\nPOKéMON. Want to feel it?$"

TiltNpc_LavaFlame_Text_Pre:
	.string "MAGMAR, light it up!$"

TiltNpc_LavaFlame_Text_Lost:
	.string "Too hot to handle! Try again.$"

TiltNpc_LavaFlame_Text_Won:
	.string "Scorched! I'm impressed.\nTake this CHARCOAL.$"

TiltNpc_LavaFlame_Text_Decline:
	.string "Cool off then, and return.$"

TiltNpc_LavaFlame_Text_After:
	.string "CHARCOAL powers up FIRE\nmoves. Stay hot!$"

TiltNpc_LavaFlame_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_FortreeBird_EventScript::
	msgbox TiltNpc_FortreeBird_Text_Main, MSGBOX_NPC
	end

TiltNpc_FortreeBird_Text_Main:
	.string "Up in the treetops, I hear\nthe TILT hum through the wind.\p"
	.string "Wingull, Swellow, even\nSkarmory follow the beat.\p"
	.string "They say a silver-haired man\nrides one all the way to the clouds.$"

TiltNpc_LilycoveBeauty_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B7, TiltNpc_LilycoveBeauty_EventScript_Done
	msgbox TiltNpc_LilycoveBeauty_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_LUXURY_BALL, 3
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_LilycoveBeauty_EventScript_Full
	giveitem ITEM_LUXURY_BALL, 3
	setflag FLAG_UNUSED_0x4B7
	release
	end

TiltNpc_LilycoveBeauty_EventScript_Done::
	msgbox TiltNpc_LilycoveBeauty_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_LilycoveBeauty_EventScript_Full::
	msgbox TiltNpc_LilycoveBeauty_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_LilycoveBeauty_Text_Intro:
	.string "Only the finest BALLS for a\ntrainer with such fine style.\p"
	.string "Please, accept these\nLUXURY BALLS.$"

TiltNpc_LilycoveBeauty_Text_After:
	.string "A LUXURY BALL makes POKéMON\nfriendlier, even in the wild.$"

TiltNpc_LilycoveBeauty_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_LilycoveSea_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B8, TiltNpc_LilycoveSea_EventScript_Done
	checkitemspace ITEM_DRAGON_SCALE, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_LilycoveSea_EventScript_Full
	msgbox TiltNpc_LilycoveSea_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_LilycoveSea_EventScript_Decline
	msgbox TiltNpc_LilycoveSea_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_SEADRA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SEADRA, 36
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_LilycoveSea_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_LilycoveSea_EventScript_Won
	msgbox TiltNpc_LilycoveSea_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_LilycoveSea_EventScript_Won::
	msgbox TiltNpc_LilycoveSea_Text_Won, MSGBOX_DEFAULT
	addmoney 3500
	giveitem ITEM_DRAGON_SCALE, 1
	setflag FLAG_UNUSED_0x4B8
	release
	end

TiltNpc_LilycoveSea_EventScript_Decline::
	msgbox TiltNpc_LilycoveSea_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_LilycoveSea_EventScript_Done::
	msgbox TiltNpc_LilycoveSea_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_LilycoveSea_EventScript_Full::
	msgbox TiltNpc_LilycoveSea_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_LilycoveSea_Text_Ask:
	.string "I pulled something strange from\nthe deep. Want to see it fight?$"

TiltNpc_LilycoveSea_Text_Pre:
	.string "SEADRA, rise from the deep!$"

TiltNpc_LilycoveSea_Text_Lost:
	.string "The sea always wins.$"

TiltNpc_LilycoveSea_Text_Won:
	.string "You tamed the sea itself!\nTake this DRAGON SCALE.$"

TiltNpc_LilycoveSea_Text_Decline:
	.string "The sea waits for no one.$"

TiltNpc_LilycoveSea_Text_After:
	.string "Trade a held DRAGON SCALE with a\nSEADRA to find something special.$"

TiltNpc_LilycoveSea_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_MossdeepSci_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4B9, TiltNpc_MossdeepSci_EventScript_Done
	msgbox TiltNpc_MossdeepSci_Text_Intro, MSGBOX_DEFAULT
	checkitemspace ITEM_ULTRA_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_MossdeepSci_EventScript_Full
	giveitem ITEM_ULTRA_BALL, 5
	setflag FLAG_UNUSED_0x4B9
	release
	end

TiltNpc_MossdeepSci_EventScript_Done::
	msgbox TiltNpc_MossdeepSci_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_MossdeepSci_EventScript_Full::
	msgbox TiltNpc_MossdeepSci_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_MossdeepSci_Text_Intro:
	.string "I study the stars from here.\nTonight they bounced!\p"
	.string "Take 5 ULTRA BALLS.\nAim for the strongest!$"

TiltNpc_MossdeepSci_Text_After:
	.string "ULTRA BALLS beat GREAT BALLS.\nThat's just science.$"

TiltNpc_MossdeepSci_Text_BagFull:
	.string "Your BAG is full!\nMake room and talk to me again.$"

TiltNpc_MossdeepSky_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4BA, TiltNpc_MossdeepSky_EventScript_Done
	checkitemspace ITEM_METAL_COAT, 1
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_MossdeepSky_EventScript_Full
	msgbox TiltNpc_MossdeepSky_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_MossdeepSky_EventScript_Decline
	msgbox TiltNpc_MossdeepSky_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_SKARMORY, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SKARMORY, 42
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_MossdeepSky_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_MossdeepSky_EventScript_Won
	msgbox TiltNpc_MossdeepSky_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_MossdeepSky_EventScript_Won::
	msgbox TiltNpc_MossdeepSky_Text_Won, MSGBOX_DEFAULT
	addmoney 4000
	giveitem ITEM_METAL_COAT, 1
	setflag FLAG_UNUSED_0x4BA
	release
	end

TiltNpc_MossdeepSky_EventScript_Decline::
	msgbox TiltNpc_MossdeepSky_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_MossdeepSky_EventScript_Done::
	msgbox TiltNpc_MossdeepSky_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_MossdeepSky_EventScript_Full::
	msgbox TiltNpc_MossdeepSky_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_MossdeepSky_Text_Ask:
	.string "My SKARMORY has never been\nknocked out of the sky.\p"
	.string "Think you can do it?$"

TiltNpc_MossdeepSky_Text_Pre:
	.string "SKARMORY, wings of steel!$"

TiltNpc_MossdeepSky_Text_Lost:
	.string "Grounded! Not today.$"

TiltNpc_MossdeepSky_Text_Won:
	.string "The sky bows to you.\nTake this METAL COAT.$"

TiltNpc_MossdeepSky_Text_Decline:
	.string "Then the sky stays mine.$"

TiltNpc_MossdeepSky_Text_After:
	.string "METAL COAT powers up STEEL\nmoves. Fly high!$"

TiltNpc_MossdeepSky_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

TiltNpc_SootoLore_EventScript::
	msgbox TiltNpc_SootoLore_Text_Main, MSGBOX_NPC
	end

TiltNpc_SootoLore_Text_Main:
	.string "Few people see what lies behind\nthis crater's walls.\p"
	.string "Yet I swear I saw a trainer\nwith six perfect POKéMON.\p"
	.string "They called him FALCON, and he\nnever once looked worried.$"

TiltNpc_SootoWave_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x4BB, TiltNpc_SootoWave_EventScript_Done
	checkitemspace ITEM_RARE_CANDY, 4
	goto_if_eq VAR_RESULT, FALSE, TiltNpc_SootoWave_EventScript_Full
	msgbox TiltNpc_SootoWave_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TiltNpc_SootoWave_EventScript_Decline
	msgbox TiltNpc_SootoWave_Text_Pre, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_WALREIN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_WALREIN, 46
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TiltNpc_SootoWave_EventScript_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TiltNpc_SootoWave_EventScript_Won
	msgbox TiltNpc_SootoWave_Text_Lost, MSGBOX_DEFAULT
	release
	end

TiltNpc_SootoWave_EventScript_Won::
	msgbox TiltNpc_SootoWave_Text_Won, MSGBOX_DEFAULT
	addmoney 5000
	giveitem ITEM_RARE_CANDY, 4
	setflag FLAG_UNUSED_0x4BB
	release
	end

TiltNpc_SootoWave_EventScript_Decline::
	msgbox TiltNpc_SootoWave_Text_Decline, MSGBOX_DEFAULT
	release
	end

TiltNpc_SootoWave_EventScript_Done::
	msgbox TiltNpc_SootoWave_Text_After, MSGBOX_DEFAULT
	release
	end

TiltNpc_SootoWave_EventScript_Full::
	msgbox TiltNpc_SootoWave_Text_BagFull, MSGBOX_DEFAULT
	release
	end

TiltNpc_SootoWave_Text_Ask:
	.string "The ice and sea made my\nWALREIN unbreakable.\p"
	.string "Care to test that?$"

TiltNpc_SootoWave_Text_Pre:
	.string "WALREIN, crush them!$"

TiltNpc_SootoWave_Text_Lost:
	.string "Frozen solid. Try again.$"

TiltNpc_SootoWave_Text_Won:
	.string "Magnificent! Take these RARE\nCANDIES. You have earned them.$"

TiltNpc_SootoWave_Text_Decline:
	.string "Come back when you are ready.$"

TiltNpc_SootoWave_Text_After:
	.string "RARE CANDIES: instant level up.\nDon't waste them.$"

TiltNpc_SootoWave_Text_BagFull:
	.string "Your BAG is full!\nMake room, then come back.$"

