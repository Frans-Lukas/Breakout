#pragma once
#include "Entity.h"

class Player: public Entity {
private:
	int lifeLeft;
public:
	int getLife();
	void setLife(int newLife);
};