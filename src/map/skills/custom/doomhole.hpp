// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Custom (Necromancer): Doom Hole - offensive Dark magic that erupts across a wide
// area (splash). Its magic damage grows with level; each enemy caught in the blast
// has a chance to be Cursed and is knocked back. Splash size, element and knockback
// come from the skill_db; the per-level ratio and the Curse are applied here.
class SkillDoomHole : public SkillImplRecursiveDamageSplash {
public:
	SkillDoomHole();

	void calculateSkillRatio(const Damage *wd, const block_list *src, const block_list *target, uint16 skill_lv, int32 &skillratio, int32 mflag) const override;
	void applyAdditionalEffects(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
};
