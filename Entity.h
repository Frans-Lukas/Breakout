#pragma once


#ifndef SFML_GRAPHICS
#define SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#endif // !SFML_GRAPHICS


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
	void setX(int newX);
	void setY(int newY);
	void callCollide();
};
