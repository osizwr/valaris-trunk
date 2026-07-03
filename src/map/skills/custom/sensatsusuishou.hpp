// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Sensatsu Suishou (Hokage custom, id HOK_SENSATSU_SUISHOU) - "Thousand Flying
// Water Needles of Death". Self-cast AoE that hits every nearby enemy for 1% of
// their CURRENT HP per level (reference: Water Ball). Each hit is applied
// manually and displayed with Water Ball's own animation (WZ_WATERBALL) so it
// looks like a water attack without any client-side effect edit.
class SkillSensatsuSuishou : public SkillImpl {
public:
	SkillSensatsuSuishou();

	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
