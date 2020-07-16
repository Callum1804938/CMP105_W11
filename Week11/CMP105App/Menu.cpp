#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	if (!backgroundTexture.loadFromFile("gfx/pixelbackground.jpg"))
	{
		std::cout << "could not load background file.";
	}
	background.setTexture(&backgroundTexture);
	background.setPosition(0, 0);
	//Loading Font file
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "failure to load font file" << std::endl;
	}
	caught.setFont(font);
	caught.setString("Net Hopper");
	caught.setCharacterSize(40);
	caught.setFillColor(sf::Color::Black);
	caught.setStyle(sf::Text::Bold);

	instructions.setFont(font);
	instructions.setString("Avoid those nets!\nAnd dont go out of bounds!");
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::Black);

	controls.setFont(font);
	controls.setString("Press 'Enter' to Play\n\nPress 'Space to flap your wings\n\nPress 'Esc' to Quit the Game at any time\n\nPress 'P' to Pause the game");
	controls.setCharacterSize(20);
	controls.setFillColor(sf::Color::Black);
}

void Menu::startGame()
{
	gameState->setCurrentState(State::LEVEL);
}

void Menu::handleInput()
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

void Menu::update(float dt)
{
	//update window size 
	sf::Vector2u pos = window->getSize();
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	caught.setPosition(window->getSize().x/3 , 40);
	instructions.setPosition(window->getSize().x / 3, 150);
	controls.setPosition(window->getSize().x / 3, 200);
}	

void Menu::render()
{
	beginDrawing();

	window->draw(background);
	window->draw(caught);
	window->draw(instructions);
	window->draw(controls);


	endDrawing();
}

void Menu::beginDrawing()
{
	window->clear(sf::Color::Blue);
}

void Menu::endDrawing()
{
	window->display();
}
