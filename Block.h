#pragma once
#include"Entity.h"

class Block: public Entity{
private:
	int lifeLeft;
public:
	Block(int newLifeLeft);
	int getLifeLeft();
	void decrementLifeLeft();
};