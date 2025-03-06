EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff
	closemessage
	end

Text_RepelWoreOff::
	.string "The {STR_VAR_1}'s effect wore off…$"

EventScript_RepelWoreOffUseAnother::
	msgbox Text_RepelWoreOffUseAnother MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOffUseAnother_End
	copyvar VAR_REPEL_STEP_COUNT, VAR_0x8006
	removeitem VAR_0x8005
	playse SE_REPEL
	waitse
	msgbox Text_UsedAnotherRepel
	closemessage
EventScript_RepelWoreOffUseAnother_End::
	end

Text_RepelWoreOffUseAnother::
	.string "The {STR_VAR_1}'s effect wore off…\n"
	.string "Use another?$"

Text_UsedAnotherRepel::
	.string "{PLAYER} used another {STR_VAR_1}.$"
