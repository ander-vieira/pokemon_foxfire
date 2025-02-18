#include "global.h"
#include "gflib.h"
#include "decompress.h"
#include "task.h"
#include "blend_palette.h"
#include "text_window.h"
#include "menu.h"
#include "help_system.h"
#include "new_menu_helpers.h"
#include "event_scripts.h"
#include "scanline_effect.h"
#include "pokeball.h"
#include "naming_screen.h"
#include "math_util.h"
#include "overworld.h"
#include "random.h"
#include "data.h"
#include "constants/songs.h"

#define INTRO_SPECIES SPECIES_VULPIX

struct OakSpeechResources
{
    void *oakSpeechBackgroundTiles;
    void *trainerPicTilemap;
    u8 hasPlayerBeenNamed;
    u16 shrinkTimer;
    u8 bg2TilemapBuffer[0x400];
    u8 bg1TilemapBuffer[0x800];
    u8 textColor[3];
};

static EWRAM_DATA struct OakSpeechResources *sOakSpeechResources = NULL;

static void Task_NewGameScene(u8);

static void Task_OakSpeech_Init(u8);
static void Task_OakSpeech_Init2(u8);
static void Task_OakSpeech_WelcomeToTheWorld(u8);
static void Task_OakSpeech_ThisWorld(u8);
static void Task_OakSpeech_ReleaseNidoranFFromPokeBall(u8);
static void Task_OakSpeech_IsInhabitedFarAndWide(u8);
static void Task_OakSpeech_IStudyPokemon(u8);
static void Task_OakSpeech_ReturnNidoranFToPokeBall(u8);
static void Task_OakSpeech_TellMeALittleAboutYourself(u8);
static void Task_OakSpeech_FadeOutOak(u8);
static void Task_OakSpeech_AskPlayerGender(u8);
static void Task_OakSpeech_ShowGenderOptions(u8);
static void Task_OakSpeech_HandleGenderInput(u8);
static void Task_OakSpeech_ClearGenderWindows(u8);
static void Task_OakSpeech_LoadPlayerPic(u8);
static void Task_OakSpeech_YourNameWhatIsIt(u8);
static void Task_OakSpeech_FadeOutForPlayerNamingScreen(u8);
static void Task_OakSpeech_DoNamingScreen(u8);
static void Task_OakSpeech_ConfirmName(u8);
static void Task_OakSpeech_HandleConfirmNameInput(u8);
static void Task_OakSpeech_FadeOutPlayerPic(u8);
static void Task_OakSpeech_FadeOutRivalPic(u8);
static void Task_OakSpeech_FadeInRivalPic(u8);
static void Task_OakSpeech_AskRivalsName(u8);
static void Task_OakSpeech_ReshowPlayersPic(u8);
static void Task_OakSpeech_LetsGo(u8);
static void Task_OakSpeech_FadeOutBGM(u8);
static void Task_OakSpeech_SetUpExitAnimation(u8);
static void Task_OakSpeech_SetUpShrinkPlayerPic(u8);
static void Task_OakSpeech_ShrinkPlayerPic(u8);
static void Task_OakSpeech_SetUpDestroyPlatformSprites(u8);
static void Task_OakSpeech_DestroyPlatformSprites(u8);
static void Task_OakSpeech_SetUpFadePlayerPicWhite(u8);
static void Task_OakSpeech_FadePlayerPicWhite(u8);
static void Task_OakSpeech_FadePlayerPicToBlack(u8);
static void Task_OakSpeech_WaitForFade(u8);
static void Task_OakSpeech_FreeResources(u8);

static void CB2_ReturnFromNamingScreen(void);
static void CreateNidoranFSprite(u8);
static void CreatePlatformSprites(u8);
static void DestroyPlatformSprites(u8);
static void LoadTrainerPic(u16, u16);
static void ClearTrainerPic(void);
static void CreateFadeInTask(u8, u8);
static void CreateFadeOutTask(u8, u8);
static void GetDefaultName();

extern const u8 gText_Boy[];
extern const u8 gText_Girl[];
extern const struct OamData gOamData_AffineOff_ObjBlend_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x8;

//TODO this palette is from the unused control tiles, but it's shared by the background behind Oak
//Get the palette directly from the background and delete the unused tiles
static const u16 sOakSpeech_Background_Pals[] = INCBIN_U16("graphics/oak_speech/bg_tiles.gbapal");
static const u32 sOakSpeech_Background_Tiles[] = INCBIN_U32("graphics/oak_speech/oak_speech_bg.4bpp.lz");
static const u32 sOakSpeech_Background_Tilemap[] = INCBIN_U32("graphics/oak_speech/oak_speech_bg.bin.lz");
static const u16 sOakSpeech_Leaf_Pal[] = INCBIN_U16("graphics/oak_speech/leaf/pal.gbapal");
static const u32 sOakSpeech_Leaf_Tiles[] = INCBIN_U32("graphics/oak_speech/leaf/pic.8bpp.lz");
static const u16 sOakSpeech_Red_Pal[] = INCBIN_U16("graphics/oak_speech/red/pal.gbapal");
static const u32 sOakSpeech_Red_Tiles[] = INCBIN_U32("graphics/oak_speech/red/pic.8bpp.lz");
static const u16 sOakSpeech_Oak_Pal[] = INCBIN_U16("graphics/oak_speech/oak/pal.gbapal");
static const u32 sOakSpeech_Oak_Tiles[] = INCBIN_U32("graphics/oak_speech/oak/pic.8bpp.lz");
static const u16 sOakSpeech_Rival_Pal[] = INCBIN_U16("graphics/oak_speech/rival/pal.gbapal");
static const u32 sOakSpeech_Rival_Tiles[] = INCBIN_U32("graphics/oak_speech/rival/pic.8bpp.lz");
static const u16 sOakSpeech_Platform_Pal[] = INCBIN_U16("graphics/oak_speech/platform.gbapal");
static const u32 sOakSpeech_Platform_Gfx[] = INCBIN_U32("graphics/oak_speech/platform.4bpp.lz");

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 1,
        .baseTile = 0
    }
};

