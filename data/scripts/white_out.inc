EventScript_AfterWhiteOutHeal::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	msgbox Text_MonsHealed
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

@ LOCALID_MOM set by PalletTown_PlayersHouse_1F

EventScript_AfterWhiteOutMomHeal::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Text_HadQuiteAnExperienceTakeRest
	call EventScript_OutOfCenterPartyHeal
	msgbox Text_MomExplainHPGetPotions
	fadedefaultbgm
	releaseall
	end
