// ABOUTME: Battle League implementation for Pokemon Infinite Emerald
// ABOUTME: Core VGC doubles battle facility with ELO system and competitive features

#include "global.h"
#include "battle_league.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "event_data.h"
#include "frontier_util.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/battle_league.h"
#include "constants/flags.h"
#include "constants/trainers.h"

// Static variables for Battle League system
static struct BattleLeagueData sBattleLeagueData;
static bool8 sInBattleLeague = FALSE;

// League tier names
static const u8 sLeagueTierNames[][16] = 
{
    _("Rookie League"),
    _("Great League"),
    _("Ultra League"), 
    _("Master League"),
    _("Champion League")
};

// League tier color codes for text display
static const u8 sLeagueTierColors[] = 
{
    TEXT_COLOR_GREEN,    // Rookie
    TEXT_COLOR_BLUE,     // Great  
    TEXT_COLOR_RED,      // Ultra
    TEXT_COLOR_LIGHT_RED, // Master
    TEXT_COLOR_LIGHT_BLUE // Champion
};

// Sample league trainers (we'll expand this later)
static const struct LeagueTrainer sLeagueTrainers[] = 
{
    // Rookie League trainers
    {
        .trainerId = TRAINER_YOUNGSTER_CALVIN,
        .trainerClass = LEAGUE_TRAINER_CLASS_ROOKIE,
        .tier = LEAGUE_TIER_ROOKIE,
        .eloRange = {800, 1199},
        .trainerName = _("Calvin"),
        .introText = _("Let's see what you've got!"),
        .defeatText = _("Good battle! Keep training!"),
        .victoryText = _("Better luck next time!")
    },
    // We'll add more trainers for each tier later
};

// Function implementations

void InitBattleLeague(void)
{
    // Initialize Battle League data if first time
    if (GetPlayerElo() == 0)
    {
        sBattleLeagueData.playerElo = LEAGUE_STARTING_ELO;
        sBattleLeagueData.currentTier = LEAGUE_TIER_ROOKIE;
        sBattleLeagueData.battlePoints = 0;
        sBattleLeagueData.winStreak = 0;
        sBattleLeagueData.dailyChallengeType = DAILY_CHALLENGE_NONE;
        sBattleLeagueData.dailyChallengeCompleted = FALSE;
        sBattleLeagueData.totalWins = 0;
        sBattleLeagueData.totalLosses = 0;
        sBattleLeagueData.highestTierReached = LEAGUE_TIER_ROOKIE;
        
        SaveBattleLeagueData();
    }
    else
    {
        LoadBattleLeagueData();
    }
    
    GenerateDailyChallenge();
}

bool8 IsBattleLeagueUnlocked(void)
{
    // For now, always unlocked. Later we can add unlock conditions
    // like having a certain number of badges or completing tutorial
    return TRUE;
}

u8 GetPlayerLeagueTier(void)
{
    return GetTierFromElo(sBattleLeagueData.playerElo);
}

u16 GetPlayerElo(void)
{
    return sBattleLeagueData.playerElo;
}

u8 GetTierFromElo(u16 elo)
{
    if (elo < 1200) return LEAGUE_TIER_ROOKIE;
    if (elo < 1500) return LEAGUE_TIER_GREAT;
    if (elo < 1800) return LEAGUE_TIER_ULTRA;
    if (elo < 2100) return LEAGUE_TIER_MASTER;
    return LEAGUE_TIER_CHAMPION;
}

const u8 *GetTierName(u8 tier)
{
    if (tier < NUM_LEAGUE_TIERS)
        return sLeagueTierNames[tier];
    return sLeagueTierNames[0];
}

const u8 *GetTierColorCode(u8 tier)
{
    if (tier < NUM_LEAGUE_TIERS)
        return &sLeagueTierColors[tier];
    return &sLeagueTierColors[0];
}

u8 GetTierMinLevel(u8 tier)
{
    switch (tier)
    {
        case LEAGUE_TIER_ROOKIE:   return LEAGUE_ROOKIE_MIN_LEVEL;
        case LEAGUE_TIER_GREAT:    return LEAGUE_GREAT_MIN_LEVEL;
        case LEAGUE_TIER_ULTRA:    return LEAGUE_ULTRA_MIN_LEVEL;
        case LEAGUE_TIER_MASTER:   return LEAGUE_MASTER_MIN_LEVEL;
        case LEAGUE_TIER_CHAMPION: return LEAGUE_CHAMPION_MIN_LEVEL;
        default:                   return LEAGUE_ROOKIE_MIN_LEVEL;
    }
}