enum
{
    WIN_INTRO_BOYGIRL,
    WIN_INTRO_YESNO,
    NUM_INTRO_WINDOWS,
};

static const struct WindowTemplate sIntro_WindowTemplates[NUM_INTRO_WINDOWS] =
{
    [WIN_INTRO_BOYGIRL] =
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 9,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 372
    },
    [WIN_INTRO_YESNO] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 384
    }
};

#define GFX_TAG_PLATFORM     0x1000
#define PAL_TAG_PLATFORM     0x1000

enum
{
    PLATFORM_LEFT,
    PLATFORM_MIDDLE,
    PLATFORM_RIGHT,
    NUM_PLATFORM_SPRITES,
};

static const struct CompressedSpriteSheet sOakSpeech_Platform_SpriteSheet =
{
    .data = sOakSpeech_Platform_Gfx,
    .size = 0x600,
    .tag = GFX_TAG_PLATFORM
};

static const struct SpritePalette sOakSpeech_Platform_SpritePalette =
{
    .data = sOakSpeech_Platform_Pal,
    .tag = PAL_TAG_PLATFORM
};

static const union AnimCmd sOakSpeech_PlatformLeft_Anim[] =
{
    ANIMCMD_FRAME( 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sOakSpeech_PlatformMiddle_Anim[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sOakSpeech_PlatformRight_Anim[] =
{
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sOakSpeech_PlatformLeft_Anims[] =
{
    sOakSpeech_PlatformLeft_Anim
};

static const union AnimCmd *const sOakSpeech_PlatformMiddle_Anims[] =
{
    sOakSpeech_PlatformMiddle_Anim
};

static const union AnimCmd *const sOakSpeech_PlatformRight_Anims[] =
{
    sOakSpeech_PlatformRight_Anim
};

static const struct SpriteTemplate sOakSpeech_Platform_SpriteTemplates[] =
{
    [PLATFORM_LEFT] =
    {
        .tileTag = GFX_TAG_PLATFORM,
        .paletteTag = PAL_TAG_PLATFORM,
        .oam = &gOamData_AffineOff_ObjBlend_32x32,
        .anims = sOakSpeech_PlatformLeft_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    [PLATFORM_MIDDLE] =
    {
        .tileTag = GFX_TAG_PLATFORM,
        .paletteTag = PAL_TAG_PLATFORM,
        .oam = &gOamData_AffineOff_ObjBlend_32x32,
        .anims = sOakSpeech_PlatformMiddle_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    [PLATFORM_RIGHT] =
    {
        .tileTag = GFX_TAG_PLATFORM,
        .paletteTag = PAL_TAG_PLATFORM,
        .oam = &gOamData_AffineOff_ObjBlend_32x32,
        .anims = sOakSpeech_PlatformRight_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
};

enum
{
    MALE_PLAYER_PIC,
    FEMALE_PLAYER_PIC,
    RIVAL_PIC,
    OAK_PIC
};

static void VBlankCB_NewGameScene(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_NewGameScene(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void StartNewGameScene(void)
{
    gPlttBufferUnfaded[0] = RGB_BLACK;
    gPlttBufferFaded[0]   = RGB_BLACK;
    CreateTask(Task_NewGameScene, 0);
    SetMainCallback2(CB2_NewGameScene);
}

#define tSpriteTimer                data[0]
#define tTrainerPicPosX             data[1]
#define tTrainerPicFadeState        data[2]
#define tTimer                      data[3]
#define tNidoranFSpriteId           data[4]
#define tPokeBallSpriteId           data[5]
#define tPlatformSpriteId(i)        data[6 + i] // The platform is built of three sprites,
                                 // data[8]     // so these are used to hold their sprite IDs
                                 // data[9]     //
#define tMenuWindowId               data[13]

static void Task_NewGameScene(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, 0, PLTT + sizeof(u16), PLTT_SIZE - 2);
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTempTileDataBuffers();
        SetHelpContext(HELPCONTEXT_NONE);
        sOakSpeechResources = AllocZeroed(sizeof(struct OakSpeechResources));
        CreateMonSpritesGfxManager(1, 1);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(1, sOakSpeechResources->bg1TilemapBuffer);
        SetBgTilemapBuffer(2, sOakSpeechResources->bg2TilemapBuffer);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        gSpriteCoordOffsetX = 0;
        gSpriteCoordOffsetY = 0;
        InitStandardTextBoxWindows();
        InitTextBoxGfxAndPrinters();
        Menu_LoadStdPalAt(BG_PLTT_ID(13));
        LoadPalette(sOakSpeech_Background_Pals, BG_PLTT_ID(0), sizeof(sOakSpeech_Background_Pals));
        LoadPalette(GetTextWindowPalette(2) + 15, BG_PLTT_ID(0), PLTT_SIZEOF(1));
        gTextFlags.canABSpeedUpPrint = TRUE;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        SetVBlankCallback(VBlankCB_NewGameScene);
        gTasks[taskId].func = Task_OakSpeech_Init;
        gMain.state = 0;
        return;
    }

    gMain.state++;
}

static void Task_OakSpeech_Init(u8 taskId) {
    u32 size = 0;

    sOakSpeechResources->oakSpeechBackgroundTiles = MallocAndDecompress(sOakSpeech_Background_Tiles, &size);
    LoadBgTiles(1, sOakSpeechResources->oakSpeechBackgroundTiles, size, 0);
    CopyToBgTilemapBuffer(1, sOakSpeech_Background_Tilemap, 0, 0);
    CopyBgTilemapBufferToVram(1);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    CreateNidoranFSprite(taskId);
    LoadTrainerPic(OAK_PIC, 0);
    CreatePlatformSprites(taskId);
    gTasks[taskId].func = Task_OakSpeech_Init2;
}

static void Task_OakSpeech_Init2(u8 taskId)
{
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    PlayBGM(MUS_ROUTE24);
    gTasks[taskId].func = Task_OakSpeech_WelcomeToTheWorld;
}

#define OakSpeechPrintMessage(str) ({                                                                                                                 \
    DrawDialogueFrame(0, FALSE);                                                                                                             \
    if (str != gStringVar4)                                                                                                                                  \
    {                                                                                                                                                        \
        StringExpandPlaceholders(gStringVar4, str);                                                                                                          \
        AddTextPrinterParameterized2(0, FONT_MALE, gStringVar4, 1, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY); \
    }                                                                                                                                                        \
    else                                                                                                                                                     \
    {                                                                                                                                                        \
        AddTextPrinterParameterized2(0, FONT_MALE, str, 1, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);         \
    }                                                                                                                                                        \
    CopyWindowToVram(0, COPYWIN_FULL);                                                                                                       \
})

static void Task_OakSpeech_WelcomeToTheWorld(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        OakSpeechPrintMessage(gOakSpeech_Text_WelcomeToTheWorld);
        gTasks[taskId].func = Task_OakSpeech_ThisWorld;
    }
}

static void Task_OakSpeech_ThisWorld(u8 taskId)
{
    if (!IsTextPrinterActive(0))
    {
        OakSpeechPrintMessage(gOakSpeech_Text_ThisWorld);
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_OakSpeech_ReleaseNidoranFFromPokeBall;
    }
}

static void Task_OakSpeech_ReleaseNidoranFFromPokeBall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 spriteId;

    if (!IsTextPrinterActive(0))
    {
        if (tTimer != 0)
            tTimer--;
        spriteId = gTasks[taskId].tNidoranFSpriteId;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].tSpriteTimer = 0;
        CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 100, 66, 0, 0, 32, 0xFFFF1FFF);
        gTasks[taskId].func = Task_OakSpeech_IsInhabitedFarAndWide;
        gTasks[taskId].tTimer = 0;
    }
}

static void Task_OakSpeech_IsInhabitedFarAndWide(u8 taskId)
{
    if (IsCryFinished())
    {
        if (gTasks[taskId].tTimer >= 96)
            gTasks[taskId].func = Task_OakSpeech_IStudyPokemon;
    }
    if (gTasks[taskId].tTimer < 0x4000)
    {
        gTasks[taskId].tTimer++;
        if (gTasks[taskId].tTimer == 32)
        {
            OakSpeechPrintMessage(gOakSpeech_Text_IsInhabitedFarAndWide);
            PlayCry_Normal(INTRO_SPECIES, 0);
        }
    }
}

static void Task_OakSpeech_IStudyPokemon(u8 taskId)
{
    if (!IsTextPrinterActive(0))
    {
        OakSpeechPrintMessage(gOakSpeech_Text_IStudyPokemon);
        gTasks[taskId].func = Task_OakSpeech_ReturnNidoranFToPokeBall;
    }
}

static void Task_OakSpeech_ReturnNidoranFToPokeBall(u8 taskId)
{
    u8 spriteId;

    if (!IsTextPrinterActive(0))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        spriteId = gTasks[taskId].tNidoranFSpriteId;
        gTasks[taskId].tPokeBallSpriteId = CreateTradePokeballSprite(spriteId, gSprites[spriteId].oam.paletteNum, 100, 66, 0, 0, 32, 0xFFFF1F3F);
        gTasks[taskId].tTimer = 48;
        gTasks[taskId].tSpriteTimer = 64;
        gTasks[taskId].func = Task_OakSpeech_TellMeALittleAboutYourself;
    }
}

