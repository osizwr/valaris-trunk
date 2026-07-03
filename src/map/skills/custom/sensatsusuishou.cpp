// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "sensatsusuishou.hpp"

#include "../../battle.hpp"
#include "../../clif.hpp"
#include "../../status.hpp"

SkillSensatsuSuishou::SkillSensatsuSuishou() : SkillImpl(HOK_SENSATSU_SUISHOU) {
}

void SkillSensatsuSuishou::castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	// Self-cast side: unleash the needles at every enemy in the splash radius.
	// Each enemy re-enters castendDamageId (below) for the actual water hit.
	clif_skill_nodamage(src, *src, getSkillId(), skill_lv);
	map_foreachinshootrange(skill_area_sub, src,
		skill_get_splash(getSkillId(), skill_lv), BL_CHAR | BL_SKILL,
		src, getSkillId(), skill_lv, tick, flag | BCT_ENEMY | SD_ANIMATION | 1,
		skill_castend_damage_id);
}

void SkillSensatsuSuishou::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	status_data* tstatus = status_get_status_data(*target);

	// 1% of the target's CURRENT HP per skill level (reference: Water Ball).
	int64 damage = (int64)tstatus->hp * skill_lv / 100;

	if (damage < 1)
		damage = 1;

	// Display the hit with Water Ball's animation, then apply the damage.
	clif_skill_damage(*src, *target, tick, status_get_amotion(src), tstatus->dmotion, damage, 1, WZ_WATERBALL, skill_lv, DMG_SPLASH);
	battle_fix_damage(src, target, damage, 1, getSkillId());
}
