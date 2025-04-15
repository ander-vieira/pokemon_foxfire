Route4_MapScripts::
	.byte 0

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_Boy::
	lock
	faceplayer
	famechecker FAMECHECKER_BROCK, 3
	msgbox Route4_Text_PeopleLikeAndRespectBrock
	release
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_EventScript_PunchesTutor::
	lock
	faceplayer
	message Route4_Text_PunchesTutor_WhichMove
	waitmessage
	multichoice 0, 0, MULTICHOICE_TUTOR_PUNCHES, FALSE
	switch VAR_RESULT
	case 0, Route4_EventScript_PunchesTutor_IcePunch
	case 1, Route4_EventScript_PunchesTutor_ThunderPunch
	case 2, Route4_EventScript_PunchesTutor_FirePunch
	case 3, Route4_EventScript_PunchesTutor_Declined
	release
	end

Route4_EventScript_PunchesTutor_IcePunch::
	setvar VAR_0x8005, TUTOR_MOVE_ICE_PUNCH
	goto Route4_EventScript_PunchesTutor_Continue

Route4_EventScript_PunchesTutor_ThunderPunch::
	setvar VAR_0x8005, TUTOR_MOVE_THUNDER_PUNCH
	goto Route4_EventScript_PunchesTutor_Continue

Route4_EventScript_PunchesTutor_FirePunch::
	setvar VAR_0x8005, TUTOR_MOVE_FIRE_PUNCH
	goto Route4_EventScript_PunchesTutor_Continue

Route4_EventScript_PunchesTutor_Continue::
	msgbox Route4_Text_PunchesTutor_WhichMon
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, Route4_EventScript_PunchesTutor_Declined
	msgbox Route4_Text_PunchesTutor_Done
	release
	end

Route4_EventScript_PunchesTutor_Declined::
	msgbox Route4_Text_PunchesTutor_Declined
	release
	end
