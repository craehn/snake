#include "Bodypart.h"

Bodypart::Bodypart(SDLBmp part) {
	posX = part.x;
	posY = part.y;

}

Bodypart::~Bodypart() {
}

Bodypart* Bodypart::AddPart(int x)
{
	if(x == 1)
	{
		Bodypart* body = new Bodypart(SDLBmp("Assets/gfx/snake_body.bmp"));
		return body;
	} 
}
