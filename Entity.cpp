#include "Entity.h"


Entity::Entity(int newX, int newY, int newWidth, int newHeight) :
		x(newX), y(newY), width(newWidth), height(newHeight){}

int Entity::getX() {
	return x;
}

int Entity::getY() {
	return y;
}

int Entity::getWidth() {
	return width;
}

int Entity::getHeight() {
	return height;
}

void Entity::setX(float newX)
{
	x = newX;
}

void Entity::setY(float newY)
{
	y = newY;
}
