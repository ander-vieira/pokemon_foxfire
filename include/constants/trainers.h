#ifndef GUARD_CONSTANTS_TRAINERS_H
#define GUARD_CONSTANTS_TRAINERS_H

#include "constants/opponents.h"

#define TRAINER_ENCOUNTER_MUSIC_MALE         0 // standard male encounter music
#define TRAINER_ENCOUNTER_MUSIC_FEMALE       1 // standard female encounter music
#define TRAINER_ENCOUNTER_MUSIC_GIRL         2 // used for male Tubers and Young Couples too
#define TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS   3
#define TRAINER_ENCOUNTER_MUSIC_INTENSE      4
#define TRAINER_ENCOUNTER_MUSIC_COOL         5
#define TRAINER_ENCOUNTER_MUSIC_AQUA         6
#define TRAINER_ENCOUNTER_MUSIC_MAGMA        7
#define TRAINER_ENCOUNTER_MUSIC_SWIMMER      8
#define TRAINER_ENCOUNTER_MUSIC_TWINS        9 // used for other trainer classes too
#define TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR  10
#define TRAINER_ENCOUNTER_MUSIC_HIKER       11 // used for other trainer classes too
#define TRAINER_ENCOUNTER_MUSIC_INTERVIEWER 12
#define TRAINER_ENCOUNTER_MUSIC_RICH        13 // Rich Boys and Gentlemen

