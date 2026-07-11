// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Custom (Necromancer): Unholy Bomb - a bomb of dead human remains that behaves
// exactly like the Alchemist's Acid Demonstration (CR_ACIDDEMONSTRATION): a
// forced-neutral Misc multi-hit that scales off the target's VIT and the caster's
// INT and shatters the target's weapon/armor. This is a verbatim mirror of
// SkillAcidDemonstration (skills/merchant/aciddemonstration) bound to its own id.
class SkillUnholyBomb : public WeaponSkillImpl {
public:
	SkillUnholyBomb();

	void applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
	void calculateSkillRatio(const Damage *wd, const block_list *src, const block_list *target, uint16 skill_lv, int32 &base_skillratio, int32 mflag) const override;
	void castendDamageId(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
