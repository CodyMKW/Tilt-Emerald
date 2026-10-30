# Tilt Emerald changelog

Existing saves stay valid from v5 onward.

## v28.1
- Fixed: in the Falcon vs Dax scene the Pokemon pictures were on the wrong sides. Falcon's Pokemon now appear on the right (matching where he stands) and Dax's on the left.

## v28
- NEW SCENE: walking west from Petalburg City onto Route 104 you come across the famous trainer FALCON in the middle of a 6-on-6 level 100 exhibition battle against a trainer named DAX. You just watch: Pokemon pop up with their cries, each move is narrated, and FALCON wins. Afterwards FALCON talks to you and both trainers walk off in different directions. It only plays once.
- Existing saves stay valid.

## v27.1
- Fixed: one of the PINBALL PHONE parts was sitting in the pond in Petalburg City and could not be reached. It is now on dry land in the south part of town.

## v27
- NEW KEY ITEM: PINBALL PHONE (custom icon). Use it from the bag, or register it to SELECT, to open the Pinball Wizard's full menu from anywhere: rules, stats, shop, buffs, scores, daily challenge and heal.
- New side quest in Petalburg City: a gadget tinkerer (south of the Pokemon Center area, near the pond) lost the phone's ANTENNA, DIAL and BATTERY. Find the three glowing balls lying in the corners of town, hand them in, then bring a TILT combo of 3 or more for a signal test to get the phone.
- Existing saves stay valid.

## v26
- Removed four options: SKIP LEARN, NO SWITCH, CATCH BOOST and SHINY CHARM. If you had any of them turned on, they now do nothing.
- The Options menu is now 4 pages (L/R flips pages).
- Existing saves stay valid.

## v25
- STARTERS are now PIKACHU, TRAPINCH and ARON. Your rival picks the one that counters yours (Pikachu -> rival Trapinch, Trapinch -> rival Aron, Aron -> rival Pikachu), and all rival teams use those lines (Pikachu/Raichu, Trapinch/Vibrava, Aron/Lairon).
- The Options menu is now 5 pages (L/R flips pages). New options, all default to the old behavior:
  - Page 3: INSTANT TEXT, EXP BOOST (1x/1.5x/2x), CATCH BOOST (1x/1.5x/2x), AUTO HEAL (full heal after winning or catching a wild Pokemon).
  - Page 4: NO SWITCH (no voluntary switching in battle), NUZLOCKE (only the first wild encounter in each map area can be caught, and fainted Pokemon are released after the battle), COMBO MODE (Easy +1 combo per hit / Normal / Hard flat +1 and a whiteout resets the combo), MULTIBALL rate (Low every 10th hit / Mid every 7th / High every 4th).
  - Page 5: BIGGER BAG (stacks up to 999), LEVEL CAP (Pokemon stop gaining EXP at 15/20/25/30/35/40/45/50 by badge count), COMBO EXP (turn the combo EXP buff off), SKIP LEARN (never asks to replace a move on level-up), SKIP NICK (never asks to nickname caught Pokemon).
- Existing saves stay valid.

## v24
- MULTIBALL is now ONE battle, not a double battle. Beat or catch the first shiny and the second one jumps in ("Another shiny wild X jumped out!"), like a trainer sending out their next Pokemon.
- No victory music or "battle won" wrap-up between the two shinies; EXP is still given after each KO.
- Catching the first shiny skips the Pokedex page and nickname prompt so the fight flows straight on; the second one gets the normal catch screens.
- Works with a single Pokemon in your party now.

## v23
- EXP MODE: Modern now gives EVERY living Pokemon in your party the FULL EXP amount after a win, like the newest games (eggs and fainted Pokemon get none). Classic is unchanged.
- The Options menu now has a second page. Press L or R to flip between PAGE 1/2 and PAGE 2/2. Page 2 holds the new modern-day options (all OFF by default, so nothing changes until you turn them on):
  - ALWAYS RUN: you run by default and holding B walks instead.
  - REUSABLE TMS: teaching a TM no longer uses it up (like Gen 5 and later).
  - SHINY CHARM: wild and gifted Pokemon get up to 3 extra shiny rolls (about 4x the odds).
  - NO MAP POISON: poison no longer drains HP while you walk around (Gen 5 and later).
