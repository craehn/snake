#ifndef BODYPART_H
#define BODYPART_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL/SDLBmp.h"

class Bodypart
{
public:
	Bodypart(int x, int y, SDLBmp* img);
	~Bodypart();

	int posX;
	int posY;

	int prevX;
	int prevY;

	int rotation;

	Bodypart* parent;
	SDLBmp* getImage();
	void setImage(SDLBmp* img);
	void setRotation(int rot);
private:
	SDLBmp* image;
};

#endif