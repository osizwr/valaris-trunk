// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "doomhole.hpp"

#include <config/core.hpp>

#include "map/status.hpp"

SkillDoomHole::SkillDoomHole() : SkillImplRecursiveDamageSplash(NEC_DOOM_HOLE) {
}

void SkillDoomHole::calculateSkillRatio(const Damage *wd, const block_list *src, const block_list *target, uint16 skill_lv, int32 &skillratio, int32 mflag) const {
	// Magic damage grows with level (MATK ratio: base 100% + 100% per level).
	skillratio += 100 * skill_lv;
}

void SkillDoomHole::applyAdditionalEffects(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const {
	// Chance to Curse each enemy struck (grows with level). Duration2 = curse time.
	sc_start(src, target, SC_CURSE, 20 + 5 * skill_lv, skill_lv, skill_get_time2(getSkillId(), skill_lv));
}
