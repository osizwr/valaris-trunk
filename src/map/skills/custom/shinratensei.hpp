// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Shinra Tensei / Almighty Push (Hokage custom, id HOK_SHINRA_TENSEI).
// Self-cast offensive AoE (like Sightrasher / Magnum Break): damages every enemy
// around the caster and knocks them radially outward. Knockback distance and
// splash radius scale with level (Knockback/SplashArea per-level in skill_db).
// Extends WeaponSkillImpl so the per-enemy hit is a BF_WEAPON attack (scales with
// the caster's ATK); we only add the self-cast fan-out and the damage ratio.
class SkillShinraTensei : public WeaponSkillImpl {
public:
	SkillShinraTensei();

	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
};
