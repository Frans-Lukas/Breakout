#pragma once
#include <SFML/Graphics.hpp>

class GameHandler {
private:
	sf::RenderWindow window;
	static GameHandler *gameHandler_instance;
public:
	GameHandler();
	void startGame();
	void draw();
	static GameHandler *getInstance();
	virtual ~GameHandler();
};