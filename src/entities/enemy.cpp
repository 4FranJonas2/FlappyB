#include "enemy.h"


namespace flappy
{
	const int maxEnemys = 5;

	float spawnTimer = 0.0f;
	float spawnDelay = 2.0f;
	float enemyCounter = 0;

	Enemy enemy[maxEnemys];

	void CheckArenaLimits(int i);

	void CreateEnemy()
	{
		float auxPosX = 50.0f;
		int minRangeYPos = 200;
		int maxRangeYPos = 700;

		for (int i = 0; i < maxEnemys; i++)
		{
			if (!enemy[i].isAlive)
			{
				enemy[i].enemyFigure.x = GetScreenWidth() + auxPosX;
				enemy[i].enemyFigure.y = static_cast<float>(GetRandomValue(minRangeYPos, maxRangeYPos));
				enemy[i].enemyFigure.width = 50.0f;
				enemy[i].enemyFigure.height = 600.0f;

				enemy[i].isAlive = true;
				enemy[i].speed = 200.0f;

				break;
			}
		}
	}
	void UpdateEnemy()
	{
		spawnTimer += GetFrameTime();

		if (spawnTimer >= spawnDelay && enemyCounter < maxEnemys)
		{
			CreateEnemy();
			spawnTimer = 0;
		}

		for (int i = 0; i < maxEnemys; i++)
		{
			if (enemy[i].isAlive)
			{
				enemy[i].enemyFigure.x -= enemy[i].speed * GetFrameTime();
				CheckArenaLimits(i);
			}
		}
	}
	void DrawEnemy()
	{
		for (int i = 0; i < maxEnemys; i++)
		{
			if (enemy[i].isAlive)
			{
				DrawRectangle(static_cast <int>(enemy[i].enemyFigure.x),
					static_cast <int>(enemy[i].enemyFigure.y),
					static_cast <int>(enemy[i].enemyFigure.width),
					static_cast <int>(enemy[i].enemyFigure.height), RED);
			}
		}
	}

	void CheckArenaLimits(int i)
	{
		if (enemy[i].isAlive && enemy[i].enemyFigure.x < 0.0f - enemy[i].enemyFigure.width)
		{
			enemy[i].isAlive = false;
		}
	}

	void CheckPlayerColision(Circle playerHitBox, bool& isHit)
	{
		for (int i = 0; i < maxEnemys; i++)
		{
			if (enemy[i].isAlive 
				&& playerHitBox.pos.x + playerHitBox.rad >= enemy[i].enemyFigure.x
				&& playerHitBox.pos.y + playerHitBox.rad >= enemy[i].enemyFigure.y
				&& playerHitBox.pos.x - playerHitBox.rad <= enemy[i].enemyFigure.x + enemy[i].enemyFigure.width)
			{
				isHit = true;
			}
		}
	}
}