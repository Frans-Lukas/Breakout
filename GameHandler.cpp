#include "GameHandler.h"
#include <iostream>

#define WINDOW_WIDTH 256
#define WINDOW_HEIGHT 512
#define FRAME_LIMIT 60
#define NUM_BLOCKS_HEIGHT 16
#define NUM_BLOCKS_WIDTH 8
#define EASY_BLOCK_LIFE 1
#define PLAYER_START_Y WINDOW_HEIGHT - WINDOW_HEIGHT / 6



GameHandler::GameHandler() {
	// init window.
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");
	window.setFramerateLimit(FRAME_LIMIT);
	

	blockHeight = WINDOW_HEIGHT / (NUM_BLOCKS_HEIGHT * 1.5);
	blockWidth = WINDOW_WIDTH / (NUM_BLOCKS_WIDTH);

	//Add blocks to vector
	setUpBlockVector();
	setUpPlayer();
	setUpBallVector();
}

void GameHandler::startGame() {


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		// Draw & update entities.
		update();
		draw();

		window.display();
	}
}

//draw entities.
void GameHandler::draw() {
	
	//draw blocks
	
	
	drawBlocks();
	drawBalls();
	
	//draw player
	drawRectangle(
		sf::Color::White,
		player->getX(),
		player->getY(),
		playerRS
	);

}




void GameHandler::drawBlocks() {

	for (blockIterator = blocksVector.begin();
			blockIterator != blocksVector.end();
			++blockIterator) {
		drawRectangle(
			blockIterator->getColor(), 
			blockIterator->getX(),
			blockIterator->getY(),
			blockRS
		);
	}

}

void GameHandler::drawRectangle(sf::Color color, int x, int  y, sf::RectangleShape rs) {
	rs.setFillColor(color);
	rs.setPosition(x, y);
	window.draw(rs);
}

void GameHandler::drawBalls() {
}


//update entities.
void GameHandler::update() {
	for (int i = 0; i < 5; i++)
	{

	}
}

GameHandler* GameHandler::gameHandler_instance = 0;

GameHandler* GameHandler::getInstance() {
	if (!gameHandler_instance)
		gameHandler_instance = new GameHandler;
		
	return gameHandler_instance;
}

GameHandler::~GameHandler()
{
}




void GameHandler::setUpBlockVector() {
	//calculate size of blocks
	blockRS.setSize(sf::Vector2f(blockWidth, blockHeight));

	//reserver size for blocks
	blocksVector.reserve(NUM_BLOCKS_WIDTH * NUM_BLOCKS_HEIGHT);

	for (int i = 0; i < NUM_BLOCKS_HEIGHT / 2; i++) {
		for (int j = 0; j < NUM_BLOCKS_WIDTH; j++) {
			Block newBlock(j*blockWidth, i*blockHeight,
				blockWidth, blockHeight, EASY_BLOCK_LIFE);
			newBlock.setColor(sf::Color(
				(255 / NUM_BLOCKS_HEIGHT * i),
				(255 / NUM_BLOCKS_WIDTH * j),
				(255 / (NUM_BLOCKS_WIDTH + NUM_BLOCKS_HEIGHT) * (i + j))
			)
			);
			blocksVector.push_back(newBlock);
		}
	}
}

void GameHandler::setUpPlayer() {
	playerWidth = WINDOW_WIDTH / 3;
	playerHeight = WINDOW_HEIGHT / 32;

	player = new Player(WINDOW_WIDTH / 2 - playerWidth / 2, 
		PLAYER_START_Y,
		playerWidth, 
		playerHeight);
	playerRS.setSize(sf::Vector2f(
		player->getWidth(), 
		player->getHeight()));
}

void GameHandler::setUpBallVector() {
}

