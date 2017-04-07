/*
 * @file: GameManager.cpp
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#include "SDL/SDLBmp.h"
#include "GameManager.h"
#include "InputManager.h"
#include "Timer.h"
#include <iostream>
#include <algorithm>

const int MAP_WIDTH		= 40;
const int MAP_HEIGHT	= 30;
const int TOTAL_SIZE	= MAP_WIDTH * MAP_HEIGHT;
float speed = 10.f;

/* Initializes SDL, creates the game window and fires off the timer. */
GameManager::GameManager()
{
	SDLManager::Instance().init();
	m_window = SDLManager::Instance().createWindow("Snake? Snake??! Snaaaakeeeee....");
	Timer::Instance().init();
}


/* Kicks off/is the the gameloop */
void GameManager::play()
{
	bool notGameOver = true;

	// Load bitmaps
	SDLBmp backround	("Assets/gfx/bg_white.bmp");
	//Load snake bitmaps
	SDLBmp snakeHead	("Assets/gfx/Snake_head_right.bmp");
	SDLBmp head_right	("Assets/gfx/Snake_head_right.bmp");
	SDLBmp head_down	("Assets/gfx/Snake_head_down.bmp");
	SDLBmp head_left	("Assets/gfx/Snake_head_left.bmp");
	SDLBmp head_up		("Assets/gfx/Snake_head_up.bmp");

	SDLBmp tail_up		("Assets/gfx/Snake_tail_up.bmp");
	SDLBmp tail_right	("Assets/gfx/Snake_tail_right.bmp");
	SDLBmp tail_down	("Assets/gfx/Snake_tail_down.bmp");
	SDLBmp tail_left	("Assets/gfx/Snake_tail_left.bmp");

	SDLBmp body_up		("Assets/gfx/Snake_body_up.bmp");
	SDLBmp body_right	("Assets/gfx/Snake_body_right.bmp");
	SDLBmp body_down	("Assets/gfx/Snake_body_down.bmp");
	SDLBmp body_left	("Assets/gfx/Snake_body_left.bmp");

	// Calculate render frames per second (second / frames) (60)
	float render_fps = 1.f / speed;
	m_lastRender = render_fps; // set it to render immediately
	int dir = 0;

	// Gameloop
	while (notGameOver)
	{
		// Update input and deltatime
		InputManager::Instance().Update();
		Timer::Instance().update();

		// Calculate displacement based on deltatime


		/* Input Management */

		// Left key
		if ((InputManager::Instance().KeyDown(SDL_SCANCODE_LEFT) ||
			InputManager::Instance().KeyStillDown(SDL_SCANCODE_LEFT)) && dir != 3)
		{
			dir = 1;
		}
		
		// Right key
		if ((InputManager::Instance().KeyDown(SDL_SCANCODE_RIGHT) ||
			InputManager::Instance().KeyStillDown(SDL_SCANCODE_RIGHT)) && dir != 1)
		{
			dir = 3;
		}

		// Key up
		if ((InputManager::Instance().KeyDown(SDL_SCANCODE_UP) ||
			InputManager::Instance().KeyStillDown(SDL_SCANCODE_UP)) && dir != 4)
		{
			dir = 2;
		}

		// Key down
		if ((InputManager::Instance().KeyDown(SDL_SCANCODE_DOWN) ||
			InputManager::Instance().KeyStillDown(SDL_SCANCODE_DOWN)) && dir != 2)
		{
			dir = 4;
		}

		// Exit on [Esc], or window close (user X-ed out the window)
		if (InputManager::Instance().hasExit() || InputManager::Instance().KeyDown(SDL_SCANCODE_ESCAPE))
		{
			notGameOver = false;
		}

		// Update time since last render
		m_lastRender += Timer::Instance().deltaTime();

		// Check if it's time to render
		if (m_lastRender >= render_fps)
		{
			float displacement = 20;//150.F * Timer::Instance().deltaTime();
			std::cout << snakeHead.x << ", " << snakeHead.y << std::endl;

			switch (dir) {
			case 1: snakeHead.x -= displacement; //Left
				snakeHead.m_texture = head_left.m_texture;
				break;
			case 2: snakeHead.y -= displacement; //Up
				snakeHead.m_texture = head_up.m_texture;
				break;
			case 3: snakeHead.x += displacement; //Right
				snakeHead.m_texture = head_right.m_texture;
				break;
			case 4: snakeHead.y += displacement; //Down
				snakeHead.m_texture = head_down.m_texture;
				break;
			default: snakeHead.x += displacement;
				break;
			}

			// Add bitmaps to renderer
			backround.draw();
			snakeHead.draw();

			// Render window
			SDLManager::Instance().renderWindow(m_window);
			m_lastRender = 0.f;
		}

		if((snakeHead.x < 0 || snakeHead.x > 780) || (snakeHead.y < 0 || snakeHead.y > 580))
		{
			notGameOver = false;
		}

		// Sleep to prevent CPU exthaustion (1ms == 1000 frames per second)
		SDL_Delay(1);
	}
}