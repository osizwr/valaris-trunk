=======================================================================
 HOKAGE CUSTOM CLASS  -  PORTABLE PACKAGE
=======================================================================
 Two files make up the whole feature:
   hokage.diff         -> SERVER patch (C++ + DB + NPC + msg)
   hokage-client.txt   -> CLIENT registration (skill lua + skilltree + sprite)

 The class rides on the stock KAGEROU (male, 4211) / OBORO (female, 4212)
 job, renamed to "Hokage": already Ninja-lineage + fully client-registered,
 so no new job id is needed. Skills HOK_KAGEBUNSHIN(7001)..SENSATSU_SUISHOU(7012).


-----------------------------------------------------------------------
 1. APPLYING THE SERVER PATCH (hokage.diff)
-----------------------------------------------------------------------
 Prereq: the target trunk must be POST "skill split" (rAthena PR #10043 /
 mid-2025 or newer) - it needs the src/map/skills/ plugin system and the
 skill_factory_custom.cpp scaffolding. Baseline used to cut this patch:
 upstream commit 7f080871c "Fix compiler errors after skill split (#10043)".

 From the target trunk root:
     git apply --check hokage.diff      # dry run - reports any conflicts
     git apply        hokage.diff       # apply
   or, without git:
     patch -p1 < hokage.diff

 If some C++ hunks reject (target trunk drifted from the baseline), the NEW
 files (skills/custom/*, db/import/*, npc/custom/hokage.txt) still apply; only
 the edited switches (skill.cpp/status.cpp/mob.cpp/script_constants.hpp) may
 need a manual 3-way merge. Use:  git apply --3way hokage.diff

 Then rebuild the map + char server.


-----------------------------------------------------------------------
 2. WHAT'S IN hokage.diff  (28 files)
-----------------------------------------------------------------------
 SKILL ENGINE
   src/map/skill.hpp / skill.cpp        HOK_* enum + castend cases (buffs,
                                        clones, dispel, earthquake)
   src/map/status.hpp / status.cpp      SC_JINTON / SC_SENNIN_MODE /
                                        SC_FUUJUTSU_KYUUIN + their stat effects
   src/map/script_constants.hpp         export the 3 custom SCs
   src/map/battle.cpp                   HOK_RASENGAN misc-damage formula
   src/map/skills/custom/*              Rasengan, Muon Satsujin, Shinra Tensei,
                                        Narakumi, Sensatsu Suishou impls +
                                        skill_factory_custom.cpp registration
   src/map/mob.cpp / mob.hpp            Kage Bunshin clone loadout + dispel
   src/map/npc.cpp                      (incidental) 2-line MVP-respawn hook -
                                        rides along because it shares mob.cpp;
                                        harmless, leave or drop.
 DATA
   db/import/skill_db.yml               12 HOK_ skill definitions
   db/import/status.yml                 the 3 custom status buffs
   db/import/skill_tree.yml             Kagerou + Oboro trees: strip native
                                        KO_/KG_/OB_ (MaxLevel:0), add HOK_
 NPC + NAMES
   npc/custom/hokage.txt                jobchange NPC (by sex -> Kagerou/Oboro)
   npc/scripts_custom.conf              registers the NPC
   conf/msg_conf/import/map_msg_eng_conf.txt   rename map msg 653/654 -> Hokage
   conf/msg_conf/char_msg.conf          rename char msg 103/104 -> Hokage


-----------------------------------------------------------------------
 3. DELIBERATELY EXCLUDED (fork config, not part of Hokage)
-----------------------------------------------------------------------
 These are in the fork but were left OUT so the patch doesn't impose unrelated
 settings on the target trunk. Add manually only if you want them:
   db/import/job_stats.yml         transcendent Base255/Job120 caps + a now-
                                   VESTIGIAL Death_Knight stat block (Hokage no
                                   longer uses it; Kagerou/Oboro keep stock stats)
   src/custom/defines_pre.hpp      PACKETVER 20220406 (client date)
   src/config/renewal.hpp          pre-renewal toggle
   conf/battle/drops.conf,monster.conf   drop-rate / monster config
   sql-files/custom/mvp_respawn.sql      MVP-respawn persistence (optional)
   compile.bat, .gitignore, src/map/unit.cpp (whitespace only)


-----------------------------------------------------------------------
 4. CLIENT SIDE  (hokage-client.txt)  -- required for skills to show
-----------------------------------------------------------------------
 For PACKETVER 20220406 clients (data\luafiles514\lua files\). See that file
 for the exact snippets; summary:
   skillinfoz\skillid.lub        + SKID.HOK_* = 7001..7012
   skillinfoz\skillinfolist.lub  + SKILL_INFO_LIST[...] (SP matches skill_db.yml)
   skillinfoz\skilldescript.lub  + tooltips
   skillinfoz\skilltreeview.lub  REPLACE the JT_KAGEROU + JT_OBORO tabs with
                                 the HOK_ layout (JT_ constants exist -> no
                                 nil-index errors)
   msgstringtable.txt            rename "Kagerou"/"Oboro" job text -> "Hokage"
   (optional) overwrite the kagerou_/oboro_ body sprites for a custom look
 Icons: the skillinfolist resource name needs data\texture\...\item\<name>.bmp,
 or point it at an existing skill's resource to reuse that icon.


-----------------------------------------------------------------------
 5. TEST
-----------------------------------------------------------------------
   Server: rebuild, restart (or @reloadskilldb / @reloaddb).
   Client: repack GRF (custom GRF must win data.ini load order).
   In-game: become the job (Hokage Master NPC or @job Kagerou/Oboro) ->
     skill tab shows ONLY the 12 HOK_ jutsu + learnable Ninja skills,
     Tajuu locked until Kage Bunshin Lv 10, job name reads "Hokage".
=======================================================================
