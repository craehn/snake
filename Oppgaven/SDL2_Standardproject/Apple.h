/*
* @file: Apple.h
* @author: Silje Lilleeng Johnsen og Sven Craehn
* @version: Exam - Spring 2017
*
* @description: A class for managing an apple on the game screen.
*/

#pragma once
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