static void Task_OakSpeech_TellMeALittleAboutYourself(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tSpriteTimer != 0)
    {
        if (tSpriteTimer < 24)
            gSprites[tNidoranFSpriteId].y--;
        tSpriteTimer--;
    }
    else
    {
        if (tTimer == 48)
        {
            DestroySprite(&gSprites[tNidoranFSpriteId]);
            DestroySprite(&gSprites[tPokeBallSpriteId]);
        }
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            OakSpeechPrintMessage(gOakSpeech_Text_TellMeALittleAboutYourself);
            gTasks[taskId].func = Task_OakSpeech_FadeOutOak;
        }
    }
}

static void Task_OakSpeech_FadeOutOak(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!IsTextPrinterActive(0))
    {
        ClearDialogWindowAndFrame(0, 1);
        CreateFadeInTask(taskId, 2);
        gTasks[taskId].func = Task_OakSpeech_AskPlayerGender;
    }
}

static void Task_OakSpeech_AskPlayerGender(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        tTrainerPicPosX = -60;
        ClearTrainerPic();
        OakSpeechPrintMessage(gOakSpeech_Text_AskPlayerGender);
        gTasks[taskId].func = Task_OakSpeech_ShowGenderOptions;
    }
}

static void Task_OakSpeech_ShowGenderOptions(u8 taskId)
{
    if (!IsTextPrinterActive(0))
    {
        gTasks[taskId].tMenuWindowId = AddWindow(&sIntro_WindowTemplates[WIN_INTRO_BOYGIRL]);
        PutWindowTilemap(gTasks[taskId].tMenuWindowId);
        DrawStdFrameWithCustomTileAndPalette(gTasks[taskId].tMenuWindowId, TRUE, GetStdWindowBaseTileNum(), 14);
        FillWindowPixelBuffer(gTasks[taskId].tMenuWindowId, PIXEL_FILL(1));
        sOakSpeechResources->textColor[0] = 1;
        sOakSpeechResources->textColor[1] = 2;
        sOakSpeechResources->textColor[2] = 3;
        AddTextPrinterParameterized3(gTasks[taskId].tMenuWindowId, FONT_NORMAL, 8, 1, sOakSpeechResources->textColor, 0, gText_Boy);
        sOakSpeechResources->textColor[0] = 1;
        sOakSpeechResources->textColor[1] = 2;
        sOakSpeechResources->textColor[2] = 3;
        AddTextPrinterParameterized3(gTasks[taskId].tMenuWindowId, FONT_NORMAL, 8, 17, sOakSpeechResources->textColor, 0, gText_Girl);
        Menu_InitCursor(gTasks[taskId].tMenuWindowId, FONT_NORMAL, 0, 1, GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT) + 2, 2, 0);
        CopyWindowToVram(gTasks[taskId].tMenuWindowId, COPYWIN_FULL);
        gTasks[taskId].func = Task_OakSpeech_HandleGenderInput;
    }
}

