#include "Death.h"



Death::Death(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;


	if (!backgroundTexture.loadFromFile("gfx/pixelbackground.jpg"))
	{
		std::cout << "could not load background file.";
	}
	background.setTexture(&backgroundTexture);
	background.setPosition(0, 0);

	if (!butterflyTexture.loadFromFile("gfx/butterfly single sprite.png"))
	{
		std::cout << "could not load butterfly file.";
	}
	butterfly.setTexture(&butterflyTexture);
	butterfly.setPosition(window->getSize().x / 3, window->getSize().y / 3);

	if (!netTexture.loadFromFile("gfx/butterfly net.png"))
	{
		std::cout << "could not load net file.";
	}
	net.setTexture(&netTexture);
	net.setPosition(window->getSize().x / 3, window->getSize().y / 3);


	//Loading Font file
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "failure to load font file" << std::endl;
	}
	caught.setFont(font);
	caught.setString("Looks like you got caught or went out of bounds!");
	caught.setCharacterSize(40);
	caught.setFillColor(sf::Color::Black);
	caught.setStyle(sf::Text::Bold);

	instructions.setFont(font);
	instructions.setString("Press 'Enter' to play again\nPress 'Esc' to quit the game");
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::Black);

}

void Death::startGame()
{
	gameState->setCurrentState(State::LEVEL);
}

void Death::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();

	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		startGame();
		
		
	}
}

void Death::update(float dt)
{
	//update window size 
	sf::Vector2u pos = window->getSize();
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	caught.setPosition(window->getSize().x / 8, 40);
	instructions.setPosition(window->getSize().x / 3, 150);



}

void Death::render()
{
	beginDrawing();

	window->draw(background);
	window->draw(caught);
	window->draw(instructions);
	window->draw(butterfly);
	window->draw(net);

	endDrawing();
}

void Death::beginDrawing()
{
	window->clear(sf::Color::Blue);
}

void Death::endDrawing()
{
	window->display();
}