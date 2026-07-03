// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Muon Satsujin no Jutsu (Hokage custom, id HOK_MUON_SATSUJIN) - "Silent Homicide".
// A weapon (ATK) skill that never misses (IgnoreFlee in skill_db). WeaponSkillImpl
// already fires the BF_WEAPON attack on castend; we only scale the damage ratio.
class SkillMuonSatsujin : public WeaponSkillImpl {
public:
	SkillMuonSatsujin();

	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
};
