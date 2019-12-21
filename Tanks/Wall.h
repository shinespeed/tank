#pragma once
#include "Object.h"
class Wall : public Object
{
public:
	Wall(int x, int y);
	~Wall();
private:
	void Object::SetPassability() override;
	bool Object::GetPassability() override;
};

