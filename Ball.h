#pragma once
#include "Entity.h"


class Ball : public Entity {
private: 
	float radius;
	int xSpeed;
	int ySpeed;
public:
	Ball(int newX, int newY, 
		int xSpeed, int ySpeed,
		float radius);
	void setRadius(float radius);
	float getRadius();
	void update();
	void callCollide(Entity collidingEntity) override;
	int getXSpeed();
	int getYSpeed();
	void setXSpeed(int xSpeed);
	void setYSpeed(int ySpeed);
};