#include "GameHandler.h"
#include <iostream>

#define WINDOW_WIDTH 256
#define WINDOW_HEIGHT 512
#define FRAME_LIMIT 60
#define NUM_BLOCKS_HEIGHT 16
#define NUM_BLOCKS_WIDTH 8
#define EASY_BLOCK_LIFE 1

GameHandler::GameHandler() {
	// init window.
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");
	window.setFramerateLimit(FRAME_LIMIT);
	
	//calculate size of blocks
	blockHeight = WINDOW_HEIGHT / NUM_BLOCKS_HEIGHT;
	blockWidth = WINDOW_WIDTH / NUM_BLOCKS_WIDTH;
	blockRS.setSize(sf::Vector2f(blockWidth, blockHeight));

	//reserver size for blocks
	blocksVector.reserve(NUM_BLOCKS_WIDTH * NUM_BLOCKS_HEIGHT);

	//Add blocks to vector
	for (int i = 0; i < NUM_BLOCKS_HEIGHT; i++){
		for (int j = 0; j < NUM_BLOCKS_WIDTH; j++){
			Block newBlock(j*blockWidth, i*blockHeight, 
				blockWidth, blockHeight, EASY_BLOCK_LIFE);
			blocksVector.push_back(newBlock);
		}
	}
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
	
	for (blockIterator = blocksVector.begin(); 
			blockIterator != blocksVector.end(); 
			++blockIterator){
		
		blockRS.setFillColor(sf::Color::Red);
		blockRS.setPosition(blockIterator->getX(), 
							blockIterator->getY());
		window.draw(blockRS);

	}
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
