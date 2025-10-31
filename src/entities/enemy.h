#pragma once

#include "raylib.h"

namespace flappy
{
	struct Enemy
	{
		Rectangle enemyFigure;
		float speed;

		bool isAlive;
	};

	void CreateEnemy();
	void UpdateEnemy();
	void DrawEnemy();
}