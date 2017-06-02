#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDLBmp.h"
#include <list>
#include "Bodypart.h"

class Snake : std::vector<Bodypart>
{
public:
	Snake(Bodypart* head, Bodypart* body);
	~Snake();
	int length;
	Bodypart* snakeHead;
	Bodypart* snakeBody;
	void addBodypart();
	int getLength();
};

#endif