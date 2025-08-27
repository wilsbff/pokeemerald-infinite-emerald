# Technical Journal - Pokemon Infinite Emerald

## Project Vision
Creating an infinitely replayable Pokemon Emerald focused on competitive battles. The key innovation is making battle facilities accessible everywhere, removing the tedium of travel while focusing on strategic depth through VGC doubles format.

## Key Decisions

### Why pokeemerald-expansion?
- Already has Gen 1-9 Pokemon and moves
- Modern battle engine with physical/special split
- Extensive configuration options
- Active community support
- Well-documented codebase

### Why Study ROWE?
- Proven level scaling implementation
- Open world mechanics we can adapt
- Grindless mode already working
- Source code available for reference

### Architecture Choices
- Battle facilities in every city (not one mega facility)
- VGC doubles as primary format (more strategic than singles)
- ELO system for skill-based progression
- Daily challenges use date-based RNG seed

## Technical Notes
- GBA has 256KB RAM limit - must be careful with battle facility data
- Save file has limited space - may need creative compression for teams
- Frame rate critical during doubles battles - optimize animations

---
*Document all technical decisions and rationale here*
