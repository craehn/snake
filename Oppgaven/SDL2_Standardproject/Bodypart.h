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

	int nextX;
	int nextY;

	int rotation;

	Bodypart* parent;
	SDLBmp* getImage();
	void setImage(SDLBmp* img);
	void setRotation(int rot);
	void setParent(Bodypart* par);
private:
	SDLBmp* image;
};

#endif