- Existing saves stay valid. Checked in an emulator: page flipping, full EXP for the whole party, Always Run. Reusable TMs, Shiny Charm and No Map Poison are untested in the emulator.

## v22
- New option in the Options menu: EXP MODE. CLASSIC works exactly like before (only Pokemon that took part in the battle get EXP, plus Exp. Share holders). MODERN gives EVERY living Pokemon in your party EXP after a win: the ones that fought get their normal share, and the ones that stayed in the party get half of the full amount (eggs and fainted Pokemon get none). Default is CLASSIC, so existing saves play the same until you change it.
- The Options menu rows are a little tighter to fit the new entry. Existing saves stay valid.

## v21.1
- Fix: the game froze when you walked in front of Cody's stage after the guard had stepped aside (the guard's trigger tiles hung once he was gone). They now switch off once the quiz is solved. Checked in an emulator with all 8 badges. Existing saves stay valid.

## v21
- Cody's gym now has its own gimmick: DRAGON GATES. Two stone gates split the hall into rooms; touch the glowing DRAGON ORB in each room to open the gate to the next. (Gates close again each time you enter the gym.)
- The guard now stops you the moment you step up in front of him (no more sneaking by on the sides). Without 8 badges he sends you back to the entrance; with 8 he asks the motto question.
- Hall is longer, with trainers in each room; dialogue updated to explain the gates. Existing saves stay valid.

## v20.1
- Cody's gym now has its own original layout (wider hall, stage with columns, staggered raised platforms, statues at the entrance) built from the same stone-gym tiles as the official gyms, instead of a copy of Rustboro's. The four trainers each guard a lane and the guard stands in front of CODY.
- No gameplay changes beyond the new coordinates. Existing saves stay valid.

## v20
- Multiball is now a real double battle: when the Multiball shiny triggers, you face TWO shiny wild Pokemon at once (needs 2 Pokemon in your party; with 1 it stays a single battle). The combo bonus counts both.
- Cody's gym redesigned as a traditional gym hall in the style of Rustboro's: a winding path past the four trainers up to a stage where the guard stands in front of CODY. The teleport pads are gone and all dialogue was updated.
- Only the two statues at the entrance have text now; the extra statue objects are removed.
- Guard no-badge warp now returns you to the new entrance. Existing saves stay valid.

## v19
- Pinball Table rebuilt: a bigger, cleaner maze with cushion-marked bumpers and flippers, a rug in the TABLE KING's room, and trainers placed so they never block corridors. Fixes the freeze when walking in the old maze (the bumper/flipper triggers were set up wrong).
- Fix: Joseph's sprite is no longer black in Petalburg during the reunion.
- Fix: talking to Joseph's Pikachu in Littleroot no longer freezes.
- Fix: Cody's gym statues now show their text (the two at the entrance included).
- The guide at the gym entrance now congratulates you once you've beaten Cody.
- The quiz guard only asks his question with all 8 badges. Otherwise he talks and sends you back to the gym entrance.
- Maze, Pikachu and statue fixes checked in an emulator. Existing saves stay valid.

## v18
- New dungeon: the PINBALL TABLE. Talk to the Attendant in the Pinball Wizard's room (needs a best combo of 10+). Inside is a pinball-hall maze with two trainers, bumpers (first one each visit gives COMBO +3), corner flippers that fling you across the table, and the TABLE KING in the top-left. Beating him gives 3 PP Max, a Lucky Egg and 3 Ball Savers.
- Trainer level scaling: every trainer's strongest Pokemon is now your highest level +1, and the rest of their team keeps its gap below that ace. Trainers are never weaker than before, so early game is unchanged. Dream Island rematch bonuses stack on top.
- Cody's final reward is now a Dragon Fang instead of a Dragon Scale (new reward only; already-given items are unchanged).
- Cody's gym trainers now spot you and walk over to battle once you have all 8 badges.
- The gym statues now have text, like the original gyms (your name appears after beating Cody).
- Untested in an emulator. Existing saves stay valid.

