/*
 * @file: GameManager.h
 * @author: Silje Lilleeng Johnsen og Sven Craehn
 * based on original code by Stig M. Halvorsen
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "SDL/SDLManager.h"
#include "Snake.h"
#include "Bodypart.h"

class GameManager
{
public:
	bool StartGame;
	/* Meyer's singleton style instance call */
	static GameManager& Instance()
	{
		static GameManager g;
		return g;
	}

	/* Kicks off/is the the gameloop */
	void play();
private:
	GameManager();								// Hidden constructor
	GameManager(const GameManager&);			// Hidden copy constructor
	GameManager& operator=(const GameManager&); // Hidden assign operator
	
	unsigned int m_window; // pointer to main window
	float m_lastRender; // Time in seconds since last render
	
	//Egna till�gg
	int score = 0;
	int snakeLength;
	std::vector<Bodypart> snake;
	void setNextPos();
	void setDisplacement(int dir);
	void drawSnake();
	void addBodypart(Bodypart body);
};

#endif