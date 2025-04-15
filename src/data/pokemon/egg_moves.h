#define EGG_MOVES_SPECIES_OFFSET 20000
#define EGG_MOVES_TERMINATOR 0xFFFF
#define egg_moves(species, moves...) (SPECIES_##species + EGG_MOVES_SPECIES_OFFSET), moves

const u16 gEggMoves[] = {
    egg_moves(BULBASAUR,
              MOVE_SKULL_BASH,
              MOVE_MAGICAL_LEAF),

    egg_moves(CHARMANDER,
              MOVE_BELLY_DRUM,
              MOVE_ANCIENT_POWER,
              MOVE_BITE,
              MOVE_OUTRAGE,
              MOVE_DRAGON_DANCE),

    egg_moves(SQUIRTLE,
              MOVE_WATER_SPOUT,
              MOVE_MIRROR_COAT,
              MOVE_HAZE,
              MOVE_FLAIL,
              MOVE_YAWN),

    egg_moves(PIDGEY,
              MOVE_PURSUIT,
              MOVE_FEINT_ATTACK,
              MOVE_AIR_CUTTER),

    egg_moves(RATTATA,
              MOVE_SCREECH,
              MOVE_FLAME_WHEEL,
              MOVE_FURY_SWIPES,
              MOVE_REVERSAL,
              MOVE_SWAGGER),

    egg_moves(SPEAROW,
              MOVE_FEINT_ATTACK,
              MOVE_FALSE_SWIPE,
              MOVE_SCARY_FACE,
              MOVE_QUICK_ATTACK,
              MOVE_TRI_ATTACK,
              MOVE_ASTONISH,
              MOVE_SKY_ATTACK),

    egg_moves(EKANS,
              MOVE_PURSUIT,
              MOVE_SLAM),

    egg_moves(SANDSHREW,
              MOVE_FLAIL,
              MOVE_METAL_CLAW),

    egg_moves(NIDORAN_F,
              MOVE_SUPERSONIC,
              MOVE_DISABLE,
              MOVE_TAKE_DOWN,
              MOVE_CHARM),

    egg_moves(NIDORAN_M,
              MOVE_DISABLE,
              MOVE_SUPERSONIC,
              MOVE_TAKE_DOWN,
              MOVE_AMNESIA,
              MOVE_CONFUSION),

    egg_moves(VULPIX,
              MOVE_HYPNOSIS,
              MOVE_FLAIL,
              MOVE_HOWL,
              MOVE_HEAT_WAVE),

    egg_moves(ZUBAT,
              MOVE_QUICK_ATTACK,
              MOVE_PURSUIT,
              MOVE_FEINT_ATTACK,
              MOVE_GUST,
              MOVE_WHIRLWIND),

    egg_moves(ODDISH,
              MOVE_LEECH_SEED,
              MOVE_RAZOR_LEAF,
              MOVE_FLAIL),

    egg_moves(PARAS,
              MOVE_LEECH_SEED,
              MOVE_FALSE_SWIPE,
              MOVE_SCREECH,
              MOVE_PSYBEAM,
              MOVE_FLAIL,
              MOVE_SWEET_SCENT,
              MOVE_PURSUIT),

    egg_moves(VENONAT,
              MOVE_BATON_PASS,
              MOVE_SCREECH,
              MOVE_SIGNAL_BEAM),

    egg_moves(DIGLETT,
              MOVE_FEINT_ATTACK,
              MOVE_SCREECH,
              MOVE_ANCIENT_POWER,
              MOVE_PURSUIT),

    egg_moves(MEOWTH,
              MOVE_CHARM,
              MOVE_AMNESIA),

    egg_moves(PSYDUCK,
              MOVE_HYPNOSIS,
              MOVE_PSYBEAM,
              MOVE_CROSS_CHOP),

    egg_moves(MANKEY,
              MOVE_MEDITATE,
              MOVE_REVERSAL),

    egg_moves(GROWLITHE,
              MOVE_CRUNCH,
              MOVE_THRASH,
              MOVE_FIRE_SPIN),

    egg_moves(POLIWAG,
              MOVE_SPLASH,
              MOVE_HAZE,
              MOVE_MIND_READER),

    egg_moves(ABRA,
              MOVE_ENCORE,
              MOVE_BARRIER),

    egg_moves(MACHOP,
              MOVE_MEDITATE,
              MOVE_ROLLING_KICK,
              MOVE_ENCORE),

    egg_moves(BELLSPROUT,
              MOVE_ENCORE,
              MOVE_LEECH_LIFE,
              MOVE_MAGICAL_LEAF),

    egg_moves(TENTACOOL,
              MOVE_AURORA_BEAM,
              MOVE_MIRROR_COAT,
              MOVE_RAPID_SPIN,
              MOVE_HAZE,
              MOVE_CONFUSE_RAY),

    egg_moves(PONYTA,
              MOVE_THRASH,
              MOVE_HYPNOSIS,
              MOVE_CHARM),

    egg_moves(SLOWPOKE,
              MOVE_BELLY_DRUM,
              MOVE_STOMP),

    egg_moves(FARFETCHD,
              MOVE_MIRROR_MOVE,
              MOVE_GUST,
              MOVE_QUICK_ATTACK,
              MOVE_FLAIL,
              MOVE_FEATHER_DANCE),

    egg_moves(DODUO,
              MOVE_SUPERSONIC,
              MOVE_HAZE,
              MOVE_FEINT_ATTACK,
              MOVE_FLAIL),

    egg_moves(SEEL,
              MOVE_PERISH_SONG,
              MOVE_DISABLE,
              MOVE_SLAM,
              MOVE_ENCORE,
              MOVE_FAKE_OUT,
              MOVE_ICICLE_SPEAR),

    egg_moves(GRIMER,
              MOVE_HAZE,
              MOVE_MEAN_LOOK,
              MOVE_LICK,
              MOVE_IMPRISON,
              MOVE_SHADOW_PUNCH),

    egg_moves(SHELLDER,
              MOVE_BUBBLE_BEAM,
              MOVE_TAKE_DOWN,
              MOVE_BARRIER,
              MOVE_RAPID_SPIN,
              MOVE_SCREECH,
              MOVE_ICICLE_SPEAR),

    egg_moves(GASTLY,
              MOVE_PERISH_SONG,
              MOVE_HAZE,
              MOVE_ASTONISH),

    egg_moves(ONIX,
              MOVE_FLAIL,
              MOVE_BLOCK),

    egg_moves(DROWZEE,
              MOVE_BARRIER,
              MOVE_ROLE_PLAY),

    egg_moves(KRABBY,
              MOVE_HAZE,
              MOVE_AMNESIA),

    egg_moves(EXEGGCUTE,
              MOVE_ANCIENT_POWER),

    egg_moves(CUBONE,
              MOVE_ANCIENT_POWER,
              MOVE_BELLY_DRUM,
              MOVE_SCREECH,
              MOVE_SKULL_BASH,
              MOVE_PERISH_SONG),

    egg_moves(LICKITUNG,
              MOVE_BELLY_DRUM,
              MOVE_MAGNITUDE),

    egg_moves(KOFFING,
              MOVE_SCREECH,
              MOVE_PSYBEAM,
              MOVE_DESTINY_BOND),

    egg_moves(RHYHORN,
              MOVE_CRUNCH,
              MOVE_REVERSAL,
              MOVE_MAGNITUDE,
              MOVE_CRUSH_CLAW),

    egg_moves(TANGELA,
              MOVE_FLAIL,
              MOVE_CONFUSION,
              MOVE_AMNESIA,
              MOVE_LEECH_SEED),

    egg_moves(KANGASKHAN,
              MOVE_STOMP,
              MOVE_FOCUS_ENERGY,
              MOVE_DISABLE,
              MOVE_CRUSH_CLAW),

    egg_moves(HORSEA,
              MOVE_FLAIL,
              MOVE_AURORA_BEAM,
              MOVE_OCTAZOOKA,
              MOVE_DISABLE,
              MOVE_SPLASH,
              MOVE_DRAGON_BREATH),

    egg_moves(GOLDEEN,
              MOVE_PSYBEAM,
              MOVE_HAZE),

    egg_moves(MR_MIME,
              MOVE_HYPNOSIS,
              MOVE_FAKE_OUT),

    egg_moves(SCYTHER,
              MOVE_BATON_PASS,
              MOVE_REVERSAL,
              MOVE_SILVER_WIND),

    egg_moves(PINSIR,
              MOVE_FURY_ATTACK,
              MOVE_FLAIL,
              MOVE_FALSE_SWIPE,
              MOVE_FEINT_ATTACK),

    egg_moves(LAPRAS,
              MOVE_TICKLE,
              MOVE_DRAGON_DANCE),

    egg_moves(EEVEE,
              MOVE_FLAIL,
              MOVE_TICKLE),

    egg_moves(OMANYTE,
              MOVE_AURORA_BEAM,
              MOVE_SLAM,
              MOVE_SUPERSONIC,
              MOVE_HAZE,
              MOVE_SPIKES),

    egg_moves(KABUTO,
              MOVE_BUBBLE_BEAM,
              MOVE_AURORA_BEAM,
              MOVE_RAPID_SPIN,
              MOVE_FLAIL,
              MOVE_CONFUSE_RAY),

    egg_moves(AERODACTYL,
              MOVE_WHIRLWIND,
              MOVE_PURSUIT,
              MOVE_DRAGON_BREATH),

    egg_moves(DRATINI,
              MOVE_HAZE,
              MOVE_SUPERSONIC,
              MOVE_DRAGON_BREATH,
              MOVE_EXTREME_SPEED),

    egg_moves(CHIKORITA,
              MOVE_VINE_WHIP,
              MOVE_LEECH_SEED,
              MOVE_ANCIENT_POWER,
              MOVE_FLAIL,
              MOVE_GRASS_WHISTLE),

    egg_moves(CYNDAQUIL,
              MOVE_FURY_SWIPES,
              MOVE_QUICK_ATTACK,
              MOVE_REVERSAL,
              MOVE_THRASH,
              MOVE_COVET,
              MOVE_HOWL,
              MOVE_CRUSH_CLAW),

    egg_moves(TOTODILE,
              MOVE_CRUNCH,
              MOVE_THRASH,
              MOVE_ANCIENT_POWER,
              MOVE_DRAGON_CLAW),

    egg_moves(SENTRET,
              MOVE_PURSUIT,
              MOVE_SLASH,
              MOVE_FOCUS_ENERGY,
              MOVE_CHARM,
              MOVE_REVERSAL),

    egg_moves(HOOTHOOT,
              MOVE_MIRROR_MOVE,
              MOVE_SUPERSONIC,
              MOVE_FEINT_ATTACK,
              MOVE_WING_ATTACK,
              MOVE_WHIRLWIND,
              MOVE_SKY_ATTACK,
              MOVE_FEATHER_DANCE),

    egg_moves(LEDYBA,
              MOVE_PSYBEAM,
              MOVE_SILVER_WIND),

    egg_moves(SPINARAK,
              MOVE_PSYBEAM,
              MOVE_DISABLE,
              MOVE_BATON_PASS,
              MOVE_PURSUIT,
              MOVE_SIGNAL_BEAM),

    egg_moves(CHINCHOU,
              MOVE_FLAIL,
              MOVE_SCREECH,
              MOVE_AMNESIA),

    egg_moves(PICHU,
              MOVE_REVERSAL,
              MOVE_ENCORE,
              MOVE_DOUBLE_SLAP,
              MOVE_CHARGE),

    egg_moves(CLEFFA,
              MOVE_AMNESIA,
              MOVE_BELLY_DRUM,
              MOVE_SPLASH),

    egg_moves(IGGLYBUFF,
              MOVE_FEINT_ATTACK),

    egg_moves(TOGEPI,
              MOVE_MIRROR_MOVE,
              MOVE_PECK),

    egg_moves(NATU,
              MOVE_HAZE,
              MOVE_DRILL_PECK,
              MOVE_QUICK_ATTACK,
              MOVE_FEINT_ATTACK,
              MOVE_FEATHER_DANCE),

    egg_moves(MAREEP,
              MOVE_TAKE_DOWN,
              MOVE_SCREECH,
              MOVE_CHARGE),

    egg_moves(HOPPIP,
              MOVE_CONFUSION,
              MOVE_ENCORE,
              MOVE_AMNESIA),

    egg_moves(AIPOM,
              MOVE_SCREECH,
              MOVE_PURSUIT,
              MOVE_AGILITY,
              MOVE_SLAM,
              MOVE_DOUBLE_SLAP),

    egg_moves(SUNKERN,
              MOVE_ENCORE),

    egg_moves(YANMA,
              MOVE_WHIRLWIND,
              MOVE_REVERSAL,
              MOVE_LEECH_LIFE,
              MOVE_SIGNAL_BEAM,
              MOVE_SILVER_WIND),

    egg_moves(WOOPER,
              MOVE_ANCIENT_POWER),

    egg_moves(MURKROW,
              MOVE_WHIRLWIND,
              MOVE_DRILL_PECK,
              MOVE_MIRROR_MOVE,
              MOVE_WING_ATTACK,
              MOVE_SKY_ATTACK,
              MOVE_CONFUSE_RAY,
              MOVE_FEATHER_DANCE,
              MOVE_PERISH_SONG),

    egg_moves(MISDREAVUS,
              MOVE_SCREECH,
              MOVE_DESTINY_BOND,
              MOVE_IMPRISON),

    egg_moves(GIRAFARIG,
              MOVE_TAKE_DOWN,
              MOVE_AMNESIA),

    egg_moves(PINECO,
              MOVE_PIN_MISSILE,
              MOVE_FLAIL,
              MOVE_SWIFT,
              MOVE_SAND_TOMB),

    egg_moves(DUNSPARCE,
              MOVE_ANCIENT_POWER,
              MOVE_BITE,
              MOVE_HEADBUTT,
              MOVE_ASTONISH),

    egg_moves(GLIGAR,
              MOVE_METAL_CLAW,
              MOVE_WING_ATTACK,
              MOVE_SAND_TOMB),

    egg_moves(SNUBBULL,
              MOVE_FEINT_ATTACK,
              MOVE_CRUNCH),

    egg_moves(QWILFISH,
              MOVE_FLAIL,
              MOVE_HAZE,
              MOVE_BUBBLE_BEAM,
              MOVE_SUPERSONIC,
              MOVE_ASTONISH),

    egg_moves(SHUCKLE,
              MOVE_SWEET_SCENT),

    egg_moves(HERACROSS,
              MOVE_HARDEN,
              MOVE_FLAIL,
              MOVE_FALSE_SWIPE),

    egg_moves(SNEASEL,
              MOVE_BITE,
              MOVE_CRUSH_CLAW,
              MOVE_FAKE_OUT),

    egg_moves(TEDDIURSA,
              MOVE_CRUNCH,
              MOVE_TAKE_DOWN,
              MOVE_SEISMIC_TOSS,
              MOVE_METAL_CLAW,
              MOVE_FAKE_TEARS,
              MOVE_YAWN),

    egg_moves(SLUGMA,
              MOVE_ACID_ARMOR),

    egg_moves(SWINUB,
              MOVE_TAKE_DOWN,
              MOVE_BITE,
              MOVE_ANCIENT_POWER,
              MOVE_MUD_SHOT,
              MOVE_ICICLE_SPEAR),

    egg_moves(CORSOLA,
              MOVE_SCREECH,
              MOVE_AMNESIA,
              MOVE_BARRIER,
              MOVE_CONFUSE_RAY,
              MOVE_ICICLE_SPEAR),

    egg_moves(REMORAID,
              MOVE_AURORA_BEAM,
              MOVE_OCTAZOOKA,
              MOVE_SUPERSONIC,
              MOVE_HAZE,
              MOVE_SCREECH,
              MOVE_ROCK_BLAST),

    egg_moves(MANTINE,
              MOVE_TWISTER,
              MOVE_HAZE,
              MOVE_SLAM),

    egg_moves(SKARMORY,
              MOVE_PURSUIT,
              MOVE_SKY_ATTACK),

    egg_moves(HOUNDOUR,
              MOVE_PURSUIT,
              MOVE_REVERSAL),

    egg_moves(PHANPY,
              MOVE_FOCUS_ENERGY,
              MOVE_ANCIENT_POWER),

    egg_moves(STANTLER,
              MOVE_DISABLE,
              MOVE_BITE,
              MOVE_SWAGGER,
              MOVE_EXTRASENSORY),

    egg_moves(TYROGUE,
              MOVE_HI_JUMP_KICK,
              MOVE_MACH_PUNCH,
              MOVE_RAPID_SPIN),

    egg_moves(SMOOCHUM,
              MOVE_MEDITATE,
              MOVE_FAKE_OUT),

    egg_moves(ELEKID,
              MOVE_KARATE_CHOP,
              MOVE_BARRIER,
              MOVE_ROLLING_KICK,
              MOVE_MEDITATE,
              MOVE_CROSS_CHOP),

    egg_moves(MAGBY,
              MOVE_KARATE_CHOP,
              MOVE_MEGA_PUNCH,
              MOVE_BARRIER,
              MOVE_SCREECH,
              MOVE_CROSS_CHOP),

    egg_moves(MILTANK,
              MOVE_REVERSAL,
              MOVE_SEISMIC_TOSS),

    egg_moves(LARVITAR,
              MOVE_PURSUIT,
              MOVE_STOMP,
              MOVE_OUTRAGE,
              MOVE_FOCUS_ENERGY,
              MOVE_ANCIENT_POWER,
              MOVE_DRAGON_DANCE),

    egg_moves(TREECKO,
              MOVE_CRUNCH,
              MOVE_ENDEAVOR,
              MOVE_LEECH_SEED,
              MOVE_DRAGON_BREATH,
              MOVE_GRASS_WHISTLE,
              MOVE_CRUSH_CLAW),

    egg_moves(TORCHIC,
              MOVE_REVERSAL,
              MOVE_SWAGGER,
              MOVE_SMELLING_SALT),

    egg_moves(MUDKIP,
              MOVE_STOMP,
              MOVE_ICE_BALL,
              MOVE_MIRROR_COAT),

    egg_moves(POOCHYENA,
              MOVE_ASTONISH,
              MOVE_POISON_FANG,
              MOVE_COVET,
              MOVE_LEER,
              MOVE_YAWN),

    egg_moves(ZIGZAGOON,
              MOVE_CHARM,
              MOVE_PURSUIT,
              MOVE_TICKLE),

    egg_moves(LOTAD,
              MOVE_SYNTHESIS,
              MOVE_RAZOR_LEAF,
              MOVE_SWEET_SCENT,
              MOVE_LEECH_SEED,
              MOVE_FLAIL,
              MOVE_WATER_GUN),

    egg_moves(SEEDOT,
              MOVE_LEECH_SEED,
              MOVE_AMNESIA,
              MOVE_QUICK_ATTACK,
              MOVE_TAKE_DOWN,
              MOVE_FALSE_SWIPE),

    egg_moves(NINCADA,
              MOVE_FEINT_ATTACK,
              MOVE_GUST,
              MOVE_SILVER_WIND),

    egg_moves(TAILLOW,
              MOVE_PURSUIT,
              MOVE_SUPERSONIC,
              MOVE_MIRROR_MOVE,
              MOVE_SKY_ATTACK),

    egg_moves(SHROOMISH,
              MOVE_FAKE_TEARS,
              MOVE_SWAGGER,
              MOVE_CHARM,
              MOVE_FALSE_SWIPE),

    egg_moves(SPINDA,
              MOVE_ENCORE,
              MOVE_DISABLE,
              MOVE_BATON_PASS,
              MOVE_SMELLING_SALT),

    egg_moves(WINGULL,
              MOVE_TWISTER,
              MOVE_AGILITY,
              MOVE_GUST),

    egg_moves(SURSKIT,
              MOVE_MUD_SHOT,
              MOVE_PSYBEAM,
              MOVE_HYDRO_PUMP,
              MOVE_MIND_READER),

    egg_moves(WAILMER,
              MOVE_THRASH,
              MOVE_SWAGGER,
              MOVE_TICKLE),

    egg_moves(SKITTY,
              MOVE_FAKE_TEARS,
              MOVE_BATON_PASS,
              MOVE_TICKLE),

    egg_moves(KECLEON,
              MOVE_DISABLE),

    egg_moves(NOSEPASS,
              MOVE_MAGNITUDE,
              MOVE_ROLLOUT),

    egg_moves(TORKOAL,
              MOVE_YAWN),

    egg_moves(SABLEYE,
              MOVE_RECOVER),

    egg_moves(BARBOACH,
              MOVE_THRASH,
              MOVE_WHIRLPOOL,
              MOVE_SPARK),

    egg_moves(LUVDISC,
              MOVE_SPLASH,
              MOVE_SUPERSONIC),

    egg_moves(CORPHISH,
              MOVE_ENDEAVOR,
              MOVE_ANCIENT_POWER),

    egg_moves(FEEBAS,
              MOVE_MIRROR_COAT,
              MOVE_DRAGON_BREATH,
              MOVE_HYPNOSIS,
              MOVE_CONFUSE_RAY),

    egg_moves(CARVANHA,
              MOVE_HYDRO_PUMP,
              MOVE_THRASH),

    egg_moves(TRAPINCH,
              MOVE_FOCUS_ENERGY,
              MOVE_QUICK_ATTACK,
              MOVE_GUST),

    egg_moves(MAKUHITA,
              MOVE_FEINT_ATTACK,
              MOVE_CROSS_CHOP,
              MOVE_DYNAMIC_PUNCH),

    egg_moves(ELECTRIKE,
              MOVE_CRUNCH,
              MOVE_HEADBUTT,
              MOVE_SWIFT),

    egg_moves(NUMEL,
              MOVE_HOWL,
              MOVE_SCARY_FACE,
              MOVE_ROLLOUT,
              MOVE_DEFENSE_CURL,
              MOVE_STOMP),

    egg_moves(SPHEAL,
              MOVE_YAWN),

    egg_moves(CACNEA,
              MOVE_GRASS_WHISTLE,
              MOVE_ACID,
              MOVE_TEETER_DANCE,
              MOVE_DYNAMIC_PUNCH),

    egg_moves(SNORUNT,
              MOVE_BLOCK,
              MOVE_SPIKES),

    egg_moves(AZURILL,
              MOVE_AMNESIA,
              MOVE_BELLY_DRUM,
              MOVE_PERISH_SONG,
              MOVE_SUPERSONIC,
              MOVE_ENCORE,
              MOVE_SING,
              MOVE_SLAM,
              MOVE_TICKLE),

    egg_moves(SPOINK,
              MOVE_EXTRASENSORY),

    egg_moves(MAWILE,
              MOVE_FALSE_SWIPE,
              MOVE_POISON_FANG,
              MOVE_ANCIENT_POWER,
              MOVE_TICKLE),

    egg_moves(MEDITITE,
              MOVE_FAKE_OUT,
              MOVE_BATON_PASS,
              MOVE_DYNAMIC_PUNCH),

    egg_moves(SWABLU,
              MOVE_AGILITY,
              MOVE_HAZE,
              MOVE_PURSUIT),

    egg_moves(DUSKULL,
              MOVE_IMPRISON,
              MOVE_DESTINY_BOND,
              MOVE_PAIN_SPLIT,
              MOVE_MEMENTO,
              MOVE_FEINT_ATTACK),

    egg_moves(ROSELIA,
              MOVE_SPIKES,
              MOVE_SYNTHESIS,
              MOVE_PIN_MISSILE,
              MOVE_COTTON_SPORE),

    egg_moves(SLAKOTH,
              MOVE_PURSUIT,
              MOVE_SLASH,
              MOVE_CRUSH_CLAW),

    egg_moves(GULPIN,
              MOVE_ACID_ARMOR,
              MOVE_SMOG,
              MOVE_PAIN_SPLIT),

    egg_moves(TROPIUS,
              MOVE_HEADBUTT,
              MOVE_SLAM,
              MOVE_LEECH_SEED),

    egg_moves(WHISMUR,
              MOVE_TAKE_DOWN,
              MOVE_SWAGGER,
              MOVE_EXTRASENSORY,
              MOVE_SMELLING_SALT),

    egg_moves(CLAMPERL,
              MOVE_SUPERSONIC,
              MOVE_BARRIER,
              MOVE_CONFUSE_RAY),

    egg_moves(ABSOL,
              MOVE_BATON_PASS,
              MOVE_FEINT_ATTACK),

    egg_moves(SHUPPET,
              MOVE_DISABLE,
              MOVE_DESTINY_BOND,
              MOVE_ASTONISH,
              MOVE_IMPRISON),

    egg_moves(ZANGOOSE,
              MOVE_FLAIL,
              MOVE_DOUBLE_KICK),

    egg_moves(RELICANTH,
              MOVE_MAGNITUDE,
              MOVE_SKULL_BASH,
              MOVE_AMNESIA),

    egg_moves(ARON,
              MOVE_ENDEAVOR,
              MOVE_STOMP,
              MOVE_SMELLING_SALT),

    egg_moves(VOLBEAT,
              MOVE_BATON_PASS,
              MOVE_SILVER_WIND),

    egg_moves(ILLUMISE,
              MOVE_BATON_PASS,
              MOVE_SILVER_WIND,
              MOVE_GROWTH),

    egg_moves(LILEEP,
              MOVE_BARRIER,
              MOVE_RECOVER,
              MOVE_MIRROR_COAT),

    egg_moves(ANORITH,
              MOVE_RAPID_SPIN,
              MOVE_KNOCK_OFF),

    egg_moves(RALTS,
              MOVE_DISABLE,
              MOVE_MEAN_LOOK,
              MOVE_MEMENTO,
              MOVE_DESTINY_BOND),

    egg_moves(BAGON,
              MOVE_HYDRO_PUMP,
              MOVE_THRASH,
              MOVE_TWISTER,
              MOVE_DRAGON_DANCE),

    egg_moves(CHIMECHO,
              MOVE_DISABLE,
              MOVE_HYPNOSIS),

    EGG_MOVES_TERMINATOR
};
