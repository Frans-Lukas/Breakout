#include "GameHandler.h"
#include <iostream>


Ball *ballPointer;

using namespace std;

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
			(*blockIterator)->getColor(), 
			(*blockIterator)->getX(),
			(*blockIterator)->getY(),
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
			(*ballsIterator)->getX(), 
			(*ballsIterator)->getY()
		);
		window.draw(ballCS);

	}
}


//update entities.
void GameHandler::update() {

	//check for collision between all entities;

	for (blockIterator = blocksVector.begin();
		blockIterator != blocksVector.end(); blockIterator++) {
		if (isColliding(**blockIterator, *ballPointer)) {
			(*blockIterator)->callCollide(*ballPointer);

			(ballPointer)->callCollide(**blockIterator);
		}
	}

	if (isColliding(*player, *ballPointer)) {
		ballPointer->callCollide(*ballPointer);
	}

	for (ballsIterator = ballsVector.begin();
		ballsIterator != ballsVector.end();
		ballsIterator++) {

		if ((*ballsIterator)->getX() + 
			BALL_RADIUS_START * 2 > WINDOW_WIDTH ||
			(*ballsIterator)->getX() < 0) {

			(*ballsIterator)->setXSpeed(-(*ballsIterator)->getXSpeed());
		}

		if ((*ballsIterator)->getY() <= 0) {
			(*ballsIterator)->setYSpeed(-(*ballsIterator)->getYSpeed());
		}
	}


	for (blockIterator = blocksVector.begin(); 
		blockIterator != blocksVector.end(); blockIterator++) {

		if ((*blockIterator)->getLifeLeft() <= 0) {
			
			blockIterator = blocksVector.erase(blockIterator);
			break;
		}

	}

	for (ballsIterator = ballsVector.begin();
			ballsIterator != ballsVector.end();
			++ballsIterator) {
		(*ballsIterator)->update();
	}


	player->update();
}

bool GameHandler::isColliding(Entity rect1, Entity rect2) {
	return rect1.getX() < rect2.getX() + rect2.getWidth() &&
		rect1.getX() + rect1.getWidth() > rect2.getX() &&
		rect1.getY() < rect2.getY() + rect2.getHeight() &&
		rect1.getHeight() + rect1.getY() > rect2.getY();
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

			Block *newBlock = new Block(j*BLOCK_WIDTH, i*BLOCK_HEIGHT,
				BLOCK_WIDTH, BLOCK_HEIGHT, EASY_BLOCK_LIFE);
			newBlock->setColor(sf::Color(
				((NUM_BLOCKS_HEIGHT * i )% RGB_MAX_COLOR),
				((NUM_BLOCKS_WIDTH * j) % RGB_MAX_COLOR),
				(((NUM_BLOCKS_HEIGHT * i) + (j + NUM_BLOCKS_WIDTH)) % RGB_MAX_COLOR)
			)
			);
			blocksVector.push_back(newBlock);
			entityVector.push_back(newBlock);
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
	entityVector.push_back(player);

}

void GameHandler::setUpBallVector() {
	ballsVector.reserve(BALL_RESERVE);
	Ball *ball = new Ball(
		WINDOW_WIDTH / 2 - BALL_RADIUS_START / 2, 
		WINDOW_HEIGHT / 2, 
		BALL_SPEED_START,
		BALL_SPEED_START,
		BALL_RADIUS_START
	);
	ballPointer = ball;


	ballsVector.push_back(ball);
	//entityVector.push_back(ball);

	ballCS.setRadius(BALL_RADIUS_START);
	ballCS.setFillColor(sf::Color::White);
}

