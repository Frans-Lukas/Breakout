#pragma once

class Entity {
private:
	int x;
	int y;
	int width;
	int height;

public:
	Entity(int newX, int newY, int newWidth, int newHeight);
	Entity() = default;
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	void setX(float newX);
	void setY(float newY);
};
