#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <string>
#include <iostream>
#include "Butterfly.h"
#include "Net.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	GameObject net1;
	GameObject net2;
	GameObject net3;
	GameObject net4;
	GameObject net5;
	GameObject net6;
	sf::Texture netTexture;
	float speed;
	int randYPos;
	//Game objects

	sf::Text game_title;
	sf::Text instructions;
	sf::Text score;
	sf::Font font;
};