## v17
- 20 new Tilt mechanics: Combo Catch Bonus, Rare Bounce, flower Bumper Zones, Combo Decay (idle too long and it drops), Tilt Warning (running resets combo), Jackpot Berries (10/20/30), Ball Saver revive, free Flipper switch, Multiball (back-to-back second shiny ball), Slingshot Crit (every 5th hit), Bank Shot (super effective hits add combo), Wizard buffs, Combo Shop stock by best combo, High Score Board with prizes at 10/25/50/100, Heal Ticket crafting, Tilt Weather storms (stronger wild Pokemon), Daily Tilt Challenge, Nightly Jackpot route, Dream Island rematches, Easy Retry (keep half your combo after a blackout).
- Combo HUD: opening the Start menu shows COMBO, SAVERS and TICKETS in the top-left.
- Fix: the male player no longer sees the Pinball Wizard pop in on the first exit.
- Not yet done: the Pinball Table dungeon (planned).
- Untested in an emulator. Existing saves stay valid.

## v16
- Wild Pokémon are back to the original encounter tables everywhere (no more random species).
- New Tilt gimmick, COMBO LUCK: the longer your combo, the more wild encounters (grass, surfing, rock smash) shift toward the rare end of the area's table (+3% per combo, up to 60%). Combo level bonus and the every-7th-hit shiny multiball still apply.
- Updated the Wizard's rules text and two NPC lines to match. Dream Island still has only starters. Existing saves stay valid.

## v15.1
- Dream Island's wild encounters are no longer randomized: the tall grass now only has the starters (Bulbasaur, Charmander, Squirtle, Chikorita, Cyndaquil, Totodile, Treecko, Torchic, Mudkip). Everywhere else is still random.

## v15
- New late-game area: DREAM ISLAND, rebuilt from CodyMKW's old FireRed hack. After you're Champion, talk to the Sailor beside the Ever Grande Pokémon Center to sail there. Three rock pockets hold the island's leaders: MrBean, Chadderz and Vantox (fight them in that order). Each gives a prize (Rare Candies, PP Maxes, a Master Ball). Tall grass has the starters from other regions, and a Sailor on the beach takes you home.
- Removed the walk-through-walls testing aid (hold L), as promised.
- Existing saves stay valid.

## v14
- New intro scene: the first time you step outside after setting the clock and talking to Mom, the Pinball Wizard walks up from the west, explains TILT MODE and combos, tells you he's set up shop upstairs in the Pokémon Center, then walks back that way. Only plays on a new game. Existing saves stay valid and won't see it.

