CeladonCity_DepartmentStore_5F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_CheckOften, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_WhatTMs, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_TMCorner, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkTMsUpper::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_TMsUpper
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_TMsUpper::
	.2byte ITEM_TM07
	.2byte ITEM_TM10
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM40
	.2byte ITEM_TM42
	.2byte ITEM_TM46
	.2byte ITEM_TM47
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkTMsMiddle::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_TMsMiddle
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_TMsMiddle::
	.2byte ITEM_TM03
	.2byte ITEM_TM04
	.2byte ITEM_TM06
	.2byte ITEM_TM19
	.2byte ITEM_TM34
	.2byte ITEM_TM39
	.2byte ITEM_TM38
	.2byte ITEM_TM26
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkTMsLower::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_TMsLower
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_TMsLower::
	.2byte ITEM_TM05
	.2byte ITEM_TM16
	.2byte ITEM_TM17
	.2byte ITEM_TM32
	.2byte ITEM_TM33
	.2byte ITEM_TM43
	.2byte ITEM_NONE
	release
	end
