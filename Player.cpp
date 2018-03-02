#include "Player.h"


Player::Player(int newX, int newY, int newWidth, int newHeight)
	: Entity(newX, newY, newWidth, newHeight){
	left = false;
	right = false;
}



int Player::getLife() {
	return lifeLeft;
}

void Player::update() {
	getUserInput();
	if (left) {
		setX(getX() - 1);
	} 
	if (right) {
		setX(getX() + 1);
	}
}

void Player::getUserInput() {
	left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Player::setLife(int newLife){
	lifeLeft = newLife;
}