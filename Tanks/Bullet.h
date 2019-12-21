#pragma once
#include "Object.h"
class Bullet : public Object
{
private:
	enum class Ways { UP, RIGHT, DOWN, LEFT };
	int way;
public:
	Bullet(int x, int y, int way);

	bool Object::GetPassability() override;

	void Object::SetPassability() override;

	int GetWay();

	void Move();

	~Bullet();
};