/*
* @file: Bodypart.cpp
* @author: Silje Lilleeng Johnsen og Sven Craehn
* @version: Exam - Spring 2017
*
* @description: A class for managing each bodypart of the snake.
*/
#ifndef BODYPART_H
#define BODYPART_H

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

	SDLBmp* getImage();
	void setImage(SDLBmp* img);
	void setRotation(int rot);
private:
	SDLBmp* image;
};

#endif