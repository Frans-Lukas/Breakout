
#include <SFML/Graphics.hpp>
#include "GameHandler.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC  

int main(){
	GameHandler *gm = GameHandler::getInstance();
	gm->startGame();
	_CrtDumpMemoryLeaks();
	return 0;
}