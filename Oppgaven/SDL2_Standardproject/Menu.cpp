#include "Menu.h"
#include "SDL/SDLBmp.h"


Menu::Menu(SDLBmp* bg, SDLBmp* btn) {
	background = bg;
	button = btn;
}


Menu::~Menu() {
}

void Menu::StartMenu()
{

	button->x = 300;
	button->y = 300;
	background->draw();
	button->draw();

}

SDLBmp* Menu::GetButton()
{
	return button;
}