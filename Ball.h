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
	void callCollide() override;
};