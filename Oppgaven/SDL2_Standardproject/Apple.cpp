#include "Apple.h"
#include <iostream>
#include <string>
#include <vector>

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
