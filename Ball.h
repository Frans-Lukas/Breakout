#pragma once
#include "Entity.h"


class Ball : public Entity {
private: 
	float radius;
public:
	Ball(int newX, int newY, 
		float radius);
	void setRadius(float radius);
	float getRadius();
};