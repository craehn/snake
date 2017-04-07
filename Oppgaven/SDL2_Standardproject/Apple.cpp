/*
* @file: Apple.cpp
* @author: Silje Lilleeng Johnsen
* @spring - 2017
*
* @description: Class for Apple "to be eaten" by class Snake
*				One apple at a time, located at random positioning
*				By coordinates
*/

#include <iostream>
#include "Apple.h"
#include "SDL/SDLBmp.h"
#include "GameManager.h"


Apple::Apple()
{
	SDLBmp apple ("Assets/gfx/eple.bmp");

}


Apple::~Apple()
{
}