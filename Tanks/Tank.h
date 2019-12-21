#pragma once
#include "Object.h"
#include "Bullet.h"
class Tank : public Object
{
public:
	Tank(int x, int y);
	~Tank();

	int GetWay();
	void SetWay(int way);

	bool Object::GetPassability() override;
	void Object::SetPassability() override;
	void Move();
	Bullet Shoot(/*int tankX, int tankY*/);
	void LoseHealth();
	void Die();
	enum class Ways { UP, RIGHT, DOWN, LEFT };
private:
	int way;
	int health;
};