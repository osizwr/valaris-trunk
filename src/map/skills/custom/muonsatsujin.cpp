// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "muonsatsujin.hpp"

SkillMuonSatsujin::SkillMuonSatsujin() : WeaponSkillImpl(HOK_MUON_SATSUJIN) {
}

void SkillMuonSatsujin::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	// Base 100% + 200% ATK per level (300% at Lv1 -> 1100% at Lv5). Tune here.
	base_skillratio += 200 * skill_lv;
}
