#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"

#include "Framework/Collision.h"
#include "Butterfly.h"
#include "Framework/Vector.h"
#include "Framework/GameObject.h"








class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	//*****************************************************************************************

	
	

	//Added Game assets
	GameObject background;
	sf::Texture backgroundTexture;

	Butterfly butterfly;
	sf::Texture butterflyTexture;
	



	GameObject net[6];
	sf::Texture netTexture;
	float speed{ 0.f };
	int randYPos{ 0 };

	GameObject deathScreen;

	//Text in Window

	sf::Text gameTitle;
	sf::Text instructions;
	sf::Text gameOver;
	sf::Text score;
	sf::Font font;
};