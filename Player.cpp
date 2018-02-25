#include "Player.h"


Player::Player(float newX, float newY, int newWidth, int newHeight) 
	: Entity(newX, newY, newWidth, newHeight){}

int Player::getLife() {
	return lifeLeft;
}

void Player::setLife(int newLife){
	lifeLeft = newLife;
}