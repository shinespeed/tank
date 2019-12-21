#include "Object.h"

Object::Object() {
}

void Object::SetCoordinates(int x, int y) {
	coordinates.X = x;
	coordinates.Y = y;
}

COORD Object::GetCoordinates() {
	return coordinates;
}

void Object::printElement(COORD c, int color){
	static HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	static DWORD written;

	/*COORD c;
	c.X = x;
	c.Y = y;*/
	//FillConsoleOutputAttribute(hout, FOREGROUND_GREEN | BACKGROUND_RED, 1, c, &written);
	FillConsoleOutputAttribute(hout, color, 1, c, &written);
}

void Object::HideElement() {
	printElement(coordinates, 0);
}

void Object::ShowElement() {
	printElement(coordinates, color);
}

Object::~Object() {
}