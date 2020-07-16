#include "Pause.h"

Pause::Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

}

void Pause::pauseGame()
{
	gameState->setCurrentState(State::PAUSE);
}

void Pause::resumeGame()
{
	gameState->setCurrentState(State::LEVEL);

}

void Pause::handleInput()
{
	//input to close window 
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	//input to resume game
	if (input->isKeyDown(sf::Keyboard::P))
	{
		resumeGame();
		input->setKeyUp(sf::Keyboard::P);
	}
}

void Pause::render()
{
	beginDrawing();
	
	endDrawing();
}

void Pause::beginDrawing()
{
	window->clear(sf::Color(100, 149, 237));
}

void Pause::endDrawing()
{
	window->display();
}
