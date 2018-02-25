#pragma once
#include "Entity.h"

class Player: public Entity {
private:
	int lifeLeft;
public:
	Player(float newX, float newY, int newWidth, int newHeight);
	int getLife();
	void setLife(int newLife);
};