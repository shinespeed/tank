#include "Game.h"
#include <time.h>
#include <conio.h>

#include <iostream>

Game::Game() {
	GenerateField();
	PrintTheField();
	GenerateMyTank();
	HandleKeys();
}

void Game::GenerateField() {
	srand(time(0));
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if ((rand() % 100) < 20) {
				field[i][j] = new Wall(j, i);
			}
			else {
				field[i][j] = new Space(j, i);
			}
		}
	}
}

void Game::PrintTheField() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			field[i][j]->ShowElement();
		}
	}
}

void Game::GenerateMyTank() {
	int x, y;
	while (true) {
		x = (rand() % 10) + 20;
		y = (rand() % 5) + 20;
		if (field[y][x]->GetPassability()) {
			myTank = new Tank(x, y);
			myTank->ShowElement();
			//field[y][x]
			break;
		}
	}
}

void Game::HandleKeys() {

	char k;
	while (true) {
		if (_kbhit()) {
			k = _getch();

			if (k == static_cast<int>(Game::Keys::SHOOT)) {
				if (!myTank->GetWay()) {
					if (field[myTank->GetCoordinates().Y - 1][myTank->GetCoordinates().X]->GetPassability()) {
						//std::cout << "shoot up";
						bullets.emplace_back(myTank->Shoot());
						BulletsMove();
					}
				}
				if (myTank->GetWay() == 1) {
					if (field[myTank->GetCoordinates().Y][myTank->GetCoordinates().X + 1]->GetPassability()) {
						//std::cout << "shoot right";
						bullets.emplace_back(myTank->Shoot());
						BulletsMove();
					}
				}
				if (myTank->GetWay() == 2) {
					if (field[myTank->GetCoordinates().Y + 1][myTank->GetCoordinates().X]->GetPassability()) {
						//std::cout << "shoot down";
						bullets.emplace_back(myTank->Shoot());
						BulletsMove();
					}
				}
				if (myTank->GetWay() == 3) {
					if (field[myTank->GetCoordinates().Y][myTank->GetCoordinates().X - 1]->GetPassability()) {
						//std::cout << "shoot left";
						bullets.emplace_back(myTank->Shoot());
						BulletsMove();
					}
				}
			}

			else if (k == static_cast<int>(Game::Keys::UP)) {
				myTank->SetWay(static_cast<int>(Tank::Ways::UP));
				if (myTank->GetCoordinates().Y > 0) {
					if (field[myTank->GetCoordinates().Y - 1][myTank->GetCoordinates().X]->GetPassability()) {
						myTank->Move();
					}
				}
			}
			else if (k == static_cast<int>(Game::Keys::RIGHT)) {
				myTank->SetWay(static_cast<int>(Tank::Ways::RIGHT));
				if (myTank->GetCoordinates().X < 49) {
					if (field[myTank->GetCoordinates().Y][myTank->GetCoordinates().X + 1]->GetPassability()) {
						myTank->Move();
					}
				}
			}
			else if (k == static_cast<int>(Game::Keys::DOWN)) {
				myTank->SetWay(static_cast<int>(Tank::Ways::DOWN));
				if (myTank->GetCoordinates().Y < 24) {
					if (field[myTank->GetCoordinates().Y + 1][myTank->GetCoordinates().X]->GetPassability()) {
						myTank->Move();
					}
				}
			}
			else if (k == static_cast<int>(Game::Keys::LEFT)) {
				myTank->SetWay(static_cast<int>(Tank::Ways::LEFT));
				if (myTank->GetCoordinates().X > 0) {
					if (field[myTank->GetCoordinates().Y][myTank->GetCoordinates().X - 1]->GetPassability()) {
						myTank->Move();
					}
				}
			}
		}
	}
}

void Game::BulletsMove() {
	while (!bullets.empty()) {
		for (int i = 0; i < bullets.size(); ++i) {
			if (bullets.at(i).GetCoordinates().Y > 0 &&
				!bullets.at(i).GetWay() &&
				field[bullets.at(i).GetCoordinates().Y - 1][bullets.at(i).GetCoordinates().X]->GetPassability()) {
				bullets.at(i).Move();
			}
			else if (bullets.at(i).GetCoordinates().X < 49 &&
				bullets.at(i).GetWay() == 1 &&
				field[bullets.at(i).GetCoordinates().Y][bullets.at(i).GetCoordinates().X + 1]->GetPassability()) {
				bullets.at(i).Move();
			}
			else if (bullets.at(i).GetCoordinates().Y < 24 &&
				bullets.at(i).GetWay() == 2 &&
				field[bullets.at(i).GetCoordinates().Y + 1][bullets.at(i).GetCoordinates().X]->GetPassability()) {
				bullets.at(i).Move();
			}
			else if (bullets.at(i).GetCoordinates().X > 0 &&
				bullets.at(i).GetWay() == 3 &&
				field[bullets.at(i).GetCoordinates().Y][bullets.at(i).GetCoordinates().X - 1]->GetPassability()) {
				bullets.at(i).Move();
			}
			else {
				bullets.erase(bullets.begin() + i);
			}
		}
	}
}

Game::~Game() {
}