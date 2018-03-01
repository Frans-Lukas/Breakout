#pragma once
#include"Entity.h"

class Block: public Entity{
private:
	int lifeLeft;
public:
	Block(float newX, float newY, int newWidth,
		int newHeight, int newLifeLeft);
	int getLifeLeft();
	void decrementLifeLeft();
};