u8 GetTierMaxLevel(u8 tier)
{
    switch (tier)
    {
        case LEAGUE_TIER_ROOKIE:   return LEAGUE_ROOKIE_MAX_LEVEL;
        case LEAGUE_TIER_GREAT:    return LEAGUE_GREAT_MAX_LEVEL;
        case LEAGUE_TIER_ULTRA:    return LEAGUE_ULTRA_MAX_LEVEL;
        case LEAGUE_TIER_MASTER:   return LEAGUE_MASTER_MAX_LEVEL;
        case LEAGUE_TIER_CHAMPION: return LEAGUE_CHAMPION_MAX_LEVEL;
        default:                   return LEAGUE_ROOKIE_MAX_LEVEL;
    }
}

void UpdatePlayerElo(bool8 won)
{
    u16 eloChange;
    
    // Basic ELO calculation (we can make this more sophisticated later)
    if (won)
    {
        eloChange = LEAGUE_ELO_WIN_BASE;
        sBattleLeagueData.playerElo += eloChange;
        sBattleLeagueData.winStreak++;
        sBattleLeagueData.totalWins++;
    }
    else
    {
        eloChange = LEAGUE_ELO_LOSS_BASE;
        sBattleLeagueData.playerElo = (sBattleLeagueData.playerElo > eloChange) ? 
                                     sBattleLeagueData.playerElo - eloChange : LEAGUE_MIN_ELO;
        sBattleLeagueData.winStreak = 0;
        sBattleLeagueData.totalLosses++;
    }
    
    // Cap ELO within bounds
    if (sBattleLeagueData.playerElo > LEAGUE_MAX_ELO)
        sBattleLeagueData.playerElo = LEAGUE_MAX_ELO;
    
    // Update tier
    sBattleLeagueData.currentTier = GetTierFromElo(sBattleLeagueData.playerElo);
    
    // Track highest tier reached
    if (sBattleLeagueData.currentTier > sBattleLeagueData.highestTierReached)
        sBattleLeagueData.highestTierReached = sBattleLeagueData.currentTier;
    
    SaveBattleLeagueData();
}

void GiveLeagueRewards(bool8 won)
{
    u16 bpReward = 0;
    
    if (won)
    {
        bpReward = LEAGUE_BP_WIN;
        // Bonus BP for win streaks
        if (sBattleLeagueData.winStreak > 1)
            bpReward += (sBattleLeagueData.winStreak - 1) * LEAGUE_BP_WIN_STREAK_BONUS;
    }
    else
    {
        bpReward = LEAGUE_BP_LOSS; // Consolation BP
    }
    
    sBattleLeagueData.battlePoints += bpReward;
    
    if (sBattleLeagueData.battlePoints > MAX_LEAGUE_BP)
        sBattleLeagueData.battlePoints = MAX_LEAGUE_BP;
    
    SaveBattleLeagueData();
}

void GenerateDailyChallenge(void)
{
    // Simple daily challenge generation based on current day
    // In a real implementation, we'd use RTC and save the challenge day
    sBattleLeagueData.dailyChallengeType = Random() % NUM_DAILY_CHALLENGES;
    sBattleLeagueData.dailyChallengeCompleted = FALSE;
    SaveBattleLeagueData();
}

bool8 IsDailyChallengeActive(void)
{
    return (sBattleLeagueData.dailyChallengeType != DAILY_CHALLENGE_NONE && 
            !sBattleLeagueData.dailyChallengeCompleted);
}

void SaveBattleLeagueData(void)
{
    // TODO: Integrate with save system
    // For now, this is a stub that we'll implement when we add save data integration
}

void LoadBattleLeagueData(void)
{
    // TODO: Integrate with save system  
    // For now, this is a stub that we'll implement when we add save data integration
}

// Basic Battle League menu (stub for now)
void BattleLeague_ShowMainMenu(void)
{
    // TODO: Implement full menu system
    // For now, just start a simple battle setup
    ScriptContext_Enable();
    ScriptCall(EventScript_BattleLeagueChallenge);
}

// Placeholder event script (we'll need to define this in the data files)
const u8 EventScript_BattleLeagueChallenge[] = 
{
    SCRIPT_END
};