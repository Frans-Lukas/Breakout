#pragma once
#include"Entity.h"

class Block: public Entity{
private:
	int lifeLeft;
public:
	Block(int newX, int newY, int newWidth,
		int newHeight, int newLifeLeft);
	int getLifeLeft();
	void decrementLifeLeft();
};