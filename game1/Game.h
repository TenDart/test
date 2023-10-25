#pragma once
#include "includes.h"
#include "Objects.h"

class Game {
public:
	Objects objects;

	void Initialize() {
		objects.Initialize();
	}

	void loop(sf::RenderWindow& window) {

		for (int i = 0; i < objects.objs.size(); ++i) {
			window.draw(objects.objs[i]);
			objects.objs[i].move(objects.moveSpeedX[i], objects.moveSpeedY[i]);
		}

		window.draw(objects.leftWall);
		window.draw(objects.rightWall);
		window.draw(objects.topWall);
		window.draw(objects.downWall);

		objects.checkWallCollision();
	}
};