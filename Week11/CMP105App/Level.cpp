#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	//Adding background
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
	
	butterfly.setPosition((window->getSize().x / 4) - 35, (window->getSize().y / 3));
	butterfly.setTexture(&butterflyTexture);
	butterfly.setVelocity(0, 10.f);
	butterfly.setInput(input);

	//Obsticles
	if (!netTexture.loadFromFile("butterfly net/Butterfly net.png"))
	{
		std::cout << "could not load net sprite.";
	}
	net1.setTexture(&netTexture);
	net1.setPosition((window->getSize().x) + 65, 300);
	
	net2.setTexture(&netTexture);
	net2.setPosition((window->getSize().x) + 435, 50);

	net3.setTexture(&netTexture);
	net3.setPosition((window->getSize().x) + 810, 350);

	net4.setTexture(&netTexture);
	net4.setPosition((window->getSize().x) + 1185, 550);

	speed = 100.f;
	



	//Loading Font file
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "failure to load font file" << std::endl;
	}
	//Game Title
	game_title.setFont(font);
	game_title.setString("A Shameless Copy");
	game_title.setCharacterSize(30);
	game_title.setFillColor(sf::Color::Black);
	game_title.setStyle(sf::Text::Bold);
	game_title.setPosition(0, 0);
	//Instructions

	instructions.setFont(font);
	instructions.setString("Press Enter to flap\nAvoid those nets!");
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::Black);
	instructions.setPosition(0, 35);

	//score

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	butterfly.handleInput(dt);

	//input to close window 
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	//check for focus

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
	net1.move(-speed * dt, 0);
	net2.move(-speed * dt, 0);
	net3.move(-speed * dt, 0);
	net4.move(-speed * dt, 0);
	net1.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net2.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net3.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net4.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));

}

// Render level
void Level::render()
{
	beginDraw();
	//thing to draw go here
	
	window->draw(background);

	window->draw(butterfly);

	window->draw(net1);
	window->draw(net2);
	window->draw(net3);
	window->draw(net4);

	window->draw(game_title);

	window->draw(instructions);

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