## v13.2
- Testing aid: hold L while walking to walk through walls and objects (won't leave the map edge). Handy if you get stuck. This is temporary and only here for testing, so it will be removed in a later version.

## v13.1
- Pricier healing: Pokémon Center ¥1000, Wizard tune-up 250 COINS. The Wizard menu now just says "Heal". HEAL TICKETS drop about 1 in 30 combo hits. Mom now raises HP only up to half, so repeat visits never go past half.

## v13
- Healing now costs something. Pokémon Centers charge ¥300 (the Gold Card still heals free). The Pinball Wizard's heal costs 50 COINS, or is free if you spend a HEAL TICKET. Mom now only restores half HP and cures status.
- New rare drop: roughly 1 in 12 winning combo hits drops a HEAL TICKET (hold up to 9).
- Existing saves stay valid.

## v12
- The scattered NPC challengers (Pip, Rick, Sue, the Maze Runner, Trav) and Dr. Glitch (boss and rematch) are now real trainer battles with trainer sprites and small teams instead of single wild POKéMON. Rewards and story progress are unchanged. Existing saves stay valid.

## v11.2
- Joseph won't battle you until you have beaten Cody. You can still talk to him, and he explains why. Saves that already beat Joseph are unaffected.

## v11.1
- Mart exterior: added the missing top row of the roof, removed the tree in front of the door, and added a dirt path in front of the mart that joins the main path (matching the Pokémon Center).

## v11
- New Littleroot Poké Mart building across the path from the Pokémon Center, with its own interior (clerk, a shopper and a boy).
- The mart clerk moves out of the Pokémon Center into the new mart, with a new intro about finally having a real shop. Same inventory as before.
- The wandering boy in the yard moved out of the mart's spot; his dialogue and the little girl's in the Pokémon Center now mention the new mart.

## v10.8
- Wizard room: you can now walk behind both plants under the bookshelves. The plant tops draw in front of you and the tile behind each plant is walkable.

## v10.7
- Fixed the gym hedges in the Littleroot yard: the bottoms were cut off, they now have rounded end caps.
- Fixed Joseph turning all black in Littleroot (the palette fix from v10.6 only works in Petalburg; Littleroot uses the normal sprite again).
- Fixed the two cut-off potted plants in the Pinball Wizard's room (their tops were missing).
- From this version on the ROM inside each zip is simply named `Tilt Emerald.gba`.

## v10.6
- Fixed Flygon's colours: it shared a palette slot with Joseph's sprite, so Joseph now has his own copy of the sprite on a separate slot.
- Moved the Petalburg reunion trigger to two tiles below Cody (x 20-22, y 11).

## v10.5
- Moved the Petalburg reunion group (Flygon, Cody, Joseph, Pikachu) up to the pond shore so the Pokémon Center roof no longer hides them.

## v10.4
- New animated 4-direction Flygon overworld sprite (armored Flygon sheet), replacing the shrunk front-art version.

## v10.3
- Petalburg City reunion: Cody + Flygon and Joseph + Pikachu stand side by side, reminisce about a Fortnite match, and bet lunch on a rematch.
- After the Aqua story, Joseph moves to Petalburg. Talking to him offers the Holy City of Pikachus legend, then a rematch.
- Custom Flygon overworld sprite (first version).

## v10.2
- Joseph's Pikachu stands beside him in the overworld (cry and dialogue on interaction; lines up in the Aqua scene).

## v10.1
- Polish: the player and Joseph line up side by side facing the grunts, and turn to each other afterwards.
- Nova's intro in Oldale: Nova runs up to wherever you stand on the crossing and you turn to face her.

## v10
- New trainer Joseph (Pikachu team: Plusle, Manectric, Jolteon, Ampharos, Raichu, Light Ball Pikachu ace, L74-90) in the Littleroot yard.
- He lets you decline the battle, and rematches whenever you ask once you have beaten him.
- Story: after you beat him he asks you to tag team against two Team Aqua grunts. 2-on-2 multi battle with Joseph's own partner Pokémon, reward of 3 Rare Candy and a PP Max.
- Nothing starts unless you have at least one Pokémon in your party.
- New partner-battle slot for Joseph (shares Steven's multi-battle code); three trainer slots added.

## v9.2
- Fixed being stuck on the stairs in the Pokémon Center 2F (approach tile elevation).

## v9.1
- Removed the door-like panels in the Wizard's room, added picture frames and a second bookshelf.

## v9
- Cozy room upstairs in the Littleroot Pokémon Center for the Pinball Wizard (he moves in from the middle of town). Cable Club and Union Room doors removed.

## v8.1
- Moved the mart clerk and the little girl in the Pokémon Center.
- Nurse Joy will not heal if you have no Pokémon yet (prevents a soft lock).

## v8
- Littleroot Pokémon Center below the gym, with excited NPCs and a Poké Mart clerk working inside it.
- Prettier Littleroot west yard.

## v7
- Custom title screen: green TILT EMERALD text and recoloured logo.

## v6
- Fixed the dead teleport pad in Cody's room.
- Prettier gym yard that blends into Littleroot.

## v5
- Littleroot expanded to the left (new connected map).
- Cody's Gym: pad-warp puzzle, four gym trainers, leader Cody with a Flygon team. Nobody battles until you have 8 badges, but everyone can be talked to.

## v4
- New intro, Steven Stone cutscene on Route 102, 15 scattered NPCs.

## v3
- Oldale mini story, new NPCs, Wizard menu and shop.

## v2
- Pinball Wizard NPC, multiball, Ball Saver, combo messages.

## v1
- Tilt mode: random wild species, win/catch combo jackpots, starter coins, new title.
