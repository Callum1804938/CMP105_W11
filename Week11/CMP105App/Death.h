#pragma once
#include <iostream>

#include "Framework/AudioManager.h"
#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include "Level.h"


class Death
{
public:
	Death(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
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
	//*****************************************************************

	GameObject background;
	sf::Texture backgroundTexture;
	Butterfly butterfly;
	sf::Texture butterflyTexture;
	GameObject net;
	sf::Texture netTexture;

	sf::Font font;
	sf::Text caught;
	sf::Text instructions;

};

