#include "Tank.h"

Tank::Tank(int x, int y)
{
	coordinates.X = x;
	coordinates.Y = y;
	passability = false;
	color = 60;
	health = 3;
	way = static_cast<int>(Ways::UP);
}

bool Tank::GetPassability() {
	return passability;
}

void Tank::SetPassability() {

}

int Tank::GetWay() {
	return way;
}

void Tank::Move() {
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

void Tank::SetWay(int way) {
	this->way = way;
}

void Tank::LoseHealth() {
	--health;
}

Bullet Tank::Shoot() {
	if (!this->GetWay()) {
		Bullet b(this->coordinates.X, this->coordinates.Y - 1, this->GetWay());
		return b;
	}
	if (this->GetWay() == 1) {
		Bullet b(this->coordinates.X + 1, this->coordinates.Y, this->GetWay());
		return b;
	}
	if (this->GetWay() == 2) {
		Bullet b(this->coordinates.X, this->coordinates.Y + 1, this->GetWay());
		return b;
	}
	if (this->GetWay() == 3) {
		Bullet b(this->coordinates.X - 1, this->coordinates.Y, this->GetWay());
		return b;
	}
}

Tank::~Tank() {
}