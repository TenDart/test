#pragma once
#include "includes.h"

class Objects {
public:
	int offsetX = 1;
	int offsetY = 1;

	std::vector<sf::CircleShape> objs;
	std::vector<int> moveSpeedX;
	std::vector<int> moveSpeedY;

	sf::RectangleShape leftWall;
	sf::RectangleShape rightWall;
	sf::RectangleShape topWall;
	sf::RectangleShape downWall;
	sf::FloatRect test;

	void Initialize() {
		for (int i = 0; i < 10; ++i) {
			objs.push_back(sf::CircleShape(1));
			objs[i].setFillColor(sf::Color::Cyan);
			objs[i].setRadius(20);
			objs[i].setPosition(i*90,i * 50);

			moveSpeedX.push_back(10);
			moveSpeedY.push_back(10);
		}
		leftWall.setSize(sf::Vector2f(10, 800));
		rightWall.setSize(sf::Vector2f(10,800));
		topWall.setSize(sf::Vector2f(900,10));
		downWall.setSize(sf::Vector2f(900, 10));

		leftWall.setPosition(0, 0);
		rightWall.setPosition(890, 0);
		topWall.setPosition(0, 0);
		downWall.setPosition(0,790);

	}



	void checkWallCollision() {

		if (this->objs.size() > 1);
		{
			for (int i = 0; i < objs.size(); ++i) {

				if (this->rightWall.getGlobalBounds().intersects(this->objs[i].getGlobalBounds()))
				{
					 moveSpeedX[i] = -moveSpeedX[i];
				};

				if (this->topWall.getGlobalBounds().intersects(this->objs[i].getGlobalBounds()))
				{
					moveSpeedY[i] = -moveSpeedY[i];
				};

				if (this->leftWall.getGlobalBounds().intersects(this->objs[i].getGlobalBounds()))
				{
					moveSpeedX[i] = -moveSpeedX[i];
				};

				if (this->downWall.getGlobalBounds().intersects(this->objs[i].getGlobalBounds()))
				{
					moveSpeedY[i] = -moveSpeedY[i];
				};
			}
		}
	}

};