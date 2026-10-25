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
	case 6, TiltEmerald_EventScript_MsgTilt
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

TiltEmerald_EventScript_MsgTilt::
	msgbox TiltEmerald_Text_Tilt, MSGBOX_DEFAULT
	releaseall
	end

TiltEmerald_EventScript_MultiballCheck::
	call_if_eq VAR_0x8008, 1, TiltEmerald_EventScript_TicketMsg
	call_if_eq VAR_0x8009, 1, TiltEmerald_EventScript_LuckyMsg
	call_if_eq VAR_0x800A, 1, TiltEmerald_EventScript_StormMsg
	call_if_ne VAR_0x800B, 0, TiltEmerald_EventScript_BankMsg
	call_if_eq VAR_0x8002, 1, TiltEmerald_EventScript_BerryMsg
	goto_if_eq VAR_0x8003, 1, TiltEmerald_EventScript_BonusBall
	goto_if_eq VAR_0x8007, 1, TiltEmerald_EventScript_Multiball
	releaseall
	end

TiltEmerald_EventScript_LuckyMsg::
	msgbox TiltEmerald_Text_Lucky, MSGBOX_DEFAULT
	return

TiltEmerald_EventScript_StormMsg::
	msgbox TiltEmerald_Text_Storm, MSGBOX_DEFAULT
	return

TiltEmerald_EventScript_BankMsg::
	buffernumberstring STR_VAR_1, VAR_0x800B
	msgbox TiltEmerald_Text_Bank, MSGBOX_DEFAULT
	return

TiltEmerald_EventScript_BerryMsg::
	msgbox TiltEmerald_Text_BerryReady, MSGBOX_DEFAULT
	return

@ MULTIBALL bonus: a second shiny ball drops right away
TiltEmerald_EventScript_BonusBall::
	msgbox TiltEmerald_Text_BonusBall, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, TiltBonusEncounter
	goto_if_eq VAR_RESULT, FALSE, TiltEmerald_EventScript_BonusBallFail
	waitstate
	releaseall
	end

TiltEmerald_EventScript_BonusBallFail::
	msgbox TiltEmerald_Text_BonusBallFail, MSGBOX_DEFAULT
	releaseall
	end

@ ---------------- Bumpers, decay, buffs (called from step code) ----------------

TiltEmerald_EventScript_FlowerBumper::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, TiltEmerald_Movement_FlowerBumper
	waitmovement 0
	msgbox TiltEmerald_Text_Bumper, MSGBOX_AUTOCLOSE
	releaseall
	end

TiltEmerald_Movement_FlowerBumper:
	jump_in_place_down
	face_original_direction
	step_end

TiltEmerald_EventScript_Decay::
	lockall
	msgbox TiltEmerald_Text_Decay, MSGBOX_AUTOCLOSE
	releaseall
	end

TiltEmerald_EventScript_BuffEnded::
	lockall
	msgbox TiltEmerald_Text_BuffEnded, MSGBOX_AUTOCLOSE
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

TiltEmerald_Text_Tilt:
	.string "TILT! You ran and the ball drained.\n"
	.string "Your COMBO is gone.$"

TiltEmerald_Text_Lucky:
	.string "JACKPOT ROUTE! Today's winnings\n"
	.string "were tripled!$"

TiltEmerald_Text_Storm:
	.string "TILT STORM! The COMBO gain\n"
	.string "was doubled!$"

TiltEmerald_Text_Bank:
	.string "BANK SHOT! Super effective hits\n"
	.string "added +{STR_VAR_1} to the COMBO!$"

TiltEmerald_Text_BerryReady:
	.string "Berry JACKPOT! The next berry tree\n"
	.string "you pick pays out a rare berry!$"

TiltEmerald_Text_BonusBall:
	.string "MULTIBALL! A second SHINY ball\n"
	.string "drops right behind it!$"

TiltEmerald_Text_BonusBallFail:
	.string "The second ball rolled out of\n"
	.string "bounds...$"

TiltEmerald_Text_Bumper:
	.string "BUMPER! COMBO +1!$"

TiltEmerald_Text_Decay:
	.string "The ball is slowing down...\n"
	.string "COMBO -1.$"

TiltEmerald_Text_BuffEnded:
	.string "The Wizard's buff wore off.$"

TiltEmerald_Text_Multiball:
	.string "MULTIBALL!\p"
	.string "The next wild POKéMON will be\n"
	.string "SHINY!$"
