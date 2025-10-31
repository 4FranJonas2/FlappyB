#include "game.h"

#include <iostream>

#include "entities/player.h"
#include "entities/enemy.h"

using namespace std;

namespace flappy
{
	Player player;

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
		BeginDrawing();
		ClearBackground(BLACK);

		DrawPlayer(player);
		DrawEnemy();

		if (player.playerGotHit)
		{
			DrawText("colision", 500, 500, 20, WHITE);
			player.playerGotHit = false;
		}

		EndDrawing();
	}
}