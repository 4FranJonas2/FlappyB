#pragma once

#include "../utilities.h"

#include "raylib.h"

namespace flappy
{
	struct Player
	{
		Rectangle playerFigure;
		Circle playerHitbox;
		int lives;
		float speed;

		bool moveUp;
		bool moveDown;
		bool playerGotHit;
	};

	void InitPlayer(Player& player);
	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player player);
}