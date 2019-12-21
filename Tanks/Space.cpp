#include "Space.h"

Space::Space(int x, int y) {
	passability = true;
	color = 0;
	coordinates.X = x;
	coordinates.Y = y;
}

bool Space::GetPassability() {
	return passability;
}

void Space::SetPassability() {
	if (passability) {
		passability = false;
	}
	else {
		passability = true;
	}
}

Space::~Space() {
}