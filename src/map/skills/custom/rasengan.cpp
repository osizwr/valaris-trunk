// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "rasengan.hpp"

#include "../../status.hpp"

SkillRasengan::SkillRasengan() : SkillImpl(HOK_RASENGAN) {
}

void SkillRasengan::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	// Damage (10% of target max HP per level) is calculated in battle_calc_misc_attack().
	skill_attack(BF_MISC, src, src, target, getSkillId(), skill_lv, tick, flag);
}
