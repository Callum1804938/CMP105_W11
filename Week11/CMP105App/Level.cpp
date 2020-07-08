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
	if (!texture.loadFromFile("background/pixelbackground.jpg"))
	{
		std::cout << "could not load background file.";
	}
	background.setTexture(&texture);
	background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	background.setPosition(0, 0);


	//butterfly object
	butterfly.setRadius(15);
	butterfly.setPosition((window->getSize().x / 4) - 30, (window->getSize().y / 2) - 30);
	butterfly.setFillColor(sf::Color::Yellow);

	

	//Obsticle object
	obsticle.setSize(sf::Vector2f(50, 300));
	obsticle.setPosition(1180,375);
	obsticle.setFillColor(sf::Color::Green);
	
	speed = 80.f;
	
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
	//if space is pressed output to console
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		std::cout << "Spacebar was pressed" << std::endl << std::endl;
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		std::cout << "Enter was pressed" << std::endl << std::endl;
	}
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	//update positions 
	sf::Vector2u pos = window->getSize();
	//background
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//butterfly
		butterfly.setPosition((window->getSize().x / 4) - 30, (window->getSize().y / 2) - 30);
	//obsticles



	
	obsticle.move(-speed * dt, 0);
}

// Render level
void Level::render()
{
	beginDraw();
	//thing to draw go here
	
	window->draw(background);
	window->draw(butterfly);
	window->draw(obsticle);
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