//TODO remove unused trainers
enum {
	TRAINER_PIC_AQUA_LEADER_ARCHIE = 0,
	TRAINER_PIC_AQUA_GRUNT_M,
	TRAINER_PIC_AQUA_GRUNT_F,
	TRAINER_PIC_RS_AROMA_LADY,
	TRAINER_PIC_RS_RUIN_MANIAC,
	TRAINER_PIC_INTERVIEWER,
	TRAINER_PIC_RS_TUBER_F,
	TRAINER_PIC_RS_TUBER_M,
	TRAINER_PIC_RS_COOLTRAINER_M,
	TRAINER_PIC_RS_COOLTRAINER_F,
	TRAINER_PIC_HEX_MANIAC,
	TRAINER_PIC_RS_LADY,
	TRAINER_PIC_RS_BEAUTY,
	TRAINER_PIC_RICH_BOY,
	TRAINER_PIC_RS_POKEMANIAC,
	TRAINER_PIC_RS_SWIMMER_M,
	TRAINER_PIC_RS_BLACK_BELT,
	TRAINER_PIC_GUITARIST,
	TRAINER_PIC_KINDLER,
	TRAINER_PIC_RS_CAMPER,
	TRAINER_PIC_BUG_MANIAC,
	TRAINER_PIC_RS_PSYCHIC_M,
	TRAINER_PIC_RS_PSYCHIC_F,
	TRAINER_PIC_RS_GENTLEMAN,
	TRAINER_PIC_ELITE_FOUR_SIDNEY,
	TRAINER_PIC_ELITE_FOUR_PHOEBE,
	TRAINER_PIC_LEADER_ROXANNE,
	TRAINER_PIC_LEADER_BRAWLY,
	TRAINER_PIC_LEADER_TATE_AND_LIZA,
	TRAINER_PIC_SCHOOL_KID_M,
	TRAINER_PIC_SCHOOL_KID_F,
	TRAINER_PIC_SR_AND_JR,
	TRAINER_PIC_POKEFAN_M,
	TRAINER_PIC_POKEFAN_F,
	TRAINER_PIC_EXPERT_M,
	TRAINER_PIC_EXPERT_F,
	TRAINER_PIC_RS_YOUNGSTER,
	TRAINER_PIC_CHAMPION_STEVEN,
	TRAINER_PIC_RS_FISHERMAN,
	TRAINER_PIC_CYCLING_TRIATHLETE_M,
	TRAINER_PIC_CYCLING_TRIATHLETE_F,
	TRAINER_PIC_RUNNING_TRIATHLETE_M,
	TRAINER_PIC_RUNNING_TRIATHLETE_F,
	TRAINER_PIC_SWIMMING_TRIATHLETE_M,
	TRAINER_PIC_SWIMMING_TRIATHLETE_F,
	TRAINER_PIC_DRAGON_TAMER,
	TRAINER_PIC_RS_BIRD_KEEPER,
	TRAINER_PIC_NINJA_BOY,
	TRAINER_PIC_BATTLE_GIRL,
	TRAINER_PIC_PARASOL_LADY,
	TRAINER_PIC_RS_SWIMMER_F,
	TRAINER_PIC_RS_PICNICKER,
	TRAINER_PIC_RS_TWINS,
	TRAINER_PIC_RS_SAILOR,
	TRAINER_PIC_COLLECTOR,
	TRAINER_PIC_WALLY,
	TRAINER_PIC_RS_BRENDAN_1,
	TRAINER_PIC_RS_MAY_1,
	TRAINER_PIC_RS_POKEMON_BREEDER_M,
	TRAINER_PIC_RS_POKEMON_BREEDER_F,
	TRAINER_PIC_RS_POKEMON_RANGER_M,
	TRAINER_PIC_RS_POKEMON_RANGER_F,
	TRAINER_PIC_MAGMA_LEADER_MAXIE,
	TRAINER_PIC_MAGMA_GRUNT_M,
	TRAINER_PIC_MAGMA_GRUNT_F,
	TRAINER_PIC_RS_LASS,
	TRAINER_PIC_RS_BUG_CATCHER,
	TRAINER_PIC_RS_HIKER,
	TRAINER_PIC_RS_YOUNG_COUPLE,
	TRAINER_PIC_OLD_COUPLE,
	TRAINER_PIC_RS_SIS_AND_BRO,
	TRAINER_PIC_AQUA_ADMIN_M,
	TRAINER_PIC_AQUA_ADMIN_F,
	TRAINER_PIC_MAGMA_ADMIN_M,
	TRAINER_PIC_MAGMA_ADMIN_F,
	TRAINER_PIC_LEADER_WATTSON,
	TRAINER_PIC_LEADER_FLANNERY,
	TRAINER_PIC_LEADER_NORMAN,
	TRAINER_PIC_LEADER_WINONA,
	TRAINER_PIC_LEADER_WALLACE,
	TRAINER_PIC_ELITE_FOUR_GLACIA,
	TRAINER_PIC_ELITE_FOUR_DRAKE,
	TRAINER_PIC_YOUNGSTER,
	TRAINER_PIC_BUG_CATCHER,
	TRAINER_PIC_LASS,
	TRAINER_PIC_SAILOR,
	TRAINER_PIC_CAMPER,
	TRAINER_PIC_PICNICKER,
	TRAINER_PIC_POKEMANIAC,
	TRAINER_PIC_SUPER_NERD,
	TRAINER_PIC_HIKER,
	TRAINER_PIC_BIKER,
	TRAINER_PIC_BURGLAR,
	TRAINER_PIC_ENGINEER,
	TRAINER_PIC_FISHERMAN,
	TRAINER_PIC_SWIMMER_M,
	TRAINER_PIC_CUE_BALL,
	TRAINER_PIC_GAMER,
	TRAINER_PIC_BEAUTY,
	TRAINER_PIC_SWIMMER_F,
	TRAINER_PIC_PSYCHIC_M,
	TRAINER_PIC_ROCKER,
	TRAINER_PIC_JUGGLER,
	TRAINER_PIC_TAMER,
	TRAINER_PIC_BIRD_KEEPER,
	TRAINER_PIC_BLACK_BELT,
	TRAINER_PIC_RIVAL_EARLY,
	TRAINER_PIC_SCIENTIST,
	TRAINER_PIC_LEADER_GIOVANNI,
	TRAINER_PIC_ROCKET_GRUNT_M,
	TRAINER_PIC_COOLTRAINER_M,
	TRAINER_PIC_COOLTRAINER_F,
	TRAINER_PIC_ELITE_FOUR_LORELEI,
	TRAINER_PIC_ELITE_FOUR_BRUNO,
	TRAINER_PIC_ELITE_FOUR_AGATHA,
	TRAINER_PIC_ELITE_FOUR_LANCE,
	TRAINER_PIC_LEADER_BROCK,
	TRAINER_PIC_LEADER_MISTY,
	TRAINER_PIC_LEADER_LT_SURGE,
	TRAINER_PIC_LEADER_ERIKA,
	TRAINER_PIC_LEADER_KOGA,
	TRAINER_PIC_LEADER_BLAINE,
	TRAINER_PIC_LEADER_SABRINA,
	TRAINER_PIC_GENTLEMAN,
	TRAINER_PIC_RIVAL_LATE,
	TRAINER_PIC_CHAMPION_RIVAL,
	TRAINER_PIC_CHANNELER,
	TRAINER_PIC_TWINS,
	TRAINER_PIC_COOL_COUPLE,
	TRAINER_PIC_YOUNG_COUPLE,
	TRAINER_PIC_CRUSH_KIN,
	TRAINER_PIC_SIS_AND_BRO,
	TRAINER_PIC_PROFESSOR_OAK,
	TRAINER_PIC_RS_BRENDAN_2,
	TRAINER_PIC_RS_MAY_2,
	TRAINER_PIC_RED,
	TRAINER_PIC_LEAF,
	TRAINER_PIC_ROCKET_GRUNT_F,
	TRAINER_PIC_PSYCHIC_F,
	TRAINER_PIC_CRUSH_GIRL,
	TRAINER_PIC_TUBER_F,
	TRAINER_PIC_POKEMON_BREEDER,
	TRAINER_PIC_POKEMON_RANGER_M,
	TRAINER_PIC_POKEMON_RANGER_F,
	TRAINER_PIC_AROMA_LADY,
	TRAINER_PIC_RUIN_MANIAC,
	TRAINER_PIC_LADY,
	TRAINER_PIC_PAINTER,
};

