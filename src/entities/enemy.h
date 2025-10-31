#pragma once

#include "../utilities.h"

namespace flappy
{
	struct Enemy
	{
		Rectangle enemyFigure;
		float speed;

		bool isAlive;
	};

	void InitEnemy(Enemy& enemy);
	void UpdateEnemy(Enemy& enemy);
	void DrawEnemy(Enemy enemy);
}