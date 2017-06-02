#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDLBmp.h"
#include "Bodypart.h"
#include <list>

class Snake : std::vector<Bodypart>
{
public:
	Snake(Bodypart* head, Bodypart* body);
	~Snake();
	int length;
	Bodypart* snakeHead;
	Bodypart* snakeBody;

	Bodypart* getBodyPart(int i);
	void addBodypart();
	int getLength();
};

#endif