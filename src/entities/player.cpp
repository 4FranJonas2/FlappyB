#include "player.h"

namespace flappy
{
	void CheckArenaCollision(Player& player);

	void InitPlayer(Player& player)
	{
		player.playerFigure.x = 400.0f;
		player.playerFigure.y = 500.0f;
		player.playerFigure.width = 30.0f;
		player.playerFigure.height = 40.0f;

		player.playerHitbox.pos.x = 400.0f;
		player.playerHitbox.pos.y = 500.0f;
		player.playerHitbox.rad = 25.0f;

		player.lives = 1;
		player.speed = 1300.0f;

		player.moveUp = false;
		player.moveDown = false;
		player.playerGotHit = false;
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
			player.playerFigure.y -= player.speed * GetFrameTime();
			player.playerHitbox.pos.y = player.playerFigure.y;
		}
		if (player.moveDown)
		{
			player.playerFigure.y += player.speed * GetFrameTime();
			player.playerHitbox.pos.y = player.playerFigure.y;
		}
		else
		{
			player.playerFigure.y = player.playerFigure.y;
		}

		CheckArenaCollision(player);

		player.playerHitbox.pos.x = player.playerFigure.x + player.playerFigure.width / 2;
		player.playerHitbox.pos.y = player.playerFigure.y + player.playerFigure.height / 2;
	}
	void DrawPlayer(Player player)
	{
		DrawRectangle(static_cast <int>(player.playerFigure.x),
			static_cast <int>(player.playerFigure.y),
			static_cast <int>(player.playerFigure.width),
			static_cast <int>(player.playerFigure.height), RED);
		DrawCircleLines(static_cast <int>(player.playerHitbox.pos.x),
			static_cast <int>(player.playerHitbox.pos.y),
			static_cast <float>(player.playerHitbox.rad), RED);
	}

	void CheckArenaCollision(Player& player)
	{
		if (player.playerFigure.y <= 0.0f)
		{
			player.playerFigure.y += player.playerFigure.height;
		}
		if (player.playerFigure.y + player.playerFigure.height >= GetScreenHeight())
		{
			player.playerFigure.y -= player.playerFigure.height;
		}
	}
}