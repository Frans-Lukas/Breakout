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


#define WINDOW_WIDTH 256
#define WINDOW_HEIGHT 512
#define FRAME_LIMIT 60
#define RGB_MAX_COLOR 255

#define NUM_BLOCKS_HEIGHT 16
#define NUM_BLOCKS_WIDTH 8
#define EASY_BLOCK_LIFE 1
#define BLOCK_WIDTH WINDOW_WIDTH / NUM_BLOCKS_WIDTH
#define BLOCK_HEIGHT WINDOW_HEIGHT / NUM_BLOCKS_HEIGHT * 1.5

#define PLAYER_START_Y WINDOW_HEIGHT - WINDOW_HEIGHT / 6
#define PLAYER_WIDTH WINDOW_WIDTH / 3
#define PLAYER_HEIGHT WINDOW_HEIGHT / 32

#define BALL_RESERVE 5
#define BALL_RADIUS_START WINDOW_HEIGHT / 128


class GameHandler {
private:
	sf::RenderWindow window;
	
	std::vector<Block> blocksVector;
	std::vector<Block>::iterator blockIterator;
	sf::RectangleShape blockRS;

	std::vector<Ball> ballsVector;
	std::vector<Ball>::iterator ballsIterator;
	sf::CircleShape ballCS;

	Player *player;
	sf::RectangleShape playerRS;

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