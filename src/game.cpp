#include "game.h"

#include <iostream>

#include "entities/player.h"
#include "entities/enemy.h"
#include "entities/menu.h"
#include "entities/background.h"

using namespace std;

namespace flappy
{
	Player player;
	GameStats gameStats;
	MenuButtons buttons;

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

		UnloadBackGorund();
		CloseWindow();
	}

	void Init()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		InitWindow(screenWidth, screenHeight, "Aracnoids");

		InitBackGorund();

		InitPlayer(player);
		InitEnemy();
		InitButtons(buttons);
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
			UpdateSceneMenus(gameStats, buttons);
			break;
		case SceneStatus::GAMERULES:
			UpdateSceneMenus(gameStats, buttons);
			break;
		case SceneStatus::GAMECREDITS:
			UpdateSceneMenus(gameStats, buttons);

			break;
		case SceneStatus::FIRSTGAME:

			UpdateSceneMenus(gameStats, buttons);

			break;
		case SceneStatus::GAMEPLAY:

			UpdateBackGorund();
			UpdatePlayer(player);
			UpdateEnemy();
			UpdateSceneMenus(gameStats, buttons);
			CheckPlayerColision(player.playerHitbox, player.playerGotHit);

			if (player.playerGotHit)
			{
				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			break;
		case SceneStatus::GAMEPAUSE:

			UpdateSceneMenus(gameStats, buttons);

			break;
		case SceneStatus::RESETGAME:

			InitPlayer(player);
			InitEnemy();
			gameStats.gameStatus = SceneStatus::FIRSTGAME;
			break;
		case SceneStatus::GAMEEND:

			UpdateSceneMenus(gameStats, buttons);

			break;

		default:
			break;
		}
	}

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:
			DrawMenuTypeScene(gameStats, buttons);
			break;
		case SceneStatus::GAMERULES:
			DrawMenuTypeScene(gameStats, buttons);

			break;
		case SceneStatus::GAMECREDITS:
			DrawMenuTypeScene(gameStats, buttons);

			break;
		case SceneStatus::FIRSTGAME:
			DrawBackGround();

			DrawPlayer(player);
			DrawMenuTypeScene(gameStats, buttons);

			break;
		case SceneStatus::GAMEPLAY:

			DrawBackGround();
			DrawPlayer(player);
			DrawEnemy();

			break;
		case SceneStatus::GAMEPAUSE:
			DrawBackGround();

			DrawPlayer(player);
			DrawEnemy();
			DrawMenuTypeScene(gameStats, buttons);

			break;
		case SceneStatus::RESETGAME:
				/*DrawText("colision",static_cast <int> (player.playerFigure.x), 
					static_cast <int> (player.playerFigure.y - player.playerFigure.height/2), auxFont, WHITE);*/
			break;
		case SceneStatus::GAMEEND:
			DrawBackGround();

			DrawPlayer(player);
			DrawEnemy();
			DrawMenuTypeScene(gameStats, buttons);

			break;

		default:
			break;
		}



		EndDrawing();
	}
}