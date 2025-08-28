// ABOUTME: Battle League system for Pokemon Infinite Emerald
// ABOUTME: Main header for VGC doubles battle facility with ELO progression

#ifndef GUARD_BATTLE_LEAGUE_H
#define GUARD_BATTLE_LEAGUE_H

#include "constants/battle_league.h"

// Forward declarations
struct BattleLeagueData;
struct LeagueTrainer;

// Battle League Data Structure
struct BattleLeagueData
{
    u16 playerElo;
    u8 currentTier;
    u16 battlePoints;
    u8 winStreak;
    u8 dailyChallengeType;
    bool8 dailyChallengeCompleted;
    u16 totalWins;
    u16 totalLosses;
    u8 highestTierReached;
};

// League Trainer Structure
struct LeagueTrainer  
{
    u16 trainerId;
    u8 trainerClass;
    u8 tier;
    u16 eloRange[2]; // [min, max]
    const u8 *trainerName;
    const u8 *introText;
    const u8 *defeatText;
    const u8 *victoryText;
};

// Function declarations
void InitBattleLeague(void);
void BattleLeague_ShowMainMenu(void);
void BattleLeague_TestInitialize(void);
void GetPartySize(void);
void BattleLeague_StartTestBattle(void);
bool8 IsBattleLeagueUnlocked(void);
u8 GetPlayerLeagueTier(void);
u16 GetPlayerElo(void);
void UpdatePlayerElo(bool8 won);
void GiveLeagueRewards(bool8 won);
void SetupLeagueBattle(void);
struct LeagueTrainer *GetRandomLeagueOpponent(u8 tier);
void ShowLeagueRankings(void);
void ShowLeagueShop(void);
void ShowLeagueRules(void);
u8 GetTierFromElo(u16 elo);
u16 GetTierEloRange(u8 tier, bool8 isMax);
void GenerateDailyChallenge(void);
bool8 IsDailyChallengeActive(void);
void ApplyDailyChallengeMods(void);

// Battle setup functions
void CB2_InitLeagueBattle(void);
void SetupLeagueOpponent(u8 tier);
void InitLeagueTeamPreview(void);

// Menu callback functions
void CB2_BattleLeagueMenu(void);
void Task_BattleLeagueMenu(u8 taskId);
void BattleLeagueMenu_HandleInput(u8 taskId);

// Save/Load functions
void SaveBattleLeagueData(void);
void LoadBattleLeagueData(void);

// Helper functions
const u8 *GetTierName(u8 tier);
const u8 *GetTierColorCode(u8 tier);
u8 GetTierMinLevel(u8 tier);
u8 GetTierMaxLevel(u8 tier);

#endif // GUARD_BATTLE_LEAGUE_H