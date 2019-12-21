#pragma once
#include "Object.h"
class Space : public Object
{
public:
	Space(int x, int y);
	~Space();
private:
	void Object::SetPassability() override;
	bool Object::GetPassability() override;
};

