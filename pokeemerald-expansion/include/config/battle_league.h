// ABOUTME: Battle League configuration for Pokemon Infinite Emerald
// ABOUTME: Configures battle engine settings specifically for VGC doubles format

#ifndef GUARD_CONFIG_BATTLE_LEAGUE_H
#define GUARD_CONFIG_BATTLE_LEAGUE_H

// Battle League Feature Toggles
#define BATTLE_LEAGUE_ENABLED           TRUE   // Master toggle for Battle League system
#define BATTLE_LEAGUE_TEAM_PREVIEW      TRUE   // Enable team preview for VGC format
#define BATTLE_LEAGUE_TIME_LIMIT        TRUE   // Enable battle time limits  
#define BATTLE_LEAGUE_SLEEP_CLAUSE      TRUE   // Enable sleep clause for competitive play
#define BATTLE_LEAGUE_ELO_SYSTEM        TRUE   // Enable ELO ranking system
#define BATTLE_LEAGUE_DAILY_CHALLENGES  TRUE   // Enable daily challenge modifiers

// VGC Format Settings
#define LEAGUE_DEFAULT_BATTLE_MODE      FRONTIER_MODE_DOUBLES  // Always doubles
#define LEAGUE_TEAM_SELECTION_TIME      60     // Seconds for team preview
#define LEAGUE_BATTLE_TIME_LIMIT        900    // 15 minutes per battle (seconds)
#define LEAGUE_TURN_TIME_LIMIT          45     // 45 seconds per turn

// Battle Engine Overrides for League Battles
// These flags will be set automatically during Battle League battles
#define LEAGUE_BATTLE_FLAGS    (1 << 0)  // Custom battle flag for League battles

// Competitive Rule Enforcement
#define LEAGUE_ENFORCE_SPECIES_CLAUSE   FALSE  // Allow duplicate species (official VGC allows this)
#define LEAGUE_ENFORCE_ITEM_CLAUSE      FALSE  // Allow duplicate items (official VGC allows this) 
#define LEAGUE_ENFORCE_SLEEP_CLAUSE     TRUE   // Prevent multiple sleep (competitive standard)
#define LEAGUE_ENFORCE_TIMER            TRUE   // Enforce turn and battle time limits

// AI Settings for League Battles
#define LEAGUE_AI_SMART_SWITCHING       TRUE   // AI makes intelligent switches
#define LEAGUE_AI_PREDICTION            TRUE   // AI predicts player moves
#define LEAGUE_AI_DOUBLES_COORDINATION  TRUE   // AI coordinates doubles strategies
#define LEAGUE_AI_ADVANCED_CALC         TRUE   // AI uses advanced damage calculations

// Battle Mechanics for Competitive Play
#define LEAGUE_SHOW_MOVE_EFFECTIVENESS  TRUE   // Show type effectiveness indicators
#define LEAGUE_SHOW_STAT_CHANGES        TRUE   // Show stat change indicators
#define LEAGUE_SHOW_ABILITY_POPUPS      TRUE   // Show ability activation messages
#define LEAGUE_FAST_BATTLE_INTRO        TRUE   // Skip lengthy battle intros

// Quality of Life Features
#define LEAGUE_AUTO_SAVE_AFTER_BATTLE   TRUE   // Save after each league battle
#define LEAGUE_SHOW_ELO_CHANGES         TRUE   // Display ELO gain/loss after battle
#define LEAGUE_SHOW_BP_REWARDS          TRUE   // Display BP rewards after battle

// Debug and Testing
#define LEAGUE_DEBUG_MODE               FALSE  // Enable debug logging and cheats
#define LEAGUE_SKIP_ANIMATIONS          FALSE  // Skip battle animations (for testing)

#endif // GUARD_CONFIG_BATTLE_LEAGUE_H