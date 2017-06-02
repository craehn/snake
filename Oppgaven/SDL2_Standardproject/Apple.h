#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDLBmp.h"

class Apple
{
public:
	Apple(SDLBmp* img);
	~Apple();

	int posX;
	int posY;

	SDLBmp* getImage();
	void setImage(SDLBmp* img);
	void setCoordinates();

private:
	SDLBmp* image;
};