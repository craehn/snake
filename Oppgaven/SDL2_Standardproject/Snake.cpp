#include "Snake.h"
#include "Bodypart.h"
#include "SDL/SDLBmp.h"
#include "SDL/SDLManager.h"

Snake::Snake() {
	Snake::Init();
}

Snake::~Snake() {
}

void Snake::Init()
{
	head = new Bodypart(SDLBmp ("Assets/gfx/Snake_head_right.bmp"));
	BodyList.push_back(head);


}

void Snake::AddBodypart()
{

}
