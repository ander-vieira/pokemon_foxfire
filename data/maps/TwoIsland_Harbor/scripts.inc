TwoIsland_Harbor_MapScripts::
	.byte 0

TwoIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_TWO_ISLAND
	goto EventScript_SeviiDestinationsPage1
	end