// The player back pics are assumed to alternate according to the gender values (MALE/FEMALE)
#define TRAINER_BACK_PIC_RED                    0
#define TRAINER_BACK_PIC_LEAF                   1
#define TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN  2
#define TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY      3
#define TRAINER_BACK_PIC_POKEDUDE               4
#define TRAINER_BACK_PIC_OLD_MAN                5

// Special Trainer Ids.
#define TRAINER_UNION_ROOM          0xC00
#define TRAINER_LINK_OPPONENT       0x800
#define TRAINER_SECRET_BASE         0x400

//TODO remove unused trainers
enum {
	TRAINER_CLASS_AQUA_LEADER = 0,
	TRAINER_CLASS_TEAM_AQUA,
	TRAINER_CLASS_RS_AROMA_LADY,
	TRAINER_CLASS_RS_RUIN_MANIAC,
	TRAINER_CLASS_INTERVIEWER,
	TRAINER_CLASS_RS_TUBER_F,
	TRAINER_CLASS_RS_TUBER_M,
	TRAINER_CLASS_RS_COOLTRAINER,
	TRAINER_CLASS_HEX_MANIAC,
	TRAINER_CLASS_RS_LADY,
	TRAINER_CLASS_RS_BEAUTY,
	TRAINER_CLASS_RICH_BOY,
	TRAINER_CLASS_RS_POKEMANIAC,
	TRAINER_CLASS_RS_SWIMMER_M,
	TRAINER_CLASS_RS_BLACK_BELT,
	TRAINER_CLASS_GUITARIST,
	TRAINER_CLASS_KINDLER,
	TRAINER_CLASS_RS_CAMPER,
	TRAINER_CLASS_BUG_MANIAC,
	TRAINER_CLASS_RS_PSYCHIC,
	TRAINER_CLASS_RS_GENTLEMAN,
	TRAINER_CLASS_RS_ELITE_FOUR,
	TRAINER_CLASS_RS_LEADER,
	TRAINER_CLASS_SCHOOL_KID,
	TRAINER_CLASS_SR_AND_JR,
	TRAINER_CLASS_POKEFAN,
	TRAINER_CLASS_EXPERT,
	TRAINER_CLASS_RS_YOUNGSTER,
	TRAINER_CLASS_RS_CHAMPION,
	TRAINER_CLASS_RS_FISHERMAN,
	TRAINER_CLASS_TRIATHLETE,
	TRAINER_CLASS_DRAGON_TAMER,
	TRAINER_CLASS_RS_BIRD_KEEPER,
	TRAINER_CLASS_NINJA_BOY,
	TRAINER_CLASS_BATTLE_GIRL,
	TRAINER_CLASS_PARASOL_LADY,
	TRAINER_CLASS_RS_SWIMMER_F,
	TRAINER_CLASS_RS_PICNICKER,
	TRAINER_CLASS_RS_TWINS,
	TRAINER_CLASS_RS_SAILOR,
	TRAINER_CLASS_BOARDER,
	TRAINER_CLASS_COLLECTOR,
	TRAINER_CLASS_PKMN_TRAINER,
	TRAINER_CLASS_RS_PKMN_BREEDER,
	TRAINER_CLASS_RS_PKMN_RANGER,
	TRAINER_CLASS_MAGMA_LEADER,
	TRAINER_CLASS_TEAM_MAGMA,
	TRAINER_CLASS_RS_LASS,
	TRAINER_CLASS_RS_BUG_CATCHER,
	TRAINER_CLASS_RS_HIKER,
	TRAINER_CLASS_RS_YOUNG_COUPLE,
	TRAINER_CLASS_OLD_COUPLE,
	TRAINER_CLASS_RS_SIS_AND_BRO,
	TRAINER_CLASS_AQUA_ADMIN,
	TRAINER_CLASS_MAGMA_ADMIN,
	TRAINER_CLASS_YOUNGSTER,
	TRAINER_CLASS_BUG_CATCHER,
	TRAINER_CLASS_LASS,
	TRAINER_CLASS_SAILOR,
	TRAINER_CLASS_CAMPER,
	TRAINER_CLASS_PICNICKER,
	TRAINER_CLASS_POKEMANIAC,
	TRAINER_CLASS_SUPER_NERD,
	TRAINER_CLASS_HIKER,
	TRAINER_CLASS_BIKER,
	TRAINER_CLASS_BURGLAR,
	TRAINER_CLASS_ENGINEER,
	TRAINER_CLASS_FISHERMAN,
	TRAINER_CLASS_SWIMMER_M,
	TRAINER_CLASS_CUE_BALL,
	TRAINER_CLASS_GAMER,
	TRAINER_CLASS_BEAUTY,
	TRAINER_CLASS_SWIMMER_F,
	TRAINER_CLASS_PSYCHIC,
	TRAINER_CLASS_ROCKER,
	TRAINER_CLASS_JUGGLER,
	TRAINER_CLASS_TAMER,
	TRAINER_CLASS_BIRD_KEEPER,
	TRAINER_CLASS_BLACK_BELT,
	TRAINER_CLASS_RIVAL_EARLY,
	TRAINER_CLASS_SCIENTIST,
	TRAINER_CLASS_BOSS,
	TRAINER_CLASS_LEADER,
	TRAINER_CLASS_TEAM_ROCKET,
	TRAINER_CLASS_COOLTRAINER,
	TRAINER_CLASS_ELITE_FOUR,
	TRAINER_CLASS_GENTLEMAN,
	TRAINER_CLASS_RIVAL_LATE,
	TRAINER_CLASS_CHAMPION,
	TRAINER_CLASS_CHANNELER,
	TRAINER_CLASS_TWINS,
	TRAINER_CLASS_COOL_COUPLE,
	TRAINER_CLASS_YOUNG_COUPLE,
	TRAINER_CLASS_CRUSH_KIN,
	TRAINER_CLASS_SIS_AND_BRO,
	TRAINER_CLASS_PKMN_PROF,
	TRAINER_CLASS_PLAYER,
	TRAINER_CLASS_CRUSH_GIRL,
	TRAINER_CLASS_TUBER,
	TRAINER_CLASS_PKMN_BREEDER,
	TRAINER_CLASS_PKMN_RANGER,
	TRAINER_CLASS_AROMA_LADY,
	TRAINER_CLASS_RUIN_MANIAC,
	TRAINER_CLASS_LADY,
	TRAINER_CLASS_PAINTER,
};

