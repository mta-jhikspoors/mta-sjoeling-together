#pragma once
#include "Tools.h"

// The IDs of the game types.
// The ID should never change. The ID is what we use to identify this game type and
// allows us to change the order of the game types or remove a game type.
enum class GameType
{
	//Casual = 0,
	Pro = 0,
	Short = 1
};

struct GameDesc
{
	// The IDs of the game type
	GameType id;

	// The name of the game
	String name;

	// Offical scoring rules or casual scoring rules
	bool officialrules;

	// Game pucks
	int pucks;

	// Game rounds
	int rounds;

	// Constructor
	GameDesc(GameType _id, String _name, bool _officialrules, int _pucks, int _rounds) :
		id(_id),
		name(_name),
		officialrules(_officialrules),
		pucks(_pucks),
		rounds(_rounds)
	{
	}

	// Finds and returns a game descriptor by type
	static const GameDesc& Find(GameType type);
};

extern vector<GameDesc> GAMETYPES;
