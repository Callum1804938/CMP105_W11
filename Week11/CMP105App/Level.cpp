#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	//adding background
	if (!backgroundTexture.loadFromFile("background/pixelbackground.jpg"))
	{
		std::cout << "could not load background file.";
	}
	background.setTexture(&backgroundTexture);
	background.setPosition(0, 0);


	//Butterfly Object
	if (!butterflyTexture.loadFromFile("butterfly/butterfly side sprite strip.png"))
	{
		std::cout << "butterfly sprite sheet failed to load.";
	}
	butterfly.setSize(sf::Vector2f(70, 58));
	butterfly.setPosition((window->getSize().x / 4) - 30, (window->getSize().y / 3));
	butterfly.setTexture(&butterflyTexture);
	butterfly.setVelocity(10.f, 10.f);
	butterfly.setInput(input);


	
	//Game title
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "failure to load font file" << std::endl;
	}

	game_title.setFont(font);
	game_title.setString("A Shameless Copy");
	game_title.setCharacterSize(30);
	game_title.setFillColor(sf::Color::Black);
	game_title.setStyle(sf::Text::Bold);
	game_title.setPosition(475, 0);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	butterfly.handleInput(dt);
	


}

// Update game objects
void Level::update(float dt)
{
	//update positions 
	sf::Vector2u pos = window->getSize();
	//background
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//butterfly
	
	butterfly.setSize(sf::Vector2f(window->getSize().x / 12, window->getSize().y / 6.75));
	butterfly.update(dt);
	//obsticles



	

}

// Render level
void Level::render()
{
	beginDraw();
	//thing to draw go here
	
	window->draw(background);
	window->draw(butterfly);
	
	window->draw(game_title);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}