// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "skill_factory_custom.hpp"

// Include .cpp files into the TU to optimize compile time
// For reference see unity builds or amalgamated builds
#include "rasengan.cpp"
#include "muonsatsujin.cpp"
#include "shinratensei.cpp"
#include "narakumi.cpp"
#include "sensatsusuishou.cpp"

std::unique_ptr<const SkillImpl> SkillFactoryCustom::create(const e_skill skill_id) const {
	switch( skill_id ){
		// Hokage custom offensive skills
		case HOK_RASENGAN:
			return std::make_unique<SkillRasengan>();
		case HOK_MUON_SATSUJIN:
			return std::make_unique<SkillMuonSatsujin>();
		case HOK_SHINRA_TENSEI:
			return std::make_unique<SkillShinraTensei>();
		case HOK_NARAKUMI:
			return std::make_unique<SkillNarakumi>();
		case HOK_SENSATSU_SUISHOU:
			return std::make_unique<SkillSensatsuSuishou>();

		default:
			return nullptr;
	}
}
