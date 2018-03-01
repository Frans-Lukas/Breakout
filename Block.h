#pragma once
#include"Entity.h"

class Block: public Entity{
private:
	int lifeLeft;
	sf::Color color = sf::Color::Red;
public:
	Block(int newX, int newY, int newWidth,
		int newHeight, int newLifeLeft);
	int getLifeLeft();
	sf::Color getColor();
	void setColor(sf::Color color);
	void decrementLifeLeft();
};