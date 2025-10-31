#include "game.h"

#include "entities/player.h"

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
	}

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawPlayer(player);

		EndDrawing();
	}
}