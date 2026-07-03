// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "shinratensei.hpp"

#include "../../clif.hpp"

SkillShinraTensei::SkillShinraTensei() : WeaponSkillImpl(HOK_SHINRA_TENSEI) {
}

void SkillShinraTensei::castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	// Self-cast side: show the effect on the caster, then strike every enemy in
	// the splash radius. Each hit runs through castendDamageId (BF_WEAPON) and the
	// per-level Knockback field pushes them away from the caster (skill_get_blewcount).
	clif_skill_nodamage(src, *src, getSkillId(), skill_lv);
	map_foreachinshootrange(skill_area_sub, src,
		skill_get_splash(getSkillId(), skill_lv), BL_CHAR | BL_SKILL,
		src, getSkillId(), skill_lv, tick, flag | BCT_ENEMY | SD_ANIMATION | 1,
		skill_castend_damage_id);
}

void SkillShinraTensei::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	// Base 100% + 100% ATK per level (200% at Lv1 -> 600% at Lv5). Tune here.
	base_skillratio += 100 * skill_lv;
}
