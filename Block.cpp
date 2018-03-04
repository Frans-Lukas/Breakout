#include "Block.h"
#include <iostream>

Block::Block(int newX, int newY, int newWidth,
	int newHeight, int newLifeLeft) : 
	Entity(newX, newY, newWidth, newHeight){
	lifeLeft = newLifeLeft;
}

int Block::getLifeLeft()
{
	return lifeLeft;
}

sf::Color Block::getColor() {
	return color;
}

void Block::setColor(sf::Color color){
	this->color = color;
}

void Block::decrementLifeLeft(){
	lifeLeft--;
}

void Block::callCollide(Entity collidingEntity) {
	decrementLifeLeft();
}

