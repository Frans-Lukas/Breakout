#pragma once

class Entity {
private:
	float x;
	float y;
	int width;
	int height;

public:
	Entity(float x, float y, int width, int height);

	float getX();
	float getY();
	int getWidth();
	int getHeight();
};