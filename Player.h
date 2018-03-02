#pragma once
#include "Entity.h"

class Player: public Entity {
private:
	int lifeLeft;
	bool left;
	bool right;

	void getUserInput();
public:
	Player(int newX, int newY, int newWidth, int newHeight);
	int getLife();
	void update();
	void setLife(int newLife);
};