#include "Apple.h"
#include <iostream>
#include <string>
#include <vector>

Apple::Apple(int x, int y, SDLBmp * img)
{
	this->posX = x;
	this->posY = y;

	this->prevX = x;
	this->prevY = y;

	image = img;
}

Apple::~Apple()
{
}
SDLBmp* Apple::getImage() {
	image->x = this->posX;
	image->y = this->posY;
	return image;
}

void Apple::setImage(SDLBmp* img) {
	image = img;
}
