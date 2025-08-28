// ABOUTME: Battle League implementation for Pokemon Infinite Emerald
// ABOUTME: Core VGC doubles battle facility with ELO system and competitive features

#include "global.h"
#include "battle_league.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "event_data.h"
#include "field_message_box.h"
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
#include "constants/trainer_types.h"
#include "constants/battle.h"

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

// Battle League text constants
static const u8 sText_Calvin[] = _("Calvin");
static const u8 sText_CalvinIntro[] = _("Let's see what you've got!");
static const u8 sText_CalvinDefeat[] = _("Good battle! Keep training!");
static const u8 sText_CalvinVictory[] = _("Better luck next time!");

// Test message constants
const u8 gText_BattleLeagueInit[] = _("Battle League initialized!\nUse R+START for debug menu!");
const u8 gText_BattleLeagueInitRookie[] = _("Battle League initialized!\nCurrent Tier: Rookie League\nUse R+START for debug menu!");

// Sample league trainers (we'll expand this later)
static const struct LeagueTrainer sLeagueTrainers[] = 
{
    // Rookie League trainers
    {
        .trainerId = TRAINER_SAWYER_1,
        .trainerClass = TRAINER_TYPE_NORMAL,
        .tier = LEAGUE_TIER_ROOKIE,
        .eloRange = {800, 1199},
        .trainerName = sText_Calvin,
        .introText = sText_CalvinIntro,
        .defeatText = sText_CalvinDefeat,
        .victoryText = sText_CalvinVictory
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
    // For now, just a placeholder function
    // ScriptContext_Enable();
    // ScriptCall(EventScript_BattleLeagueChallenge);
}

// Test initialization function for Battle League
void BattleLeague_TestInitialize(void)
{
    // Initialize the Battle League system
    InitBattleLeague();
    
    // Show current player stats for testing
    u8 currentTier = GetPlayerLeagueTier();
    u16 currentElo = GetPlayerElo();
    
    // For now, just show a simple message
    // TODO: Later we can create a proper status display with formatted stats
    const u8 *tierName = GetTierName(currentTier);
    
    // Use a simple approach for now - just show tier and basic info
    if (currentTier == LEAGUE_TIER_ROOKIE)
    {
        ShowFieldMessage(gText_BattleLeagueInitRookie);
    }
    else
    {
        ShowFieldMessage(gText_BattleLeagueInit);
    }
}

// Special function to get party size for scripts
void GetPartySize(void)
{
    gSpecialVar_Result = CalculatePlayerPartyCount();
}

void BattleLeague_StartTestBattle(void)
{
    // Set up Battle League test battle as VGC doubles
    gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE;
    
    // Configure trainer battle parameters
    TRAINER_BATTLE_PARAM.mode = 0;
    TRAINER_BATTLE_PARAM.isDoubleBattle = TRUE;
    TRAINER_BATTLE_PARAM.isRematch = FALSE;
    TRAINER_BATTLE_PARAM.playMusicA = TRUE;
    TRAINER_BATTLE_PARAM.playMusicB = FALSE;
    TRAINER_BATTLE_PARAM.objEventLocalIdA = gSelectedObjectEvent;
    TRAINER_BATTLE_PARAM.opponentA = TRAINER_SAWYER_1;
    TRAINER_BATTLE_PARAM.introTextA = (u8*)sText_CalvinIntro;
    TRAINER_BATTLE_PARAM.defeatTextA = (u8*)sText_CalvinDefeat;
    TRAINER_BATTLE_PARAM.battleScriptRetAddrA = NULL;
    TRAINER_BATTLE_PARAM.victoryText = (u8*)sText_CalvinVictory;
    TRAINER_BATTLE_PARAM.cannotBattleText = NULL;
    
    // Start the trainer battle
    BattleSetup_StartTrainerBattle();
}

// TODO: Placeholder event script (we'll need to define this in the data files later)
// const u8 EventScript_BattleLeagueChallenge[] = 
// {
//     SCRIPT_END
// };