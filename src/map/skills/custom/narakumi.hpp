// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

#include "../skill_impl.hpp"

// Narakumi no Jutsu (Hokage custom, id HOK_NARAKUMI) - "Hell Viewing Technique".
// A genjutsu that makes the target see horrifying, confusing illusions: inflicts
// Confusion + Hallucination (same effect as Wink of Charm / DC_WINKCHARM).
// Duration1 = Confusion, Duration2 = Hallucination (skill_db).
class SkillNarakumi : public SkillImpl {
public:
	SkillNarakumi();

	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
