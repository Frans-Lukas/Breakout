#include <SFML/Graphics.hpp>
#include "GameHandler.h"

int main(){
	GameHandler *gm = GameHandler::getInstance();
	gm->startGame();
	return 0;
}