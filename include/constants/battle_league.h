// ABOUTME: Battle League constants for Pokemon Infinite Emerald
// ABOUTME: Defines ELO system, tiers, and facility configuration for competitive VGC battles

#ifndef GUARD_CONSTANTS_BATTLE_LEAGUE_H
#define GUARD_CONSTANTS_BATTLE_LEAGUE_H

// Battle League facility ID (extends the frontier system)
#define FRONTIER_FACILITY_LEAGUE   7  // Next available facility ID
#define FACILITY_BATTLE_LEAGUE     FRONTIER_FACILITY_LEAGUE

// Battle League specific modes (all doubles)
#define LEAGUE_MODE_VGC_DOUBLES    FRONTIER_MODE_DOUBLES

// ELO System Constants
#define LEAGUE_STARTING_ELO        1000
#define LEAGUE_MIN_ELO             0
#define LEAGUE_MAX_ELO             3000
#define LEAGUE_ELO_WIN_BASE        20
#define LEAGUE_ELO_LOSS_BASE       15

// Battle League Tiers
#define LEAGUE_TIER_ROOKIE         0  // 0-1199 ELO
#define LEAGUE_TIER_GREAT          1  // 1200-1499 ELO  
#define LEAGUE_TIER_ULTRA          2  // 1500-1799 ELO
#define LEAGUE_TIER_MASTER         3  // 1800-2099 ELO
#define LEAGUE_TIER_CHAMPION       4  // 2100+ ELO
#define NUM_LEAGUE_TIERS           5

// Tier Level Ranges (for opponent scaling)
#define LEAGUE_ROOKIE_MIN_LEVEL    25
#define LEAGUE_ROOKIE_MAX_LEVEL    35
#define LEAGUE_GREAT_MIN_LEVEL     40
#define LEAGUE_GREAT_MAX_LEVEL     50
#define LEAGUE_ULTRA_MIN_LEVEL     55
#define LEAGUE_ULTRA_MAX_LEVEL     65
#define LEAGUE_MASTER_MIN_LEVEL    70
#define LEAGUE_MASTER_MAX_LEVEL    80
#define LEAGUE_CHAMPION_MIN_LEVEL  85
#define LEAGUE_CHAMPION_MAX_LEVEL  100

// Battle League Points (separate from Frontier BP)
#define LEAGUE_BP_WIN              10
#define LEAGUE_BP_WIN_STREAK_BONUS 5   // Additional BP per consecutive win
#define LEAGUE_BP_LOSS             3   // Consolation BP
#define MAX_LEAGUE_BP              9999

// Daily Challenge Types
#define DAILY_CHALLENGE_NONE       0
#define DAILY_CHALLENGE_WEATHER    1  // Permanent weather
#define DAILY_CHALLENGE_TERRAIN    2  // Battle terrain active
#define DAILY_CHALLENGE_MONOTYPE   3  // Single type teams
#define DAILY_CHALLENGE_RENTAL     4  // Rental Pokemon only
#define DAILY_CHALLENGE_INVERSE    5  // Inverse type effectiveness
#define NUM_DAILY_CHALLENGES       6

// Team Preview Settings
#define LEAGUE_TEAM_SIZE           6  // Bring 6 Pokemon
#define LEAGUE_BATTLE_SIZE         4  // Pick 4 to battle
#define LEAGUE_PREVIEW_TIME        60 // 60 seconds for team selection

// Menu Options
#define LEAGUE_MENU_BATTLE         0
#define LEAGUE_MENU_RANKINGS       1
#define LEAGUE_MENU_SHOP           2
#define LEAGUE_MENU_RULES          3
#define LEAGUE_MENU_EXIT           4
#define NUM_LEAGUE_MENU_OPTIONS    5

// Special Battle League Trainers (using trainer types instead of classes)
#define LEAGUE_TRAINER_CLASS_ROOKIE    TRAINER_TYPE_NORMAL
#define LEAGUE_TRAINER_CLASS_GREAT     TRAINER_TYPE_NORMAL  
#define LEAGUE_TRAINER_CLASS_ULTRA     TRAINER_TYPE_NORMAL
#define LEAGUE_TRAINER_CLASS_MASTER    TRAINER_TYPE_NORMAL
#define LEAGUE_TRAINER_CLASS_CHAMPION  TRAINER_TYPE_NORMAL

// Battle League Status Flags (to be defined in flags.h)
// These will need to be added to the main flags.h file
// #define FLAG_BATTLE_LEAGUE_UNLOCKED        FLAG_UNUSED_0x###
// #define FLAG_DAILY_CHALLENGE_COMPLETED     FLAG_UNUSED_0x###
// #define FLAG_BATTLE_LEAGUE_TUTORIAL        FLAG_UNUSED_0x###

// Battle League Variables (to be defined in vars.h)  
// These will need to be added to the main vars.h file
// #define VAR_BATTLE_LEAGUE_ELO              VAR_UNUSED_0x###
// #define VAR_BATTLE_LEAGUE_TIER             VAR_UNUSED_0x###
// #define VAR_BATTLE_LEAGUE_BP               VAR_UNUSED_0x###
// #define VAR_BATTLE_LEAGUE_WIN_STREAK       VAR_UNUSED_0x###
// #define VAR_DAILY_CHALLENGE_TYPE           VAR_UNUSED_0x###

#endif // GUARD_CONSTANTS_BATTLE_LEAGUE_H