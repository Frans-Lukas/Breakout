#include "Ball.h"

Ball::Ball(int newX, int newY,  
		float radius) : 
		Entity(newX, newY, 0, 0){
	this->radius = radius;
}

void Ball::setRadius(float radius) {
	this->radius = radius;
}

float Ball::getRadius() {
	return radius;
}
