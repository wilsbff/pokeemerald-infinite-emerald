# Todo: Pokemon Infinite Emerald

## Phase 0: Environment Setup ⏳
- [ ] Development Environment Setup
  - [ ] Install build tools and dependencies
  - [ ] Clone pokeemerald-expansion repository
  - [ ] Set up agbcc compiler
  - [ ] Configure VSCode with extensions
  - [ ] Test vanilla build

- [ ] ROWE Source Analysis
  - [ ] Clone ROWE source repository
  - [ ] Study level scaling implementation
  - [ ] Extract open world mechanics
  - [ ] Document useful features
  - [ ] Create feature extraction notes

## Phase 1: Foundation 🏗️
- [ ] Configuration & Constants
  - [ ] Configure battle engine settings
  - [ ] Enable Gen 9 mechanics
  - [ ] Set doubles as default
  - [ ] Configure Pokemon settings
  - [ ] Create battle facility constants

- [ ] Level Scaling System
  - [ ] Write scaling tests
  - [ ] Port ROWE's logic
  - [ ] Implement badge calculations
  - [ ] Add grindless mode
  - [ ] All tests pass
- [ ] Battle Facility Core
  - [ ] Write facility tests
  - [ ] Create facility manager
  - [ ] Add Rustboro prototype
  - [ ] Test battle flow
  - [ ] Verify rewards work

## Phase 2: Battle Systems ⚔️
- [ ] VGC Doubles Implementation
  - [ ] Write format tests
  - [ ] Implement team preview
  - [ ] Add selection UI
  - [ ] Configure doubles rules
  - [ ] Test clause enforcement

- [ ] AI Strategy System
  - [ ] Import competitive sets
  - [ ] Create strategy system
  - [ ] Implement difficulty scaling
  - [ ] Add team composition
  - [ ] Test AI behavior

- [ ] ELO Rating System
  - [ ] Write ELO tests
  - [ ] Implement calculations
  - [ ] Add persistence
  - [ ] Create matchmaking
  - [ ] Verify rankings
## Phase 3: Challenge Systems 🎮
- [ ] Daily Challenge Generator
  - [ ] Write generator tests
  - [ ] Implement date-based RNG
  - [ ] Add ruleset variations
  - [ ] Create reward system
  - [ ] Test daily rotation

- [ ] Weekly Events Framework
  - [ ] Design gauntlet system
  - [ ] Implement 5-battle runs
  - [ ] Add special rewards
  - [ ] Track progression
  - [ ] Test weekly reset

- [ ] Reward & Progression
  - [ ] Write progression tests
  - [ ] Implement Battle Points
  - [ ] Create unlockables
  - [ ] Add achievements
  - [ ] Test all systems

## Phase 4: Distribution 🌍
- [ ] City Battle Facilities
  - [ ] Add to all cities
  - [ ] Create unique NPCs
  - [ ] Implement fast travel
  - [ ] Add customization
  - [ ] Test accessibility
- [ ] Quality of Life Features
  - [ ] Port ROWE QoL features
  - [ ] PC access everywhere
  - [ ] Nature mints system
  - [ ] Team presets
  - [ ] Quick battle mode

- [ ] UI/UX Polish
  - [ ] Design facility menus
  - [ ] Create challenge UI
  - [ ] Add leaderboards
  - [ ] ELO visualization
  - [ ] Polish animations

## Phase 5: Future Preparation 🔌
- [ ] Save File Hooks
  - [ ] Write export tests
  - [ ] Create export system
  - [ ] Add import validation
  - [ ] Showdown compatibility
  - [ ] Test data integrity

- [ ] External Communication
  - [ ] Design protocol
  - [ ] Add connection stubs
  - [ ] Create serialization
  - [ ] Document API
  - [ ] Test protocol
## Phase 6: Testing & Release 🚀
- [ ] Comprehensive Testing
  - [ ] Unit test suite
  - [ ] Integration tests
  - [ ] Performance testing
  - [ ] Balance testing
  - [ ] Full playtest

- [ ] Documentation & Release
  - [ ] Write player guide
  - [ ] Create mod documentation
  - [ ] Feature documentation
  - [ ] Release notes
  - [ ] Installation guide
  - [ ] Build final ROM

## Progress Tracking
- Phase 0: 0/2 complete (0%)
- Phase 1: 0/3 complete (0%)
- Phase 2: 0/3 complete (0%)
- Phase 3: 0/3 complete (0%)
- Phase 4: 0/3 complete (0%)
- Phase 5: 0/2 complete (0%)
- Phase 6: 0/2 complete (0%)
- **Overall: 0/18 steps (0%)**

## Daily Checklist
- [ ] Pull latest pokeemerald-expansion updates
- [ ] Run tests before starting work- [ ] Commit at each logical checkpoint
- [ ] Test in mGBA after changes
- [ ] Update this todo list
- [ ] Document any issues found

## Quick Commands
```bash
# Build ROM
make clean && make -j$(nproc)

# Test in mGBA
mgba-qt pokeemerald.gba

# Quick rebuild
make -j$(nproc)

# Debug build
make MODERN=1

# Check for issues
make tidy
```

## Important Files to Track
- `include/config/battle.h` - Battle configuration
- `include/config/pokemon.h` - Pokemon settings  
- `src/battle_facility/` - Main facility code
- `src/challenges/` - Challenge systems
- `data/battle_facilities/` - Facility data
- `save_block.h` - Save data structure

## Notes
- Always test save/load after major changes
- Keep RAM usage under 256KB
- Target 60 FPS minimum
- Document all new functions
- Use ROWE source as reference