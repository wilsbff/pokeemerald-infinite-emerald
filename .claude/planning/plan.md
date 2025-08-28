# Implementation Plan: Pokemon Infinite Emerald

## Phase 0: Environment Setup (Day 1)

### Step 0: Development Environment
Testing Strategy: Configuration
- Install build tools: `sudo apt install build-essential binutils-arm-none-eabi git libpng-dev`
- Clone pokeemerald-expansion: `git clone https://github.com/rh-hideout/pokeemerald-expansion`
- Set up agbcc compiler
- Configure VSCode with C/C++ extensions
- Test: Build vanilla ROM successfully
- Commit: "chore: initialize pokeemerald-expansion base"

### Step 1: ROWE Source Analysis
Testing Strategy: Research
- Clone ROWE source: `git clone https://github.com/BelialClover/RoweSource`
- Study level scaling implementation in `src/battle_setup.c`
- Extract open world mechanics from `src/field_control.c`
- Document useful features to port
- Create `docs/rowe-features.md`
- Test: Understand compilation differences
- Commit: "docs: analyze ROWE source for feature extraction"

## Phase 1: Foundation (Week 1)

### Step 2: Configuration & Constants
Testing Strategy: Configuration
- Configure battle engine in `include/config/battle.h`
  - Enable Gen 9 mechanics
  - Set doubles as default format
  - Enable team preview- Configure Pokemon in `include/config/pokemon.h`
  - Enable all generations
  - Perfect IV options
- Create `include/constants/battle_facility.h`
- Test: Verify configuration changes compile
- Commit: "feat: configure battle engine for competitive play"

### Step 3: Level Scaling System
Testing Strategy: TDD Required
- Test: Wild Pokemon scale with badges
- Test: Trainer Pokemon scale appropriately
- Test: Evolution scaling works correctly
- Port ROWE's scaling logic
- Implement badge-based calculations
- Add grindless mode toggle
- Verify: All scaling tests pass
- Commit: "feat: implement level scaling system"

### Step 4: Battle Facility Core
Testing Strategy: TDD Required
- Test: Facility accessible from menu
- Test: Battle initialization works
- Test: Rewards distributed correctly
- Create `src/battle_facility/facility_manager.c`
- Implement facility data structure
- Add facility to Rustboro City (prototype)
- Verify: Can enter and battle
- Commit: "feat: create core battle facility system"
## Phase 2: Battle Systems (Week 2)

### Step 5: VGC Doubles Implementation
Testing Strategy: TDD Required
- Test: Team preview shows 6 Pokemon
- Test: Player can select 4 Pokemon
- Test: Item/species clause enforced
- Implement team preview UI
- Add selection logic
- Configure doubles rules
- Verify: VGC format works correctly
- Commit: "feat: implement VGC doubles format"

### Step 6: AI Strategy System
Testing Strategy: Test After
- Import competitive movesets from Smogon
- Create `src/battle_facility/ai_strategies.c`
- Implement strategy selection by difficulty
- Add team composition logic
- Test: AI uses appropriate strategies
- Test: Difficulty scaling works
- Commit: "feat: add competitive AI strategies"

### Step 7: ELO Rating System
Testing Strategy: TDD Required
- Test: ELO calculates correctly
- Test: Ratings persist between battles
- Test: Matchmaking uses ELO appropriately
- Implement `src/battle_facility/elo_system.c`- Add rating calculations
- Create matchmaking logic
- Verify: Rankings work properly
- Commit: "feat: implement ELO rating system"

## Phase 3: Challenge Systems (Week 3)

### Step 8: Daily Challenge Generator
Testing Strategy: TDD Required
- Test: New challenge each day
- Test: Ruleset applies correctly
- Test: Rewards granted properly
- Create `src/challenges/daily_generator.c`
- Implement RNG with date seed
- Add ruleset variations:
  - Weather locked
  - Terrain active
  - Type restrictions
  - Inverse battles
- Verify: Daily rotation works
- Commit: "feat: add daily challenge system"

