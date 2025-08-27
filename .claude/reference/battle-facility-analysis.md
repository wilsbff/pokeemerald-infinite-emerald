# Battle Facility Analysis & Design

## What We Found in pokeemerald-expansion

### ✅ Already Available Features
1. **Battle Tents** - Mini battle frontier facilities in Verdanturf, Fallarbor, and Slateport
2. **Battle Frontier** - Complete implementation of all facilities (Tower, Dome, Palace, Arena, Pike, Pyramid, Factory)
3. **Modern Battle Engine** - Gen 9 mechanics, Z-moves, Dynamax, Terastalization, etc.
4. **VGC Support** - Double battles already supported
5. **Trainer Customization** - Showdown team syntax, custom AI, sliding messages
6. **Battle Configuration** - Massive config system in `include/config/battle.h`

### 🏗️ Key Architecture
- Battle facilities use consistent pattern: `battle_[facility].c`
- Frontier utilities in `frontier_util.c` 
- Battle setup in `battle_setup.c`
- Trainer data in `src/data/battle_frontier/`

## What We Found in ROWE

### ✅ Level Scaling System
- Badge-based scaling (`GetNumBadges()`)
- Difficulty modes (Easy/Normal/Hard)
- Wild Pokemon scaling with evolution handling
- Move power limits based on progression
- Level cap enforcement

### 🏗️ Key Architecture
- Level scaling in `src/level_scaling.c`
- Badge detection via flag checking
- Progression tied to story completion

## Our Battle Facility Design

### 🎯 Core Concept: "Battle League Centers"
Replace traditional Pokémon Centers with **Battle League Centers** that offer:

1. **Healing Station** (traditional PC functionality)
2. **Battle League Desk** (our main feature)
3. **Team Builder** (rental Pokemon system)
4. **Leaderboards** (ELO display)

### 🏟️ Battle League Mechanics

#### **Format: VGC Doubles**
- Bring 6, pick 4 team preview
- Double battles only
- 15-minute time limit
- Official VGC rules

#### **Difficulty Tiers**
1. **Rookie League** (Lv 25-35) - Early game
2. **Great League** (Lv 40-50) - Mid game  
3. **Ultra League** (Lv 55-65) - Late game
4. **Master League** (Lv 70-80) - Post game
5. **Champion League** (Lv 85-100) - Elite tier

#### **ELO System**
- Start at 1000 ELO
- Win/Loss affects rating (+/- 15-30 points)
- Tier promotion at rating thresholds
- Daily/Weekly leaderboards

### 🎲 Daily Challenge System
Each day, one random modifier:
- **Weather Day**: Permanent weather effect
- **Terrain Day**: Battle terrain active
- **Monotype Day**: Single type teams only
- **Rental Day**: Must use rental Pokemon
- **Inverse Day**: Type effectiveness inverted

### 🏆 Rewards System
- **Battle Points (BP)** for wins
- **League Tokens** for tier advancement
- **Items/TMs** from BP shop
- **Cosmetic rewards** (trainer customization)
- **Pokemon** (rare species, Hidden Abilities)

## Implementation Plan

### Phase 1: Basic Battle Facility (Rustboro)
1. Add Battle League NPC to Rustboro Pokemon Center
2. Implement basic VGC double battle
3. Simple opponent pool (5-10 trainers)
4. Basic reward system (items only)

### Phase 2: Full System
1. ELO tracking in save data
2. Tier system implementation  
3. Daily challenge rotation
4. All cities enabled
5. Full reward catalog

### Phase 3: Advanced Features
1. Online connectivity simulation
2. Tournament modes
3. Seasonal events
4. Meta analysis tools

## Technical Implementation Notes

### Existing Code to Leverage
- `battle_tent.c` - Pattern for city-specific facilities
- `battle_tower.c` - ELO/progression system
- `frontier_util.c` - Common battle facility functions
- `battle_setup.c` - VGC battle configuration

### New Files Needed
- `src/battle_league.c` - Main facility logic
- `include/battle_league.h` - Headers and constants
- `src/data/battle_league/` - Trainer/reward data
- `include/constants/battle_league.h` - Configuration

### Save Data Requirements
- ELO rating (u16)
- Current tier (u8) 
- Daily challenge completion flags
- Battle League statistics
- Reward unlock flags

This design leverages existing pokeemerald-expansion infrastructure while creating our unique infinitely replayable competitive experience!