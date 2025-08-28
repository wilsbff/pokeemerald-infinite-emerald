# Infinite Emerald 🏆

An infinitely replayable Pokemon Emerald ROM hack focused on competitive VGC doubles battling and endless challenges.

**Fork of:** [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion)

## 🎮 Core Features

### Battle League System
- 🏟️ **VGC Doubles Format** - Competitive 4v4 bring-6-pick-4 battles
- 📈 **ELO Ranking System** - 7 tiers from Rookie to Grand Master  
- 🎯 **Skill-Based Matchmaking** - Face opponents near your skill level
- 🏆 **Battle Points & Rewards** - Earn currency for competitive items

### Infinite Replayability  
- 🎲 **Daily Challenges** - New rulesets and modifiers every day
- 🌍 **Open World Design** - Start battles anywhere, anytime
- 📊 **Meta Progression** - Track wins, losses, streaks, and achievements
- ⚖️ **Level Scaling** - All battles normalized to competitive level 50 

## 🚀 Quick Start

### Prerequisites
```bash
# Install dependencies (Ubuntu/Debian)
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
```

### Building
```bash
# Clone and setup
git clone https://github.com/wilsbff/pokeemerald-infinite-emerald.git
cd pokeemerald-infinite-emerald

# Setup agbcc compiler (first time only)
./build_tools.sh

# Build ROM
make -j$(nproc)
```

### Testing
```bash
# Launch in mGBA (with VSCode debug support)
./launch_mgba.js

# Or use VSCode - open project and hit F5
```

## 🎯 Current Status

**Version:** 0.1.0-alpha  
**Focus:** Battle League Foundation

### ✅ Implemented
- [x] Battle League core system with ELO rankings
- [x] VGC doubles battle format integration  
- [x] Test NPC in Littleroot Town for immediate testing
- [x] Save/Load system structure prepared
- [x] Battle League data structures and progression

### 🔄 In Progress  
- [ ] Competitive trainers for each tier (Rookie → Grand Master)
- [ ] Proper ELO updates after battles
- [ ] Battle League facility/menu system

### 📋 Planned
- [ ] Team preview system (bring-6-pick-4)
- [ ] VGC rule enforcement (species clause, item clause, etc.)
- [ ] Daily challenges with modifiers
- [ ] Battle League shop and rewards
- [ ] Multiple Battle League locations across Hoenn
- [ ] Meta progression tracking and achievements

## 🎮 How to Test Current Features

1. **Build and launch** the ROM
2. **Start new game** and progress through intro
3. **Go to Littleroot Town** - find the Battle League Tester NPC
4. **Accept the test** - initializes your Battle League data
5. **Battle test** - experience VGC doubles format (currently vs basic trainer)
6. **Check your rank** - starts at Rookie Rank, ELO 1000

---

# [pokeemerald-expansion Features](FEATURES.md)

**`pokeemerald-expansion`** offers hundreds of features from various [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series), along with popular quality-of-life enhancements designed to streamline development and improve the player experience. A full list of those featues can be found in [`FEATURES.md`](FEATURES.md).

# [Credits](CREDITS.md)

 [![](https://img.shields.io/github/all-contributors/rh-hideout/pokeemerald-expansion/upcoming)](CREDITS.md)

If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity.

```
Based off RHH's pokeemerald-expansion 1.12.2 https://github.com/rh-hideout/pokeemerald-expansion/
```

Please consider [crediting all contributors](CREDITS.md) involved in the project!

# Choosing `pokeemerald` or **`pokeemerald-expansion`**

- **`pokeemerald-expansion`** supports multiplayer functionality with other games built on **`pokeemerald-expansion`**. It is not compatible with official Pokémon games.
- If compatibility with official games is important, use [`pokeemerald`](https://github.com/pret/pokeemerald). Otherwise, we recommend using **`pokeemerald-expansion`**.
- **`pokeemerald-expansion`** incorporates regular updates from `pokeemerald`, including bug fixes and documentation improvements.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches. 

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide on forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

## 📥 [Installing **`pokeemerald-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokeemerald-expansion`**](INSTALL.md#Building-pokeemerald-expansion)
## 🚚 [Migrating from **`pokeemerald`**](INSTALL.md#Migrating-from-pokeemerald)
## 🚀 [Updating **`pokeemerald-expansion`**](INSTALL.md#Updating-pokeemerald-expansion)

# [Documentation](https://rh-hideout.github.io/pokeemerald-expansion/)

For detailed documentation, visit the [pokeemerald-expansion documentation page](https://rh-hideout.github.io/pokeemerald-expansion/).

# [Contributions](CONTRIBUTING.md)
If you are looking to [report a bug](CONTRIBUTING.md#Bug-Report), [open a pull request](CONTRIBUTING.md#Pull-Requests), or [request a feature](CONTRIBUTING.md#Feature-Request), our [`CONTRIBUTING.md`](CONTRIBUTING.md) has guides for each.

# [Community](https://discord.gg/6CzjAG6GZk)

[![](https://dcbadge.limes.pink/api/server/6CzjAG6GZk)](https://discord.gg/6CzjAG6GZk)

Our community uses the [Rom Hacking Hideout (RHH) Discord server](https://discord.gg/6CzjAG6GZk) to communicate and organize. Most of our discussions take place there, and we welcome anybody to join us!