static void Task_OakSpeech_HandleGenderInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrapAround();
    switch (input)
    {
    case 0: // BOY
        gSaveBlock2Ptr->playerGender = MALE;
        break;
    case 1: // GIRL
        gSaveBlock2Ptr->playerGender = FEMALE;
        break;
    case MENU_B_PRESSED:
    case MENU_NOTHING_CHOSEN:
        return;
    }
    gTasks[taskId].func = Task_OakSpeech_ClearGenderWindows;

}

static void Task_OakSpeech_ClearGenderWindows(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ClearStdWindowAndFrameToTransparent(tMenuWindowId, TRUE);
    RemoveWindow(tMenuWindowId);
    tMenuWindowId = 0;
    ClearDialogWindowAndFrame(tMenuWindowId, TRUE);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
    gTasks[taskId].func = Task_OakSpeech_LoadPlayerPic;
}

static void Task_OakSpeech_LoadPlayerPic(u8 taskId)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        LoadTrainerPic(MALE_PLAYER_PIC, 0);
    else
        LoadTrainerPic(FEMALE_PLAYER_PIC, 0);
    CreateFadeOutTask(taskId, 2);
    gTasks[taskId].func = Task_OakSpeech_YourNameWhatIsIt;
}

static void Task_OakSpeech_YourNameWhatIsIt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        tTrainerPicPosX = 0;
        OakSpeechPrintMessage(gOakSpeech_Text_YourNameWhatIsIt);
        gTasks[taskId].func = Task_OakSpeech_FadeOutForPlayerNamingScreen;
    }
}

static void Task_OakSpeech_FadeOutForPlayerNamingScreen(u8 taskId)
{
    if (IsTextPrinterActive(0))
        return;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    sOakSpeechResources->hasPlayerBeenNamed = FALSE;
    gTasks[taskId].func = Task_OakSpeech_DoNamingScreen;
}

static void Task_OakSpeech_FadeOutForRivalNamingScreen(u8 taskId)
{
    if (IsTextPrinterActive(0))
        return;
    
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    sOakSpeechResources->hasPlayerBeenNamed = TRUE;
    gTasks[taskId].func = Task_OakSpeech_DoNamingScreen;
}

#define tNameNotConfirmed data[15]

