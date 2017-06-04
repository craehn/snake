/*
* @file: Apple.cpp
* @author: Silje Lilleeng Johnsen og Sven Craehn
* @version: Exam - Spring 2017
*
* @description: A class for managing an apple on the game screen.
*/
#include "Apple.h"
#include <iostream>

Apple::Apple(SDLBmp * img)
{
	image = img;
}

Apple::~Apple()
{
}

void Apple::setCoordinates()
{
	this->posX = (rand() % 39) * 20;
	this->posY = (rand() % 29) * 20;
}


SDLBmp* Apple::getImage() {
	image->x = this->posX;
	image->y = this->posY;
	return image;
}

void Apple::setImage(SDLBmp* img) {
	image = img;
}
