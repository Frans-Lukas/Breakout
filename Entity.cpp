#include "Entity.h"


Entity::Entity(float newX, float newY, int newWidth, int newHeight) :
		x(newX), y(newY), width(newWidth), height(newHeight){}

float Entity::getX() {
	return x;
}

float Entity::getY() {
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
