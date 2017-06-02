#include "Snake.h"
#include "Bodypart.h"
#include <iterator>

Snake::Snake(Bodypart* head, Bodypart* body)
{
	length = 3;
	snakeHead = head;
	snakeBody = body;
	snake.push_back(snakeHead);
	addBodypart(snakeBody);
}

Snake::~Snake()
{
	
}

void Snake::setNextPos() {
	for (int i = 1; i < snake.size(); i++) {
		snake[i]->nextX = snake[i - 1]->posX;
		snake[i]->nextY = snake[i - 1]->posY;
	}
}

void Snake::setDisplacement(int dir) {
	float displacement = 20;
	//std::cout << snake[0].posX << ", " << snake[0].posY << std::endl;
	switch (dir) {
	case 1: snake[0]->posX -= displacement; //Left
		snake[0]->setRotation(180);
		break;
	case 2: snake[0]->posY -= displacement; //Up
		snake[0]->setRotation(270);
		break;
	case 3: snake[0]->posX += displacement; //Right
		snake[0]->setRotation(0);
		break;
	case 4: snake[0]->posY += displacement; //Down
		snake[0]->setRotation(90);
		break;
	default: snake[0]->posX += displacement;
		break;
	}
}

void Snake::drawSnake() {
	for (int i = 1; i < snake.size(); i++) {
		snake[i]->posX = snake[i]->nextX;
		snake[i]->posY = snake[i]->nextY;
	}
	for (int i = 0; i < snake.size(); i++) {
		snake[i]->getImage()->draw(snake[i]->rotation);
	}
}

void Snake::addBodypart(Bodypart* body) {
	snake.push_back(body);
}