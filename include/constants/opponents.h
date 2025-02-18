#ifndef GUARD_CONSTANTS_OPPONENTS_H
#define GUARD_CONSTANTS_OPPONENTS_H


//TODO remove unused trainers
enum {
	TRAINER_NONE = 0,
	TRAINER_AQUA_LEADER,
	TRAINER_AQUA_GRUNT_M,
	TRAINER_AQUA_GRUNT_F,
	TRAINER_RS_AROMA_LADY,
	TRAINER_RS_RUIN_MANIAC,
	TRAINER_INTERVIEWER,
	TRAINER_RS_TUBER_F,
	TRAINER_RS_TUBER_M,
	TRAINER_RS_COOLTRAINER_M,
	TRAINER_RS_COOLTRAINER_F,
	TRAINER_HEX_MANIAC,
	TRAINER_RS_LADY,
	TRAINER_RS_BEAUTY,
	TRAINER_RICH_BOY,
	TRAINER_RS_POKEMANIAC,
	TRAINER_RS_SWIMMER_M,
	TRAINER_RS_BLACK_BELT,
	TRAINER_GUITARIST,
	TRAINER_KINDLER,
	TRAINER_RS_CAMPER,
	TRAINER_BUG_MANIAC,
	TRAINER_RS_PSYCHIC_M,
	TRAINER_RS_PSYCHIC_F,
	TRAINER_RS_GENTLEMAN,
	TRAINER_ELITE_FOUR_SIDNEY,
	TRAINER_ELITE_FOUR_PHOEBE,
	TRAINER_LEADER_ROXANNE,
	TRAINER_LEADER_BRAWLY,
	TRAINER_LEADER_TATE_LIZA,
	TRAINER_SCHOOL_KID_M,
	TRAINER_SCHOOL_KID_F,
	TRAINER_SR_AND_JR,
	TRAINER_POKEFAN_M,
	TRAINER_POKEFAN_F,
	TRAINER_EXPERT_M,
	TRAINER_EXPERT_F,
	TRAINER_RS_YOUNGSTER,
	TRAINER_RS_CHAMPION,
	TRAINER_RS_FISHERMAN,
	TRAINER_CYCLING_TRIATHLETE_M,
	TRAINER_CYCLING_TRIATHLETE_F,
	TRAINER_RUNNING_TRIATHLETE_M,
	TRAINER_RUNNING_TRIATHLETE_F,
	TRAINER_SWIMMING_TRIATHLETE_M,
	TRAINER_SWIMMING_TRIATHLETE_F,
	TRAINER_DRAGON_TAMER,
	TRAINER_RS_BIRD_KEEPER,
	TRAINER_NINJA_BOY,
	TRAINER_BATTLE_GIRL,
	TRAINER_PARASOL_LADY,
	TRAINER_RS_SWIMMER_F,
	TRAINER_RS_PICNICKER,
	TRAINER_RS_TWINS,
	TRAINER_RS_SAILOR,
	TRAINER_BOARDER_M,
	TRAINER_BOARDER_F,
	TRAINER_COLLECTOR,
	TRAINER_WALLY,
	TRAINER_BRENDAN,
	TRAINER_BRENDAN_2,
	TRAINER_BRENDAN_3,
	TRAINER_MAY,
	TRAINER_MAY_2,
	TRAINER_MAY_3,
	TRAINER_RS_PKMN_BREEDER_M,
	TRAINER_RS_PKMN_BREEDER_F,
	TRAINER_RS_PKMN_RANGER_M,
	TRAINER_RS_PKMN_RANGER_F,
	TRAINER_MAGMA_LEADER,
	TRAINER_MAGMA_GRUNT_M,
	TRAINER_MAMGA_GRUNT_F,
	TRAINER_RS_LASS,
	TRAINER_RS_BUG_CATCHER,
	TRAINER_RS_HIKER,
	TRAINER_RS_YOUNG_COUPLE,
	TRAINER_OLD_COUPLE,
	TRAINER_RS_SIS_AND_BRO,
	TRAINER_AQUA_ADMIN_MATT,
	TRAINER_AQUA_ADMIN_SHELLY,
	TRAINER_MAGMA_ADMIN_TABITHA,
	TRAINER_MAGMA_ADMIN_COURTNEY,
	TRAINER_LEADER_WATTSON,
	TRAINER_LEADER_FLANNERY,
	TRAINER_LEADER_NORMAN,
	TRAINER_LEADER_WINONA,
	TRAINER_LEADER_WALLACE,
	TRAINER_ELITE_FOUR_GLACIA,
	TRAINER_ELITE_FOUR_DRAKE,
// Actual FRLG trainers start here
	TRAINER_YOUNGSTER_BEN,
	TRAINER_YOUNGSTER_CALVIN,
	TRAINER_YOUNGSTER_JOSH,
	TRAINER_YOUNGSTER_TIMMY,
	TRAINER_YOUNGSTER_JOEY,
	TRAINER_YOUNGSTER_DAN,
	TRAINER_YOUNGSTER_CHAD,
	TRAINER_YOUNGSTER_TYLER,
	TRAINER_YOUNGSTER_EDDIE,
	TRAINER_YOUNGSTER_DILLON,
	TRAINER_YOUNGSTER_YASU,
	TRAINER_YOUNGSTER_DAVE,
	TRAINER_YOUNGSTER_BEN_2,
	TRAINER_BUG_CATCHER_RICK,
	TRAINER_BUG_CATCHER_DOUG,
	TRAINER_BUG_CATCHER_SAMMY,
	TRAINER_BUG_CATCHER_COLTON,
	TRAINER_BUG_CATCHER_GREG,
	TRAINER_BUG_CATCHER_JAMES,
	TRAINER_BUG_CATCHER_KENT,
	TRAINER_BUG_CATCHER_ROBBY,
	TRAINER_BUG_CATCHER_CALE,
	TRAINER_BUG_CATCHER_KEIGO,
	TRAINER_BUG_CATCHER_ELIJAH,
	TRAINER_BUG_CATCHER_2,
	TRAINER_BUG_CATCHER_BRENT,
	TRAINER_BUG_CATCHER_CONNER,
	TRAINER_LASS_JANICE,
	TRAINER_LASS_SALLY,
	TRAINER_LASS_ROBIN,
	TRAINER_LASS_CRISSY,
	TRAINER_LASS_MIRIAM,
	TRAINER_LASS_IRIS,
	TRAINER_LASS_RELI,
	TRAINER_LASS_ALI,
	TRAINER_LASS_2,
	TRAINER_LASS_HALEY,
	TRAINER_LASS_ANN,
	TRAINER_LASS_DAWN,
	TRAINER_LASS_PAIGE,
	TRAINER_LASS_ANDREA,
	TRAINER_LASS_MEGAN,
	TRAINER_LASS_JULIA,
	TRAINER_LASS_KAY,
	TRAINER_LASS_LISA,
	TRAINER_SAILOR_EDMOND,
	TRAINER_SAILOR_TREVOR,
	TRAINER_SAILOR_LEONARD,
	TRAINER_SAILOR_DUNCAN,
	TRAINER_SAILOR_HUEY,
	TRAINER_SAILOR_DYLAN,
	TRAINER_SAILOR_PHILLIP,
	TRAINER_SAILOR_DWAYNE,
	TRAINER_CAMPER_LIAM,
	TRAINER_CAMPER_SHANE,
	TRAINER_CAMPER_ETHAN,
	TRAINER_CAMPER_RICKY,
	TRAINER_CAMPER_JEFF,
	TRAINER_CAMPER_2,
	TRAINER_CAMPER_CHRIS,
	TRAINER_CAMPER_DREW,
	TRAINER_PICNICKER_DIANA,
	TRAINER_PICNICKER_NANCY,
	TRAINER_PICNICKER_ISABELLE,
	TRAINER_PICNICKER_KELSEY,
	TRAINER_PICNICKER_ALICIA,
	TRAINER_PICNICKER_CAITLIN,
	TRAINER_PICNICKER_HEIDI,
	TRAINER_PICNICKER_CAROL,
	TRAINER_PICNICKER_SOFIA,
	TRAINER_PICNICKER_MARTHA,
	TRAINER_PICNICKER_TINA,
	TRAINER_PICNICKER_HANNAH,
	TRAINER_POKEMANIAC_MARK,
	TRAINER_POKEMANIAC_HERMAN,
	TRAINER_POKEMANIAC_COOPER,
	TRAINER_POKEMANIAC_STEVE,
	TRAINER_POKEMANIAC_WINSTON,
	TRAINER_POKEMANIAC_DAWSON,
	TRAINER_POKEMANIAC_ASHTON,
	TRAINER_SUPER_NERD_JOVAN,
	TRAINER_SUPER_NERD_MIGUEL,
	TRAINER_SUPER_NERD_AIDAN,
	TRAINER_SUPER_NERD_GLENN,
	TRAINER_SUPER_NERD_LESLIE,
	TRAINER_SUPER_NERD_1,
	TRAINER_SUPER_NERD_2,
	TRAINER_SUPER_NERD_3,
	TRAINER_SUPER_NERD_ERIK,
	TRAINER_SUPER_NERD_AVERY,
	TRAINER_SUPER_NERD_DEREK,
	TRAINER_SUPER_NERD_ZAC,
	TRAINER_HIKER_MARCOS,
	TRAINER_HIKER_FRANKLIN,
	TRAINER_HIKER_NOB,
	TRAINER_HIKER_WAYNE,
	TRAINER_HIKER_ALAN,
	TRAINER_HIKER_BRICE,
	TRAINER_HIKER_CLARK,
	TRAINER_HIKER_TRENT,
	TRAINER_HIKER_DUDLEY,
	TRAINER_HIKER_ALLEN,
	TRAINER_HIKER_ERIC,
	TRAINER_HIKER_LENNY,
	TRAINER_HIKER_OLIVER,
	TRAINER_HIKER_LUCAS,
	TRAINER_BIKER_JARED,
	TRAINER_BIKER_MALIK,
	TRAINER_BIKER_ERNEST,
	TRAINER_BIKER_ALEX,
	TRAINER_BIKER_LAO,
	TRAINER_BIKER_1,
	TRAINER_BIKER_HIDEO,
	TRAINER_BIKER_RUBEN,
	TRAINER_BIKER_BILLY,
	TRAINER_BIKER_NIKOLAS,
	TRAINER_BIKER_JAXON,
	TRAINER_BIKER_WILLIAM,
	TRAINER_BIKER_LUKAS,
	TRAINER_BIKER_ISAAC,
	TRAINER_BIKER_GERALD,
	TRAINER_BURGLAR_1,
	TRAINER_BURGLAR_2,
	TRAINER_BURGLAR_3,
	TRAINER_BURGLAR_QUINN,
	TRAINER_BURGLAR_RAMON,
	TRAINER_BURGLAR_DUSTY,
	TRAINER_BURGLAR_ARNIE,
	TRAINER_BURGLAR_4,
	TRAINER_BURGLAR_SIMON,
	TRAINER_BURGLAR_LEWIS,
	TRAINER_ENGINEER_BAILY,
	TRAINER_ENGINEER_BRAXTON,
	TRAINER_ENGINEER_BERNIE,
	TRAINER_FISHERMAN_DALE,
	TRAINER_FISHERMAN_BARNY,
	TRAINER_FISHERMAN_NED,
	TRAINER_FISHERMAN_CHIP,
	TRAINER_FISHERMAN_HANK,
	TRAINER_FISHERMAN_ELLIOT,
	TRAINER_FISHERMAN_RONALD,
	TRAINER_FISHERMAN_CLAUDE,
	TRAINER_FISHERMAN_WADE,
	TRAINER_FISHERMAN_NOLAN,
	TRAINER_FISHERMAN_ANDREW,
	TRAINER_SWIMMER_MALE_LUIS,
	TRAINER_SWIMMER_MALE_RICHARD,
	TRAINER_SWIMMER_MALE_REECE,
	TRAINER_SWIMMER_MALE_MATTHEW,
	TRAINER_SWIMMER_MALE_DOUGLAS,
	TRAINER_SWIMMER_MALE_DAVID,
	TRAINER_SWIMMER_MALE_TONY,
	TRAINER_SWIMMER_MALE_AXLE,
	TRAINER_SWIMMER_MALE_BARRY,
	TRAINER_SWIMMER_MALE_DEAN,
	TRAINER_SWIMMER_MALE_DARRIN,
	TRAINER_SWIMMER_MALE_SPENCER,
	TRAINER_SWIMMER_MALE_JACK,
	TRAINER_SWIMMER_MALE_JEROME,
	TRAINER_SWIMMER_MALE_ROLAND,
	TRAINER_CUE_BALL_KOJI,
	TRAINER_CUE_BALL_LUKE,
	TRAINER_CUE_BALL_CAMRON,
	TRAINER_CUE_BALL_RAUL,
	TRAINER_CUE_BALL_ISAIAH,
	TRAINER_CUE_BALL_ZEEK,
	TRAINER_CUE_BALL_JAMAL,
	TRAINER_CUE_BALL_COREY,
	TRAINER_CUE_BALL_CHASE,
	TRAINER_GAMER_HUGO,
	TRAINER_GAMER_JASPER,
	TRAINER_GAMER_DIRK,
	TRAINER_GAMER_DARIAN,
	TRAINER_GAMER_STAN,
	TRAINER_GAMER_1,
	TRAINER_GAMER_RICH,
	TRAINER_BEAUTY_BRIDGET,
	TRAINER_BEAUTY_TAMIA,
	TRAINER_BEAUTY_LORI,
	TRAINER_BEAUTY_LOLA,
	TRAINER_BEAUTY_SHEILA,
	TRAINER_SWIMMER_FEMALE_TIFFANY,
	TRAINER_SWIMMER_FEMALE_NORA,
	TRAINER_SWIMMER_FEMALE_MELISSA,
	TRAINER_BEAUTY_GRACE,
	TRAINER_BEAUTY_OLIVIA,
	TRAINER_BEAUTY_LAUREN,
	TRAINER_SWIMMER_FEMALE_ANYA,
	TRAINER_SWIMMER_FEMALE_ALICE,
	TRAINER_SWIMMER_FEMALE_CONNIE,
	TRAINER_SWIMMER_FEMALE_SHIRLEY,
	TRAINER_PSYCHIC_JOHAN,
	TRAINER_PSYCHIC_TYRON,
	TRAINER_PSYCHIC_CAMERON,
	TRAINER_PSYCHIC_PRESTON,
	TRAINER_ROCKER_RANDALL,
	TRAINER_ROCKER_LUCA,
	TRAINER_JUGGLER_DALTON,
	TRAINER_JUGGLER_NELSON,
	TRAINER_JUGGLER_KIRK,
	TRAINER_JUGGLER_SHAWN,
	TRAINER_JUGGLER_GREGORY,
	TRAINER_JUGGLER_EDWARD,
	TRAINER_JUGGLER_KAYDEN,
	TRAINER_JUGGLER_NATE,
	TRAINER_TAMER_PHIL,
	TRAINER_TAMER_EDGAR,
	TRAINER_TAMER_JASON,
	TRAINER_TAMER_COLE,
	TRAINER_TAMER_VINCENT,
	TRAINER_TAMER_JOHN,
	TRAINER_BIRD_KEEPER_SEBASTIAN,
	TRAINER_BIRD_KEEPER_PERRY,
	TRAINER_BIRD_KEEPER_ROBERT,
	TRAINER_BIRD_KEEPER_DONALD,
	TRAINER_BIRD_KEEPER_BENNY,
	TRAINER_BIRD_KEEPER_EDWIN,
	TRAINER_BIRD_KEEPER_CHESTER,
	TRAINER_BIRD_KEEPER_WILTON,
	TRAINER_BIRD_KEEPER_RAMIRO,
	TRAINER_BIRD_KEEPER_JACOB,
	TRAINER_BIRD_KEEPER_ROGER,
	TRAINER_BIRD_KEEPER_REED,
	TRAINER_BIRD_KEEPER_KEITH,
	TRAINER_BIRD_KEEPER_CARTER,
	TRAINER_BIRD_KEEPER_MITCH,
	TRAINER_BIRD_KEEPER_BECK,
	TRAINER_BIRD_KEEPER_MARLON,
	TRAINER_BLACK_BELT_KOICHI,
	TRAINER_BLACK_BELT_MIKE,
	TRAINER_BLACK_BELT_HIDEKI,
	TRAINER_BLACK_BELT_AARON,
	TRAINER_BLACK_BELT_HITOSHI,
	TRAINER_BLACK_BELT_ATSUSHI,
	TRAINER_BLACK_BELT_KIYO,
	TRAINER_BLACK_BELT_TAKASHI,
	TRAINER_BLACK_BELT_DAISUKE,
	TRAINER_RIVAL_OAKS_LAB_SQUIRTLE,
	TRAINER_RIVAL_OAKS_LAB_BULBASAUR,
	TRAINER_RIVAL_OAKS_LAB_CHARMANDER,
	TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE,
	TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR,
	TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER,
	TRAINER_RIVAL_CERULEAN_SQUIRTLE,
	TRAINER_RIVAL_CERULEAN_BULBASAUR,
	TRAINER_RIVAL_CERULEAN_CHARMANDER,
	TRAINER_SCIENTIST_TED,
	TRAINER_SCIENTIST_CONNOR,
	TRAINER_SCIENTIST_JERRY,
	TRAINER_SCIENTIST_JOSE,
	TRAINER_SCIENTIST_RODNEY,
	TRAINER_SCIENTIST_BEAU,
	TRAINER_SCIENTIST_TAYLOR,
	TRAINER_SCIENTIST_JOSHUA,
	TRAINER_SCIENTIST_PARKER,
	TRAINER_SCIENTIST_ED,
	TRAINER_SCIENTIST_TRAVIS,
	TRAINER_SCIENTIST_BRAYDON,
	TRAINER_SCIENTIST_IVAN,
	TRAINER_BOSS_GIOVANNI,
	TRAINER_BOSS_GIOVANNI_2,
	TRAINER_LEADER_GIOVANNI,
	TRAINER_TEAM_ROCKET_GRUNT,
	TRAINER_TEAM_ROCKET_GRUNT_2,
	TRAINER_TEAM_ROCKET_GRUNT_3,
	TRAINER_TEAM_ROCKET_GRUNT_4,
	TRAINER_TEAM_ROCKET_GRUNT_5,
	TRAINER_TEAM_ROCKET_GRUNT_6,
	TRAINER_TEAM_ROCKET_GRUNT_7,
	TRAINER_TEAM_ROCKET_GRUNT_8,
	TRAINER_TEAM_ROCKET_GRUNT_9,
	TRAINER_TEAM_ROCKET_GRUNT_10,
	TRAINER_TEAM_ROCKET_GRUNT_11,
	TRAINER_TEAM_ROCKET_GRUNT_12,
	TRAINER_TEAM_ROCKET_GRUNT_13,
	TRAINER_TEAM_ROCKET_GRUNT_14,
	TRAINER_TEAM_ROCKET_GRUNT_15,
	TRAINER_TEAM_ROCKET_GRUNT_16,
	TRAINER_TEAM_ROCKET_GRUNT_17,
	TRAINER_TEAM_ROCKET_GRUNT_18,
	TRAINER_TEAM_ROCKET_GRUNT_19,
	TRAINER_TEAM_ROCKET_GRUNT_20,
	TRAINER_TEAM_ROCKET_GRUNT_21,
	TRAINER_TEAM_ROCKET_GRUNT_22,
	TRAINER_TEAM_ROCKET_GRUNT_23,
	TRAINER_TEAM_ROCKET_GRUNT_24,
	TRAINER_TEAM_ROCKET_GRUNT_25,
	TRAINER_TEAM_ROCKET_GRUNT_26,
	TRAINER_TEAM_ROCKET_GRUNT_27,
	TRAINER_TEAM_ROCKET_GRUNT_28,
	TRAINER_TEAM_ROCKET_GRUNT_29,
	TRAINER_TEAM_ROCKET_GRUNT_30,
	TRAINER_TEAM_ROCKET_GRUNT_31,
	TRAINER_TEAM_ROCKET_GRUNT_32,
	TRAINER_TEAM_ROCKET_GRUNT_33,
	TRAINER_TEAM_ROCKET_GRUNT_34,
	TRAINER_TEAM_ROCKET_GRUNT_35,
	TRAINER_TEAM_ROCKET_GRUNT_36,
	TRAINER_TEAM_ROCKET_GRUNT_37,
	TRAINER_TEAM_ROCKET_GRUNT_38,
	TRAINER_TEAM_ROCKET_GRUNT_39,
	TRAINER_TEAM_ROCKET_GRUNT_40,
	TRAINER_TEAM_ROCKET_GRUNT_41,
	TRAINER_COOLTRAINER_SAMUEL,
	TRAINER_COOLTRAINER_GEORGE,
	TRAINER_COOLTRAINER_COLBY,
	TRAINER_COOLTRAINER_PAUL,
	TRAINER_COOLTRAINER_ROLANDO,
	TRAINER_COOLTRAINER_GILBERT,
	TRAINER_COOLTRAINER_OWEN,
	TRAINER_COOLTRAINER_BERKE,
	TRAINER_COOLTRAINER_YUJI,
	TRAINER_COOLTRAINER_WARREN,
	TRAINER_COOLTRAINER_MARY,
	TRAINER_COOLTRAINER_CAROLINE,
	TRAINER_COOLTRAINER_ALEXA,
	TRAINER_COOLTRAINER_SHANNON,
	TRAINER_COOLTRAINER_NAOMI,
	TRAINER_COOLTRAINER_BROOKE,
	TRAINER_COOLTRAINER_AUSTINA,
	TRAINER_COOLTRAINER_JULIE,
	TRAINER_ELITE_FOUR_LORELEI,
	TRAINER_ELITE_FOUR_BRUNO,
	TRAINER_ELITE_FOUR_AGATHA,
	TRAINER_ELITE_FOUR_LANCE,
	TRAINER_LEADER_BROCK,
	TRAINER_LEADER_MISTY,
	TRAINER_LEADER_LT_SURGE,
	TRAINER_LEADER_ERIKA,
	TRAINER_LEADER_KOGA,
	TRAINER_LEADER_BLAINE,
	TRAINER_LEADER_SABRINA,
	TRAINER_GENTLEMAN_THOMAS,
	TRAINER_GENTLEMAN_ARTHUR,
	TRAINER_GENTLEMAN_TUCKER,
	TRAINER_GENTLEMAN_NORTON,
	TRAINER_GENTLEMAN_WALTER,
	TRAINER_RIVAL_SS_ANNE_SQUIRTLE,
	TRAINER_RIVAL_SS_ANNE_BULBASAUR,
	TRAINER_RIVAL_SS_ANNE_CHARMANDER,
	TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE,
	TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR,
	TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER,
	TRAINER_RIVAL_SILPH_SQUIRTLE,
	TRAINER_RIVAL_SILPH_BULBASAUR,
	TRAINER_RIVAL_SILPH_CHARMANDER,
	TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE,
	TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR,
	TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER,
	TRAINER_CHAMPION_FIRST_SQUIRTLE,
	TRAINER_CHAMPION_FIRST_BULBASAUR,
	TRAINER_CHAMPION_FIRST_CHARMANDER,
	TRAINER_CHANNELER_PATRICIA,
	TRAINER_CHANNELER_CARLY,
	TRAINER_CHANNELER_HOPE,
	TRAINER_CHANNELER_PAULA,
	TRAINER_CHANNELER_LAUREL,
	TRAINER_CHANNELER_JODY,
	TRAINER_CHANNELER_TAMMY,
	TRAINER_CHANNELER_RUTH,
	TRAINER_CHANNELER_KARINA,
	TRAINER_CHANNELER_JANAE,
	TRAINER_CHANNELER_ANGELICA,
	TRAINER_CHANNELER_EMILIA,
	TRAINER_CHANNELER_JENNIFER,
	TRAINER_CHANNELER_1,
	TRAINER_CHANNELER_2,
	TRAINER_CHANNELER_3,
	TRAINER_CHANNELER_4,
	TRAINER_CHANNELER_5,
	TRAINER_CHANNELER_6,
	TRAINER_CHANNELER_7,
	TRAINER_CHANNELER_8,
	TRAINER_CHANNELER_AMANDA,
	TRAINER_CHANNELER_STACY,
	TRAINER_CHANNELER_TASHA,
	TRAINER_HIKER_JEREMY,
	TRAINER_PICNICKER_ALMA,
	TRAINER_PICNICKER_SUSIE,
	TRAINER_PICNICKER_VALERIE,
	TRAINER_PICNICKER_GWEN,
	TRAINER_BIKER_VIRGIL,
	TRAINER_CAMPER_FLINT,
	TRAINER_PICNICKER_MISSY,
	TRAINER_PICNICKER_IRENE,
	TRAINER_PICNICKER_DANA,
	TRAINER_PICNICKER_ARIANA,
	TRAINER_PICNICKER_LEAH,
	TRAINER_CAMPER_JUSTIN,
	TRAINER_PICNICKER_YAZMIN,
	TRAINER_PICNICKER_KINDRA,
	TRAINER_PICNICKER_BECKY,
	TRAINER_PICNICKER_CELIA,
	TRAINER_GENTLEMAN_BROOKS,
	TRAINER_GENTLEMAN_LAMAR,
	TRAINER_TWINS_ELI_ANNE,
	TRAINER_COOL_COUPLE_RAY_TYRA,
	TRAINER_YOUNG_COUPLE_GIA_JES,
	TRAINER_TWINS_KIRI_JAN,
	TRAINER_CRUSH_KIN_RON_MYA,
	TRAINER_YOUNG_COUPLE_LEA_JED,
	TRAINER_SIS_AND_BRO_LIA_LUC,
	TRAINER_SIS_AND_BRO_LIL_IAN,
	TRAINER_BUG_CATCHER_3,
	TRAINER_BUG_CATCHER_4,
	TRAINER_BUG_CATCHER_5,
	TRAINER_BUG_CATCHER_6,
	TRAINER_BUG_CATCHER_7,
	TRAINER_BUG_CATCHER_8,
	TRAINER_YOUNGSTER_BEN_3,
	TRAINER_YOUNGSTER_BEN_4,
	TRAINER_YOUNGSTER_CHAD_2,
	TRAINER_LASS_RELI_2,
	TRAINER_LASS_RELI_3,
	TRAINER_YOUNGSTER_TIMMY_2,
	TRAINER_YOUNGSTER_TIMMY_3,
	TRAINER_YOUNGSTER_TIMMY_4,
	TRAINER_YOUNGSTER_CHAD_3,
	TRAINER_LASS_JANICE_2,
	TRAINER_LASS_JANICE_3,
	TRAINER_YOUNGSTER_CHAD_4,
	TRAINER_HIKER_FRANKLIN_2,
	TRAINER_PKMN_PROF_PROF_OAK,
	TRAINER_PLAYER_BRENDAN,
	TRAINER_PLAYER_MAY,
	TRAINER_PLAYER_RED,
	TRAINER_PLAYER_LEAF,
	TRAINER_TEAM_ROCKET_GRUNT_42,
	TRAINER_PSYCHIC_JACLYN,
	TRAINER_CRUSH_GIRL_SHARON,
	TRAINER_TUBER_AMIRA,
	TRAINER_PKMN_BREEDER_ALIZE,
	TRAINER_PKMN_RANGER_NICOLAS,
	TRAINER_PKMN_RANGER_MADELINE,
	TRAINER_AROMA_LADY_NIKKI,
	TRAINER_RUIN_MANIAC_STANLY,
	TRAINER_LADY_JACKI,
	TRAINER_PAINTER_DAISY,
	TRAINER_BIKER_GOON,
	TRAINER_BIKER_GOON_2,
	TRAINER_BIKER_GOON_3,
	TRAINER_BIKER_2,
	TRAINER_BUG_CATCHER_ANTHONY,
	TRAINER_BUG_CATCHER_CHARLIE,
	TRAINER_TWINS_ELI_ANNE_2,
	TRAINER_YOUNGSTER_JOHNSON,
	TRAINER_BIKER_RICARDO,
	TRAINER_BIKER_JAREN,
	TRAINER_TEAM_ROCKET_GRUNT_43,
	TRAINER_TEAM_ROCKET_GRUNT_44,
	TRAINER_TEAM_ROCKET_GRUNT_45,
	TRAINER_TEAM_ROCKET_GRUNT_46,
	TRAINER_TEAM_ROCKET_GRUNT_47,
	TRAINER_TEAM_ROCKET_GRUNT_48,
	TRAINER_TEAM_ROCKET_ADMIN,
	TRAINER_TEAM_ROCKET_ADMIN_2,
	TRAINER_SCIENTIST_GIDEON,
	TRAINER_SWIMMER_FEMALE_AMARA,
	TRAINER_SWIMMER_FEMALE_MARIA,
	TRAINER_SWIMMER_FEMALE_ABIGAIL,
	TRAINER_SWIMMER_MALE_FINN,
	TRAINER_SWIMMER_MALE_GARRETT,
	TRAINER_FISHERMAN_TOMMY,
	TRAINER_CRUSH_GIRL_TANYA,
	TRAINER_BLACK_BELT_SHEA,
	TRAINER_BLACK_BELT_HUGH,
	TRAINER_CAMPER_BRYCE,
	TRAINER_PICNICKER_CLAIRE,
	TRAINER_CRUSH_KIN_MIK_KIA,
	TRAINER_AROMA_LADY_VIOLET,
	TRAINER_TUBER_ALEXIS,
	TRAINER_TWINS_JOY_MEG,
	TRAINER_SWIMMER_FEMALE_TISHA,
	TRAINER_PAINTER_CELINA,
	TRAINER_PAINTER_RAYNA,
	TRAINER_LADY_GILLIAN,
	TRAINER_YOUNGSTER_DESTIN,
	TRAINER_SWIMMER_MALE_TOBY,
	TRAINER_TEAM_ROCKET_GRUNT_49,
	TRAINER_TEAM_ROCKET_GRUNT_50,
	TRAINER_TEAM_ROCKET_GRUNT_51,
	TRAINER_BIRD_KEEPER_MILO,
	TRAINER_BIRD_KEEPER_CHAZ,
	TRAINER_BIRD_KEEPER_HAROLD,
	TRAINER_FISHERMAN_TYLOR,
	TRAINER_SWIMMER_MALE_MYMO,
	TRAINER_SWIMMER_FEMALE_NICOLE,
	TRAINER_SIS_AND_BRO_AVA_GEB,
	TRAINER_AROMA_LADY_ROSE,
	TRAINER_SWIMMER_MALE_SAMIR,
	TRAINER_SWIMMER_FEMALE_DENISE,
	TRAINER_TWINS_MIU_MIA,
	TRAINER_HIKER_EARL,
	TRAINER_RUIN_MANIAC_FOSTER,
	TRAINER_RUIN_MANIAC_LARRY,
	TRAINER_HIKER_DARYL,
	TRAINER_POKEMANIAC_HECTOR,
	TRAINER_PSYCHIC_DARIO,
	TRAINER_PSYCHIC_RODETTE,
	TRAINER_AROMA_LADY_MIAH,
	TRAINER_YOUNG_COUPLE_EVE_JON,
	TRAINER_JUGGLER_MASON,
	TRAINER_CRUSH_GIRL_CYNDY,
	TRAINER_CRUSH_GIRL_JOCELYN,
	TRAINER_TAMER_EVAN,
	TRAINER_POKEMANIAC_MARK_2,
	TRAINER_PKMN_RANGER_LOGAN,
	TRAINER_PKMN_RANGER_JACKSON,
	TRAINER_PKMN_RANGER_BETH,
	TRAINER_PKMN_RANGER_KATELYN,
	TRAINER_COOLTRAINER_LEROY,
	TRAINER_COOLTRAINER_MICHELLE,
	TRAINER_COOL_COUPLE_LEX_NYA,
	TRAINER_RUIN_MANIAC_BRANDON,
	TRAINER_RUIN_MANIAC_BENJAMIN,
	TRAINER_PAINTER_EDNA,
	TRAINER_GENTLEMAN_CLIFFORD,
	TRAINER_LADY_SELPHY,
	TRAINER_RUIN_MANIAC_LAWSON,
	TRAINER_PSYCHIC_LAURA,
	TRAINER_PKMN_BREEDER_BETHANY,
	TRAINER_PKMN_BREEDER_ALLISON,
	TRAINER_BUG_CATCHER_GARRET,
	TRAINER_BUG_CATCHER_JONAH,
	TRAINER_BUG_CATCHER_VANCE,
	TRAINER_YOUNGSTER_NASH,
	TRAINER_YOUNGSTER_CORDELL,
	TRAINER_LASS_DALIA,
	TRAINER_LASS_JOANA,
	TRAINER_CAMPER_RILEY,
	TRAINER_PICNICKER_MARCY,
	TRAINER_RUIN_MANIAC_LAYTON,
	TRAINER_PICNICKER_KELSEY_2,
	TRAINER_PICNICKER_KELSEY_3,
	TRAINER_PICNICKER_KELSEY_4,
	TRAINER_CAMPER_RICKY_2,
	TRAINER_CAMPER_RICKY_3,
	TRAINER_CAMPER_RICKY_4,
	TRAINER_CAMPER_JEFF_2,
	TRAINER_CAMPER_JEFF_3,
	TRAINER_CAMPER_JEFF_4,
	TRAINER_PICNICKER_ISABELLE_2,
	TRAINER_PICNICKER_ISABELLE_3,
	TRAINER_PICNICKER_ISABELLE_4,
	TRAINER_YOUNGSTER_YASU_2,
	TRAINER_YOUNGSTER_YASU_3,
	TRAINER_ENGINEER_BERNIE_2,
	TRAINER_GAMER_DARIAN_2,
	TRAINER_CAMPER_CHRIS_2,
	TRAINER_CAMPER_CHRIS_3,
	TRAINER_CAMPER_CHRIS_4,
	TRAINER_PICNICKER_ALICIA_2,
	TRAINER_PICNICKER_ALICIA_3,
	TRAINER_PICNICKER_ALICIA_4,
	TRAINER_HIKER_JEREMY_2,
	TRAINER_POKEMANIAC_MARK_3,
	TRAINER_POKEMANIAC_HERMAN_2,
	TRAINER_POKEMANIAC_HERMAN_3,
	TRAINER_HIKER_TRENT_2,
	TRAINER_LASS_MEGAN_2,
	TRAINER_LASS_MEGAN_3,
	TRAINER_SUPER_NERD_GLENN_2,
	TRAINER_GAMER_RICH_2,
	TRAINER_BIKER_JAREN_2,
	TRAINER_FISHERMAN_ELLIOT_2,
	TRAINER_ROCKER_LUCA_2,
	TRAINER_BEAUTY_SHEILA_2,
	TRAINER_BIRD_KEEPER_ROBERT_2,
	TRAINER_BIRD_KEEPER_ROBERT_3,
	TRAINER_PICNICKER_SUSIE_2,
	TRAINER_PICNICKER_SUSIE_3,
	TRAINER_PICNICKER_SUSIE_4,
	TRAINER_BIKER_LUKAS_2,
	TRAINER_BIRD_KEEPER_BENNY_2,
	TRAINER_BIRD_KEEPER_BENNY_3,
	TRAINER_BIRD_KEEPER_MARLON_2,
	TRAINER_BIRD_KEEPER_MARLON_3,
	TRAINER_BEAUTY_GRACE_2,
	TRAINER_BIRD_KEEPER_CHESTER_2,
	TRAINER_BIRD_KEEPER_CHESTER_3,
	TRAINER_PICNICKER_BECKY_2,
	TRAINER_PICNICKER_BECKY_3,
	TRAINER_PICNICKER_BECKY_4,
	TRAINER_CRUSH_KIN_RON_MYA_2,
	TRAINER_CRUSH_KIN_RON_MYA_3,
	TRAINER_CRUSH_KIN_RON_MYA_4,
	TRAINER_BIKER_RUBEN_2,
	TRAINER_CUE_BALL_CAMRON_2,
	TRAINER_BIKER_JAXON_2,
	TRAINER_CUE_BALL_ISAIAH_2,
	TRAINER_CUE_BALL_COREY_2,
	TRAINER_BIRD_KEEPER_JACOB_2,
	TRAINER_BIRD_KEEPER_JACOB_3,
	TRAINER_SWIMMER_FEMALE_ALICE_2,
	TRAINER_SWIMMER_MALE_DARRIN_2,
	TRAINER_PICNICKER_MISSY_2,
	TRAINER_PICNICKER_MISSY_3,
	TRAINER_FISHERMAN_WADE_2,
	TRAINER_SWIMMER_MALE_JACK_2,
	TRAINER_SIS_AND_BRO_LIL_IAN_2,
	TRAINER_SIS_AND_BRO_LIL_IAN_3,
	TRAINER_SWIMMER_MALE_FINN_2,
	TRAINER_CRUSH_GIRL_SHARON_2,
	TRAINER_CRUSH_GIRL_SHARON_3,
	TRAINER_CRUSH_GIRL_TANYA_2,
	TRAINER_CRUSH_GIRL_TANYA_3,
	TRAINER_BLACK_BELT_SHEA_2,
	TRAINER_BLACK_BELT_SHEA_3,
	TRAINER_BLACK_BELT_HUGH_2,
	TRAINER_BLACK_BELT_HUGH_3,
	TRAINER_CRUSH_KIN_MIK_KIA_2,
	TRAINER_CRUSH_KIN_MIK_KIA_3,
	TRAINER_TUBER_AMIRA_2,
	TRAINER_TWINS_JOY_MEG_2,
	TRAINER_PAINTER_RAYNA_2,
	TRAINER_YOUNGSTER_DESTIN_2,
	TRAINER_PKMN_BREEDER_ALIZE_2,
	TRAINER_YOUNG_COUPLE_GIA_JES_2,
	TRAINER_YOUNG_COUPLE_GIA_JES_3,
	TRAINER_BIRD_KEEPER_MILO_2,
	TRAINER_BIRD_KEEPER_CHAZ_2,
	TRAINER_BIRD_KEEPER_HAROLD_2,
	TRAINER_SWIMMER_FEMALE_NICOLE_2,
	TRAINER_PSYCHIC_JACLYN_2,
	TRAINER_SWIMMER_MALE_SAMIR_2,
	TRAINER_HIKER_EARL_2,
	TRAINER_RUIN_MANIAC_LARRY_2,
	TRAINER_POKEMANIAC_HECTOR_2,
	TRAINER_PSYCHIC_DARIO_2,
	TRAINER_PSYCHIC_RODETTE_2,
	TRAINER_JUGGLER_MASON_2,
	TRAINER_PKMN_RANGER_NICOLAS_2,
	TRAINER_PKMN_RANGER_MADELINE_2,
	TRAINER_CRUSH_GIRL_CYNDY_2,
	TRAINER_TAMER_EVAN_2,
	TRAINER_PKMN_RANGER_JACKSON_2,
	TRAINER_PKMN_RANGER_KATELYN_2,
	TRAINER_COOLTRAINER_LEROY_2,
	TRAINER_COOLTRAINER_MICHELLE_2,
	TRAINER_COOL_COUPLE_LEX_NYA_2,
	TRAINER_BUG_CATCHER_COLTON_2,
	TRAINER_BUG_CATCHER_COLTON_3,
	TRAINER_BUG_CATCHER_COLTON_4,
	TRAINER_SWIMMER_MALE_MATTHEW_2,
	TRAINER_SWIMMER_MALE_TONY_2,
	TRAINER_SWIMMER_FEMALE_MELISSA_2,
	TRAINER_ELITE_FOUR_LORELEI_2,
	TRAINER_ELITE_FOUR_BRUNO_2,
	TRAINER_ELITE_FOUR_AGATHA_2,
	TRAINER_ELITE_FOUR_LANCE_2,
	TRAINER_CHAMPION_REMATCH_SQUIRTLE,
	TRAINER_CHAMPION_REMATCH_BULBASAUR,
	TRAINER_CHAMPION_REMATCH_CHARMANDER,
	TRAINER_CUE_BALL_PAXTON
};

// NOTE: Because each Trainer uses a flag to determine when they are defeated, there is 
//       only space for 25 additional trainers before trainer flag space overflows.
//       MAX_TRAINERS_COUNT can be increased but will take up additional saveblock space
#define MAX_TRAINERS_COUNT                       768

#endif  // GUARD_CONSTANTS_OPPONENTS_H
