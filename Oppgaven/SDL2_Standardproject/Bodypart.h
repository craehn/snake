#ifndef BODYPART_H
#define BODYPART_H

#include <vector>
#include <iostream>
#include "SDL/SDLBmp.h"
#include "../packages/sdl2.2.0.5/build/native/include/SDL.h"

class SDLBmp;

class Bodypart {
public:
	Bodypart(SDLBmp part);

	~Bodypart();
	int posX;
	int posY;
	int nextX;
	int nextY;

	Bodypart* AddPart(int x);
};

#endif // BODYPART_H