static void Task_OakSpeech_DoNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        GetDefaultName();
        if (!sOakSpeechResources->hasPlayerBeenNamed)
            DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnFromNamingScreen);
        else
            DoNamingScreen(NAMING_SCREEN_RIVAL, gSaveBlock1Ptr->rivalName, 0, 0, 0, CB2_ReturnFromNamingScreen);
        DestroyPlatformSprites(taskId);
        FreeAllWindowBuffers();
    }
}

static void Task_OakSpeech_ConfirmName(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        if (tNameNotConfirmed)
        {
            if (!sOakSpeechResources->hasPlayerBeenNamed)
                StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_SoYourNameIsPlayer);
            else
                StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_ConfirmRivalName);
            OakSpeechPrintMessage(gStringVar4);
            tNameNotConfirmed = FALSE;
        }
        else if (!IsTextPrinterActive(0))
        {
            CreateYesNoMenu(&sIntro_WindowTemplates[WIN_INTRO_YESNO], FONT_NORMAL, 0, 2, GetStdWindowBaseTileNum(), 14, 0);
            gTasks[taskId].func = Task_OakSpeech_HandleConfirmNameInput;
        }
    }
}

static void Task_OakSpeech_HandleConfirmNameInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    switch (input)
    {
    case 0: // YES
        PlaySE(SE_SELECT);
        gTasks[taskId].tTimer = 40;
        if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
        {
            ClearDialogWindowAndFrame(0, TRUE);
            CreateFadeInTask(taskId, 2);
            gTasks[taskId].func = Task_OakSpeech_FadeOutPlayerPic;
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_RememberRivalsName);
            OakSpeechPrintMessage(gStringVar4);
            gTasks[taskId].func = Task_OakSpeech_FadeOutRivalPic;
        }
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        if (!sOakSpeechResources->hasPlayerBeenNamed)
            gTasks[taskId].func = Task_OakSpeech_FadeOutForPlayerNamingScreen;
        else
            gTasks[taskId].func = Task_OakSpeech_FadeOutForRivalNamingScreen;
        break;
    }
}

static void Task_OakSpeech_FadeOutPlayerPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        ClearTrainerPic();
        if (tTimer != 0)
            tTimer--;
        else
            gTasks[taskId].func = Task_OakSpeech_FadeInRivalPic;
    }
}

static void Task_OakSpeech_FadeOutRivalPic(u8 taskId)
{
    if (!IsTextPrinterActive(0))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        CreateFadeInTask(taskId, 2);
        gTasks[taskId].func = Task_OakSpeech_ReshowPlayersPic;
    }
}

static void Task_OakSpeech_FadeInRivalPic(u8 taskId)
{
    ChangeBgX(2, 0, BG_COORD_SET);
    gTasks[taskId].tTrainerPicPosX = 0;
    gSpriteCoordOffsetX = 0;
    LoadTrainerPic(RIVAL_PIC, 0);
    CreateFadeOutTask(taskId, 2);
    gTasks[taskId].func = Task_OakSpeech_AskRivalsName;
}

static void Task_OakSpeech_AskRivalsName(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        OakSpeechPrintMessage(gOakSpeech_Text_WhatWasHisName);
        sOakSpeechResources->hasPlayerBeenNamed = TRUE;
        gTasks[taskId].func = Task_OakSpeech_FadeOutForRivalNamingScreen;
    }
}

static void Task_OakSpeech_ReshowPlayersPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        ClearTrainerPic();
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            if (gSaveBlock2Ptr->playerGender == MALE)
                LoadTrainerPic(MALE_PLAYER_PIC, 0);
            else
                LoadTrainerPic(FEMALE_PLAYER_PIC, 0);
            gTasks[taskId].tTrainerPicPosX = 0;
            gSpriteCoordOffsetX = 0;
            ChangeBgX(2, 0, BG_COORD_SET);
            CreateFadeOutTask(taskId, 2);
            gTasks[taskId].func = Task_OakSpeech_LetsGo;
        }
    }
}

static void Task_OakSpeech_LetsGo(u8 taskId)
{
    if (gTasks[taskId].tTrainerPicFadeState != 0)
    {
        StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_LetsGo);
        OakSpeechPrintMessage(gStringVar4);
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_OakSpeech_FadeOutBGM;
    }
}

static void Task_OakSpeech_FadeOutBGM(u8 taskId)
{
    if (!IsTextPrinterActive(0))
    {
        if (gTasks[taskId].tTimer != 0)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            FadeOutBGM(4);
            gTasks[taskId].func = Task_OakSpeech_SetUpExitAnimation;
        }
    }
}

static void Task_OakSpeech_SetUpExitAnimation(u8 taskId)
{
    sOakSpeechResources->shrinkTimer = 0;
    Task_OakSpeech_SetUpDestroyPlatformSprites(taskId);
    Task_OakSpeech_SetUpFadePlayerPicWhite(taskId);
    Task_OakSpeech_SetUpShrinkPlayerPic(taskId);
}

#define tPlayerPicFadeOutTimer data[0]
#define tScaleDelta            data[2]
#define tPlayerIsShrunk        data[15]

