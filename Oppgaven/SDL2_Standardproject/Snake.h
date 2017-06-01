#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <iostream>
#include "../packages/sdl2.2.0.5/build/native/include/SDL.h"
#include "Bodypart.h"

class Bodypart;

class Snake {
public:
	Snake();

	~Snake();
	std::vector<Snake*> SnakeList;
	std::vector<Bodypart*> BodyList;

	Bodypart* head;
	Bodypart* tail;

	void Init();
	void AddBodypart();
};

#endif // SNAKE_H