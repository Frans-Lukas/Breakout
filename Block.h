#pragma once
#include"Entity.h"

class Block: public Entity{
private:
	int lifeLeft;
public:
	Block(int lifeLeft);
	int getLifeLeft();
	void decrementLifeLeft();
};