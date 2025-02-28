#include "global.h"
#include "gflib.h"
#include "event_data.h"
#include "event_scripts.h"
#include "fldeff.h"
#include "field_effect.h"
#include "map_preview_screen.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "constants/songs.h"
#include "constants/map_types.h"

struct FlashStruct
{
    u8 fromType;
    u8 toType;
    bool8 isEnter;
    bool8 isExit;
};

static void FieldCallback_Flash(void);
static void FldEff_UseFlash(void);
static bool8 TryDoMapTransition(void);
static void FlashTransition_Exit(void);
static void Task_FlashTransition_Exit_1(u8 taskId);
static void Task_FlashTransition_Exit_2(u8 taskId);
static void Task_FlashTransition_Exit_3(u8 taskId);
static void FlashTransition_Enter(void);
static void Task_FlashTransition_Enter_1(u8 taskId);
static void Task_FlashTransition_Enter_2(u8 taskId);
static void Task_FlashTransition_Enter_3(u8 taskId);

static const struct FlashStruct sTransitionTypes[] = {
    {
        .fromType = MAP_TYPE_TOWN,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_CITY,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_ROUTE,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_UNDERWATER,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_OCEAN_ROUTE,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_UNKNOWN,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_INDOOR,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_SECRET_BASE,
        .toType = MAP_TYPE_UNDERGROUND,
        .isEnter = TRUE,
        .isExit = FALSE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_TOWN,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_CITY,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_ROUTE,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_UNDERWATER,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_OCEAN_ROUTE,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_UNKNOWN,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_INDOOR,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {
        .fromType = MAP_TYPE_UNDERGROUND,
        .toType = MAP_TYPE_SECRET_BASE,
        .isEnter = FALSE,
        .isExit = TRUE
    }, {0}
};

static const u16 sCaveTransitionPalette_White[] = INCBIN_U16("graphics/cave_transition/white.gbapal");
static const u16 sCaveTransitionPalette_Black[] = INCBIN_U16("graphics/cave_transition/black.gbapal");

static const u16 sCaveTransitionPalette_Enter[] = INCBIN_U16("graphics/cave_transition/enter.gbapal");
static const u16 sCaveTransitionPalette_Exit[] = INCBIN_U16("graphics/cave_transition/exit.gbapal");
static const u32 sCaveTransitionTilemap[] = INCBIN_U32("graphics/cave_transition/tilemap.bin.lz");
static const u32 sCaveTransitionTiles[] = INCBIN_U32("graphics/cave_transition/tiles.4bpp.lz");

#define COUNT gTasks[taskId].data[0]

bool8 SetUpFieldMove_Flash(void)
{
    if (gMapHeader.cave != TRUE)
        return FALSE;

    if (FlagGet(FLAG_SYS_FLASH_ACTIVE))
        return FALSE;

    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    gPostMenuFieldCallback = FieldCallback_Flash;
    return TRUE;
}

static void FieldCallback_Flash(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    gTasks[taskId].data[8] = ((uintptr_t)FldEff_UseFlash) >> 16;
    gTasks[taskId].data[9] = ((uintptr_t)FldEff_UseFlash);
}

static void FldEff_UseFlash(void)
{
    PlaySE(SE_M_REFLECT);
    FlagSet(FLAG_SYS_FLASH_ACTIVE);
    ScriptContext_SetupScript(EventScript_FldEffFlash);
}

// Map transition animatics

static void CB2_ChangeMapMain(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBC_ChangeMapVBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_DoChangeMap(void)
{
    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
    ResetPaletteFade();
    ResetTasks();
    ResetSpriteData();
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBC_ChangeMapVBlank);
    SetMainCallback2(CB2_ChangeMapMain);
    if (!TryDoMapTransition())
        SetMainCallback2(gMain.savedCallback);
}

static bool8 TryDoMapTransition(void)
{
    u8 fromType = GetLastUsedWarpMapType();
    u8 toType = GetCurrentMapType();
    u8 i;
    const struct FlashStruct *transitionType;

    for (i = 0 ; sTransitionTypes[i].fromType != 0 ; i++)
    {
        transitionType = &(sTransitionTypes[i]);

        if (transitionType->fromType == fromType && transitionType->toType == toType)
        {
            if(transitionType->isEnter)
                FlashTransition_Enter();
            else if(transitionType->isExit)
                FlashTransition_Exit();
            return TRUE;
        }
    }
    return FALSE;
}

bool8 MapTransitionIsEnter(u8 _fromType, u8 _toType)
{
    u8 fromType = _fromType;
    u8 toType = _toType;
    u8 i = 0;
    for (; sTransitionTypes[i].fromType != 0; i++)
    {
        if (sTransitionTypes[i].fromType == fromType && sTransitionTypes[i].toType == toType)
        {
            return sTransitionTypes[i].isEnter;
        }
    }
    return FALSE;
}

bool8 MapTransitionIsExit(u8 _fromType, u8 _toType)
{
    u8 fromType = _fromType;
    u8 toType = _toType;
    u8 i = 0;
    for (; sTransitionTypes[i].fromType != 0; i++)
    {
        if (sTransitionTypes[i].fromType == fromType && sTransitionTypes[i].toType == toType)
        {
            return sTransitionTypes[i].isExit;
        }
    }
    return FALSE;
}

static void FlashTransition_Exit(void)
{
    CreateTask(Task_FlashTransition_Exit_1, 0);
}

static void Task_FlashTransition_Exit_1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    LZ77UnCompVram(sCaveTransitionTiles, (void *)BG_CHAR_ADDR(3));
    LZ77UnCompVram(sCaveTransitionTilemap, (void *)BG_SCREEN_ADDR(31));
    LoadPalette(sCaveTransitionPalette_White, BG_PLTT_ID(14), sizeof(sCaveTransitionPalette_White));
    LoadPalette(sCaveTransitionPalette_Exit, BG_PLTT_ID(14), sizeof(sCaveTransitionPalette_Exit));
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(31));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_FlashTransition_Exit_2;
    COUNT = 0;
}

