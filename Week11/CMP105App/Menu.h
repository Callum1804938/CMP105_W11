#pragma once
#include <iostream>

#include "Framework/AudioManager.h"
#include "Framework/GameObject.h"
#include "Framework/GameState.h"



class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	void startGame();
	void handleInput();
	void render();
	void update(float dt);

private:
	void beginDrawing();
	void endDrawing();

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	//*****************************************************************

	GameObject background;
	sf::Texture backgroundTexture;

	sf::Font font;
	sf::Text caught;
	sf::Text instructions;
	sf::Text controls;
};

