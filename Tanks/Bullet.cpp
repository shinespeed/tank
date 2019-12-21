#include "Bullet.h"
#include "Game.h"



Bullet::Bullet(int x, int y, int way) {
	color = 250;
	coordinates.X = x;
	coordinates.Y = y;
	this->way = way;
	passability = true;//
	ShowElement();
}

bool Bullet::GetPassability() {
	return passability;
}

int Bullet::GetWay() {
	return way;
}

void Bullet::SetPassability() {}

void Bullet::Move() {
	if (way == static_cast<int>(Ways::UP)) {
		HideElement();
		SetCoordinates(coordinates.X, --coordinates.Y);
		ShowElement();
	}
	else if (way == static_cast<int>(Ways::RIGHT)) {
		HideElement();
		SetCoordinates(++coordinates.X, coordinates.Y);
		ShowElement();
	}
	else if (way == static_cast<int>(Ways::DOWN)) {
		HideElement();
		SetCoordinates(coordinates.X, ++coordinates.Y);
		ShowElement();
	}
	else if (way == static_cast<int>(Ways::LEFT)) {
		HideElement();
		SetCoordinates(--coordinates.X, coordinates.Y);
		ShowElement();
	}
}

Bullet::~Bullet() {
}