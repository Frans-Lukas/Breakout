#pragma once

class Entity {
private:
	float x;
	float y;
	int width;
	int height;

public:
	Entity(float newX, float newY, int newWidth, int newHeight);
	float getX();
	float getY();
	int getWidth();
	int getHeight();
	void setX();
	void setY();
};
