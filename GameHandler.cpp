#include "GameHandler.h"
#include <iostream>

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 200
#define FRAME_LIMIT 60

GameHandler::GameHandler() {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "test");
	window.setFramerateLimit(FRAME_LIMIT);
}

void GameHandler::startGame() {


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		// Draw stuff
		update();
		draw();
		window.display();
	}
}



//draw entities.
void GameHandler::draw() {
	for (int i = 0; i < 1; i++)
	{

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
