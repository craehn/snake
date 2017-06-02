#pragma once
#include "SDL/SDLBmp.h"

class Menu {
public:
	Menu(SDLBmp* bg, SDLBmp* btn);
	~Menu();
	SDLBmp* button;
	SDLBmp* background;
	void StartMenu();
	SDLBmp* Menu::GetButton();
};

