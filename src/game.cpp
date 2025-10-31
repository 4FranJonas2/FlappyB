#include "game.h"

#include <iostream>

#include "entities/player.h"
#include "entities/enemy.h"

using namespace std;

namespace flappy
{
	Player player;
	GameStats gameStats;

	void Init();
	void Input();
	void Update();
	void Draw();

	void RunGame()
	{
		Init();

		while (!WindowShouldClose())
		{
			Input();
			Update();
			Draw();
		}

		CloseWindow();
	}

	void Init()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		InitWindow(screenWidth, screenHeight, "Aracnoids");

		InitPlayer(player);
	}

	void Input()
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEPLAY:
			break;

		default:
			break;
		}
		InputPlayer(player);
	}

	void Update()
	{
		UpdatePlayer(player);
		UpdateEnemy();
		CheckPlayerColision(player.playerHitbox, player.playerGotHit);
	}

	void Draw()
	{
		int auxPosX = 10;
		int auxPosY = 10;
		int auxFont = 10;

		BeginDrawing();
		ClearBackground(BLACK);

		DrawPlayer(player);
		DrawEnemy();

		if (player.playerGotHit)
		{
			DrawText("colision",static_cast <int> (player.playerFigure.x), 
				static_cast <int> (player.playerFigure.y - player.playerFigure.height/2), auxFont, WHITE);

			player.playerGotHit = false;
		}

		DrawText("v0.1", auxPosX, auxPosY, auxFont, WHITE);

		EndDrawing();
	}
}