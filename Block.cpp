#include "Block.h"


Block::Block(int newX, int newY, int newWidth,
	int newHeight, int newLifeLeft) : 
	Entity(newX, newY, newWidth, newHeight){
	lifeLeft = newLifeLeft;
}

int Block::getLifeLeft()
{
	return lifeLeft;
}

void Block::decrementLifeLeft()
{
	lifeLeft--;
}