//TODO remove unused trainers
enum {
	FACILITY_CLASS_AQUA_LEADER_ARCHIE = 0,
	FACILITY_CLASS_AQUA_GRUNT_M,
	FACILITY_CLASS_AQUA_GRUNT_F,
	FACILITY_CLASS_RS_AROMA_LADY,
	FACILITY_CLASS_RS_RUIN_MANIAC,
	FACILITY_CLASS_INTERVIEWER,
	FACILITY_CLASS_RS_TUBER_F,
	FACILITY_CLASS_RS_TUBER_M,
	FACILITY_CLASS_RS_COOLTRAINER_M,
	FACILITY_CLASS_RS_COOLTRAINER_F,
	FACILITY_CLASS_HEX_MANIAC,
	FACILITY_CLASS_RS_LADY,
	FACILITY_CLASS_RS_BEAUTY,
	FACILITY_CLASS_RICH_BOY,
	FACILITY_CLASS_RS_POKEMANIAC,
	FACILITY_CLASS_RS_SWIMMER_M,
	FACILITY_CLASS_RS_BLACK_BELT,
	FACILITY_CLASS_GUITARIST,
	FACILITY_CLASS_KINDLER,
	FACILITY_CLASS_RS_CAMPER,
	FACILITY_CLASS_BUG_MANIAC,
	FACILITY_CLASS_RS_PSYCHIC_M,
	FACILITY_CLASS_RS_PSYCHIC_F,
	FACILITY_CLASS_RS_GENTLEMAN,
	FACILITY_CLASS_ELITE_FOUR_SIDNEY,
	FACILITY_CLASS_ELITE_FOUR_PHOEBE,
	FACILITY_CLASS_LEADER_ROXANNE,
	FACILITY_CLASS_LEADER_BRAWLY,
	FACILITY_CLASS_LEADER_TATE_AND_LIZA,
	FACILITY_CLASS_SCHOOL_KID_M,
	FACILITY_CLASS_SCHOOL_KID_F,
	FACILITY_CLASS_SR_AND_JR,
	FACILITY_CLASS_POKEFAN_M,
	FACILITY_CLASS_POKEFAN_F,
	FACILITY_CLASS_EXPERT_M,
	FACILITY_CLASS_EXPERT_F,
	FACILITY_CLASS_RS_YOUNGSTER,
	FACILITY_CLASS_CHAMPION_STEVEN,
	FACILITY_CLASS_RS_FISHERMAN,
	FACILITY_CLASS_CYCLING_TRIATHLETE_M,
	FACILITY_CLASS_CYCLING_TRIATHLETE_F,
	FACILITY_CLASS_RUNNING_TRIATHLETE_M,
	FACILITY_CLASS_RUNNING_TRIATHLETE_F,
	FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
	FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
	FACILITY_CLASS_DRAGON_TAMER,
	FACILITY_CLASS_RS_BIRD_KEEPER,
	FACILITY_CLASS_NINJA_BOY,
	FACILITY_CLASS_BATTLE_GIRL,
	FACILITY_CLASS_PARASOL_LADY,
	FACILITY_CLASS_RS_SWIMMER_F,
	FACILITY_CLASS_RS_PICNICKER,
	FACILITY_CLASS_RS_TWINS,
	FACILITY_CLASS_RS_SAILOR,
	FACILITY_CLASS_BOARDER_M,
	FACILITY_CLASS_BOARDER_F,
	FACILITY_CLASS_COLLECTOR,
	FACILITY_CLASS_PKMN_TRAINER_WALLY,
	FACILITY_CLASS_PKMN_TRAINER_BRENDAN,
	FACILITY_CLASS_PKMN_TRAINER_BRENDAN_2,
	FACILITY_CLASS_PKMN_TRAINER_BRENDAN_3,
	FACILITY_CLASS_PKMN_TRAINER_MAY,
	FACILITY_CLASS_PKMN_TRAINER_MAY_2,
	FACILITY_CLASS_PKMN_TRAINER_MAY_3,
	FACILITY_CLASS_RS_PKMN_BREEDER_M,
	FACILITY_CLASS_RS_PKMN_BREEDER_F,
	FACILITY_CLASS_RS_PKMN_RANGER_M,
	FACILITY_CLASS_RS_PKMN_RANGER_F,
	FACILITY_CLASS_MAGMA_LEADER_MAXIE,
	FACILITY_CLASS_MAGMA_GRUNT_M,
	FACILITY_CLASS_MAGMA_GRUNT_F,
	FACILITY_CLASS_RS_LASS,
	FACILITY_CLASS_RS_BUG_CATCHER,
	FACILITY_CLASS_RS_HIKER,
	FACILITY_CLASS_RS_YOUNG_COUPLE,
	FACILITY_CLASS_OLD_COUPLE,
	FACILITY_CLASS_RS_SIS_AND_BRO,
	FACILITY_CLASS_AQUA_ADMIN_M,
	FACILITY_CLASS_AQUA_ADMIN_F,
	FACILITY_CLASS_MAGMA_ADMIN_M,
	FACILITY_CLASS_MAGMA_ADMIN_F,
	FACILITY_CLASS_LEADER_WATTSON,
	FACILITY_CLASS_LEADER_FLANNERY,
	FACILITY_CLASS_LEADER_NORMAN,
	FACILITY_CLASS_LEADER_WINONA,
	FACILITY_CLASS_LEADER_WALLACE,
	FACILITY_CLASS_ELITE_FOUR_GLACIA,
	FACILITY_CLASS_ELITE_FOUR_DRAKE,
	FACILITY_CLASS_YOUNGSTER,
	FACILITY_CLASS_BUG_CATCHER,
	FACILITY_CLASS_LASS,
	FACILITY_CLASS_SAILOR,
	FACILITY_CLASS_CAMPER,
	FACILITY_CLASS_PICNICKER,
	FACILITY_CLASS_POKEMANIAC,
	FACILITY_CLASS_SUPER_NERD,
	FACILITY_CLASS_HIKER,
	FACILITY_CLASS_BIKER,
	FACILITY_CLASS_BURGLAR,
	FACILITY_CLASS_ENGINEER,
	FACILITY_CLASS_FISHERMAN,
	FACILITY_CLASS_SWIMMER_M,
	FACILITY_CLASS_CUE_BALL,
	FACILITY_CLASS_GAMER,
	FACILITY_CLASS_BEAUTY,
	FACILITY_CLASS_SWIMMER_F,
	FACILITY_CLASS_PSYCHIC_M,
	FACILITY_CLASS_ROCKER,
	FACILITY_CLASS_JUGGLER,
	FACILITY_CLASS_TAMER,
	FACILITY_CLASS_BIRD_KEEPER,
	FACILITY_CLASS_BLACK_BELT,
	FACILITY_CLASS_RIVAL_EARLY,
	FACILITY_CLASS_SCIENTIST,
	FACILITY_CLASS_BOSS,
	FACILITY_CLASS_ROCKET_GRUNT_M,
	FACILITY_CLASS_COOLTRAINER_M,
	FACILITY_CLASS_COOLTRAINER_F,
	FACILITY_CLASS_ELITE_FOUR_LORELEI,
	FACILITY_CLASS_ELITE_FOUR_BRUNO,
	FACILITY_CLASS_LEADER_M,
	FACILITY_CLASS_LEADER_F,
	FACILITY_CLASS_GENTLEMAN,
	FACILITY_CLASS_RIVAL_LATE,
	FACILITY_CLASS_CHAMPION_RIVAL,
	FACILITY_CLASS_CHANNELER,
	FACILITY_CLASS_TWINS,
	FACILITY_CLASS_COOL_COUPLE,
	FACILITY_CLASS_YOUNG_COUPLE,
	FACILITY_CLASS_CRUSH_KIN,
	FACILITY_CLASS_SIS_AND_BRO,
	FACILITY_CLASS_PKMN_PROF,
	FACILITY_CLASS_BRENDAN,
	FACILITY_CLASS_MAY,
	FACILITY_CLASS_RED,
	FACILITY_CLASS_LEAF,
	FACILITY_CLASS_ROCKET_GRUNT_F,
	FACILITY_CLASS_PSYCHIC_F,
	FACILITY_CLASS_CRUSH_GIRL,
	FACILITY_CLASS_TUBER,
	FACILITY_CLASS_PKMN_BREEDER,
	FACILITY_CLASS_PKMN_RANGER_M,
	FACILITY_CLASS_PKMN_RANGER_F,
	FACILITY_CLASS_AROMA_LADY,
	FACILITY_CLASS_RUIN_MANIAC,
	FACILITY_CLASS_LADY,
	FACILITY_CLASS_PAINTER,
	FACILITY_CLASS_ELITE_FOUR_AGATHA,
	FACILITY_CLASS_ELITE_FOUR_LANCE,
	FACILITY_CLASS_CHAMPION_RIVAL_2,
};

#define F_TRAINER_FEMALE (1 << 7)

// All trainer parties specify the IV, level, and species for each Pokémon in the
// party. Some trainer parties also specify held items and custom moves for each
// Pokémon.
#define F_TRAINER_PARTY_CUSTOM_MOVESET (1 << 0)
#define F_TRAINER_PARTY_HELD_ITEM      (1 << 1)

#endif  // GUARD_CONSTANTS_TRAINERS_H
