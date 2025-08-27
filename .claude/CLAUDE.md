# CLAUDE.md - Pokemon Infinite Emerald

**FOLLOW ALL GLOBAL RULES UNLESS CONTRADICTED BY THIS FILE**

## Project Overview
Pokemon Infinite Emerald - An infinitely replayable Pokemon Emerald ROM hack focused on competitive battling, team building, and progression systems. Built on pokeemerald-expansion with inspiration from Pokemon ROWE.

## Critical Development Workflow

### ⚠️ MANDATORY FEATURE CHECK ORDER
Before implementing ANY feature, ALWAYS follow this process:

1. **FIRST: Check pokeemerald-expansion**
   - Search the repository for existing implementation
   - Check `include/config/` files for toggleable features
   - Review FEATURES.md for available systems
   - Many features already exist and just need enabling!

2. **SECOND: Check Pokemon ROWE source**
   - Reference `BelialClover/RoweSource` for implementation ideas
   - Study how they solved similar problems
   - Extract and adapt code patterns (with credit)

3. **ONLY THEN: Implement from scratch**
   - If neither source has what we need
   - Document why existing solutions don't work
   - Follow pokeemerald coding conventions

### Example Check Process
```
Need: Level scaling system
1. Check pokeemerald-expansion: Look for SCALED_LEVEL or similar flags
2. Check ROWE: Find GetScaledLevel() in src/battle_setup.c
3. Implement: Adapt ROWE's approach to our needs
```

## Project Structure
```
infinite-emerald/
├── .claude/
│   ├── planning/         # Our planning artifacts
│   │   ├── spec.md      # Project specification
│   │   ├── plan.md      # Implementation plan
│   │   └── todo.md      # Progress tracking
│   ├── reference/        # External code references
│   │   ├── rowe-features.md   # ROWE features to port
│   │   └── expansion-features.md # Available in expansion
│   ├── changes.md        # Track all changes
│   ├── journal.md        # Technical decisions
│   └── CLAUDE.md         # This file
├── src/
│   ├── battle_facility/  # Our main feature
│   ├── challenges/       # Daily/weekly systems
│   └── progression/      # Rewards and unlocks
├── data/
│   └── battle_facilities/
└── include/
    └── constants/
```

## Tech Stack
- **Base**: pokeemerald-expansion (latest)
- **Reference**: Pokemon ROWE source code
- **Build**: agbcc + devkitARM
- **Testing**: mGBA with debug features
- **IDE**: VSCode with Claude Code
- **Target**: GBA ROM (32MB max)

## Core Features We're Building
1. **Battle Facilities** in every city (no backtracking!)
2. **VGC Doubles Format** with team preview (bring 6, pick 4)
3. **Dynamic Challenges** - daily randomized, weekly gauntlets
4. **ELO System** - skill-based matchmaking
5. **Level Scaling** - adapted from ROWE
6. **Meta Progression** - unlockables and achievements

## Code Style Notes
- **Naming**: Follow pokeemerald conventions (snake_case)
- **Constants**: UPPER_CASE in header files
- **Functions**: Descriptive names, document complex logic
- **Memory**: Always consider GBA RAM limits (256KB)
- **Performance**: Target 60 FPS minimum

## Key Files to Reference

### From pokeemerald-expansion
- `include/config/battle.h` - Battle engine configuration
- `include/config/pokemon.h` - Pokemon settings
- `include/config/item.h` - Item configuration  
- `src/battle_ai_*.c` - AI system reference
- `src/battle_script_commands.c` - Battle mechanics

### From ROWE (when checking)
- `src/battle_setup.c` - Level scaling
- `src/field_control.c` - Open world mechanics
- `src/start_menu.c` - Menu modifications
- `src/pokemon.c` - Pokemon modifications

## Testing Requirements
- **EVERY** battle facility change needs save/load testing
- **EVERY** new feature needs RAM usage check
- **ALWAYS** test in mGBA before committing
- **NEVER** skip pre-commit hooks

## Common Pitfalls to Avoid
- Don't reinvent features that exist in expansion
- Don't copy ROWE code without understanding it
- Don't ignore memory limits (crashes in battles)
- Don't skip the planning phase for new features
- Don't modify save structure without versioning

## Development Commands
```bash
# Check expansion features
grep -r "FEATURE_NAME" include/

# Find ROWE implementations  
grep -r "function_name" ../RoweSource/src/

# Build and test quickly
make -j$(nproc) && mgba-qt pokeemerald.gba

# Clean build when issues occur
make clean && make -j$(nproc)
```

## When Stuck
1. Check if pokeemerald-expansion already has it
2. See how ROWE implemented similar features
3. Ask in ROM Hacking Hideout Discord
4. Reference pret/pokeemerald for vanilla behavior
5. Document the issue in journal.md

## Credits Required
When using code/ideas from:
- **pokeemerald-expansion**: Credit RHH (Rom Hacking Hideout)
- **Pokemon ROWE**: Credit rioluwott
- **Other sources**: Always attribute

## Remember
- **Quality > Quantity**: Better to have 5 polished features than 20 broken ones
- **Test Everything**: Save corruption kills ROM hacks
- **Document Decisions**: Future you will thank present you
- **Check Existing First**: Most features already exist somewhere
- **Performance Matters**: Nobody plays laggy ROM hacks

## Current Development Phase
**Phase 0**: Environment Setup & Analysis
- Setting up pokeemerald-expansion
- Analyzing ROWE source code
- Planning feature architecture

## Next Major Milestone
Working battle facility prototype in Rustboro City with:
- Basic VGC doubles battles
- Simple AI opponents
- Battle Point rewards
- Save/load functionality
