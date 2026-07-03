// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Rasengan (Hokage custom, id HOK_RASENGAN) - offensive Misc skill.
// The damage formula (10% of the target's max HP per level) lives in
// battle_calc_misc_attack(); here we only fire the Misc attack on castend.
class SkillRasengan : public SkillImpl {
public:
	SkillRasengan();

	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
