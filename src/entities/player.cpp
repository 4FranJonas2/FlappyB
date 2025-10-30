#include "player.h"

namespace flappy
{

	void InitPlayer(Player& player)
	{
		player.playerFigure.x = 300.0f;
		player.playerFigure.y = 500.0f;
		player.playerFigure.width = 30.0f;
		player.playerFigure.height = 40.0f;

		player.playerHitbox.pos.x = 300.0f;
		player.playerHitbox.pos.y = 500.0f;
		player.playerHitbox.rad = 10.0f;

		player.lives = 1;

		player.moveUp = false;
		player.moveDown = false;
	}
	void InputPlayer(Player& player)
	{
		if (IsKeyDown(KEY_W) && !player.moveDown)
		{
			player.moveUp = true;
		}
		if (IsKeyDown(KEY_S) && !player.moveUp)
		{
			player.moveDown = true;
		}
		if (!IsKeyDown(KEY_W))
		{
			player.moveUp = false;
		}
		if (!IsKeyDown(KEY_S))
		{
			player.moveDown = false;
		}
	}
	void UpdatePlayer(Player& player)
	{
		if (player.moveUp)
		{
			player.playerFigure.x--;
			player.playerHitbox.pos.x = player.playerFigure.x;
		}
		if (player.moveDown)
		{
			player.playerFigure.x++;
			player.playerHitbox.pos.x = player.playerFigure.x;
		}
	}
	void DrawPlayer(Player& player)
	{
		DrawRectangle(static_cast <int>(player.playerFigure.x),
			static_cast <int>(player.playerFigure.y),
			static_cast <int>(player.playerFigure.width),
			static_cast <int>(player.playerFigure.height),RED);
		DrawCircleLines(static_cast <int>(player.playerHitbox.pos.x),
			static_cast <int>(player.playerHitbox.pos.y),
			static_cast <int>(player.playerHitbox.rad), RED);
	}
}