### Step 9: Weekly Events Framework
Testing Strategy: Test After
- Create `src/challenges/weekly_events.c`
- Design 5-battle gauntlets
- Implement special rewards
- Add progression tracking
- Test: Weekly reset works
- Test: Gauntlet progression saves
- Commit: "feat: implement weekly event challenges"
### Step 10: Reward & Progression
Testing Strategy: TDD Required
- Test: Battle Points accumulate
- Test: Unlockables trigger correctly
- Test: Achievements track properly
- Create `src/progression/` systems
- Implement reward distribution
- Add achievement framework
- Verify: All progression works
- Commit: "feat: add progression and rewards"

## Phase 4: Distribution (Week 4)

### Step 11: City Battle Facilities
Testing Strategy: Test After
- Add facility to each city
- Create unique NPCs per location
- Implement fast travel system
- Add facility customization
- Test: All facilities accessible
- Test: Fast travel works
- Commit: "feat: add battle facilities to all cities"

### Step 12: Quality of Life Features
Testing Strategy: Test After
- Port QoL from ROWE:
  - PC access everywhere
  - Nature mints
  - Ability capsules
  - IV/EV modification- Add team preset system
- Implement quick battle mode
- Test: All QoL features work
- Commit: "feat: add quality of life improvements"

### Step 13: UI/UX Polish
Testing Strategy: Visual Testing
- Create battle facility menus
- Design challenge selection UI
- Add leaderboard displays
- Implement ELO visualization
- Polish battle animations
- Test: UI is intuitive
- Commit: "feat: polish user interface"

## Phase 5: Companion App Preparation (Week 5)

### Step 14: Save File Hooks
Testing Strategy: TDD Required
- Test: Save export works
- Test: Import validates correctly
- Test: Team format compatible
- Create export/import functions
- Add Showdown format conversion
- Implement checksum validation
- Verify: Data integrity maintained
- Commit: "feat: add save file export system"

### Step 15: External Communication
Testing Strategy: Integration Test
- Design communication protocol- Add placeholder connection code
- Create data serialization
- Document API structure
- Test: Protocol follows spec
- Commit: "feat: prepare external app hooks"

## Phase 6: Testing & Polish (Week 6)

### Step 16: Comprehensive Testing
Testing Strategy: Full Test Suite
- Unit test all calculations
- Integration test save/load
- Performance test battles
- Balance test difficulty
- Playtest full experience
- Fix identified bugs
- Commit: "test: comprehensive test coverage"

### Step 17: Documentation & Release
Testing Strategy: Documentation
- Write player guide
- Create modding documentation
- Document all features
- Prepare release notes
- Create installation guide
- Build final ROM
- Commit: "docs: complete documentation"

## Implementation Instructions

For Claude Code:
```
1. Start with Phase 0 setup2. For each step:
   - Review testing requirements
   - Write tests first if TDD
   - Implement features
   - Verify tests pass
   - Commit with message provided
3. Use mGBA debug for testing
4. Regular saves in case of issues
5. Port ROWE features carefully
```

## Critical Code Patterns

### Level Scaling Template
```c
u8 GetScaledLevel(u8 baseLevel, u8 badgeCount) {
    if (FlagGet(FLAG_GRINDLESS_MODE)) {
        return min(50 + (badgeCount * 5), 100);
    }
    return baseLevel + (badgeCount * 3);
}
```

### Daily Challenge Seed
```c
u32 GetDailySeed(void) {
    RTCTime time;
    RTC_GetTime(&time);
    return (time.year * 365) + time.day;
}
```

### ELO Calculation
```cu16 CalculateNewELO(u16 playerELO, u16 opponentELO, bool won) {
    f32 expected = 1.0 / (1.0 + pow(10, (opponentELO - playerELO) / 400.0));
    u8 k = 32; // K-factor
    return playerELO + k * (won ? 1 : 0) - expected);
}
```

## Risk Mitigation

### Memory Management
- Monitor RAM usage closely
- Limit active Pokemon to 12
- Use compression for large datasets

### Save Corruption
- Implement checksums
- Backup save before major operations
- Test save/load extensively

### Performance
- Profile battle calculations
- Optimize AI decision trees
- Limit particle effects

## Success Metrics
- ✅ All 16+ cities have facilities
- ✅ 50+ challenge rulesets implemented
- ✅ ELO system working correctly
- ✅ No save corruption in testing
- ✅ Stable 60 FPS maintained
- ✅ AI strategies are challenging