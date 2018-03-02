#include "Ball.h"

Ball::Ball(int newX, int newY, 
		int xSpeed, int ySpeed,
		int width, int height,
		float radius) : 
		Entity(newX, newY, width, height){
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->radius = radius;
}

void Ball::setRadius(float radius) {
	this->radius = radius;
}

float Ball::getRadius() {
	return radius;
}

void Ball::update() {
	setX(getX() + xSpeed);
	setY(getY() + ySpeed);
}