static void Task_FlashTransition_Exit_2(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, (16 << 8) + COUNT);
    if (COUNT < 16)
        COUNT++;
    else
        gTasks[taskId].func = Task_FlashTransition_Exit_3;
}

static void Task_FlashTransition_Exit_3(u8 taskId)
{
    LoadPalette(sCaveTransitionPalette_White, BG_PLTT_ID(0), sizeof(sCaveTransitionPalette_White));
    SetMainCallback2(gMain.savedCallback);
}

static void FlashTransition_Enter(void)
{
    CreateTask(Task_FlashTransition_Enter_1, 0);
}

static void Task_FlashTransition_Enter_1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    LZ77UnCompVram(sCaveTransitionTiles, (void *)BG_CHAR_ADDR(3));
    LZ77UnCompVram(sCaveTransitionTilemap, (void *)BG_SCREEN_ADDR(31));
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(31));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_OBJ_ON);
    LoadPalette(sCaveTransitionPalette_White, BG_PLTT_ID(14), sizeof(sCaveTransitionPalette_White));
    LoadPalette(sCaveTransitionPalette_Black, BG_PLTT_ID(0), sizeof(sCaveTransitionPalette_Black));
    gTasks[taskId].func = Task_FlashTransition_Enter_2;
    COUNT = 0;
}

static void Task_FlashTransition_Enter_2(u8 taskId)
{
    if (COUNT < 16)
    {
        LoadPalette(&sCaveTransitionPalette_Enter[15 - COUNT], BG_PLTT_ID(14), PLTT_SIZEOF(COUNT + 1));
        COUNT += 2;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, (16 << 8) + 16);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD);
        COUNT = 0;
        gTasks[taskId].func = Task_FlashTransition_Enter_3;
    }
}

static void Task_FlashTransition_Enter_3(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, (16 << 8) + (16 - COUNT));
    if (COUNT < 16)
        COUNT++;
    else
    {
        LoadPalette(sCaveTransitionPalette_Black, BG_PLTT_ID(0), sizeof(sCaveTransitionPalette_Black));
        SetMainCallback2(gMain.savedCallback);
    }
}

#undef COUNT
