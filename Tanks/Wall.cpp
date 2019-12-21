#include "Wall.h"



Wall::Wall(int x, int y) {
	coordinates.X = x;
	coordinates.Y = y;
	passability = false;
	color = 120;
}

bool Wall::GetPassability() {
	return passability;
}

void Wall::SetPassability() {}

Wall::~Wall()
{
}
