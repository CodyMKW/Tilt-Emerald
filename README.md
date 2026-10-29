# Tilt Emerald

A random, vibe-coded ROM hack of Pokémon Emerald, built entirely with AI to see how badly (or how well) it does. It adds a pinball-style "Tilt" combo mechanic, a pile of new towns, NPCs, trainers and story bits, and a custom title screen.

Tilt Emerald is a fan project built on top of the [pret/pokeemerald](https://github.com/pret/pokeemerald) decompilation. It is not affiliated with Nintendo, Game Freak or The Pokémon Company.

## Download and play

Every version is in the [`releases/`](releases) folder as a zip containing `Tilt Emerald.gba` (older versions are named `TiltEmerald_vX.gba` inside the zip). The newest zip is the latest build.

- [`releases/CHANGELOG.md`](releases/CHANGELOG.md) lists what changed in each version.
- Run the `.gba` in any GBA emulator, a flash cart, or a 3DS GBA setup.
- **Saves:** existing saves stay valid from v5 onward, so you can keep playing across updates.
- The ROM uses 128 KB flash saves with a real-time clock, like the original Emerald. If your emulator or injector asks for a save type, pick 128K/1Mbit flash.

## What's in it

**Tilt mode**
- Win/catch combos (longer combos push wild encounters toward the rare end of each area and raise their levels), jackpots, starter coins, and multiball (shinies).
- The Ball Saver item, and a Pinball Wizard NPC with a rules, shop and heal menu. He lives in a cozy room upstairs in the Littleroot Pokémon Center.
- A short intro scene where the Pinball Wizard introduces himself the first time you leave your house.
- DREAM ISLAND, a late-game island recreated from an old FireRed hack. Become Champion, then ask the Sailor next to the Ever Grande Pokémon Center for a ride. Three leaders (MrBean, Chadderz, Vantox) wait up the stairs, and starters from other regions roam the grass.
- Tilt v17 mechanics: bumper flowers, combo decay, ball savers, flipper, bank shot, slingshot crits, jackpot berries, storms, daily challenge, high score board, and a Start-menu combo HUD.
- The Pinball Table dungeon (maze, bumpers, flippers, TABLE KING) and trainer level scaling that keeps battles level with you. Plus Cody's gym polish: statue text, a congratulating guide, and a guard who only quizzes players with 8 badges. Multiball is now a true double battle, and Cody's gym is a traditional winding hall (v20). v21 adds the Dragon Gates gimmick and a guard that stops you at the stage. v22 adds an EXP MODE option (Classic or Modern, where the whole party gets EXP). v23: Modern EXP gives the full amount to the whole party, plus a second Options page (Always Run, Reusable TMs, Shiny Charm, No Map Poison). v24: Multiball is a single battle where the second shiny jumps in after you beat or catch the first. v25: new starters (Pikachu, Trapinch, Aron) with matching rival teams, and 13 new options across Options pages 3-5.
- A healing economy: Pokémon Centers are broke, so a heal costs ¥1000 (Gold Card holders still heal free). The Wizard's tune-up costs 250 COINS, but a lucky combo hit (about 1 in 30) can drop a HEAL TICKET that makes it free. Mom only restores HP up to half, never more.

**Towns and places**
- Littleroot's new west yard, with a Pokémon Center and a Poké Mart (with its own interior).
- **Cody's Gym:** a pad-warp puzzle, four gym trainers and the leader Cody with a Flygon dragon team. Nobody battles until you have 8 badges, but everyone can be talked to.
- An Oldale Town mini story, a Steven Stone cutscene on Route 102, and about 15 scattered NPCs.

**Trainers and story**
- **Joseph**, the Pikachu trainer in the Littleroot yard. He is as strong as Cody, so he won't battle you until you have beaten Cody (you can still talk to him). He lets you skip the battle, and rematches whenever you ask once you have beaten him. His story event is a 2-on-2 tag battle with him against two Team Aqua grunts, with a reunion in Petalburg City afterwards.
- A custom animated Flygon overworld sprite.

**Polish**
- A custom title screen with new TILT EMERALD text and an emerald-green logo.
- Nurse Joy won't heal you before you have a starter, which avoids a soft lock.

## Building from source

This repo is the decomp source plus the Tilt Emerald changes.

1. Follow [INSTALL.md](INSTALL.md) to set up the toolchain.
2. Build with `make -j$(nproc)`. This produces `pokeemerald.gba`, which is the Tilt Emerald ROM.
3. For the newer-GCC ("modern") build, use `make -j$(nproc) MODERN=1`, which produces `pokeemerald_modern.gba`.

The Tilt Emerald scripts live in `data/scripts/tilt_*.inc`, the save flags and variables it uses are documented in `include/constants/tilt.h`, and the trainer data is in `src/data/trainers.h` and `src/data/trainer_parties.h` (trainer slots 855 onward).

## Credits

- The [pret](https://github.com/pret) team and contributors for the pokeemerald decompilation.
- Built with [Claude](https://claude.ai) by Anthropic, directed and tested by CodyMKW.
