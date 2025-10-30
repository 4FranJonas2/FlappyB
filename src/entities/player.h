#pragma once

#include "../utilities.h"

namespace flappy
{
	struct Player
	{
		Rectangle playerFigure;
		Circle playerHitbox;
		int lives;

		bool moveUp;
		bool moveDown;
	};

	void InitPlayer(Player& player);
	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player& player);

}