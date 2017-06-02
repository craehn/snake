#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDLBmp.h"
#include "Bodypart.h"
#include <list>

class Snake
{
public:
	Snake(Bodypart* head, Bodypart* body);
	~Snake();
	int length;
	Bodypart* snakeHead;
	Bodypart* snakeBody;

	std::vector<Bodypart*> snake;
	void setNextPos();
	void setDisplacement(int dir);
	void drawSnake();
	void addBodypart(Bodypart* body);
};

#endif