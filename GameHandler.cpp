#include "GameHandler.h"
#include <iostream>

GameHandler::GameHandler() {
	// init window.
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");
	window.setFramerateLimit(FRAME_LIMIT);

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
	for (ballsIterator = ballsVector.begin(); 
		ballsIterator != ballsVector.end(); 
		++ballsIterator) {

		ballCS.setPosition(
			ballsIterator->getX(), 
			ballsIterator->getY()
		);

		window.draw(ballCS);

	}
}


//update entities.
void GameHandler::update() {
	for (ballsIterator = ballsVector.begin();
			ballsIterator != ballsVector.end();
			++ballsIterator) {
		ballsIterator->update();
	}
	player->update();
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
	blockRS.setSize(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));

	//reserver size for blocks
	blocksVector.reserve(NUM_BLOCKS_WIDTH * NUM_BLOCKS_HEIGHT);

	for (int i = 0; i < NUM_BLOCKS_HEIGHT / 2; i++) {
		for (int j = 0; j < NUM_BLOCKS_WIDTH; j++) {

			Block newBlock(j*BLOCK_WIDTH, i*BLOCK_HEIGHT,
				BLOCK_WIDTH, BLOCK_HEIGHT, EASY_BLOCK_LIFE);
			newBlock.setColor(sf::Color(
				(RGB_MAX_COLOR / NUM_BLOCKS_HEIGHT * i),
				(RGB_MAX_COLOR / NUM_BLOCKS_WIDTH * j),
				(RGB_MAX_COLOR / (NUM_BLOCKS_WIDTH + NUM_BLOCKS_HEIGHT) * (i + j))
			)
			);
			blocksVector.push_back(newBlock);
		}
	}
}

void GameHandler::setUpPlayer() {

	player = new Player(WINDOW_WIDTH / 2 - PLAYER_WIDTH / 2, 
		PLAYER_START_Y,
		PLAYER_WIDTH, 
		PLAYER_HEIGHT);
	playerRS.setSize(sf::Vector2f(
		player->getWidth(), 
		player->getHeight()));
}

void GameHandler::setUpBallVector() {
	ballsVector.reserve(BALL_RESERVE);
	Ball ball(
		WINDOW_WIDTH / 2 - BALL_RADIUS_START / 2, 
		WINDOW_HEIGHT / 2, 
		BALL_SPEED_START,
		BALL_SPEED_START,
		BALL_RADIUS_START
	);
	ballsVector.push_back(ball);

	ballCS.setRadius(BALL_RADIUS_START);
	ballCS.setFillColor(sf::Color::White);
}

