#include "GameDesc.h"

vector<GameDesc> GAMETYPES
{
	// The casual game is just plain "sjoelen" with relaxed game rules.
	// Puck may be halfway through the gate to score.
	GameDesc(GameType::Casual, "CASUAL", false, 30, 3),

	// Same as classic "sjoelen" but with professional game rules.
	// Puck must be fully inside the gate to score.
	GameDesc(GameType::Pro, "PROFESSIONAL", true, 30, 3),

	// Same as classic "sjoelen" with professional game rules but a short version.
	GameDesc(GameType::Short, "SHORT", true, 30, 1),

	// A multiplayer mode of "sjoelen" with professional game rules.
	GameDesc(GameType::Multiplayer, "MULTIPLAYER", true, 30, 2, true)
};

const GameDesc& GameDesc::Find(GameType type)
{
	for(const GameDesc& gd : GAMETYPES)
	{
		if(gd.id == type)
			return gd;
	}
	FAIL("Requested game type descriptor is not registered");
	return GAMETYPES.front();
}
