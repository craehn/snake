#include "Bodypart.h"

Bodypart::Bodypart(int x, int y, SDLBmp* img)
{	
	this->posX = x;
	this->posY = y;

	this->nextX = x;
	this->nextY = y;

	image = img;
	rotation = 0;
	parent = NULL;
}

Bodypart::~Bodypart()
{
}

SDLBmp* Bodypart::getImage() {
	image->x = this->posX;
	image->y = this->posY;
	return image;
}

void Bodypart::setImage(SDLBmp* img) {
	image = img;
}

void Bodypart::setRotation(int rot)
{
	rotation = rot;
}

void Bodypart::setParent(Bodypart* par)
{
	par = parent;
}