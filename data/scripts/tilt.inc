@ Tilt mode scripts: post-battle combo messages (the Wizard is in tilt_wizard.inc).
@ VAR_0x8004 = combo, VAR_0x8005 = payout, VAR_0x8006 = result type, VAR_0x8007 = multiball next
@ VAR_UNUSED_0x404E = combo, VAR_UNUSED_0x4083 = best combo, VAR_UNUSED_0x408B = Ball Savers

TiltEmerald_EventScript_ComboMessage::
	lockall
	buffernumberstring STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	switch VAR_0x8006
	case 0, TiltEmerald_EventScript_MsgHit
	case 1, TiltEmerald_EventScript_MsgCoins
	case 2, TiltEmerald_EventScript_MsgCandy
	case 3, TiltEmerald_EventScript_MsgSuper
	case 4, TiltEmerald_EventScript_MsgDrain
	case 5, TiltEmerald_EventScript_MsgSaved
	releaseall
	end

TiltEmerald_EventScript_MsgHit::
	msgbox TiltEmerald_Text_Hit, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgCoins::
	msgbox TiltEmerald_Text_Coins, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgCandy::
	msgbox TiltEmerald_Text_Candy, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgSuper::
	msgbox TiltEmerald_Text_Super, MSGBOX_DEFAULT
	goto TiltEmerald_EventScript_MultiballCheck
	end

TiltEmerald_EventScript_MsgDrain::
	msgbox TiltEmerald_Text_Drain, MSGBOX_DEFAULT
	releaseall
	end

TiltEmerald_EventScript_MsgSaved::
	msgbox TiltEmerald_Text_Saved, MSGBOX_DEFAULT
	releaseall
	end

TiltEmerald_EventScript_MultiballCheck::
	call_if_eq VAR_0x8008, 1, TiltEmerald_EventScript_TicketMsg
	goto_if_eq VAR_0x8007, 1, TiltEmerald_EventScript_Multiball
	releaseall
	end

TiltEmerald_EventScript_TicketMsg::
	msgbox TiltEmerald_Text_TicketFound, MSGBOX_DEFAULT
	return

TiltEmerald_EventScript_MomHalfHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HalfHealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

TiltEmerald_EventScript_Multiball::
	msgbox TiltEmerald_Text_Multiball, MSGBOX_DEFAULT
	releaseall
	end

@ ---------------- Text ----------------

TiltEmerald_Text_TicketFound:
	.string "Lucky! A HEAL TICKET dropped!\n"
	.string "The Wizard heals for free with it.$"

TiltEmerald_Text_MomHalf:
	.string "MOM: Money's tight, honey. I can\n"
	.string "only afford half a pot of soup.\p"
	.string "Take care out there!$"

TiltEmerald_Text_Hit:
	.string "COMBO x{STR_VAR_1}!\n"
	.string "You earned ¥{STR_VAR_2}!$"

TiltEmerald_Text_Coins:
	.string "COMBO x{STR_VAR_1}! You earned\n"
	.string "¥{STR_VAR_2}!\p"
	.string "JACKPOT! You won 50 COINS!$"

TiltEmerald_Text_Candy:
	.string "COMBO x{STR_VAR_1}! You earned\n"
	.string "¥{STR_VAR_2}!\p"
	.string "MEGA JACKPOT! A RARE CANDY,\n"
	.string "100 COINS and a full heal!$"

TiltEmerald_Text_Super:
	.string "SUPER JACKPOT! COMBO x{STR_VAR_1}!\p"
	.string "You won a MASTER BALL, 250 COINS,\n"
	.string "¥{STR_VAR_2} and a full heal!$"

TiltEmerald_Text_Drain:
	.string "The ball drained!\n"
	.string "Your combo was lost...$"

TiltEmerald_Text_Saved:
	.string "The BALL SAVER kicked in!\n"
	.string "Your combo is safe!$"

TiltEmerald_Text_Multiball:
	.string "MULTIBALL!\p"
	.string "The next wild POKéMON will be\n"
	.string "SHINY!$"
