#include "Bodypart.h"
#include "SDL/SDLBmp.h"

Bodypart::Bodypart(int x) {
	switch (x) {
	case 1: {SDLBmp head_up("Assets/gfx/Snake_body_up.bmp"); //Up
		break; }
	case 2: {SDLBmp head_right("Assets/gfx/Snake_body_right.bmp");//Right
		break; }
	case 3: {SDLBmp body_down("Assets/gfx/Snake_body_down.bmp"); //Down
		break; }
	case 4: {SDLBmp body_left("Assets/gfx/Snake_body_left.bmp");//Left
		break; }
	default: SDLBmp body("Assets/gfx/Snake_body_left.bmp");
		break;
	}
}

Bodypart::~Bodypart() {
}