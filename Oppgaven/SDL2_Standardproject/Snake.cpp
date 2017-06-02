#include "Snake.h"
#include "Bodypart.h"
#include <iterator>

Snake::Snake(Bodypart* head, Bodypart* body)
{
	length = 3;
	snakeHead = head;
	snakeBody = body;
	this->push_back(Bodypart(*snakeHead));
	addBodypart();
	addBodypart();
}

Snake::~Snake()
{
	
}

void Snake::addBodypart()
{
	this->push_back(Bodypart(*snakeBody));
	length++;
}

int Snake::getLength()
{
	return length;
}

Bodypart* Snake::getBodyPart(int i)
{
	Bodypart* temp = this[i].snakeBody;
	return temp;
}