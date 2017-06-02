#include "Snake.h"
#include "Bodypart.h"

Snake::Snake(Bodypart* head, Bodypart* body)
{
	snakeHead = head;
	snakeBody = body;
	length = 3;
	this->push_back(Bodypart(*snakeHead));
	this->push_back(Bodypart(*snakeBody));
	this->push_back(Bodypart(*snakeBody));


}

Snake::~Snake()
{
	
}

void Snake::addBodypart()
{
	
}

int Snake::getLength()
{
	return length;
}