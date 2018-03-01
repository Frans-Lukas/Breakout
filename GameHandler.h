#pragma once

#ifndef SFML_GRAPHICS
#define SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#endif // !SFML_GRAPHICS


#ifndef VECTOR_INCLUDE
#define VECTOR_INCLUDE
#include <vector>
#endif // !VECTOR_INCLUDE

#ifndef BLOCK_INCLUDE
#define BLOCK_INCLUDE
#include "Block.h"
#endif // !BLOCK_INCLUDE

#ifndef PLAYER_INCLUDE
#define PLAYER_INCLUDE
#include "Player.h"
#endif // !PLAYER_INCLUDE

#ifndef BALL_INCLUDE
#define BALL_INCLUDE
#include "Ball.h"
#endif // !BALL_INCLUDE




class GameHandler {
private:
	sf::RenderWindow window;
	
	std::vector<Block> blocksVector;
	std::vector<Block>::iterator blockIterator;
	sf::RectangleShape blockRS;
	int blockWidth;
	int blockHeight;

	std::vector<Ball> ballsVector;
	Player *player;
	sf::RectangleShape playerRS;
	int playerWidth;
	int playerHeight;

	static GameHandler *gameHandler_instance;

	void setUpBlockVector();
	void setUpPlayer();
	void setUpBallVector();

	void drawBlocks();
	void drawBalls();

	void drawRectangle(sf::Color color, int x, int  y, sf::RectangleShape rs);

public:
	GameHandler();
	void startGame();
	void draw();
	void update();
	static GameHandler *getInstance();
	virtual ~GameHandler();
};