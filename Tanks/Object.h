#pragma once
#include <windows.h>
class Object
{
public:
	Object();
	virtual ~Object();
//protected:
	COORD coordinates;
	int color;
	bool passability;

	virtual bool GetPassability() = 0;
	virtual void SetPassability() = 0;
	COORD GetCoordinates();
	void SetCoordinates(int x, int y);
	void HideElement();
	void ShowElement();
	void printElement(COORD c, int color);
};

