// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "narakumi.hpp"

#include "../../clif.hpp"
#include "../../status.hpp"

SkillNarakumi::SkillNarakumi() : SkillImpl(HOK_NARAKUMI) {
}

void SkillNarakumi::castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	// Genjutsu: horrifying + confusing illusions -> Hallucination + Confusion.
	sc_start(src, target, SC_CONFUSION, 100, skill_lv, skill_get_time(getSkillId(), skill_lv));
	sc_start(src, target, SC_HALLUCINATION, 100, skill_lv, skill_get_time2(getSkillId(), skill_lv));
	clif_skill_nodamage(src, *target, getSkillId(), skill_lv);
}