static void Task_OakSpeech_SetUpShrinkPlayerPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    SetBgAttribute(2, BG_ATTR_WRAPAROUND, 1);
    tPlayerPicFadeOutTimer = 0;
    data[1] = 0; // assigned, but never read
    tScaleDelta = 256;
    tPlayerIsShrunk = FALSE;
    gTasks[taskId].func = Task_OakSpeech_ShrinkPlayerPic;
}

static void Task_OakSpeech_ShrinkPlayerPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 x, y;
    u16 oldScaleDelta;

    sOakSpeechResources->shrinkTimer++;
    if (sOakSpeechResources->shrinkTimer % 20 == 0)
    {
        if (sOakSpeechResources->shrinkTimer == 40)
            PlaySE(SE_WARP_IN);
        oldScaleDelta = tScaleDelta;
        tScaleDelta -= 32;
        x = Q_8_8_inv(oldScaleDelta - 8);
        y = Q_8_8_inv(tScaleDelta - 16);
        SetBgAffine(2, 0x7800, 0x5400, 120, 84, x, y, 0);
        if (tScaleDelta <= 96)
        {
            tPlayerIsShrunk = TRUE;
            tPlayerPicFadeOutTimer = 36;
            gTasks[taskId].func = Task_OakSpeech_FadePlayerPicToBlack;
        }
    }
}

#define tBGFadeStarted data[1]

static void Task_OakSpeech_SetUpDestroyPlatformSprites(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_OakSpeech_DestroyPlatformSprites, 1);
    s16 *data = gTasks[taskId2].data;
    data[0] = 0; // assigned, but never read
    tBGFadeStarted = 0;
    data[2] = 0; // assigned, but never read
    data[15] = 0; // assigned, but never read
    BeginNormalPaletteFade(PALETTES_OBJECTS | 0x0FCF, 4, 0, 16, RGB_BLACK);
}

static void Task_OakSpeech_DestroyPlatformSprites(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        if (tBGFadeStarted != 0)
        {
            DestroyTask(taskId);
            // As this function's taskId is in fact taskId2 above, in
            // Task_OakSpeech_SetUpDestroyPlatformSprites, the platform sprite
            // IDs have not been assigned to this task's data[7], data[8] and
            // data[9].
            // As a result, the function below will only delete the sprite with
            // ID 0.
            // This can be verified by looking at the sprite viewer in an
            // emulator at the end of the Oak speech.
            DestroyPlatformSprites(taskId);
        }
        else
        {
            tBGFadeStarted++;
            BeginNormalPaletteFade(0x0000 | 0xF000, 0, 0, 16, RGB_BLACK);
        }
    }
}

#undef tBGFadeStarted

#define tPlayerPicFadeWhiteTimer data[0]
#define tUnderflowingTimer       data[1]
#define tSecondaryTimer          data[2]
#define tBlendCoefficient        data[14]

static void Task_OakSpeech_SetUpFadePlayerPicWhite(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_OakSpeech_FadePlayerPicWhite, 2);
    s16 *data = gTasks[taskId2].data;
    tPlayerPicFadeWhiteTimer = 8;
    tUnderflowingTimer = 0;
    tSecondaryTimer = 8;
    tBlendCoefficient = 0;
    data[15] = 0; // assigned, but never read
}

static void Task_OakSpeech_FadePlayerPicWhite(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 i;

    if (tPlayerPicFadeWhiteTimer != 0)
    {
        tPlayerPicFadeWhiteTimer--;
    }
    else
    {
        if (tUnderflowingTimer <= 0 && tSecondaryTimer != 0)
            tSecondaryTimer--;
        BlendPalette(BG_PLTT_ID(4), 0x20, tBlendCoefficient, RGB_WHITE);
        tBlendCoefficient++;
        tUnderflowingTimer--;
        tPlayerPicFadeWhiteTimer = tSecondaryTimer;
        if (tBlendCoefficient > 14)
        {
            for (i = 0; i < 32; i++)
            {
                gPlttBufferFaded[i + BG_PLTT_ID(4)] = RGB_WHITE;
                gPlttBufferUnfaded[i + BG_PLTT_ID(4)] = RGB_WHITE;
            }
            DestroyTask(taskId);
        }
    }
}

