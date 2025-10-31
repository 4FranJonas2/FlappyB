#pragma once

#include "raylib.h"

namespace flappy
{
	struct Circle
	{
		Vector2 pos;
		float rad;
	};

	enum class SceneStatus
	{
		GAMEMENU = 1,
		GAMERULES,
		GAMECREDITS,
		FIRSTGAME,
		GAMEPLAY,
		GAMEPAUSE,
		RESETGAME,
		GAMEEND,
		SIMEND
	};

	struct GameStats
	{
		SceneStatus gameStatus = SceneStatus::GAMEPLAY;

		int fontSize = 25;
	};
}