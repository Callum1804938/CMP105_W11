#pragma once

#include "Framework/AudioManager.h"
#include "Framework/GameObject.h"
#include "Framework/GameState.h"


class Pause
{
public:
	Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs,AudioManager* aud);
	void pauseGame();
	void resumeGame();
	void handleInput();
	void render();
private:
	void beginDrawing();
	void endDrawing();

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	//**************************************************
};

