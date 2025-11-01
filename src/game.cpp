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
		InitEnemy();

	}

	void Input()
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:
			break;
		case SceneStatus::GAMERULES:
			break;
		case SceneStatus::GAMECREDITS:
			break;
		case SceneStatus::FIRSTGAME:
			break;
		case SceneStatus::GAMEPLAY:
			
			InputPlayer(player);
			break;
		case SceneStatus::GAMEPAUSE:
			break;
		case SceneStatus::RESETGAME:
			break;
		case SceneStatus::GAMEEND:
			break;
		
		default:
			break;
		}
	}

	void Update()
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:
			break;
		case SceneStatus::GAMERULES:
			break;
		case SceneStatus::GAMECREDITS:
			break;
		case SceneStatus::FIRSTGAME:
			break;
		case SceneStatus::GAMEPLAY:

			UpdatePlayer(player);
			UpdateEnemy();
			CheckPlayerColision(player.playerHitbox, player.playerGotHit);
			break;
		case SceneStatus::GAMEPAUSE:
			break;
		case SceneStatus::RESETGAME:

			InitPlayer(player);
			InitEnemy();
			gameStats.gameStatus = SceneStatus::GAMEPLAY;
			break;
		case SceneStatus::GAMEEND:
			break;

		default:
			break;
		}
	}

	void Draw()
	{
		int auxPosX = 10;
		int auxPosY = 10;
		int auxFont = 10;

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("v0.1", auxPosX, auxPosY, auxFont, WHITE);

		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:
			break;
		case SceneStatus::GAMERULES:
			break;
		case SceneStatus::GAMECREDITS:
			break;
		case SceneStatus::FIRSTGAME:
			break;
		case SceneStatus::GAMEPLAY:

			DrawPlayer(player);
			DrawEnemy();

			if (player.playerGotHit)
			{
				DrawText("colision",static_cast <int> (player.playerFigure.x), 
					static_cast <int> (player.playerFigure.y - player.playerFigure.height/2), auxFont, WHITE);

				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			break;
		case SceneStatus::GAMEPAUSE:
			break;
		case SceneStatus::RESETGAME:
			break;
		case SceneStatus::GAMEEND:
			break;

		default:
			break;
		}



		EndDrawing();
	}
}