static void Task_OakSpeech_FadePlayerPicToBlack(u8 taskId)
{
    if (gTasks[taskId].tPlayerPicFadeOutTimer != 0)
    {
        gTasks[taskId].tPlayerPicFadeOutTimer--;
    }
    else
    {
        BeginNormalPaletteFade(0x0000 | 0x0030, 2, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_OakSpeech_WaitForFade;
    }
}

static void Task_OakSpeech_WaitForFade(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OakSpeech_FreeResources;
}

static void Task_OakSpeech_FreeResources(u8 taskId)
{
    FreeAllWindowBuffers();
    DestroyMonSpritesGfxManager();
    Free(sOakSpeechResources);
    sOakSpeechResources = NULL;
    gTextFlags.canABSpeedUpPrint = FALSE;
    SetMainCallback2(CB2_NewGame);
    DestroyTask(taskId);
}

static void CB2_ReturnFromNamingScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, RGB_BLACK, PLTT + sizeof(u16), PLTT_SIZE - sizeof(u16));
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTempTileDataBuffers();
        break;
    case 1:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(1, sOakSpeechResources->bg1TilemapBuffer);
        SetBgTilemapBuffer(2, sOakSpeechResources->bg2TilemapBuffer);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        break;
    case 2:
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        break;
    case 3:
        FreeAllWindowBuffers();
        InitStandardTextBoxWindows();
        InitTextBoxGfxAndPrinters();
        // Below is reading 48 colors beyond the background palette (into the tiles that follow it).
        // This color range is used by the player and rival pic, which will overwrite them with the correct colors.
        LoadPalette(sOakSpeech_Background_Pals, BG_PLTT_ID(0), sizeof(sOakSpeech_Background_Pals));
        break;
    case 4:
        DecompressAndCopyTileDataToVram(1, sOakSpeech_Background_Tiles, 0, 0, 0);
        break;
    case 5:
        if (FreeTempTileDataBuffersIfPossible())
            return;
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
        CopyToBgTilemapBuffer(1, sOakSpeech_Background_Tilemap, 0, 0);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        break;
    case 6:
        taskId = CreateTask(Task_OakSpeech_ConfirmName, 0);
        if (!sOakSpeechResources->hasPlayerBeenNamed)
        {
            if (gSaveBlock2Ptr->playerGender == MALE)
                LoadTrainerPic(MALE_PLAYER_PIC, 0);
            else
                LoadTrainerPic(FEMALE_PLAYER_PIC, 0);
        }
        else
        {
            LoadTrainerPic(RIVAL_PIC, 0);
        }
        gTasks[taskId].tTrainerPicPosX = -60;
        gSpriteCoordOffsetX += 60;
        ChangeBgX(2, 0xFFFFC400, BG_COORD_SET);
        CreatePlatformSprites(taskId);
        gTasks[taskId].tNameNotConfirmed = TRUE;
        break;
    case 7:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_NewGameScene);
        gTextFlags.canABSpeedUpPrint = TRUE;
        SetMainCallback2(CB2_NewGameScene);
        return;
    }

    gMain.state++;
}

static void CreateNidoranFSprite(u8 taskId)
{
    u8 spriteId;

    DecompressPicFromTable(&gMonFrontPicTable[INTRO_SPECIES], MonSpritesGfxManager_GetSpritePtr(0), INTRO_SPECIES);
    LoadCompressedSpritePaletteUsingHeap(&gMonPaletteTable[INTRO_SPECIES]);
    SetMultiuseSpriteTemplateToPokemon(INTRO_SPECIES, 0);
    spriteId = CreateSprite(&gMultiuseSpriteTemplate, 96, 96, 1);
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].invisible = TRUE;
    gTasks[taskId].tNidoranFSpriteId = spriteId;
}

static void CreatePlatformSprites(u8 taskId)
{
    u8 spriteId;
    u8 i = 0;

    LoadCompressedSpriteSheet(&sOakSpeech_Platform_SpriteSheet);
    LoadSpritePalette(&sOakSpeech_Platform_SpritePalette);
    for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
    {
        spriteId = CreateSprite(&sOakSpeech_Platform_SpriteTemplates[i], i * 32 + 88, 112, 1);
        gSprites[spriteId].oam.priority = 2;
        gSprites[spriteId].animPaused = TRUE;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gTasks[taskId].tPlatformSpriteId(i) = spriteId;
    }
}

static void DestroyPlatformSprites(u8 taskId)
{
    u8 i;
    for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
        DestroySprite(&gSprites[gTasks[taskId].tPlatformSpriteId(i)]);

    FreeSpriteTilesByTag(GFX_TAG_PLATFORM);
    FreeSpritePaletteByTag(PAL_TAG_PLATFORM);
}

