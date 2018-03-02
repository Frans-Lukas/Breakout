#include "Ball.h"

Ball::Ball(int newX, int newY, 
		int xSpeed, int ySpeed,
		float radius) : 
		Entity(newX, newY, radius * 2, radius * 2){
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->radius = radius;
}

void Ball::setRadius(float radius) {
	this->radius = radius;
	this->width = radius * 2;
	this->height = radius * 2;
}

float Ball::getRadius() {
	return radius;
}

void Ball::update() {
	setX(getX() + xSpeed);
	setY(getY() + ySpeed);
}

void Ball::callCollide() {
	xSpeed = -xSpeed;
	ySpeed = -ySpeed;
}
