# Tilt Emerald

A random, vibe-coded ROM hack of Pokémon Emerald, built entirely with AI to see how badly (or how well) it does. It turns wild encounters into a pinball table with a combo system, and adds new towns, a custom gym, NPCs, trainers, a story or two, new starters and a big pile of quality-of-life options.

Tilt Emerald is a fan project built on top of the [pret/pokeemerald](https://github.com/pret/pokeemerald) decompilation. It is not affiliated with Nintendo, Game Freak or The Pokémon Company.

## Download and play

**Easiest:** open the project page (GitHub Pages) and use the in-browser builder. Drop in your own Pokémon Emerald (US) ROM and it builds Tilt Emerald for you, entirely locally. You can also grab `docs/patch/tilt-emerald.bps` and apply it to a clean Emerald ROM with any BPS patcher.

Every version is in the [`releases/`](releases) folder as a zip containing `Tilt Emerald.gba` (older versions are named `TiltEmerald_vX.gba` inside the zip). The newest zip is the latest build.

- [`releases/CHANGELOG.md`](releases/CHANGELOG.md) lists what changed in each version.
- Run the `.gba` in any GBA emulator, a flash cart, or a 3DS GBA setup.
- **Saves:** existing saves stay valid from v5 onward, so you can keep playing across updates.
- The ROM uses 128 KB flash saves with a real-time clock, like the original Emerald. If your emulator or injector asks for a save type, pick 128K/1Mbit flash.

## Starters

Birch's bag holds **Pikachu, Trapinch and Aron**. Your rival always takes the one that counters yours:

| You pick | Rival picks |
|----------|-------------|
| Pikachu  | Trapinch    |
| Trapinch | Aron        |
| Aron     | Pikachu     |

Every rival team uses the matching line (Pikachu/Raichu, Trapinch/Vibrava, Aron/Lairon).

## Tilt mode

Every wild win or catch adds to a combo, and the combo drives the whole game.

- **Combo:** longer combos push wild encounters toward the rare end of each area, raise their levels, and boost catch odds. Milestones pay coins, Rare Candies, Master Balls and full heals. A whiteout halves the combo; running away tilts the table and ends it.
- **Multiball:** every 7th combo hit sets up a guaranteed shiny. A second shiny waits behind it, and when you beat or catch the first, the next one jumps in like a trainer's next Pokémon, all in one battle.
- **Table mechanics:** bumper flowers, combo decay, ball savers, flipper, bank shots, slingshot crits, jackpot berries, Tilt Storms, a daily challenge, a high score board and a Start-menu combo HUD.
- **Pinball Wizard:** an NPC with a rules, shop and heal menu, found in a room upstairs in the Littleroot Pokémon Center. He introduces himself the first time you leave your house.
- **Healing economy:** Pokémon Centers are broke, so a heal costs ¥1000 (Gold Card holders still heal free). The Wizard's tune-up costs 250 COINS, and a lucky combo hit can drop a HEAL TICKET that makes it free. Mom only restores HP up to half.
- **Trainer level scaling** keeps battles level with you.

## Places

- **Littleroot's west yard:** a new Pokémon Center and a Poké Mart with its own interior.
- **Cody's Gym:** a traditional winding gym hall with a Dragon Gates gimmick, four gym trainers and the leader Cody with a Flygon dragon team. A guard quizzes you and stops anyone who tries to walk past. Nobody battles until you have 8 badges, but everyone can be talked to.
- **The Pinball Table dungeon:** a maze with bumpers, flippers and the TABLE KING.
- **Dream Island:** a late-game island recreated from an old FireRed hack. Become Champion, then ask the Sailor next to the Ever Grande Pokémon Center for a ride. Three leaders (MrBean, Chadderz, Vantox) wait up the stairs, and starters from other regions roam the grass.
- **Oldale Town** has a mini story, there is a Steven Stone cutscene on Route 102, and about 15 NPCs are scattered around Hoenn.

## Characters

- **Joseph**, the Pikachu trainer in the Littleroot yard, is as strong as Cody, so he won't battle until you have beaten Cody (you can still talk to him). He lets you skip the battle and rematches whenever you ask. His story event is a 2-on-2 tag battle against two Team Aqua grunts, with a reunion in Petalburg City afterwards.
- A custom animated Flygon overworld sprite.

## Options menu

The Options menu has 5 pages. Press L or R to flip between them. Everything on pages 2 to 5 is off or set to the classic behavior by default.

| Page | Option | What it does |
|------|--------|--------------|
| 1 | EXP MODE | Classic (only battlers get EXP) or Modern (the whole party gets the full amount) |
| 2 | ALWAYS RUN | Run by default, hold B to walk |
| 2 | REUSABLE TMS | TMs are not used up |
| 2 | SHINY CHARM | Up to 3 extra shiny rolls on new Pokémon |
| 2 | NO MAP POISON | Poison no longer drains HP while walking |
| 3 | INSTANT TEXT | Text boxes print instantly |
| 3 | EXP BOOST | 1x, 1.5x or 2x EXP |
| 3 | CATCH BOOST | 1x, 1.5x or 2x catch odds |
| 3 | AUTO HEAL | Full heal after winning or catching a wild Pokémon |
| 4 | NO SWITCH | No voluntary switching in battle |
| 4 | NUZLOCKE | Only the first wild encounter per area can be caught, and fainted Pokémon are released after the battle |
| 4 | COMBO MODE | Easy (+1 per hit), Normal, or Hard (flat +1, and a whiteout resets the combo) |
| 4 | MULTIBALL | Shiny pair every 10th (Low), 7th (Mid) or 4th (High) hit |
| 5 | BIGGER BAG | Item stacks up to 999 |
| 5 | LEVEL CAP | Pokémon stop gaining EXP at a cap set by your badge count |
| 5 | COMBO EXP | Turn the combo EXP buff off |
| 5 | SKIP LEARN | Never asks to replace a move on level-up |
| 5 | SKIP NICK | Never asks to nickname a caught Pokémon |

The level cap is 15, 20, 25, 30, 35, 40, 45 and 50 for 0 to 7 badges, and there is no cap at 8 badges.

## Polish

- A custom title screen with new TILT EMERALD text and an emerald-green logo.
- Nurse Joy won't heal you before you have a starter, which avoids a soft lock.

## Building from source

This repo is the decomp source plus the Tilt Emerald changes.

1. Follow [INSTALL.md](INSTALL.md) to set up the toolchain.
2. Build with `make -j$(nproc)`. This produces `pokeemerald.gba`, which is the Tilt Emerald ROM.
3. For the newer-GCC ("modern") build, use `make -j$(nproc) MODERN=1`, which produces `pokeemerald_modern.gba`.

The Tilt Emerald scripts live in `data/scripts/tilt_*.inc`, the save flags and variables it uses are documented in `include/constants/tilt.h`, and the trainer data is in `src/data/trainers.h` and `src/data/trainer_parties.h` (trainer slots 855 onward). The options on pages 3 to 5 are bit-packed in `tiltOpts` in `SaveBlock2` (see `src/tilt_mechanics.c`), and Nuzlocke area flags use the unused flags 0x264 to 0x2BB.

## Project page and patch

The `docs/` folder is the GitHub Pages site (set Pages to deploy from the `main` branch, `/docs` folder). `docs/patch/` holds the BPS patch and `info.json` that the builder uses. After each release, regenerate them with:

```
python3 tools/tilt/make_patch.py VANILLA_EMERALD.gba pokeemerald.gba vX
```

`VANILLA_EMERALD.gba` must be clean US Emerald (SHA-1 `f3ae088181bf583e55daf962a92bb46f4f1d07b7`). Building the upstream base commit (pret/pokeemerald 731ad5b) gives a byte-identical file. Never commit a ROM, only the patch.

## Credits

- The [pret](https://github.com/pret) team and contributors for the pokeemerald decompilation.
- Built with [Claude](https://claude.ai) by Anthropic, directed and tested by CodyMKW.
