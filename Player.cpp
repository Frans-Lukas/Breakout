#include "Player.h"


Player::Player(int newX, int newY, int newWidth, int newHeight)
	: Entity(newX, newY, newWidth, newHeight){}

int Player::getLife() {
	return lifeLeft;
}

void Player::setLife(int newLife){
	lifeLeft = newLife;
}