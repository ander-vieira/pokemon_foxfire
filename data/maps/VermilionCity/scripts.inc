.equ LOCALID_FERRY_SAILOR, 6
.equ LOCALID_CELIO, 8

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	end

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	switch VAR_MAP_SCENE_VERMILION_CITY
	case 0, VermilionCity_EventScript_FerrySailor_Welcome
	case 1, VermilionCity_EventScript_FerrySailor_Welcome
	case 2, VermilionCity_EventScript_FerrySailor_Welcome
	case 3, VermilionCity_EventScript_FerrySailor_SetSail
	call VermilionCity_EventScript_CheckHasMysticTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	goto EventScript_SeviiDestinationsPage1

VermilionCity_EventScript_FerrySailor_Welcome::
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_FerrySailor_SetSail::
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_CheckHasMysticTicket::
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckHasAuroraTicket::
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_HasMysticTicket::
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_ReleaseEnd
	case 127, EventScript_ReleaseEnd
	end

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	return

VermilionCity_EventScript_HasAuroraTicket::
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_ReleaseEnd
	case 127, EventScript_ReleaseEnd
	end

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	return

VermilionCity_EventScript_HasMysticAndAuroraTickets::
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_SailToBirthIsland
	case 3, EventScript_ReleaseEnd
	case 127, EventScript_ReleaseEnd
	end

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_CheckSSTicket::
	lockall
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox VermilionCity_Text_CheckSSTicket
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	releaseall
	end

VermilionCity_EventScript_Celio_Left::
	lockall
	applymovement LOCALID_CELIO, VermilionCity_Movement_CelioNorth_Left_Enter
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_CelioNorth_Left_WatchEnter
	waitmovement LOCALID_CELIO
	waitmovement OBJ_EVENT_ID_PLAYER
	call VermilionCity_EventScript_Celio
	applymovement LOCALID_CELIO, VermilionCity_Movement_CelioNorth_Left_Exit
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_CelioNorth_Left_WatchExit
	waitmovement LOCALID_CELIO
	waitmovement OBJ_EVENT_ID_PLAYER
	removeobject LOCALID_CELIO
	releaseall
	end

VermilionCity_Movement_CelioNorth_Left_Enter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

VermilionCity_Movement_CelioNorth_Left_WatchEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end

VermilionCity_Movement_CelioNorth_Left_Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_CelioNorth_Left_WatchExit::
	delay_16
	face_down
	step_end

VermilionCity_EventScript_Celio_Center::
	lockall
	applymovement LOCALID_CELIO, VermilionCity_Movement_CelioNorth_Center_Enter
	waitmovement LOCALID_CELIO
	call VermilionCity_EventScript_Celio
	applymovement LOCALID_CELIO, VermilionCity_Movement_CelioNorth_Center_Exit
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_CelioNorth_Center_WatchExit
	waitmovement LOCALID_CELIO
	waitmovement OBJ_EVENT_ID_PLAYER
	removeobject LOCALID_CELIO
	releaseall
	end

VermilionCity_Movement_CelioNorth_Center_Enter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_CelioNorth_Center_Exit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_CelioNorth_Center_WatchExit::
	delay_16
	face_right
	delay_16
	face_down
	step_end

VermilionCity_EventScript_Celio_Right::
	lockall
	applymovement LOCALID_CELIO, VermilionCity_Movement_CelioNorth_Right_Enter
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_CelioNorth_Right_WatchEnter
	waitmovement LOCALID_CELIO
	waitmovement OBJ_EVENT_ID_PLAYER
	call VermilionCity_EventScript_Celio
	applymovement LOCALID_CELIO, VermilionCity_Movement_CelioNorth_Right_Exit
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_CelioNorth_Right_WatchExit
	waitmovement LOCALID_CELIO
	waitmovement OBJ_EVENT_ID_PLAYER
	removeobject LOCALID_CELIO
	releaseall
	end

VermilionCity_Movement_CelioNorth_Right_Enter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

VermilionCity_Movement_CelioNorth_Right_WatchEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	step_end

VermilionCity_Movement_CelioNorth_Right_Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_Movement_CelioNorth_Right_WatchExit::
	delay_16
	face_down
	step_end

VermilionCity_EventScript_Celio::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox VermilionCity_Text_Celio MSGBOX_NPC
	giveitem ITEM_RAINBOW_PASS
	closemessage
	setvar VAR_MAP_SCENE_VERMILION_CITY, 4
	return
