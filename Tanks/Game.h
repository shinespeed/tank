#pragma once
#include "Object.h"
#include "Space.h"
#include "Wall.h"
#include "Tank.h"
#include "Bullet.h"

#include <vector>
class Game
{
public:
	Game();
	~Game();
private:
	void GenerateField();
	void PrintTheField();
	void GenerateMyTank();
	void HandleKeys();
	void BulletsMove();

	static const int ROW = 25, COL = 50;

	Object* field[ROW][COL];
	Tank* myTank;

	enum class Keys {UP = 72, RIGHT = 77, DOWN = 80, LEFT = 75, SHOOT = 32};
	std::vector <Bullet> bullets;
	std::vector <Tank> tanks;
};