static void LoadTrainerPic(u16 whichPic, u16 tileOffset)
{
    u32 i;

    switch (whichPic)
    {
    case MALE_PLAYER_PIC:
        LoadPalette(sOakSpeech_Red_Pal, BG_PLTT_ID(4), sizeof(sOakSpeech_Red_Pal));
        LZ77UnCompVram(sOakSpeech_Red_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    case FEMALE_PLAYER_PIC:
        LoadPalette(sOakSpeech_Leaf_Pal, BG_PLTT_ID(4), sizeof(sOakSpeech_Leaf_Pal));
        LZ77UnCompVram(sOakSpeech_Leaf_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    case RIVAL_PIC:
        LoadPalette(sOakSpeech_Rival_Pal, BG_PLTT_ID(6), sizeof(sOakSpeech_Rival_Pal));
        LZ77UnCompVram(sOakSpeech_Rival_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    case OAK_PIC:
        LoadPalette(sOakSpeech_Oak_Pal, BG_PLTT_ID(6), sizeof(sOakSpeech_Oak_Pal));
        LZ77UnCompVram(sOakSpeech_Oak_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    default:
        return;
    }

    sOakSpeechResources->trainerPicTilemap = AllocZeroed(0x60);
    for (i = 0; i < 0x60; i++)
        ((u8 *)sOakSpeechResources->trainerPicTilemap)[i] = i;
    FillBgTilemapBufferRect(2, 0, 0, 0, 32, 32, 16);
    CopyRectToBgTilemapBufferRect(2, sOakSpeechResources->trainerPicTilemap, 0, 0, 8, 12, 11, 2, 8, 12, 16, (tileOffset / 64) + 24, 0);
    CopyBgTilemapBufferToVram(2);
    Free(sOakSpeechResources->trainerPicTilemap);
    sOakSpeechResources->trainerPicTilemap = 0;
}

static void ClearTrainerPic(void)
{
    FillBgTilemapBufferRect(2, 0, 11, 1, 8, 12, 16);
    CopyBgTilemapBufferToVram(2);
}

#define tParentTaskId data[0]
#define tBlendTarget1 data[1]
#define tBlendTarget2 data[2]
#define tFadeTimer    data[3]

static void Task_SlowFadeIn(u8 taskId)
{
    u8 i = 0;
    if (gTasks[taskId].tBlendTarget1 == 0)
    {
        gTasks[gTasks[taskId].tParentTaskId].tTrainerPicFadeState = 1;
        DestroyTask(taskId);
        for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
            gSprites[gTasks[taskId].tPlatformSpriteId(i)].invisible = TRUE;
    }
    else
    {
        if (gTasks[taskId].tFadeTimer != 0)
        {
            gTasks[taskId].tFadeTimer--;
        }
        else
        {
            gTasks[taskId].tFadeTimer = gTasks[taskId].tTimer;
            gTasks[taskId].tBlendTarget1--;
            gTasks[taskId].tBlendTarget2++;
            if (gTasks[taskId].tBlendTarget1 == 8)
            {
                for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
                    gSprites[gTasks[taskId].tPlatformSpriteId(i)].invisible ^= TRUE;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].tBlendTarget2 * 256) + gTasks[taskId].tBlendTarget1);
        }
    }
}

static void CreateFadeInTask(u8 taskId, u8 delay)
{
    u8 taskId2;
    u8 i = 0;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tTrainerPicFadeState = 0;
    taskId2 = CreateTask(Task_SlowFadeIn, 0);
    gTasks[taskId2].tParentTaskId = taskId;
    gTasks[taskId2].tBlendTarget1 = 16;
    gTasks[taskId2].tBlendTarget2 = 0;
    gTasks[taskId2].tFadeTimer = delay;
    for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
        gTasks[taskId2].tPlatformSpriteId(i) = gTasks[taskId].tPlatformSpriteId(i);
}

static void Task_SlowFadeOut(u8 taskId)
{
    u8 i = 0;

    if (gTasks[taskId].tBlendTarget1 == 16)
    {
        if (!gPaletteFade.active)
        {
            gTasks[gTasks[taskId].tParentTaskId].tTrainerPicFadeState = 1;
            DestroyTask(taskId);
        }
    }
    else
    {
        if (gTasks[taskId].tFadeTimer != 0)
        {
            gTasks[taskId].tFadeTimer--;
        }
        else
        {
            gTasks[taskId].tFadeTimer = gTasks[taskId].tTimer;
            gTasks[taskId].tBlendTarget1 += 2;
            gTasks[taskId].tBlendTarget2 -= 2;
            if (gTasks[taskId].tBlendTarget1 == 8)
            {
                for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
                    gSprites[gTasks[taskId].tPlatformSpriteId(i)].invisible ^= TRUE;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].tBlendTarget2 * 256) + gTasks[taskId].tBlendTarget1);
        }
    }
}

static void CreateFadeOutTask(u8 taskId, u8 delay)
{
    u8 taskId2;
    u8 i = 0;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tTrainerPicFadeState = 0;

    taskId2 = CreateTask(Task_SlowFadeOut, 0);
    gTasks[taskId2].tParentTaskId = taskId;
    gTasks[taskId2].tBlendTarget1 = 0;
    gTasks[taskId2].tBlendTarget2 = 16;
    gTasks[taskId2].tFadeTimer = delay;
    for (i = PLATFORM_LEFT; i < NUM_PLATFORM_SPRITES; i++)
        gTasks[taskId2].tPlatformSpriteId(i) = gTasks[taskId].tPlatformSpriteId(i);
}

static void GetDefaultName()
{
    const u8 *src;
    u8 *dest;
    u8 i;

    if (sOakSpeechResources->hasPlayerBeenNamed)
    {
        src = gNameChoice_Green;
        dest = gSaveBlock1Ptr->rivalName;
    }
    else
    {
        src = gNameChoice_Red;
        dest = gSaveBlock2Ptr->playerName;
    }

    for (i = 0; i < PLAYER_NAME_LENGTH && src[i] != EOS; i++)
        dest[i] = src[i];
    for (; i < PLAYER_NAME_LENGTH + 1; i++)
        dest[i] = EOS;
}

#undef tSpriteTimer
#undef tTrainerPicPosX
#undef tTrainerPicFadeState
#undef tTimer
#undef tNidoranFSpriteId
#undef tPokeBallSpriteId
#undef tMenuWindowId
#undef tPlayerPicFadeOutTimer
#undef tScaleDelta
#undef tPlayerIsShrunk
#undef shrinkTimer
#undef tPlayerPicFadeWhiteTimer
#undef tUnderflowingTimer
#undef tSecondaryTimer
#undef tBlendCoefficient
#undef tNameNotConfirmed
#undef tParentTaskId
#undef tBlendTarget1
#undef tBlendTarget2
#undef tFadeTimer
