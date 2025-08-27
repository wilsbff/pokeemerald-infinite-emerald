# Pokemon Infinite Emerald 🎮

An infinitely replayable Pokemon Emerald ROM hack focused on competitive battling and endless challenges.

## Features
- 🏟️ **Battle Facilities in Every City** - Jump into battles instantly
- 🎯 **VGC Doubles Format** - Strategic bring-6-pick-4 battles  
- 🎲 **Daily Challenges** - New rulesets every day
- 📈 **ELO Progression** - Skill-based matchmaking
- 🌍 **Open World** - Start anywhere, level scaling included
- 🏆 **Meta Progression** - Unlock rewards and achievements

## Development Status
**Phase 0**: Environment Setup (Current)

## Building
```bash
# Install dependencies
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev

# Clone and build
git clone https://github.com/rh-hideout/pokeemerald-expansion .
# Set up agbcc...
make -j$(nproc)
```

## Credits
- Based on pokeemerald-expansion by RHH (Rom Hacking Hideout)
- Inspired by Pokemon ROWE by rioluwott
- Using pret's pokeemerald decompilation

## Documentation
See `.claude/planning/` for detailed specifications and plans.
