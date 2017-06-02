#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDLBmp.h"

class Apple
{
public:
	Apple(int x, int y, SDLBmp* img);
	~Apple();

	int posX;
	int posY;

	int prevX;
	int prevY;

	SDLBmp* getImage();
	void setImage(SDLBmp* img);

private:
	SDLBmp* image;
};