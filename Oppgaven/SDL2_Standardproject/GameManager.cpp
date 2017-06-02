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
#include "Bodypart.h"
#include <iostream>
#include <algorithm>
#include "Snake.h"

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
	bool GameOver = false;
	
	// Load bitmaps
	SDLBmp backround	("Assets/gfx/bg_sand.bmp");
	//Load snake bitmaps
	SDLBmp head			("Assets/gfx/snakehead_right.bmp");
	SDLBmp body			("Assets/gfx/snake_body.bmp");

	Bodypart snakeHead(360, 260, &head);
	Bodypart snakeBody(360, 260, &body);

	snake.push_back(snakeHead);
	snake.push_back(snakeBody);
	snake.push_back(snakeBody);

	// Calculate render frames per second (second / frames) (60)
	float render_fps = 1.f / speed;
	m_lastRender = render_fps; // set it to render immediately
	int dir = 3;

	// Gameloop
	while (!GameOver)
	{
		// Update input and deltatime
		InputManager::Instance().Update();
		Timer::Instance().update();

		setNextPos();

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
			GameOver = true;
		}

		// Update time since last render
		m_lastRender += Timer::Instance().deltaTime();

		// Check if it's time to render
		if (m_lastRender >= render_fps)
		{
			setDisplacement(dir);

			// Add bitmaps to renderer
			backround.draw();
			drawSnake();

			// Render window
			SDLManager::Instance().renderWindow(m_window);
			m_lastRender = 0.f;
		}

		if((snake[0].posX < 0 || snake[0].posX > 780) || 
			(snake[0].posY < 0 || snake[0].posY > 580))
		{
			GameOver = true;
		}

		// Sleep to prevent CPU exthaustion (1ms == 1000 frames per second)
		SDL_Delay(1);
	}
}

void GameManager::setNextPos()
{
	for (int i = 1; i < snake.size(); i++) {
		snake[i].nextX = snake[i - 1].posX;
		snake[i].nextY = snake[i - 1].posY;
	}
}

void GameManager::setDisplacement(int dir)
{
	float displacement = 20;
	std::cout << snake[0].posX << ", " << snake[0].posY << std::endl;
	switch (dir) {
	case 1: snake[0].posX -= displacement; //Left
			snake[0].setRotation(180);
		break;
	case 2: snake[0].posY -= displacement; //Up
			snake[0].setRotation(270);
		break;
	case 3: snake[0].posX += displacement; //Right
			snake[0].setRotation(0);
		break;
	case 4: snake[0].posY += displacement; //Down
			snake[0].setRotation(90);
		break;
	default: snake[0].posX += displacement;
		break;
	}
}

void GameManager::drawSnake()
{
	for (int i = 1; i < snake.size(); i++) {
		snake[i].posX = snake[i].nextX;
		snake[i].posY = snake[i].nextY;
	}
	for (int i = 0; i < snake.size(); i++) {
		snake[i].getImage()->draw(snake[i].rotation);
	}
}

void GameManager::addBodypart(Bodypart body)
{
	snake.push_back(body);
}